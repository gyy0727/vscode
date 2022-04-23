#include<iostream>
using namespace std;
struct student
{
    int number;
    int age;
    int score;
};
int main()
{
    struct student arr[3]={{111,24,99},{112,23,98},{113,22,97}};
    struct student*p=&arr[0];
    for(int i=0;i<3;i++)
    {
    cout << p->number << endl;
    p++;
    }
    return 0;
