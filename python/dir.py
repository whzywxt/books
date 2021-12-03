import os
import file_replace


# 遍历文件夹
def walk_file(file):
    for root, dirs, files in os.walk(file):

        # root 表示当前正在访问的文件夹路径
        # dirs 表示该文件夹下的子目录名list
        # files 表示该文件夹下的文件list

        # 遍历文件
        for f in files:
            file_path = os.path.join(root, f)
            print(file_path)
            file_replace.alter(file_path)

        # 遍历所有的文件夹
        # for d in dirs:
        # print(os.path.join(root, d))


def main():
    walk_file("C:/www/code/whzywxt.github.io/content/post/")


if __name__ == '__main__':
    main()
