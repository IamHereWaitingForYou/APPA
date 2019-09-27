#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
FILE *fp; //�ļ�ָ��
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
printf("*****************************1. �� �� �� ¼ \t2. ɾ �� �� ¼*****************************\n");
printf("*****************************3. �� �� �� ¼ \t4. �� �� �� �� ��***************************\n");
printf("*****************************5. �� �� �� ¼ \t6. �� �� �� ¼**************************\n");
printf("*****************************7. �� ��\t***************************************\n");
while(~scanf("%d",&n))
{
if(n>=1&&n<=6){
switch(n)
{
case 1:
{printf("����ѧ�š� ������ �绰\n");scanf("%d%s%d",&ID,&NAME,&TEL);
Inside(s,ID,NAME,TEL);break;}
case 2:
{printf("�����롰ѧ�š� \n");
scanf("%d",&ID);
Delete(s,ID);break;}
case 3:
{Output(s);break;}
case 4:
{printf("�����롰������ \n");
scanf("%s",&NAME);
Sereachname(s,NAME);break;}
case 5:
{Memory(s);printf("����ɹ�\n");break;}
case 6:
{Empty(s);break;}
}
}
if(n==7)
{printf("***********ллʹ��************\n");break;}
printf("*****************************1. �� �� �� ¼ \t2. ɾ �� �� ¼*****************************\n");
printf("*****************************3. �� �� �� ¼ \t4. �� �� �� �� *********************\n");
printf("*****************************5. �� �� �� ¼ \t6. �� �� �� ¼********************\n");
printf("*****************************7. �� ��\t***************************************\n");
}
return 0;
}
void Ini(stud *&s)
{
s=(stud *)malloc(sizeof(stud));
s->next=NULL;
}
void Inside(stud * &s,int ID,char *NAME,int TEL) //�����¼
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
bool Delete(stud * &s,int ID) //ɾ����¼
{
stud *r=s,*q,*pre=s;
r=r->next;
while(r!=NULL && r->id!=ID)
{
pre=pre->next;
r=r->next;
}
if(r==NULL){
printf("�ü�¼������\n");
return false;
}
else
{
q=pre->next;
pre->next=q->next;
free(q);
printf("ɾ���ɹ�\n");
return true;
}
}
void Output(stud *s) //�����¼
{
if(s!=NULL)
s=s->next;
if(s!=NULL)
{
while(s!=NULL)
{ printf("ѧ��\t ����\t �绰\n");
printf("%d\t",s->id);
printf("%s\t",s->name);
printf("%d\n",s->tel);
s=s->next;
}
}
else
{
printf("��ͨѶ¼Ϊ��\n");
}
}
bool Sereachname(stud *&s,char *NAME) //�����ֲ���
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
printf("��ѧ��������\n");
return false;
}
else
{
printf("ѧ��\t ����\t �绰\n");
printf("%d\t",p->id);
printf("%s\t",p->name);
printf("%d\n",p->tel);
return true;
}
}
void Memory(stud * s) //
{
fp=fopen("d:\\in.txt","w"); //���ݱ��浽�ļ���
if(s!=NULL)
s=s->next;
while(s!=NULL)
{
fprintf(fp,"%d\t%s\t%d\n",s->id,s->name,s->tel);//д���ļ�
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
printf("��ͨѶ¼�ѿ�\n");
}
void Start(stud *s) // ��ʼ���������ļ�������
{
system("color 09"); //��Ļ�� ������ɫ
char NAME[10];
int ID,TEL;
fp=fopen("d:\\in.txt","a"); //���ļ��м������ݣ� ���û�и��ļ����½�
fclose(fp);
fp=fopen("d:\\in.txt","r");
while(fscanf(fp,"%d%s%d",&ID,NAME,&TEL)!=EOF) //���ļ��ж�������
Inside(s,ID,NAME,TEL);
fclose(fp);
}
