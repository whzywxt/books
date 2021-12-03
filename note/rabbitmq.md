> RabbitMQ Go语言客户端教程 
> https://blog.csdn.net/u012988901/article/details/89296451

## 消息持久化、消费者Ack确认与重回队列
- 交换机持久化，durable设为true，否则重启后，交换机不存在了，但是消息还在，但是不能往该交换机发送消息，一般会持久化
- 队列持久化，durable设为true，如果队列不设置持久化，那么RabbitMQ重启之后该队列上的消息就丢失了。
- 消息持久化，deliveryMode设为2表示设置消息持久化

### deliveryMode设为2表示设置消息持久化
#### Message状态
- Ready：准备好了，可以投递给消费者，对于未开启持久化的消息写入内存即为`Ready`状态；如果开启持久化了，则持久化到磁盘后才会变成`Ready`状态。
- Unacked：表示已经投递到消费者但是还没有收到消费者Ack确认时的消息状态。

#### 消费者Ack机制与重回队列
为了保证消息从队列可靠地达到消费者， RabbitMQ 提供了消息确认机制( message acknowledgement，简称Ack) 。

当 AutoAck 为 true，会自动把发出去的消息设置为确认，然后从内容（或磁盘）中删除；
当 AutoAck 为 false，会等待消费者通过 basicAck 方法，显示地回复确认信号后才从内存（或磁盘）中移除消息（实质上是先打上删除标记，之后再删除）。

AutoAck 为 false 时，如果一直没有收到消费者的确认信号，并且消费该消息的消费者已经断开连接，则会安排该消息重新进入队列，等待投递给下一个消费者。（可以关掉消费者再启动验证）


## 生产者确认：事务与confirm机制

生产者消息确认两种方式：
- 事务机制
- 发送方确认机制，publish confirm 模式
    - 单条 confirm 模式 *发送一条消息后，等待确认*
    - 批量 confirm 模式 *发送多条消息后，等待确认*
    - 异步 confirm 模式 *使用最为复杂，维护已发送消息序号的有序集合，收到回调后，删除对应的消息 `deliveryTag` 元素*

事务机制和confirm机制两者是互斥的，只能开启一种。

注意：上述两种方式可以确保消息发送到交换机，如果交换机没有队列，那么消息仍然会丢失，并且生产者会收到发送成功的消息。
如果想知道消息到底有没有路由到队列里面，发送消息时要结合 `mandatory` 参数和 `ReturnListener`。

效率从低到高为： 事务模式 < 单条confirm模式 < 批量confirm模式 < 异步confirm模式。

### 事务机制
- 开启事务
- 提交事务
- 回滚事务

事务机制主要有如下步骤：（Producer <----> Broker）
1. 客户端发送 `Tx.Select`. 将信道置为事务模式；
2. Broker 回复 `Tx.Select-Ok`. 确认己将信道置为事务模式；
3. 在发送完消息之后，客户端发送 `Tx.Commit` 提交事务；
4. Broker 回复 `Tx.Commit-Ok`. 确认事务提交。

## 高级特性：mandatory、immediate 和 ReturnListener

发送消息时，并且设置 `ReturnListener` 回调：
- `mandatory=true`，如果消息无法路由到相应的队列，会给生产者发送一条 return 消息；
- `mandatory=false`，如果消息无法路由到相应的队列，不发送任何消息，消息也就丢失了。


## 高级特性：TTL（Time-To-Live 消息有效期）和DLX（Dead-Letter-Exchange 死信交换机/队列）

消息如果在队列中一直没有被消费并且存在时间超过了TTL，消息就会变成了"死信" (Dead Message)，后续无法再被消费了。

设置TTL有两种方式：

- 第一种是声明队列的时候，在队列的属性中设置，这样该队列中的消息都会有相同的有效期；
- 第二种是发送消息时给消息设置属性，可以为每条消息都设置不同的TTL。

如果不设置TTL，则表示此消息永久有效（默认消息是不会失效的）。

如果将TTL设为0，则表示如果消息不能被立马消费则会被立即丢掉。

DLX是Dead-Letter-Exchange的简写，意思是死信交换机。

它的作用其实是用来接收死信消息（dead message）的。那什么是死信消息呢？一般消息变成死信消息有如下几种情况：

- 消息被拒绝(Basic.Reject/Basic.Nack) ，并且不再重新投递requeue 参数为false
- 消息过期未消费
- 达到最大队列长度

场景：
- 延时关闭订单



## 发布/订阅
向多个消费者传递一个消息，所谓的“订阅/发布模式”。

设计：一个简单的日志系统。
- 第一个程序将发出日志消息；
- 第二个程序将接收并打印它们。

运行的接收器程序副本都会收到消息，一个接收器可以将日志重定向到磁盘；同时，运行另一个接收器并在屏幕上查看日志。

> Exchanges（交换器）

- **生产者**是发送消息的用户应用程序。
- **队列**是存储消息的缓冲区。
- **消费者**是接收消息的用户应用程序。

RabbitMQ消息传递模型中的核心思想是生产者从不将任何消息直接发送到队列。实际上生产者经常甚至根本不知道是否将消息传递到任何队列。

相反，生产者只能将消息发送到交换器。

交换器作用，一方面，它接收来自生产者的消息，另一方面，将它们推入队列。

交换器必须确切知道如何处理接收到的消息。
1. 被附加到特定的队列？
2. 被附加到许多队列中？
3. 被丢弃？

交换器类型：
- `direct`
- `topic`
- `headers`
- `fanout` 将接收到的所有消息广播到它知道的所有队列中。