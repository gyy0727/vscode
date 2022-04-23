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
//������д���ļ�
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
    int c, f;
    double d, e;
    scanf("%s %d %lf", a, &c, &d);
    struct student s = {0};
    strcpy(s.name, a);
    s.cla = c;
    s.xiehao = d;
    recordstu(s);
} //����ѧ����Ϣ
void searchstu(struct student s) //����ѧ����Ϣ
{
    int i = 0;
    struct student k[100] = {0}; //���������д�ļ���ʱ�������
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
            printf("���ҳɹ�,����:\n");
            printf("\n");
            printf("%s,%d,%1.0lf", k[i].name, k[i].cla, k[i].xiehao);
            break;
        }
    }
    printf("\n");

    printf(" ����ʾѧ����Ϣ��Ϊ���ҳɹ�, ����Ϊ����ʧ��, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
}; //����ѧ��ѧ�Ų�����
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
    struct student k[100] = {0}; //���������д�ļ���ʱ�������
    FILE *fp = fopen("stu.dat", "a+");
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
    FILE *fpp = fopen("stu.dat", "w");
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
    struct student k[100] = {0}; //���������д�ļ���ʱ�������
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
    printf(" ɾ���ɹ�, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
}; //�����鼮����Ų�����
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
}; //�ռ�Ҫ������鼮��Ϣ
void recordstub1(struct book s)
{

    FILE *fp;
    fopen_s(&fp, "book.dat", "a+");
    if (fp == NULL)
    {
        printf("��ʧ��\n");
    }
    fwrite(&s, sizeof(struct book), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("\n");
    printf("�鼮��Ϣ����ɹ�,�ѻص��˵�,�������������ѡ����\n");
};
void searchbook(struct book s)
{
    int i = 0;
    struct book k[100] = {0}; //���������д�ļ���ʱ�������
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
            printf("���ҳɹ�,����(�鼮��,����,�۸�:\n");
            printf("\n");
            printf("%s,%1.0lf,%d", k[i].name, k[i].number, k[i].price);
            break;
        }
    }
    printf("\n");
    printf(" ����ʾ�鼮��Ϣ��Ϊ���ҳɹ�, ����Ϊ����ʧ��, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
    struct book k[100] = {0}; //���������д�ļ���ʱ�������
    FILE *fp = fopen("book.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 40; i++)
    {
        fread(&k[i], sizeof(struct book), 1, fp);
    }
    printf("�������޸ĺ������Ʒ����ϢΪ(����,������,�۸�)\n");
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
    printf(" �޸ĳɹ�, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
    struct book k[100] = {0}; //���������д�ļ���ʱ�������
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
    printf(" ɾ���ɹ�, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
        printf("��ʧ��\n");
    }
    fwrite(&s, sizeof(struct exchange), 1, fp);
    fclose(fp);
    fp = NULL;
    printf("������Ϣ����ɹ�,�ѻص��˵�,�������������ѡ����\n");
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
    struct exchange k[100] = {0}; //���������д�ļ���ʱ�������
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
            printf("���ҳɹ�,����:\n");
            printf("\n");
            printf("%s,%s,%lf,%lf", k[i].name1, k[i].name2, k[i].bianhao, k[i].time);
        }
    }
    printf("\n");
    printf(" ����ʾ������Ϣ��Ϊ���ҳɹ�, ����Ϊ����ʧ��, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
    struct exchange k[100] = {0}; //���������д�ļ���ʱ�������
    FILE *fp = fopen("excahnge.dat", "a+");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    for (i = 0; i < size / 56; i++)
    {
        fread(&k[i], sizeof(struct exchange), 1, fp);
    }
    printf("�������޸ĺ�ѧ������ϢΪ(����,�༶,ѧ��)\n");
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
    printf(" �޸ĳɹ�, ���ѳɹ��ص��˵�,����������ѡ����\n");
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
    struct exchange k[100] = {0}; //���������д�ļ���ʱ�������
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
    printf(" ɾ���ɹ�, ���ѳɹ��ص��˵�,����������ѡ����\n");
    fclose(fpp);
    fpp = NULL;
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
        printf("�����������Ʒ����Ʒ��,��Ʒ����,�۸�(Ԫ)���ϼ���Ʒ\n");
        collectbook();
        break;
    case 6:
        printf("�����������Ʒ���������\n");
        booknumber();
        break;
    case 7:
        printf("�����������Ʒ���������޸���Ϣ\n");
        bookchange();
        break;
    case 8:
        printf("��������Ҫ�¼ܵĶ�����Ʒ������\n");
        bookdelete();
        break;
    case 9:
        printf("�����뽻�׵���������������,������Ʒ�������źͽ���ʱ��(��20210614)\n");
        collectexchange();
        break;
    case 10:
        printf("�����뽻�׵Ķ�����Ʒ����Ų��ҽ�����Ϣ\n");
        findcollect();
        break;
    case 11:
        printf("�����뽻�׵���Ʒ�������޸Ľ�����Ϣ\n");
        changenew();
        break;
    case 12:
        printf("������Ҫɾ���Ľ�����Ϣ����Ʒ�����\n");
        deletenew();
        break;
    case 0:
        break;
    }
    return a;
}
void menu()
{
    printf("*                            �˵�ѡ��                                    *\n");
    printf("*                ����1����,2����,3�޸�4ɾ��ѧ��������Ϣ                  *\n");
    printf("*                ����5�ϼ�,6����,7�޸�8ɾ������ͼ����Ϣ                  *\n");
    printf("*       ����9��ӽ�����Ϣ10���ҽ�����Ϣ11�޸Ľ�����Ϣ12ɾ��������Ϣ      *\n");
    printf("*                        ����0�˳�ϵͳ                                   *\n");
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
            ability(Xx); //�˵�����
        }
        if (Xx == 0)
        {
            printf("���˳�ϵͳ\n");
            break;
        }
    }
    return 0;
}