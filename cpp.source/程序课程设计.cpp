#include<iostream>
#include<string>
using namespace std;
struct book
{
    string name;
    int number;
    int condit;
    string infor;
};
struct student 
{
    string name;
    int age;
    int 班级;
    struct book;
};
void menu()
{
    cout << "                  菜单选项                   " << endl;
    cout << "        输入1插入2查找3修改学生个人信息        " << endl;
    cout << "        输入4插入5查找6修改二手图书信息        " << endl;
    cout << "                输入0退出系统                 " << endl;
}
int main()
{
    menu();
    return 0;
}