#include<iostream>
#include<string>
#include"stdio.h"
#include"malloc.h"
using namespace std;
typedef struct Node{
	string id;
	string name;
	string tel;
	struct Node* next;
}Node,*LL;
void CLT(LL&L){//正序插入
cout<<"----添加数据----"<<endl;
	int c;
	string ID;
	string Name,TEL;
	Node*s,*r;
	L=(LL)malloc(sizeof(Node));
	L->next=NULL;
	r=L;
cout<<"输入0退出"<<endl;
while(1){
		s=(Node*)malloc(sizeof(Node));
		cout<<endl;
		cout<<"请输入学号：";
		cin>> ID;
		s->id=ID;
		cout<<"请输入姓名：";
		cin>>Name;
		s->name=Name;
		cout<<"请输入电话:"; 
		cin>>TEL;
		cout<<endl;
		r->next=s;
		r=s;
		cout<<"是否退出？（0表示退出）"<<endl; 
		cin>>c;
		if(c==0)
		break;
	}
}
Node*GD(LL L,int i){//查找第i个节点 

	int j;
	Node*p;
	if(i<=0)return NULL;
	p=L;
	j=0;
	while(p->next!=NULL&&j<i){
		p=p->next;
		j++;
		
	}
	if(i==j){
		return p;
	}
	else return NULL;
} 
int LK(LL L){
	Node*p;
	int len;
	p=L->next;
	len=0;
	while(p!=NULL){
		p=p->next;
		len++;
	}
	return len;
}
Node*LND(LL&L,string key){//按值查找zaishanchu 
	Node*p;
	int j=0;
	p=L->next;
	while(p!=NULL&&p->id!=key){
p=p->next;
j++;
}
if(j==LK(L)){
	cout<<"表中未找到该学号！"<<endl;
}
else {
Node*pre,*r;
pre=GD(L,j-1);
if(pre==NULL||pre->next==NULL)
printf("删除节点的位置i不合理！");
else
{
	r=pre->next;
	pre->next=r->next;
	free(r);
		}
	}
}
void DL(LL&L,int i,int&x){//删除指定位置的元素 
		
}

int main(){
	LL l;
	int i;
while(1){ 
cin>>i; 
if(i<=0||i>7)break; 
switch(i){ 
case 1: 
CLT(l);break; 
case 2: 
cout<<"请输入要删除的学号：";
string ke;
cin>>ke; 
LND(l,ke);
cout<<"---t "<<endl; 
//listdelete(l,t); 
break; 
} 
} 
}
