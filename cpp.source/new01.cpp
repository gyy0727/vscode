#include<iostream>
#include<string>
using namespace std;
//使用&给变量起别名 &别名=原名
int main()
{
    int a=10;
    int &b=a;//初始化b,且不能再将b作为其他变量的别名
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "a的地址为" << (int)&a << endl;
    cout << "b的地址为" << (int)&b << endl;//两者地址相同
    cout << endl;
    //a,b操作的是同一块内存,可通过修改b,修改a的值
    b=20;
    cout << "b= " << b << endl;
    cout << "a= " << a << endl;
    return 0;
}