#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[10];
    int age;
    int cla;
};
void recordstu(struct student s)//将前面输入的三个信息写入文件的函数
{
    FILE* fp;
    fp = fopen("stu.dat", "ab+");

    if (fp == NULL)
    {
        printf("文件打开失败/n");
    }
    else
    {
        fwrite(&s, sizeof(struct student), 1, fp);

    }
    fclose(fp);

};
void stude(struct student a)
{
    struct student k = a;//等量替换
    recordstu(k);//调用函数写入文件
}

int main()
{
    char a[10] = "raa";
    int b = 22;
    int c = 345;//当这三个是键盘输入的学生信息
    struct student s;
    strcpy(s.name, a);
    s.age = b;
    s.cla = c;//把这三个放进一个结构体
    stude(s);//调用函数
    struct student k = { 0 };//用来下面读写文件的时候存数据



    FILE* fp = fopen("stu.dat", "r");
    rewind(fp);//
    fseek(fp, 1 * sizeof(struct student), SEEK_SET);
    fread(&k, sizeof(struct student), 1, fp);
    printf("%s,%d,%d\n", k.name, k.age, k.cla);
    fclose(fp);
    return 0;
}