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
//????
void createlist(linklist *&l){ 
int ch; 
linklist *s,*p; 
printf("*********** ????? ***********\n"); 
printf("---- ???????? ----- :\n ???????, ?? 0 ??? :\n"); 
scanf("%d",&ch); 
l=(linklist *)malloc(sizeof(linklist)); 
s=l; 
while(ch!=0){ 
p=(linklist *)malloc(sizeof(linklist)); 
printf(" ???????? :"); 
cin>>p->name;
printf(" ????????? :"); 
cin>>p->tel; 
printf(" ?????????? :"); 
cin>>p->id; 
s->next=p; 
s=p; 
cout<<" ????????: \n ???????,?? 0 ??? :"<<endl; 
cin>>ch; 
} 
s->next=NULL; 
} 
//????
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
cout<<"*************** ???? **************"<<endl; 
cout<<"------- ???????????? -------:"<<endl; 
cout<<" ????? :"<<q->name<<endl; 
cout<<" ?????? :"<<q->tel<<endl; 
cout<<" ??????? :"<<q->id<<endl; 
cout<<"******-------****** ???? ******------*******\n"<<endl; 
free(q); 
} 
} 
//????
void output(linklist *l){ 
linklist *p; 
p=l->next; 
printf("----***---- ????????? ----***----:\n"); 
while(p!=NULL){ 
cout<<" ????? :"<<p->name<<endl; 
cout<<" ?????? :"<<p->tel<<endl; 
cout<<" ??????? :"<<p->id<<endl; 
cout<<"*****************************"<<endl; 
p=p->next; 
} 
} 
//?????
void findname(linklist *l){ 
char n[N]; 
linklist *p=l->next; 
cout<<"*************** ???? *************"<<endl; 
cout<<"---------- ????????? ---------:"<<endl; 
cin>>n;
while(p!=NULL){ 
if(strcmp(p->name,n)){ 
cout<<"-----***-- ???????? --***----:"<<endl; 
cout<<" ????? :"<<p->name<<endl; 
cout<<" ?????? :"<<p->tel<<endl; 
cout<<" ??????? :"<<p->id<<endl; 
cout<<"*****************************"<<endl; 
break; 
} 
else 
p=p->next; 
} 
} 
//??????
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
//??
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
cout<<"-------- ???????? ----------"<<endl;
cout<< " ***** ???? *****"<<endl; 
} 
//void WritetoText(linklist lin[],int n)
//{
//int i=0;
//FILE *fp; /*??????*/
//char filename[20]; /*?????*/
//printf("\t ?????\n"); /*?????*/
//printf("\t ??????????:");
//scanf("\t%s",filename);
//if((fp=fopen(filename,"w"))==NULL)
//{
//printf("\t ??????\n");
//system("pause");
//return;
//}
//fprintf(fp,"****************************************** ? ? ?******************************************\n");
//fprintf(fp,"??,??,??,????,????,????\n");
//fprintf(fp,"---------------------------------------------------------------------------------------\n");
//while(i<n)
//{
//fprintf(fp,"%-3d\t%-6s\t%-3s\t%-13s\t%-20s\t%-20s\n",per[i].score,per[i].name,per
//[i].age,per[i].num,per[i].adds,per[i].email);
//i++;
//}
//fprintf(fp,"----------------------------------------------------------------------------------\n");
//fprintf(fp,"*************************************** ? ? %d ? ? ?*********************************\n",n);
//fclose(fp); /*????*/
//printf("????!\n");
//}
////???
int main(){ 
int i,t; 
linklist *l; 
while(1){ 
cout<<" ??????? :"<<endl;
cout<<"1.??????? "<<endl;
cout<<"2.???? "<<endl;
cout<<"3.???? "<<endl;
cout<<"4.??????? "<<endl;
cout<<"5.???????? "<<endl;
cout<<"6.???? "<<endl;
cout<<"7.?? "<<endl; 
cin>>i; 
if(i<=0||i>7)break; 
switch(i){ 
case 1: 
createlist(l);break; 
case 2: 
cout<<"--------- ???? t ??????? ---------:"<<endl; 
cout<<t<<endl; 
listdelete(l,t); 
break; 
case 3: 
output(l);break; 
case 4: 
findname(l);break; 
case 5: 
sorttel(l); 
cout<<"-----***---&&&-- ? ? ? ? ? ? ? ? ? ? ? ? ? ?--&&&---***-----"<<endl; 
output(l); 
break; 
case 6: 
release(l);break; 
case 7: 
break; 
} 
} 
}
