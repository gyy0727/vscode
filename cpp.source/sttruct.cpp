#include<iostream>
#include<string>
using namespace std;
struct student
{
    string name;
    int age;
    int score;
};
int main()
{
    struct student arr[3] =
        {
            {"zhangsan", 12, 100},
            {"lisi", 23, 200},
            {"zhaowu", 22, 85}
        };
    int i;
    for (i = 0; i <3; i++)
    {
        cout << "姓名 " << arr[i].name << " 年龄 " << arr[i].age << " 成绩 " << arr[i].score << endl;
    }
    cout << endl;  

    struct student*v=&arr[1];
    cout << "指针访问数组  姓名 " << v->name << " 年龄 " << v->age << " 成绩 " << v->score << endl; 
    cout << endl;

    struct student s1 = {"zhangsan1", 399, 18};
    cout << "姓名 " << s1.name << " 年龄 " << s1.age << " 成绩 " << s1.score << endl;
    cout << endl;

    struct student s2;
    s2.name="zhangsi";
    cout << s2.name << endl;
    cout << endl;

    struct student s3={"dkaj",72,277};
    struct student*p;
    p=&s3;
    cout << "姓名 " << p->name << " 年龄 " << p->age << " 成绩 " << p->score << endl;
    return 0;
}