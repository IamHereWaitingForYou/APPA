#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> 
typedef struct Stu
{
long long id;
char name[10];
long long tel;
struct Stu*next;
}stud;
FILE *fp; //�ļ�ָ��
void CreLi(stud *&s)
{
s=(stud *)malloc(sizeof(stud));
s->next=NULL;
}
void Loading(stud * &s,long long ID,char *Name,long long Tel) //�����¼
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
bool DeLi(stud * &s,long long ID) //ɾ����¼
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
void Show(stud *s) //�����¼
{
if(s!=NULL)
s=s->next;
if(s!=NULL)
{
while(s!=NULL)
{ printf("ID\t\tName\tTel\n");
printf("%lld\t",s->id);
printf("%s\t",s->name);
printf("%lld\n\n",s->tel);
s=s->next;
}
if(s==NULL)
printf("ͨѶ¼��ӡ��ϣ�\n");
}
else
{
printf("ͨѶ¼Ϊ�գ����������ϵ�ˣ�\n");
}
}
bool NOS(stud *&s,char *Name) //�����ֲ���
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
printf("δ��ͨѶ¼�з��ָ���ϵ�ˣ�\n");
return false;
}
else
{
printf("ID\t\tName\tTel\n");
printf("%lld\t",p->id);
printf("%s\t",p->name);
printf("%lld\n\n",p->tel);
return true;
}
}
void Saving(stud * s) //
{
fp=fopen("data.txt","w"); //���ݱ��浽�ļ���
if(s!=NULL)
s=s->next;
while(s!=NULL)
{
fprintf(fp,"%s\t%lld\t%lld\n",s->name,s->id,s->tel);//д���ļ�
s=s->next;
}
fclose(fp);
}
void Empty(stud * &s) //��ռ�¼
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
void Start(stud *s) // ��ʼ���������ļ�������
{
system("color 07"); //��Ļ�� ������ɫ
char Name[10];
long long ID,Tel;
fp=fopen("data.txt","a"); //���ļ��м������ݣ����û�и��ļ����½�
fclose(fp);
fp=fopen("data.txt","r");
while(fscanf(fp,"%s%lld%lld",Name,&ID,&Tel)!=EOF) //���ļ��ж�������

Loading(s,ID,Name,Tel);
fclose(fp);
printf("�ļ����ݶ�ȡ״̬����ȡ�ɹ���\n");
}
int main()
{
int n;
long long ID,Tel;
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
scanf("%lld",&ID);
printf("Enter the name:\n");
scanf("%s",&Name);
printf("Enter phone number:\n");
scanf("%lld",&Tel); 
Loading(s,ID,Name,Tel);break;}
case 2:
{printf("Enter student id:\n");
scanf("%lld",&ID);
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
