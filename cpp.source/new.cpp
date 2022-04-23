#include <iostream>
using namespace std;
int main()
{
    // new创建的变量由程序员管理内存释放
    cout << "new创建数组" << endl;
    int *p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    cout << "new创建变量" << endl;
    ;
    int *c = new int(10);
    cout << *c << endl;

    cout << endl;

    //使用delete删除堆区数据
    cout << "使用delete删除" << endl;
    delete c;
    cout << *c << endl;

    return 0;
}