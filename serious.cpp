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
void CLT(LL&L){//�������
cout<<"----�������----"<<endl;
	int c;
	string ID;
	string Name,TEL;
	Node*s,*r;
	L=(LL)malloc(sizeof(Node));
	L->next=NULL;
	r=L;
cout<<"����0�˳�"<<endl;
while(1){
		s=(Node*)malloc(sizeof(Node));
		cout<<endl;
		cout<<"������ѧ�ţ�";
		cin>> ID;
		s->id=ID;
		cout<<"������������";
		cin>>Name;
		s->name=Name;
		cout<<"������绰:"; 
		cin>>TEL;
		cout<<endl;
		r->next=s;
		r=s;
		cout<<"�Ƿ��˳�����0��ʾ�˳���"<<endl; 
		cin>>c;
		if(c==0)
		break;
	}
}
Node*GD(LL L,int i){//���ҵ�i���ڵ� 

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
Node*LND(LL&L,string key){//��ֵ����zaishanchu 
	Node*p;
	int j=0;
	p=L->next;
	while(p!=NULL&&p->id!=key){
p=p->next;
j++;
}
if(j==LK(L)){
	cout<<"����δ�ҵ���ѧ�ţ�"<<endl;
}
else {
Node*pre,*r;
pre=GD(L,j-1);
if(pre==NULL||pre->next==NULL)
printf("ɾ���ڵ��λ��i������");
else
{
	r=pre->next;
	pre->next=r->next;
	free(r);
		}
	}
}
void DL(LL&L,int i,int&x){//ɾ��ָ��λ�õ�Ԫ�� 
		
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
cout<<"������Ҫɾ����ѧ�ţ�";
string ke;
cin>>ke; 
LND(l,ke);
cout<<"---t "<<endl; 
//listdelete(l,t); 
break; 
} 
} 
}
