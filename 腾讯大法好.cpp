#include<iostream>
#include"malloc.h"
#include"stdio.h"
#include<stdlib.h> 
#include<string.h> 
#include<iostream> 
#include<fstream>
#define N 20 
using namespace std;
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
cin>>p->name;
printf(" ������ͨѶ�ߵ绰�� :"); 
cin>>p->tel; 
printf(" ������ͨѶ�����֤�� :"); 
cin>>p->id; 
s->next=p; 
s=p; 
cout<<" ������ͨѶ����Ϣ�� \n ������������������� 0 ���˳� :"<<endl; 
cin>>ch; 
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
cout<<"*************** ɾ��ϵͳ **************"<<endl; 
cout<<"------- �㽫ɾ������ϵ�˵���ϢΪ -------:"<<endl; 
cout<<" ͨѶ������ :"<<q->name<<endl; 
cout<<" ͨѶ�ߵ绰�� :"<<q->tel<<endl; 
cout<<" ͨѶ�����֤�� :"<<q->id<<endl; 
cout<<"******-------****** ɾ���ɹ� ******------*******\n"<<endl; 
free(q); 
} 
} 
//�����Ϣ
void output(linklist *l){ 
linklist *p; 
p=l->next; 
printf("----***---- ���������ϵ����Ϣ ----***----:\n"); 
while(p!=NULL){ 
cout<<" ͨѶ������ :"<<p->name<<endl; 
cout<<" ͨѶ�ߵ绰�� :"<<p->tel<<endl; 
cout<<" ͨѶ�����֤�� :"<<p->id<<endl; 
cout<<"*****************************"<<endl; 
p=p->next; 
} 
} 
//����������
void findname(linklist *l){ 
char n[N]; 
linklist *p=l->next; 
cout<<"*************** ����ϵͳ *************"<<endl; 
cout<<"---------- ������Ҫ���ҵ����� ---------:"<<endl; 
cin>>n;
while(p!=NULL){ 
if(strcmp(p->name,n)){ 
cout<<"-----***-- ��Ҫ���ҵ�����Ϊ --***----:"<<endl; 
cout<<" ͨѶ������ :"<<p->name<<endl; 
cout<<" ͨѶ�ߵ绰�� :"<<p->tel<<endl; 
cout<<" ͨѶ�����֤�� :"<<p->id<<endl; 
cout<<"*****************************"<<endl; 
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
cout<<"-------- ������ȫ������� ----------"<<endl;
cout<< " ***** �ڴ���� *****"<<endl; 
} 
//void WritetoText(linklist lin[],int n)
//{
//int i=0;
//FILE *fp; /*�����ļ�ָ��*/
//char filename[20]; /*�����ļ���*/
//printf("\t ���浽�ļ�\n"); /*�����ļ���*/
//printf("\t ��������������ļ���:");
//scanf("\t%s",filename);
//if((fp=fopen(filename,"w"))==NULL)
//{
//printf("\t �޷����ļ�\n");
//system("pause");
//return;
//}
//fprintf(fp,"****************************************** ͨ Ѷ ¼******************************************\n");
//fprintf(fp,"���,����,����,�绰����,ͨѶ��ַ,��������\n");
//fprintf(fp,"---------------------------------------------------------------------------------------\n");
//while(i<n)
//{
//fprintf(fp,"%-3d\t%-6s\t%-3s\t%-13s\t%-20s\t%-20s\n",per[i].score,per[i].name,per
//[i].age,per[i].num,per[i].adds,per[i].email);
//i++;
//}
//fprintf(fp,"----------------------------------------------------------------------------------\n");
//fprintf(fp,"*************************************** �� �� %d �� �� ¼*********************************\n",n);
//fclose(fp); /*�ر��ļ�*/
//printf("����ɹ�!\n");
//}
////������
int main(){ 
int i,t; 
linklist *l; 
while(1){ 
cout<<" ͨѶ¼�������� :"<<endl;
cout<<"1.����ͨѶ¼��Ϣ "<<endl;
cout<<"2.ɾ����Ϣ "<<endl;
cout<<"3.�����Ϣ "<<endl;
cout<<"4.������������Ϣ "<<endl;
cout<<"5.���绰��������Ϣ "<<endl;
cout<<"6.�����Ϣ "<<endl;
cout<<"7.�˳� "<<endl; 
cin>>i; 
if(i<=0||i>7)break; 
switch(i){ 
case 1: 
createlist(l);break; 
case 2: 
cout<<"--------- ������� t ��Ҫɾ������Ϣ ---------:"<<endl; 
cout<<t<<endl; 
listdelete(l,t); 
break; 
case 3: 
output(l);break; 
case 4: 
findname(l);break; 
case 5: 
sorttel(l); 
cout<<"-----***---&&&-- �� �� �� �� �� �� �� �� �� �� �� Ϣ �� ��--&&&---***-----"<<endl; 
output(l); 
break; 
case 6: 
release(l);break; 
case 7: 
break; 
} 
} 
}
