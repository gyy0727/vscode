#include<iostream>
using namespace std;
//1.��������Ŵ���
//2.ȫ�������ȫ�ֱ���(ȫ�ֳ�����ȫ�ֱ���),��̬����,�ֲ�����
int a=10;
int b=10;
const int c=10;
int main()
{
    int d=10;
    int e=10;
    const int f=10;
    static int g=10;
    string h="aaa";//"aaa"���ַ�������,'h'�Ǿֲ�����;
   cout << "��ȫ�ֱ����ĵ�ַ��" << (int)&a << endl;
   cout << "��ȫ�ֱ����ĵ�ַ��" << (int)&b << endl;
   cout << "��ȫ�ֳ����ĵ�ַ��" << (int)&c << endl;
   cout << "�þֲ������ĵ�ַ��" << (int)&d << endl;
   cout << "�þֲ������ĵ�ַ��" << (int)&e << endl;
   cout << "�þֲ������ĵ�ַ��" << (int)&f << endl;
   cout << "�þ�̬�����ĵ�ַ��" << (int)&g << endl;
   cout << "���ַ��������ĵ�ַ��" << (int)&"aaa" << endl;
   system("pause");
    return 0;
}