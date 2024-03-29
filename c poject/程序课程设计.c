# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define SIZE sizeof(struct Student)
 
struct Student
{	
	char Sid[10];
	char Sclass[20];
	char Sname[20];
	int Math;
	int English;
	int Physic;
	int Sum;
	int rank;
	struct Student *next;
}; 
 
void ShowMenu()
{
	printf("\n***********************************************************\n");
	printf("\twelcome to Stugent bonus management system\n\n");
	printf("\t1-------------- Record\n");                    
	printf("\t2-------------- Show all record\n");                  
	printf("\t3-------------- Find\n");
	printf("\t4-------------- Statistics\n");
	printf("\t5-------------- Delete\n");
	printf("\t6-------------- Add\n");
	printf("\t7-------------- Sort\n");
	printf("\t8-------------- Save File\n");
	printf("\t9-------------- Copy File\n");
	printf("\t10------------- Exit\n\n");                   
	printf("***********************************************************\n");
}
 
//从键盘中输入的数据创建链表
struct Student * in_stuNode()
{
	struct Student * head, * p1, * p2;
	int n = 0;
	p1 = p2 = (struct Student *)malloc(SIZE);
 
	head = NULL;
	
	scanf("%s",  p1->Sid);
	while(p1->Sid[0] != '@')
	{
		scanf("%s%s%d%d%d", p1->Sclass, p1->Sname, &p1->Math, &p1->English, &p1->Physic);
		p1->Sum = 0; p1->rank = 0;
		n++;
		if(n == 1)
		{
			head = p1;
		}else
		{
			p2->next = p1;
		}
		p2 = p1;
 
		p1 = (struct Student *)malloc(SIZE);
		scanf("%s",  p1->Sid);
	}
	p2->next = NULL;        
	return head;
}
 
//从链表中的数据 写入文件
void Record(struct Student *head)
{
	FILE *fp;
	struct Student  *p1;
	p1 = head;
 
	if((fp = fopen("D:\\Course\\student.txt", "w")) == NULL)
	{
		printf("cannot open this file\n");
		return;
	}
 
	while(p1 != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);
/*		if(fwrite(p1, SIZE, 1, fp) != 1)
			{
				printf("file write error\n");
			}
*/
		p1 = p1->next; 
 
	}
 
	if(p1 == NULL){
	printf("Record ok!\n");
	}
 
	free(p1);
	free(head);
	fclose(fp);
 
}
 
//从文件中读取的数据创建链表
struct Student * File_stuNode(){
 
	FILE *fp;
	int n = 0;
	struct Student *head, *p2, *p1;
 
	if((fp = fopen("D:\\Course\\student.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		return NULL;
	}
 
	head = NULL;
 
	p2 = p1 = (struct Student *)malloc(SIZE);
	fscanf(fp, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d", p1->Sid, p1->Sclass, p1->Sname, &p1->Math, &p1->English, &p1->Physic, &p1->Sum, &p1->rank);
//	fread(p1, SIZE, 1, fp);
	while(!feof(fp))
	{
		
		n++;
		if(n == 1)
		{
			head = p2;
		}else
		{
			p2->next = p1; 
		}
		p2 = p1;
		p1 = (struct Student *)malloc(SIZE);
	    fscanf(fp, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d", p1->Sid, p1->Sclass, p1->Sname, &p1->Math, &p1->English, &p1->Physic, &p1->Sum, &p1->rank);
//		fread(p1, SIZE, 1, fp);
	}
 
	p2->next = NULL;
	fclose(fp);
 
	return head;
}
 
void Show_stuNode()
{
	printf("---------------------------STUDENT------------------------------------\n");
	printf("|no		|class	|name	|sc1	|sc2	|sc3    |sum	|order|\n");
	printf("----------------------------------------------------------------------\n");
	struct Student *p, *head;
	head = File_stuNode();     //调用 File_stuNode();
 
	p = head;
	while(p != NULL)
	{
		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p->Sid, p->Sclass, p->Sname, p->Math, p->English, p->Physic, p->Sum, p->rank);
		
		p = p->next; 
	}
 
}
 
void ShowMenu3()
{
	printf("\t****************************************\n");
 
	printf("\t1----------按名次查询某学生的个人成绩\n");
 
	printf("\t2----------按班级查询班级前3名学生的个人成绩\n");
 
	printf("\t3----------按成绩段查询某学生的个人成绩\n");
 
	printf("\t4----------exit\n");
 
	printf("\t****************************************\n");
 
}
 
void SortRank()
{
	struct Student *p1, *head, *p2;
	int i;
	head = File_stuNode();
 
	p1 = head;
 
	while(p1 != NULL)
	{
		i = 1;
		p2 = head;
		while(p2 != NULL)
		{
			if(p1->Sum < p2->Sum)
			{
				i++;
			}
			p2 = p2->next;
		}
		p1->rank = i;
		p1 = p1->next;
 
	}
 
	Record(head);
}
 
void SearchByRank()
{
	struct Student *p1, *head;
	int number;
	head = File_stuNode();
	p1 = head;
 
	if(p1->rank == 0)
	{
		printf("你还没有排名呢？请返回主菜单执行操作7\n");
		return;
	}
	printf("请输入要查询的名次：");
 
	scanf("%d", &number);
 
	while(p1 != NULL)
	{
		if(p1->rank == number)
		{
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);
		}
		p1 = p1->next;
	}
 
	free(p1);
	free(head);
 
}
 
void SearchByClass()
{
 
	int i = 1;
	char Class[10] = {0};
	struct Student *p1, *head, *p2;
 
	printf("请输入要查询的班级：如201501 \n");
	scanf("%s", Class);
 
	head = File_stuNode();
	p1 = head;
 
	while(p1 != NULL)
	{
		if(strcmp(Class, p1->Sclass) == 0)
		{
			i = 1;
			p2 = head;
			while(p2 != NULL)
			{
				if(strcmp(Class, p2->Sclass) == 0)
				{
					if(p1->Sum < p2->Sum)
						{
							i++;
						}
				}
				p2 = p2->next;
			}
 
			if(i <= 3)
			{
				printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);	
			}
			else if(i > 3)
			{
				break;
			}
		}
		p1 = p1->next;
	}
 
	free(p1);
	free(head);
 
}
 
void SearchByScore()
{
	int scope1, scope2;
	int i = 0;
	struct Student *p1, *head;
	char course[10] = {0};
 
	printf("请输入要查询的分数段：如 70 - 80 \n");
	scanf("%d-%d", &scope1, &scope2);
	if(scope1 >= scope2)
	{
		printf("scope2 must be bigger than scope1!\n");
		return;
	}
 
	printf("请输入要查询的科目：(Math、English、Physic) \n");
 
	scanf("%s", course); 
	if(!(strcmp(course, "Math") == 0 || strcmp(course, "English") == 0 || strcmp(course, "Physic") == 0))
	{
		printf("no found the course\n");
		return;
	}
 
	head = File_stuNode();
 
	p1 = head;
 
	while(p1 != NULL)
	{
		if(strcmp(course, "Math")==0)
		{
			if(p1->Math >= scope1 && p1->Math <= scope2)
			{
				printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);		
				i++;
			}
		}else if(strcmp(course, "English")==0)
		{
			if(p1->English >= scope1 && p1->English <= scope2)
			{
				printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);		
				i++;
			}
		}else if(strcmp(course, "Physic")==0)
		{
			if(p1->Physic >= scope1 && p1->Physic <= scope2)
			{
				printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);		
				i++;
			}
		}
		p1 = p1->next;
	}
		if(i == 0)
		{
			printf("no the student adopt to adition\n");
		}
 
}
 
void Search()
{
	int op;
	do
	{
		ShowMenu3();
		printf("\tplease choose the option:: ");
		scanf("%d", &op);
 
		switch(op)
		{
			case 1: SearchByRank(); break;
 
			case 2: SearchByClass(); break;
 
			case 3: SearchByScore(); break;
 
			case 4: break;
 
			default : printf("input error!\n");
		} 
	}while(op != 4);
 
}
void ShowMenu4()
{
	printf("\t****************************************\n");
 
	printf("\t1-------------- 总计\n");
 
	printf("\t2-------------- 分班统计\n");
 
	printf("\t3----------exit\n");
 
	printf("\t****************************************\n");
 
}
void StatByStu()
{	
	struct Student *head, *p1;
 
	head = File_stuNode();
 
	p1 = head;
	while(p1 != NULL)
	{
		p1->Sum = p1->Math + p1->English + p1->Physic;
 
		p1 = p1->next;
	}
 
	Record(head);
	
}
 
void StatByClass()
{
	char Class[10][10] = {0};
	int ClassSum[10] = {0};
	FILE *fp;
	struct Student *head, *p1;
	int i = 0;  //  记录class总数
	int j;
	int tag = 1;
 
	head = File_stuNode();
	p1 = head;
 
	while(p1 != NULL)
	{
		tag = 1;
		for(j = 0; j < i; j++)
		{
			if(strcmp(Class[j] , p1->Sclass) == 0)
			{
				tag = 0; break;
			}
		}
		if(tag == 1)
		{
			strcpy(Class[i++], p1->Sclass);	
		}
		p1 = p1->next;
	}
 
	p1 = head;
	while(p1 != NULL)
	{
		for(j = 0; j < i; j++)
		{
			if(strcmp(p1->Sclass, Class[j]) == 0)
			{
				ClassSum[j] += p1->Sum;
			}
		}
		p1 = p1->next;
	}
 
 
 
	if((fp = fopen("D:\\Course\\student1.txt", "w+")) == NULL)
	{
		printf("cannot open this file\n");
		return;
	}
	
	for(j = 0; j < i; j++)
	{
		printf("%s %d\n", Class[j], ClassSum[j]);
	}
}
void Statistics()
{
	int op;
	do
	{
		ShowMenu4();
		printf("\tplease choose the option:: ");
		scanf("%d", &op);
 
		switch(op)
		{
			case 1: StatByStu(); break;
 
			case 2: StatByClass(); break;
 
			case 3: break;
 
			default : printf("input error!\n");
		} 
	}while(op != 3);
 
}
struct Student * RankSort(struct Student * head)
{
	int i;
	struct Student *p1, *p2;
 
	p1 = head;
	while(p1 != NULL)
	{
		i = 1;
		p2 = head;
		while(p2 != NULL)
		{
			if(p1->Sum < p2->Sum)
			{
				i++;
			}
			p2 = p2->next;
		}
		p1->rank = i;
		p1 = p1->next;
 
	}
 
	return head;
}
 
/* 
	对链表 按 rank 实现从小到大排序, 并返回链表的头指针。
*/
struct Student * SortByRank(struct Student *head)
{
	struct Student *p1, *p2, *p3;
 
	struct Student t;
 
    for(p1 = head; p1 != NULL; p1 = p1->next)
    {
		p3 = p1;
		for(p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if(p3->Sum < p2->Sum)
			{
				p3 = p2;   
 
			}
		}
		if(p3 != p1)
		{
 
			t.English = p1->English;
			t.Math = p1->Math;
			t.Physic = p1->Physic;
			t.Sum = p1->Sum;
			strcpy(t.Sclass, p1->Sclass);
			strcpy(t.Sid, p1->Sid);
			strcpy(t.Sname, p1->Sname);
 
			p1->English = p3->English;
			p1->Math = p3->Math;
			p1->Physic = p3->Physic;
			p1->Sum = p3->Sum;
			strcpy(p1->Sclass, p3->Sclass);
			strcpy(p1->Sid, p3->Sid);
			strcpy(p1->Sname, p3->Sname);
 
			p3->English = t.English;
			p3->Math = t.Math;
			p3->Physic = t.Physic;
			p3->Sum = t.Sum;
			strcpy(p3->Sclass, t.Sclass);
			strcpy(p3->Sid, t.Sid);
			strcpy(p3->Sname, t.Sname);
	
		}
    }
	RankSort(head);   
    return head;
}
 
 
/* 
	对链表 按 Sid 实现从小到大排序, 并返回链表的头指针。
*/
struct Student * SortBySid(struct Student *head)
{
	struct Student *p1, *p2, *p3;
 
	struct Student t;
 
    for(p1 = head; p1 != NULL; p1 = p1->next)
    {
		p3 = p1;
		for(p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if(strcmp(p3->Sid, p2->Sid) > 0)
			{
				p3 = p2;
			}
		}
		if(p3 != p1)
		{
			t.English = p1->English;
			t.Math = p1->Math;
			t.Physic = p1->Physic;
			strcpy(t.Sclass, p1->Sclass);
			strcpy(t.Sid, p1->Sid);
			strcpy(t.Sname, p1->Sname);
 
			p1->English = p3->English;
			p1->Math = p3->Math;
			p1->Physic = p3->Physic;
			strcpy(p1->Sclass, p3->Sclass);
			strcpy(p1->Sid, p3->Sid);
			strcpy(p1->Sname, p3->Sname);
 
			p3->English = t.English;
			p3->Math = t.Math;
			p3->Physic = t.Physic;
			strcpy(p3->Sclass, t.Sclass);
			strcpy(p3->Sid, t.Sid);
			strcpy(p3->Sname, t.Sname);
	
		}
    }
 
	// 统计总分;
	p1 = head;
	while(p1 != NULL)
	{
		p1->Sum = p1->Math + p1->English + p1->Physic;
 
		p1 = p1->next;
	}
	
	head = RankSort(head);   //  排名;
    return head;
}
 
void ShowSortBy(int i)
{
	struct Student *head, *p1;
	SortRank(); 
	head = File_stuNode();
 
	p1 = head;
 
	if(i == 1)
	{
		p1 = SortByRank(p1);	
	}
	else if(i == 2)
	{
		p1 = SortBySid(p1);
	}
	while(p1 != NULL)
	{
 
		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);		
		p1 = p1->next;
	}
}
 
void ShowSort()
{
	int op;
	do
	{
		printf("\t****************************************\n");
 
		printf("\t1----------sort by the rank for all student\n");
 
		printf("\t2----------sort by the Sid for all student\n");
 
		printf("\t3----------Exit!\n");
 
		printf("\t****************************************\n");
 
		printf("\tplease choose the option:: ");
		scanf("%d", &op);
 
		switch(op)
		{
			case 1: ShowSortBy(op); break;
 
			case 2: ShowSortBy(op); break;
 
			case 3: break;
 
			default : printf("input error!\n");
		} 
	}while(op != 3);
 
}
void Delete()
{
	struct Student *p1, *head, *p2;
	char stuid[10] = {0};
	int tag = 0;
 
	head = File_stuNode();
 
	printf("please input the deleted stuSid:\n");
	scanf("%s", stuid);
 
	p1 = head;
	p2 = NULL;
	while(p1 != NULL)
	{
		if(strcmp(p1->Sid, stuid) == 0)
		{
			if(p2 == NULL)
			{
				head = p1->next; // 删除是 head 结点
				tag = 1;
				break;
			}else{
 
				if(p1->next == NULL)
				{
					p2->next = NULL; // 删除是 尾节点 
				    tag = 1;
					break;
				}
				p2->next = p1->next;
				tag = 1;
				break;
			}
		}
		p2 = p1;
		p1 = p1->next;
	}
	if(tag == 0)
	{
		printf("no found the student!\n");
	}else{
		Record(head);
	}
 
}
 
void  Add()
{
	struct Student * head1, *head2, *p1, *head;
 
	head1 = File_stuNode();
	head2 = in_stuNode();
 
	p1 = head1;
	if(p1 != NULL)
	{
		while(p1->next != NULL)
		{
			p1 = p1->next;
		}
		head = head1;
		p1->next = head2;
		
	}
	else
	{
		head = head2;	
	}
	if(head == NULL){
		printf("Y");}
	Record(head);
 
}
 
void CopyFile(){
	FILE *fp, *fp1;
	char filename[30] = {0};
	char filename1[30] = {0};
	struct  Student *p1, stu;
 
	printf("please input the fileName\n");
	scanf("%s", filename);
 
	getchar();
	printf("please input the fileName path\n");
	scanf("%s", filename1);
	getchar();
 
	if((fp = fopen(filename, "r")) == NULL)
	{
		printf("open file error");
		return;
	}
 
	if((fp1 = fopen(filename1, "w")) == NULL)
	{
		printf("open file error");
		return;
	}
 
	p1 = &stu;
 
	while(!feof(fp))
	{
		fscanf(fp, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d", p1->Sid, p1->Sclass, p1->Sname, &p1->Math, &p1->English, &p1->Physic, &p1->Sum, &p1->rank);
		fprintf(fp1, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);
	}
 
	fclose(fp);
	fclose(fp1);
}
 
void SaveFile() 
{
	FILE *fp;
	char filename[30] = {0};
	struct  Student *head, *p1;
 
	scanf("%s", filename);
	getchar();
	if((fp = fopen(filename, "w")) == NULL)
	{
		printf("open file error");
		return;
	}
 
	head = File_stuNode();
	
	p1 = head;
	while(p1 != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p1->Sid, p1->Sclass, p1->Sname, p1->Math, p1->English, p1->Physic, p1->Sum, p1->rank);
 
		p1 = p1->next;
	}
 
	free(head);
	free(p1);
	fclose(fp);
}
 
int main()
{
	int option;
	
	do
	{
		ShowMenu();
		printf("\tplease choose the option: ");
		scanf("%d", &option);
		getchar();
 
		switch(option)
		{
			case 1: Record(in_stuNode()); break;
 
			case 2: Show_stuNode(); break;
 
			case 3: Search(); break;
 
			case 4: Statistics(); break;
 
			case 5: Delete(); break;
 
			case 6: Add(); break;
 
			case 7: ShowSort(); break;
 
			case 8: SaveFile();break;
 
			case 9: CopyFile();break;
 
			case 10: break;
 
			default : printf("input error!");
 
		}
	}while(option != 10);
 
	return 0;
}