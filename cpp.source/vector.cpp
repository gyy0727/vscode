#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void myprint(int a)
{
    cout << a << endl;
}
void test01()
{
    vector<int> v;//创建一个vector容器v,类似于数组
    //向容器中存入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //通过迭代器访问
    vector<int>::iterator itb = v.begin();//起始迭代器,类似于指针,指向容器开头的元素
    vector<int>::iterator ite = v.end();//结束迭代器,指向最后一个元素的下一个位置

    //第一种遍历方式
   /* while (itb != ite)
    {
        cout << *itb << endl;
        itb++;
    }*/

    //第二种遍历方式
    /*for(vector<int>::iterator itb=v.begin();itb != v.end();itb++)
    {
        cout << *itb << endl;
    }    */

    //第三种遍历方式
    for_each(v.begin(),v.end(),myprint);


}
int main()
{
    test01();
    return 0;
}
