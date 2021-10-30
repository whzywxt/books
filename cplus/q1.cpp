#include <iostream>
using namespace std;

/*
输出所有pumpkin的总重量。
说明：(1)源程序中pumkin应为pumpkin；
(2)total_weight++;应为total_weight+=weight;
*/

class pumpkin
{
public:
    pumpkin(int w)
    {
        weight = w;
        // total_weight++;
        total_weight += weight;
    }
    ~pumpkin()
    {
        total_weight -= weight;
    }
    static void total_display()
    {
        cout << "Total weight is " << total_weight << " pounds." << endl;
    }

private:
    int weight;
    static int total_weight;
};

int pumpkin::total_weight = 0;

int main()
{
    pumpkin p1(15), p2(20), p3(12);
    pumpkin::total_display();
}

