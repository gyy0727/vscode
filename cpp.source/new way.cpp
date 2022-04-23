#include<iostream>
using namespace std;
#include<string>
int main()
{
    int *p=new int (10);
    int*v=new int [10];
    for(int i=0;i<10;i++)
    {
        v[i]=i+1;
    }
    for(int i=0;i<10;i++)
    {
        cout << v[i] << " ";
    }

cout << endl;
    cout << *p << endl;
    return 0;
}