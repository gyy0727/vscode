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
//������д���ļ�
void recordstu(struct student s)
{

    FILE* fp;
    fopen_s(&fp, "stu.dat", "a+");
    if (fp == NULL)
    {
        printf("��ʧ��\n");
    }
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("ѧ������ɹ�,�ѻص��˵�,�������������ѡ����\n");

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
}//����ѧ����Ϣ
void searchstu(struct student s)//����ѧ����Ϣ
{
    int i = 0;
    struct student k[100]={0};//���������д�ļ���ʱ�������
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
            printf("���ҳɹ�,����:\n");
            printf("\n");
            printf("%s,%d,%1.0lf", k[i].name, k[i].cla,k[i].xiehao);
            break;
        }
    }
    printf("\n");
    fclose(fp);
    printf(" ����ʾѧ����Ϣ��Ϊ���ҳɹ�, ����Ϊ����ʧ��, ���ѳɹ��ص��˵�,����������ѡ����\n");
    fclose(fp);
}
void stuname()
{
    double a;
    scanf("%lf", &a);
    struct student s={0};
    s.xiehao = a;
    searchstu(s);
};//����ѧ��ѧ�Ų�����
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
    struct student k[100] = { 0 };//���������д�ļ���ʱ�������
    FILE* fp = fopen("stu.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 32; i++)
    {
        fread(&k[i], sizeof(struct student), 1, fp);
    }
    printf("�������޸ĺ�ѧ������ϢΪ(����,�༶,ѧ��)\n");
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
    printf(" �޸ĳɹ�, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
    struct student k[100] = { 0 };//���������д�ļ���ʱ�������
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
    printf(" ɾ���ɹ�, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
};//����ѧ��ѧ�Ų�����
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
        printf("��ʧ��\n");
    }
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("\n");
    printf("�鼮��Ϣ����ɹ�,�ѻص��˵�,�������������ѡ����\n");
};
void recordstub(struct book s)
{

    FILE* fp;
    fopen_s(&fp, "book.dat", "a+");
    if (fp == NULL)
    {
        printf("��ʧ��\n");
    }
    fwrite(&s, sizeof(struct student), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("�鼮��Ϣ����ɹ�,�ѻص��˵�,�������������ѡ����\n");

};
void searchbook(struct book s)
{
    int i = 0;
    struct book k[100] = { 0 };//���������д�ļ���ʱ�������
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
            printf("���ҳɹ�,����:\n");
            printf("\n");
            printf("%s,%d,%1.0lf", k[i].name, k[i].number, k[i].price);
            break;
        }
    }
    printf("\n");
    fclose(fp);
    printf(" ����ʾѧ����Ϣ��Ϊ���ҳɹ�, ����Ϊ����ʧ��, ���ѳɹ��ص��˵�,����������ѡ����\n");
    fclose(fp);
    
}
void searchbooknumber(int a)
{
    //������޴���
}
void changebookname(char a[10])
{
   //������޴���
}
void changebookprice(int a)
{
    //������޴���
}

int ability(int a)
{
    switch (a)
    {
    case 1:
        printf("������ѧ������,,�༶,ѧ���Բ�����Ϣ\n");
        collectstu();
        break;
    case 2:
        printf("������ѧ��ѧ���Բ�����Ϣ\n");
        stuname();
        break;
    case 3:
        printf("������ѧ��ѧ�����޸���Ϣ\n");
        stuchange();
        break;
    case 4:
        printf("������ѧ��ѧ����ɾ��ѧ����Ϣ\n");
        studelete();
        break;
    case 5:
        printf("�������鼮������,��Ʒ����,�۸�\n");
        collectbook();
        break;
    case 6:
        printf("�������鼮���������\n");
        scanf("%d", &c4);
       
        break;
    case 7:
        printf("�������鼮������(������1),���߱��(������2)���޸���Ϣ\n");
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
    printf("*                     �˵�ѡ��                        *\n");
    printf("*        ����1����,2����,3�޸�4ɾ��ѧ��������Ϣ       *\n");
    printf("*        ����5�ϼ�,6����,7�޸�8ɾ������ͼ����Ϣ       *\n");
    printf("*                  ����0�˳�ϵͳ                      *\n");
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
            ability(Xx);//�˵�����

        }
        if (Xx == 0)
        {
            printf("���˳�ϵͳ\n");
            break;
        }
    }
    return 0;
}