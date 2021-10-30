/*
7、定义一个表示三维空间坐标点的类，并对下列运算符重载。
 （1）、<<：按 (x,y,z) 格式输出该点坐标（坐标为整型）；
 （2）、 > ：如果A点到原点的距离大于B点到原点的距离，则A>B为真，否则为假。
*/

#include <iostream>
#include <math.h>
using namespace std;

class Point3D
{
public:
    Point3D(int xx = 0, int yy = 0, int zz = 0) : x(xx), y(yy), z(zz) {}
    friend bool operator>(const Point3D &A, const Point3D &B);
    friend ostream &operator<<(ostream &ostr, const Point3D &p);

private:
    int x, y, z;
};
bool operator>(const Point3D &A, const Point3D &B)
{
    double disA = sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
    double disB = sqrt(B.x * B.x + B.y * B.y + B.z * B.z);
    return (disA > disB) ? true : false;
}
ostream &operator<<(ostream &ostr, const Point3D &p)
{
    ostr << '(' << p.x << ',' << p.y << ',' << p.z << ')';
    return ostr;
}
int main()
{
    Point3D p1(1), p2(2, 3, 4);
    if (p1 > p2)
        cout << "The point p1:" << p1 << " is the far point." << endl;
    else
        cout << "The point p2:" << p2 << " is the far point." << endl;
}