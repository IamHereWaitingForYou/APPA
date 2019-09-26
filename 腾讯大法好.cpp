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
//创建信息
void createlist(linklist *&l){ 
int ch; 
linklist *s,*p; 
printf("*********** 创建通讯录 ***********\n"); 
printf("---- 请输入通讯者信息 ----- ：\n 请输入非零整数， 输入 0 则退出 :\n"); 
scanf("%d",&ch); 
l=(linklist *)malloc(sizeof(linklist)); 
s=l; 
while(ch!=0){ 
p=(linklist *)malloc(sizeof(linklist)); 
printf(" 请输入通讯者姓名 :"); 
cin>>p->name;
printf(" 请输入通讯者电话号 :"); 
cin>>p->tel; 
printf(" 请输入通讯者身份证号 :"); 
cin>>p->id; 
s->next=p; 
s=p; 
cout<<" 请输入通讯者信息： \n 请输入非零整数，输入 0 则退出 :"<<endl; 
cin>>ch; 
} 
s->next=NULL; 
} 
//删除信息
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
cout<<"*************** 删除系统 **************"<<endl; 
cout<<"------- 你将删除的联系人的信息为 -------:"<<endl; 
cout<<" 通讯者姓名 :"<<q->name<<endl; 
cout<<" 通讯者电话号 :"<<q->tel<<endl; 
cout<<" 通讯者身份证号 :"<<q->id<<endl; 
cout<<"******-------****** 删除成功 ******------*******\n"<<endl; 
free(q); 
} 
} 
//输出信息
void output(linklist *l){ 
linklist *p; 
p=l->next; 
printf("----***---- 输出所有联系者信息 ----***----:\n"); 
while(p!=NULL){ 
cout<<" 通讯者姓名 :"<<p->name<<endl; 
cout<<" 通讯者电话号 :"<<p->tel<<endl; 
cout<<" 通讯者身份证号 :"<<p->id<<endl; 
cout<<"*****************************"<<endl; 
p=p->next; 
} 
} 
//按姓名查找
void findname(linklist *l){ 
char n[N]; 
linklist *p=l->next; 
cout<<"*************** 查找系统 *************"<<endl; 
cout<<"---------- 请输入要查找的姓名 ---------:"<<endl; 
cin>>n;
while(p!=NULL){ 
if(strcmp(p->name,n)){ 
cout<<"-----***-- 你要查找的资料为 --***----:"<<endl; 
cout<<" 通讯者姓名 :"<<p->name<<endl; 
cout<<" 通讯者电话号 :"<<p->tel<<endl; 
cout<<" 通讯者身份证号 :"<<p->id<<endl; 
cout<<"*****************************"<<endl; 
break; 
} 
else 
p=p->next; 
} 
} 
//按电话号排序
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
//清空
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
cout<<"-------- 数据已全部被清空 ----------"<<endl;
cout<< " ***** 内存回收 *****"<<endl; 
} 
//void WritetoText(linklist lin[],int n)
//{
//int i=0;
//FILE *fp; /*定义文件指针*/
//char filename[20]; /*定义文件名*/
//printf("\t 保存到文件\n"); /*输入文件名*/
//printf("\t 请输入所保存的文件名:");
//scanf("\t%s",filename);
//if((fp=fopen(filename,"w"))==NULL)
//{
//printf("\t 无法打开文件\n");
//system("pause");
//return;
//}
//fprintf(fp,"****************************************** 通 讯 录******************************************\n");
//fprintf(fp,"编号,姓名,年龄,电话号码,通讯地址,电子邮箱\n");
//fprintf(fp,"---------------------------------------------------------------------------------------\n");
//while(i<n)
//{
//fprintf(fp,"%-3d\t%-6s\t%-3s\t%-13s\t%-20s\t%-20s\n",per[i].score,per[i].name,per
//[i].age,per[i].num,per[i].adds,per[i].email);
//i++;
//}
//fprintf(fp,"----------------------------------------------------------------------------------\n");
//fprintf(fp,"*************************************** 共 有 %d 条 记 录*********************************\n",n);
//fclose(fp); /*关闭文件*/
//printf("保存成功!\n");
//}
////主函数
int main(){ 
int i,t; 
linklist *l; 
while(1){ 
cout<<" 通讯录功能如下 :"<<endl;
cout<<"1.建立通讯录信息 "<<endl;
cout<<"2.删除信息 "<<endl;
cout<<"3.输出信息 "<<endl;
cout<<"4.按姓名查找信息 "<<endl;
cout<<"5.按电话号排序信息 "<<endl;
cout<<"6.清空信息 "<<endl;
cout<<"7.退出 "<<endl; 
cin>>i; 
if(i<=0||i>7)break; 
switch(i){ 
case 1: 
createlist(l);break; 
case 2: 
cout<<"--------- 请输入第 t 个要删除的信息 ---------:"<<endl; 
cout<<t<<endl; 
listdelete(l,t); 
break; 
case 3: 
output(l);break; 
case 4: 
findname(l);break; 
case 5: 
sorttel(l); 
cout<<"-----***---&&&-- 这 是 按 电 话 号 排 序 后 的 信 息 列 表--&&&---***-----"<<endl; 
output(l); 
break; 
case 6: 
release(l);break; 
case 7: 
break; 
} 
} 
}
