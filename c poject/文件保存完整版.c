#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[10];
    int age;
    int cla;
};
void recordstu(struct student s)//��ǰ�������������Ϣд���ļ��ĺ���
{
    FILE* fp;
    fp = fopen("stu.dat", "ab+");

    if (fp == NULL)
    {
        printf("�ļ���ʧ��/n");
    }
    else
    {
        fwrite(&s, sizeof(struct student), 1, fp);

    }
    fclose(fp);

};
void stude(struct student a)
{
    struct student k = a;//�����滻
    recordstu(k);//���ú���д���ļ�
}

int main()
{
    char a[10] = "raa";
    int b = 22;
    int c = 345;//���������Ǽ��������ѧ����Ϣ
    struct student s;
    strcpy(s.name, a);
    s.age = b;
    s.cla = c;//���������Ž�һ���ṹ��
    stude(s);//���ú���
    struct student k = { 0 };//���������д�ļ���ʱ�������



    FILE* fp = fopen("stu.dat", "r");
    rewind(fp);//
    fseek(fp, 1 * sizeof(struct student), SEEK_SET);
    fread(&k, sizeof(struct student), 1, fp);
    printf("%s,%d,%d\n", k.name, k.age, k.cla);
    fclose(fp);
    return 0;
}