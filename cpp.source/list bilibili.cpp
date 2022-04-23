#include<iostream>
using namespace std;

typedef struct node//typedef:Student代表了struct node 
{
	char name[20];
	int age;
	struct node *next;//节点指针区的指针 
 } Student;
 
 //创建链表 
 Student* creatlist(int n)//节点的个数 
 {
 	Student*head=new Student; //创建头节点：一般不存储数据 
	Student*pre =head;//创建前节点，第一个前节点是头节点 
	
	 for(int i=0;i<n;i++)
	 {
	 	Student *p=new Student;//新的节点 
		printf("输入第%d个学生的姓名和学号",i+1); 
		 cin>>p->name;
		 cin>>p->age; 
		 
		pre->next=p;//（pre指针区存放的是p类型？） 
 		pre=p;//让当前节点  成为  新节点的前节点 
 		p->next=NULL;//新节点的下一个节点为空，边界。 
	  } 
	  
	  return head;//已在主函数创建指针接受该值 
  } 
  
  void display(Student *head)
  {
  	Student*p=head->next;//头节点的指针 
  	while(p!=NULL)
  	{
  		cout<<p->name<<p->age<<endl;
  		p=p->next;//p赋予p指针区的指针 
	  }
  }
 
 int main()
 {
 	int n=3;
 	Student* head=creatlist(n);//主函数定义一个头结点 
 	display(head);
 	return 0;
 }