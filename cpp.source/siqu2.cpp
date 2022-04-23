#include<iostream>
using namespace std;
//1.代码区存放代码
//2.全局区存放全局变量(全局常量和全局变量),静态常量,局部常量
int a=10;
int b=10;
const int c=10;
int main()
{
    int d=10;
    int e=10;
    const int f=10;
    static int g=10;
    string h="aaa";//"aaa"是字符串常量,'h'是局部变量;
   cout << "该全局变量的地址是" << (int)&a << endl;
   cout << "该全局变量的地址是" << (int)&b << endl;
   cout << "该全局常量的地址是" << (int)&c << endl;
   cout << "该局部变量的地址是" << (int)&d << endl;
   cout << "该局部变量的地址是" << (int)&e << endl;
   cout << "该局部常量的地址是" << (int)&f << endl;
   cout << "该静态变量的地址是" << (int)&g << endl;
   cout << "该字符串常量的地址是" << (int)&"aaa" << endl;
   system("pause");
    return 0;
}