#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#define N 20 
typedef struct student{ 
char tel[N]; 
char name[N]; 
char id[N]; 
struct student *next; 
}linklist; 
//������Ϣ
void createlist(linklist *&l){ 
int ch; 
linklist *s,*p; 
printf("*********** ����ͨѶ¼ ***********\n"); 
printf("---- ������ͨѶ����Ϣ ----- ��\n ��������������� ���� 0 ���˳� :\n"); 
scanf("%d",&ch); 
l=(linklist *)malloc(sizeof(linklist)); 
s=l; 
while(ch!=0){ 
p=(linklist *)malloc(sizeof(linklist)); 
printf(" ������ͨѶ������ :"); 
scanf("%s",p->name); 
printf(" ������ͨѶ�ߵ绰�� :"); 
scanf("%s",p->tel); 
printf(" ������ͨѶ�����֤�� :"); 
scanf("%s",p->id); 
s->next=p; 
s=p; 
printf(" ������ͨѶ����Ϣ�� \n ������������������� 0 ���˳� :\n"); 
scanf("%d",&ch); 
} 
s->next=NULL; 
} 
//ɾ����Ϣ
void listdelete(linklist *&l,int t ){
	int j=0; 
linklist *p,*q; 
p=l; 
while(p!=NULL&&j<t-1){ 
j++; 
p=p->next; 
} 
if(p==NULL) 
exit(0); 
else{ 
q=p->next; 
if(q==NULL)exit(0); 
p->next=q->next; 
printf("*************** ɾ��ϵͳ **************\n"); 
printf("------- �㽫ɾ������ϵ�˵���ϢΪ -------:\n"); 
printf(" ͨѶ������ :%s\n",q->name); 
printf(" ͨѶ�ߵ绰�� :%s\n",q->tel); 
printf(" ͨѶ�����֤�� :%s\n",q->id); 
printf("******-------****** ɾ���ɹ� ******------*******\n"); 
free(q); 
} 
} 
//�����Ϣ
void output(linklist *l){ 
linklist *p; 
p=l->next; 
printf("----***---- ���������ϵ����Ϣ ----***----:\n"); 
while(p!=NULL){ 
printf(" ͨѶ������ :%s\n",p->name); 
printf(" ͨѶ�ߵ绰�� :%s\n",p->tel); 
printf(" ͨѶ�����֤�� :%s\n",p->id); 
printf("*****************************\n"); 
p=p->next; 
} 
} 
//����������
void findname(linklist *l){ 
char n[N];
linklist *p=l->next; 
printf("*************** ����ϵͳ *************\n"); 
printf("---------- ������Ҫ���ҵ����� ---------:\n"); 
scanf("%s",n); 
while(p!=NULL){ 
if(strcmp(p->name,n)){ 
printf("-----***-- ��Ҫ���ҵ�����Ϊ --***----:\n"); 
printf(" ͨѶ������ :%s\n",p->name); 
printf(" ͨѶ�ߵ绰�� :%s\n",p->tel); 
printf(" ͨѶ�����֤�� :%s\n",p->id); 
printf("*****************************"); 
break; 
} 
else 
p=p->next; 
} 
} 
//���绰������
void sorttel(linklist *&l){ 
linklist *p,*q,*s; 
q=l; 
p=q->next->next; 
q->next->next=NULL; 
while(p){ 
while(q->next&&(strcmp(p->tel,q->next->tel)>0)) 
q=q->next; 
s=p->next; 
p->next=q->next; 
q->next=p; 
p=s; 
q=l; 
} 
} 
//���
void release(linklist *&l){ 
linklist *p,*q; 
p=l; 
q=p->next; 
while(q!=NULL){
	free(p); 
p=q; 
q=p->next; 
} 
free(p); 
printf("-------- ������ȫ������� ----------\n ��***** �ڴ���� *****\n"); 
} 
//������
int main(){ 
int i,t; 
linklist *l; 
while(1){ 
printf(" ͨѶ¼�������� :\n1.����ͨѶ¼��Ϣ \n2.ɾ����Ϣ \n3.�����Ϣ \n4.������������Ϣ \n5.���绰��������Ϣ \n6.�����Ϣ \n7.�˳� "); 
scanf("%d",&i); 
if(i<=0||i>7)break; 
switch(i){ 
case 1: 
createlist(l);break; 
case 2: 
printf("--------- ������� t ��Ҫɾ������Ϣ ---------:\n"); 
scanf("%d",&t); 
listdelete(l,t); 
break; 
case 3: 
output(l);break; 
case 4: 
findname(l);break; 
case 5: 
sorttel(l); 
printf("-----***---&&&-- �� �� �� �� �� �� �� �� �� �� �� Ϣ �� ��-&&&---***-----\n"); 
output(l); 
break; 
case 6: 
release(l);break; 
case 7:
	break; 
} 
} 
}
