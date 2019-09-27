#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> 
typedef struct Stu
{
int id;
char name[10];
int tel;
struct Stu*next;
}stud;
FILE *fp; //文件指针
void CreLi(stud *&s)
{
s=(stud *)malloc(sizeof(stud));
s->next=NULL;
}
void Loading(stud * &s,int ID,char *Name,int Tel) //输入记录
{
stud *r,*t=s;
while(t->next!=NULL)
{
t=t->next;
}
r=(stud *)malloc(sizeof(stud));
r->id=ID;
strcpy(r->name,Name);
r->tel=Tel;
r->next=NULL;
t->next=(stud *)malloc(sizeof(stud));
t->next=r;
}
bool DeLi(stud * &s,int ID) //删除记录
{
stud *r=s,*q,*pre=s;
r=r->next;
while(r!=NULL && r->id!=ID)
{
pre=pre->next;
r=r->next;
}
if(r==NULL){
printf("Record does not exist\n");
return false;
}
else
{
q=pre->next;
pre->next=q->next;
free(q);
printf("successfully delete\n");
return true;
}
}
void Show(stud *s) //输出记录
{
if(s!=NULL)
s=s->next;
if(s!=NULL)
{
while(s!=NULL)
{ printf("ID\t Name\t Tel\n");
printf("%d\t",s->id);
printf("%s\t",s->name);
printf("%d\n",s->tel);
s=s->next;
}
}
else
{
printf("The address book is empty\n");
}
}
bool NOS(stud *&s,char *Name) //按名字查找
{
stud *p,*pre=s;
p=s->next;
while(p!=NULL&&(strcmp(p->name,Name)))
{
pre=pre->next;
p=p->next;
}
if(p==NULL)
{
printf("The student does not exist.\n");
return false;
}
else
{
printf("ID\t Name\t Tel\n");
printf("%d\t",p->id);
printf("%s\t",p->name);
printf("%d\n",p->tel);
return true;
}
}
void Saving(stud * s) //
{
fp=fopen("d:\\in.txt","w"); //数据保存到文件中
if(s!=NULL)
s=s->next;
while(s!=NULL)
{
fprintf(fp,"%d\t%s\t%d\n",s->id,s->name,s->tel);//写入文件
s=s->next;
}
fclose(fp);
}
void Empty(stud * &s) //清空记录
{
stud *p=s,*q=s;
p=p->next;
if(p!=NULL)
q=p->next;
while(q!=NULL)
{
free(p);
p=q;
q=p->next;
}
free(p);
s->next=NULL;
printf("Address Book clearance completed\n");
}
void Start(stud *s) // 初始化和载入文件中数据
{
system("color 07"); //屏幕、 字体颜色
char Name[10];
int ID,Tel;
fp=fopen("C:\\Users\\wyx03\\Desktop","a"); //从文件中加载数据，如果没有该文件则新建
fclose(fp);
fp=fopen("C:\\Users\\wyx03\\Desktop","r");
while(fscanf(fp,"%d%s%d",&ID,Name,&Tel)!=EOF) //从文件中读入数据

Loading(s,ID,Name,Tel);
fclose(fp);
printf("File status: Read normal!\n");
}
int main()
{
int n,ID,Tel;
char Name[10];
stud *s;
CreLi(s);
Start(s);
printf("Please select the sequence number you want to operate:\n");
printf(" 1. Add Records \n 2. Delete records   \n");
printf(" 3. Show record \n 4. Search by name   \n");
printf(" 5. Saving records \n 6. Clear records  \n");
printf(" 7. Sign out\t\t\t\t \n>*");
while(~scanf("%d",&n))
{
if(n>=1&&n<=6){
switch(n)
{
case 1:
{
printf("Enter student id:\n");
scanf("%d",&ID);
printf("Enter the name:\n");
scanf("%s",&Name);
printf("Enter phone number:\n");
scanf("%d",&Tel); 
Loading(s,ID,Name,Tel);break;}
case 2:
{printf("Enter student id:\n");
scanf("%d",&ID);
DeLi(s,ID);break;}
case 3:
{Show(s);break;}
case 4:
{printf("Enter the name:\n");
scanf("%s",&Name);
NOS(s,Name);break;}
case 5:
{Saving(s);printf("Data saved successfully\n");break;}
case 6:
{Empty(s);break;}
}
}
if(n==7)
{
printf("It's coming to an end. Just a moment, please.\n");
Sleep(3000); 
break;}
printf("=====  1. Add Records \t2. Delete records   =====\n");
printf("=====  3. Show record \t4. Search by name   =====\n");
printf("=====  5. Saving records \t6. Clear records   =====\n");
printf("=====  7. Sign out\t\t\t\t =====\n");
}
return 0;
}
