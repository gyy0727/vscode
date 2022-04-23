#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;
void printList(const list<int> &l)
{
    for(list<int>::const_iterator itb=l.begin();itb != l.end();itb++)
    {
        cout << *itb << " ";
    }
}
void LIST()
{
    cout << "默认构造" << endl;
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);

    list<int>::iterator itb = l.begin();
    list<int>::iterator ite = l.end();

    cout << "使用while遍历容器" << endl;
    while(itb != ite)
    {
        cout << *itb << " ";
        itb++;
    }

    cout << endl;

    cout << "函数遍历" << endl;
    printList(l);
    
    cout << endl;

    cout << "区间构造l1" << endl;
    list<int>l1(l.begin(),l.end());
    cout << "函数遍历" << endl;
    printList(l1);

    cout << endl;

    cout << "拷贝构造l2" << endl;
    list<int>l2(l1);
    cout << "函数遍历" << endl;
    printList(l2);

    cout << endl;

    cout << "n个elm构造" << endl;
    list<int>l3(12,5);
    cout << "函数遍历" << endl;
    printList(l3);

}
int main()
{
    LIST();
    return 0;
}