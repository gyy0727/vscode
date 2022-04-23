#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
} stu[100];
//将数据写入文件
struct exchange
{
    char name1[20];
    char name2[20];
    double bianhao;
    double time;
};
void recordstu(struct student s)
{

    FILE *fp;
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
    int c, f;
    double d, e;
    scanf("%s %d %lf", a, &c, &d);
    struct student s = {0};
    strcpy(s.name, a);
    s.cla = c;
    s.xiehao = d;
    recordstu(s);
} //插入学生信息
void searchstu(struct student s) //查找学生信息
{
    int i = 0;
    struct student k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("stu.dat", "a+");
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
            printf("查找成功,如下:\n");
            printf("\n");
            printf("%s,%d,%1.0lf", k[i].name, k[i].cla, k[i].xiehao);
            break;
        }
    }
    printf("\n");

    printf(" 若显示学生信息则为查找成功, 否则为查找失败, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fp);
    fp = NULL;
}
void stuname()
{
    double a;
    scanf("%lf", &a);
    struct student s = {0};
    s.xiehao = a;
    searchstu(s);
}; //处理学生学号并查找
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
    struct student k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("stu.dat", "a+");
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
    FILE *fpp = fopen("stu.dat", "w");
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
    struct student k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("stu.dat", "a+");
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
    FILE *fpp = fopen("stu.dat", "w");
    fwrite(k, sizeof(struct student), size / 32, fpp);
    printf("\n");
    printf(" 删除成功, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fpp);
    fpp = NULL;
}
void booknumber()
{
    void searchbook(struct book s);
    double a;
    scanf("%lf", &a);
    struct book s = {0};
    s.number = a;
    searchbook(s);
}; //处里书籍条码号并查找
void collectbook()
{
    void recordstub1(struct book s);
    char a[10];
    double b;
    int c;
    scanf("%s %lf %d", a, &b, &c);
    struct book s = {0};
    strcpy(s.name, a);
    s.price = c;
    s.number = b;
    recordstub1(s);
}; //收集要插入的书籍信息
void recordstub1(struct book s)
{

    FILE *fp;
    fopen_s(&fp, "book.dat", "a+");
    if (fp == NULL)
    {
        printf("打开失败\n");
    }
    fwrite(&s, sizeof(struct book), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("\n");
    printf("书籍信息插入成功,已回到菜单,请继续输入数字选择功能\n");
};
void searchbook(struct book s)
{
    int i = 0;
    struct book k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("book.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    printf("%d", size);
    rewind(fp);
    for (i = 0; i < size / 40; i++)
    {
        fread(&k[i], sizeof(struct book), 1, fp);
    }
    for (i = 0; i < size / 40; i++)
    {
        if (s.number == k[i].number)
        {
            printf("查找成功,如下(书籍名,条码,价格:\n");
            printf("\n");
            printf("%s,%1.0lf,%d", k[i].name, k[i].number, k[i].price);
            break;
        }
    }
    printf("\n");
    printf(" 若显示书籍信息则为查找成功, 否则为查找失败, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fp);
    fp = NULL;
}
void bookchange()
{
    void changebook(struct book s);
    double a;
    scanf("%lf", &a);
    struct book s;
    s.number = a;

    changebook(s);
}
void changebook(struct book s)
{
    int i = 0;
    struct book k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("book.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 40; i++)
    {
        fread(&k[i], sizeof(struct book), 1, fp);
    }
    printf("请输入修改后二手物品的信息为(名字,条码编号,价格)\n");
    char a[20];
    double b;
    int c;
    scanf("%s %lf %d", a, &b, &c);
    for (i = 0; i < size / 40; i++)
    {
        if (s.number == k[i].number)
        {
            strcpy(k[i].name, a);
            k[i].price = c;
            k[i].number = b;
        }
    }
    fclose(fp);
    fp = NULL;
    FILE *fpp = fopen("book.dat", "w");
    fwrite(k, sizeof(struct book), size / 40, fpp);
    printf("\n");
    printf(" 修改成功, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fpp);
    fpp = NULL;
}
void bookdelete()
{
    void bookdeleted(struct book s);
    double a;
    scanf("%lf", &a);
    struct book s;
    s.number = a;
    bookdeleted(s);
}
void bookdeleted(struct book s)
{
    int i = 0;
    struct book k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("book.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 40; i++)
    {
        fread(&k[i], sizeof(struct book), 1, fp);
    }
    for (i = 0; i < size / 40; i++)
    {
        if (s.number == k[i].number)
        {

            strcpy(k[i].name, "0");
            k[i].price = 0;
            k[i].number = 0;
        }
    }
    fclose(fp);
    fp = NULL;
    FILE *fpp = fopen("book.dat", "w");
    fwrite(k, sizeof(struct book), size / 40, fpp);
    printf("\n");
    printf(" 删除成功, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fpp);
    fpp = NULL;
}
void collectexchange()
{
    void exchangeadd(struct exchange s);
    char a[20];
    char b[20];
    double c;
    double d;
    scanf("%s %s %lf %lf", a, b, &c, &d);
    struct exchange s;
    strcpy(s.name1, a);
    strcpy(s.name2, b);
    s.bianhao = c;
    s.time = d;
    exchangeadd(s);
};
void exchangeadd(struct exchange s)
{
    FILE *fp;
    fopen_s(&fp, "exchange.dat", "a+");
    if (fp == NULL)
    {
        printf("打开失败\n");
    }
    fwrite(&s, sizeof(struct exchange), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("交易信息插入成功,已回到菜单,请继续输入数字选择功能\n");
}
void findcollect()
{
    double a;
    scanf("lf", &a);
    struct exchange s;
    s.bianhao = a;
    found(s);
}
void found(struct exchange s)
{
    int i = 0;
    struct exchange k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("exchange.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 56; i++)
    {
        fread(&k[i], sizeof(struct exchange), 1, fp);
    }
    for (i = 0; i < size / 56; i++)
    {
        if (s.bianhao == k[i].bianhao)
        {
            printf("查找成功,如下:\n");
            printf("\n");
            printf("%s,%s,%lf,%lf", k[i].name1, k[i].name2, k[i].bianhao, k[i].time);
        }
    }
    printf("\n");
    printf(" 若显示交易信息则为查找成功, 否则为查找失败, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fp);
    fp = NULL;
}
void changenew()
{
    double a;
    scanf("%lf", &a);
    struct exchange s;
    s.bianhao = a;
    changenews(s);
}
void changenews(struct exchange s)
{
    int i = 0;
    struct exchange k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("excahnge.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 56; i++)
    {
        fread(&k[i], sizeof(struct exchange), 1, fp);
    }
    printf("请输入修改后学生的信息为(姓名,班级,学号)\n");
    char a[20];
    char b[20];
    double d, c;

    scanf("%s %s %lf %lf", a, b, &c, &d);
    for (i = 0; i < size / 56; i++)
    {
        if (s.bianhao == k[i].bianhao)
        {
            strcpy(k[i].name1, a);
            strcpy(k[i].name2, b);
            k[i].bianhao = c;
            k[i].time = d;
        }
    }
    fclose(fp);
    fp = NULL;
    FILE *fpp = fopen("exchange.dat", "w");
    fwrite(k, sizeof(struct student), size / 56, fpp);
    printf("\n");
    printf(" 修改成功, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fpp);
    fpp = NULL;
}
void deletenew()
{
    double a;
    struct exchange s;
    scanf("%lf", &a);
    s.bianhao = a;
    deletenews(s);
}
void deletenews(struct exchange s)
{
    int i = 0;
    struct exchange k[100] = {0}; //用来下面读写文件的时候存数据
    FILE *fp = fopen("exchange.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 56; i++)
    {
        fread(&k[i], sizeof(struct exchange), 1, fp);
    }
    for (i = 0; i < size / 56; i++)
    {
        if (s.bianhao == k[i].bianhao)
        {

            strcpy(k[i].name1, "0");
            strcpy(k[i].name2, "0");
            k[i].bianhao = 0;
            k[i].time = 0;
        }
    }
    fclose(fp);
    fp = NULL;
    FILE *fpp = fopen("exchange.dat", "w");
    fwrite(k, sizeof(struct exchange), size / 56, fpp);
    printf("\n");
    printf(" 删除成功, 你已成功回到菜单,请输入数字选择功能\n");
    fclose(fpp);
    fpp = NULL;
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
        printf("请输入二手物品的物品名,商品条码,价格(元)来上架商品\n");
        collectbook();
        break;
    case 6:
        printf("请输入二手物品的条码查找\n");
        booknumber();
        break;
    case 7:
        printf("请输入二手物品条码编号以修改信息\n");
        bookchange();
        break;
    case 8:
        printf("请输入想要下架的二手物品条码编号\n");
        bookdelete();
        break;
    case 9:
        printf("请输入交易的卖家名和卖家名,二手物品的条码编号和交易时间(如20210614)\n");
        collectexchange();
        break;
    case 10:
        printf("请输入交易的二手物品条码号查找交易信息\n");
        findcollect();
        break;
    case 11:
        printf("请输入交易的商品条码来修改交易信息\n");
        changenew();
        break;
    case 12:
        printf("请输入要删除的交易信息的商品条码号\n");
        deletenew();
        break;
    case 0:
        break;
    }
    return a;
}
void menu()
{
    printf("*                            菜单选项                                    *\n");
    printf("*                输入1插入,2查找,3修改4删除学生个人信息                  *\n");
    printf("*                输入5上架,6查找,7修改8删除二手图书信息                  *\n");
    printf("*       输入9添加交易信息10查找交易信息11修改交易信息12删除交易信息      *\n");
    printf("*                        输入0退出系统                                   *\n");
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
            ability(Xx); //菜单函数
        }
        if (Xx == 0)
        {
            printf("已退出系统\n");
            break;
        }
    }
    return 0;
}