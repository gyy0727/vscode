#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
    char name[20];
    double number;
    int price;
};
struct student
{
    char name[20]; 
    int cla;
    double xiehao;
}stu[100];
struct exchange
{
    char namestu1[20];
    char namestu2[20];
    char namebook[20];
    int price;
    int time;
};
char a1[10], a2[10], a3[10], a4[10], a5[10], a6[10];
int  b1, b2, c2, c1, b4, b5;
int  b3, c3, c4, c5;
int i = 1;
//将数据写入文件
void recordstu(struct student s)
{

    FILE* fp;
    fopen_s(&fp, "stu.dat", "a+");
    if (fp == NULL)
    {
        printf("打开失败\n");
    }
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("学生插入成功,已回到菜单,请继续输入数字选择功能\n");

};         
void collectstu()
{
    char a[20];
    int  c ,f;
    double d,e;
    scanf("%s %d %lf", a, &c, &d);
    struct student s={0};
    strcpy(s.name, a);
    s.cla = c;
    s.xiehao = d;  
    recordstu(s);
}//插入学生信息
void searchstu(struct student s)//查找学生信息
{
    int i = 0;
    struct student k[100]={0};//用来下面读写文件的时候存数据
    FILE* fp = fopen("stu.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size/32; i++)
    {
        fread(&k[i], sizeof(struct student), 1, fp);
    }
    for (i = 0; i < size/32; i++)
    {
        if (s.xiehao==k[i].xiehao)
        {
            printf("查找成功,如下:\n");
            printf("\n");
            printf("%s,%d,%1.0lf", k[i].name, k[i].cla,k[i].xiehao);
            break;
        }
    }
    printf("\n");
    fclose(fp);
    printf(" 若显示学生信息则为查找成功, 否则为查找失败, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fp);
}
void stuname()
{
    double a;
    scanf("%lf", &a);
    struct student s={0};
    s.xiehao = a;
    searchstu(s);
};//处理学生学号并查找
void stuchanged()
{
    char a[20];
    double b;
    int c;
    scanf("%s %lf %d", &a[20], &b, &c);
};
void changestu(struct student s)
{
    int i = 0;
    struct student k[100] = { 0 };//用来下面读写文件的时候存数据
    FILE* fp = fopen("stu.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 32; i++)
    {
        fread(&k[i], sizeof(struct student), 1, fp);
    }
    printf("请输入修改后学生的信息为(姓名,班级,学号)\n");
    char a[20];
    double b;
    int c;
    scanf("%s %d %lf", a, &c, &b);
    for (i = 0; i < size / 32; i++)
    {
        if (s.xiehao == k[i].xiehao)
        {
            strcpy(k[i].name, a);
            k[i].cla = c;
            k[i].xiehao = b;
        }
    }
    fclose(fp);
    fp = NULL;
    FILE* fpp = fopen("stu.dat", "w");
    fwrite(k, sizeof(struct student), size / 32, fpp);
    printf("\n");
    printf(" 修改成功, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fpp);
    fpp = NULL;
    
}
void stuchange()
{
    double a;
    scanf("%lf", &a);
    struct student s;
    s.xiehao = a;

    changestu(s);
}


void studelete()
{
    void deleted(struct student s);
    double a;
    scanf("%lf", &a);
    struct student s;
    s.xiehao = a;
    deleted(s);
}
void deleted(struct student s)
{
    int i = 0;
    struct student k[100] = { 0 };//用来下面读写文件的时候存数据
    FILE* fp = fopen("stu.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 32; i++)
    {
        fread(&k[i], sizeof(struct student), 1, fp);
    }
    for (i = 0; i < size / 32; i++)
    {
        if (s.xiehao == k[i].xiehao)
        {

            strcpy(k[i].name, "0");
            k[i].cla = 0;
            k[i].xiehao = 0;
        }
    }
    fclose(fp);
    fp = NULL;
    FILE* fpp = fopen("stu.dat", "w");
    fwrite(k, sizeof(struct student), size / 32, fpp);
    printf("\n");
    printf(" 删除成功, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fpp);
    fpp = NULL;

}












void booknumber()
{
    double a;
    scanf("%lf", &a);
    struct book s = { 0 };
    s.number = a;
    searchbook(s);
};//处理学生学号并查找
void collectbook()
{
    char a[10];
    double b;
    int c;
    scanf("%s %lf %d", a, &b, &c);
    struct book s = { 0 };
    strcpy(s.name, a);
    s.price = c;
    s.number = b;
    recordstub1(s);
};
void recordstub1(struct book s)
{

    FILE* fp;
    fopen_s(&fp, "book.dat", "a+");
    if (fp == NULL)
    {
        printf("打开失败\n");
    }
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("\n");
    printf("书籍信息插入成功,已回到菜单,请继续输入数字选择功能\n");
};
void recordstub(struct book s)
{

    FILE* fp;
    fopen_s(&fp, "book.dat", "a+");
    if (fp == NULL)
    {
        printf("打开失败\n");
    }
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("书籍信息插入成功,已回到菜单,请继续输入数字选择功能\n");

};
void searchbook(struct book s)
{
    int i = 0;
    struct book k[100] = { 0 };//用来下面读写文件的时候存数据
    FILE* fp = fopen("book.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 32; i++)
    {
        fread(&k[i], sizeof(struct book), 1, fp);
    }
    for (i = 0; i < size / 32; i++)
    {
        if (s.number == k[i].number)
        {
            printf("查找成功,如下:\n");
            printf("\n");
            printf("%s,%d,%1.0lf", k[i].name, k[i].number, k[i].price);
            break;
        }
    }
    printf("\n");
    fclose(fp);
    printf(" 若显示学生信息则为查找成功, 否则为查找失败, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fp);
    
}
void searchbooknumber(int a)
{
    //加入查无此人
}
void changebookname(char a[10])
{
   //加入查无此书
}
void changebookprice(int a)
{
    //加入查无此书
}

int ability(int a)
{
    switch (a)
    {
    case 1:
        printf("请输入学生姓名,,班级,学号以插入信息\n");
        collectstu();
        break;
    case 2:
        printf("请输入学生学号以查找信息\n");
        stuname();
        break;
    case 3:
        printf("请输入学生学号以修改信息\n");
        stuchange();
        break;
    case 4:
        printf("请输入学生学号来删除学生信息\n");
        studelete();
        break;
    case 5:
        printf("请输入书籍的书名,商品条码,价格\n");
        collectbook();
        break;
    case 6:
        printf("请输入书籍的条码查找\n");
        scanf("%d", &c4);
       
        break;
    case 7:
        printf("请输入书籍的书名(请输入1),或者编号(请输入2)以修改信息\n");
        scanf("%d", &c5);
        if (c5 == 1)
        {
            changebookname(a6);
        }
        if (c5 == 2)
        {
            changebookprice(b5);
        }
        break;
    case 0:
        break;
    }
    return a;
}
void menu()
{
    printf("*                     菜单选项                        *\n");
    printf("*        输入1插入,2查找,3修改4删除学生个人信息       *\n");
    printf("*        输入5上架,6查找,7修改8删除二手图书信息       *\n");
    printf("*                  输入0退出系统                      *\n");
}
int main()
{
    menu();
    int Xx;
    while (1)
    {
        scanf("%d", &Xx);
        if (Xx != 0)
        {
            ability(Xx);//菜单函数

        }
        if (Xx == 0)
        {
            printf("已退出系统\n");
            break;
        }
    }
    return 0;
}