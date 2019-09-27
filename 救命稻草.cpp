#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
FILE *fp; //文件指针
typedef struct lnode
{
int id;
char name[10];
int tel;
struct lnode *next;
}stud;
void Inside(stud *&s,int ID,char *NAME,int TEL);
bool Delete(stud *&s,int ID);
void Output(stud *s);
bool Sereachname(stud *&s,char *NAME);
void Memory(stud * s);
void Write(stud * s);
void Empty(stud *&s);
void Ini(stud *&s);
void Start(stud *s);
int main()
{
int n,ID,TEL;
char NAME[10];
stud *s;
Ini(s);
Start(s);
printf("*****************************1. 添 加 记 录 \t2. 删 除 记 录*****************************\n");
printf("*****************************3. 输 出 记 录 \t4. 按 姓 名 查 找***************************\n");
printf("*****************************5. 保 存 记 录 \t6. 清 空 记 录**************************\n");
printf("*****************************7. 退 出\t***************************************\n");
while(~scanf("%d",&n))
{
if(n>=1&&n<=6){
switch(n)
{
case 1:
{printf("输入学号、 姓名、 电话\n");scanf("%d%s%d",&ID,&NAME,&TEL);
Inside(s,ID,NAME,TEL);break;}
case 2:
{printf("请输入“学号” \n");
scanf("%d",&ID);
Delete(s,ID);break;}
case 3:
{Output(s);break;}
case 4:
{printf("请输入“姓名” \n");
scanf("%s",&NAME);
Sereachname(s,NAME);break;}
case 5:
{Memory(s);printf("保存成功\n");break;}
case 6:
{Empty(s);break;}
}
}
if(n==7)
{printf("***********谢谢使用************\n");break;}
printf("*****************************1. 添 加 记 录 \t2. 删 除 记 录*****************************\n");
printf("*****************************3. 输 出 记 录 \t4. 按 姓 名 查 *********************\n");
printf("*****************************5. 保 存 记 录 \t6. 清 空 记 录********************\n");
printf("*****************************7. 退 出\t***************************************\n");
}
return 0;
}
void Ini(stud *&s)
{
s=(stud *)malloc(sizeof(stud));
s->next=NULL;
}
void Inside(stud * &s,int ID,char *NAME,int TEL) //输入记录
{
stud *r,*t=s;
while(t->next!=NULL)
{
t=t->next;
}
r=(stud *)malloc(sizeof(stud));
r->id=ID;
strcpy(r->name,NAME);
r->tel=TEL;
r->next=NULL;
t->next=(stud *)malloc(sizeof(stud));
t->next=r;
}
bool Delete(stud * &s,int ID) //删除记录
{
stud *r=s,*q,*pre=s;
r=r->next;
while(r!=NULL && r->id!=ID)
{
pre=pre->next;
r=r->next;
}
if(r==NULL){
printf("该记录不存在\n");
return false;
}
else
{
q=pre->next;
pre->next=q->next;
free(q);
printf("删除成功\n");
return true;
}
}
void Output(stud *s) //输出记录
{
if(s!=NULL)
s=s->next;
if(s!=NULL)
{
while(s!=NULL)
{ printf("学号\t 姓名\t 电话\n");
printf("%d\t",s->id);
printf("%s\t",s->name);
printf("%d\n",s->tel);
s=s->next;
}
}
else
{
printf("该通讯录为空\n");
}
}
bool Sereachname(stud *&s,char *NAME) //按名字查找
{
stud *p,*pre=s;
p=s->next;
while(p!=NULL&&(strcmp(p->name,NAME)))
{
pre=pre->next;
p=p->next;
}
if(p==NULL)
{
printf("该学生不存在\n");
return false;
}
else
{
printf("学号\t 姓名\t 电话\n");
printf("%d\t",p->id);
printf("%s\t",p->name);
printf("%d\n",p->tel);
return true;
}
}
void Memory(stud * s) //
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
printf("该通讯录已空\n");
}
void Start(stud *s) // 初始化和载入文件中数据
{
system("color 09"); //屏幕、 字体颜色
char NAME[10];
int ID,TEL;
fp=fopen("d:\\in.txt","a"); //从文件中加载数据， 如果没有该文件则新建
fclose(fp);
fp=fopen("d:\\in.txt","r");
while(fscanf(fp,"%d%s%d",&ID,NAME,&TEL)!=EOF) //从文件中读入数据
Inside(s,ID,NAME,TEL);
fclose(fp);
}
