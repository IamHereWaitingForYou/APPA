# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define SIZE sizeof(struct student)
struct student
{
	int num;
	char name[20];
	int telephone;
	struct student * next;
};
struct student * Create_stud();
struct student * Insert_stud_node(struct student * head,struct student * stud);
struct student * Delete_stud_node(struct student * head,int num);
void Print_stud_node(struct student * head);
struct student * Find_stud_node(struct student * head,char name[20]);
int main()
{
	
//	FILE * fp;
	struct student * head;
	struct student * p;
	int choice,num,telephone;
	char name[20];

	do
	{
		printf("请输入功能选项:\n");
		printf("1:创建链表 2:插入节点 3:删除节点 4:输出链表  5:查找  6:保存记录 0:退出 \n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			head=Create_stud();
			break;
		case 2:
			printf("Input num,name and score:\n");
			p=(struct student *)malloc(SIZE);
			scanf("%d%s%d",&num,name,&telephone);
			p->num = num;
			strcpy(p->name,name);
			p->telephone = telephone;
			head=Insert_stud_node(head,p);
			break;
		case 3:
			printf("Input num:\n");
			scanf("%d",&num);//这里很容易出错，如果他说不能读入内存的话，一般就是少些了取地址符
			head = Delete_stud_node(head,num);
			break;
		case 4:
			Print_stud_node(head);
			break;
		case 5:
			printf("nput name:\n");
			scanf("%s",&name);
			p = Find_stud_node(head,name);
			printf("%8d%10s%12d",p->num ,p->name,p->telephone );
			break;
/*		case 6:
			if((fp = fopen("fi.txt","w"))==NULL)
			{
				printf("File open error!\n");
				exit(0);
			}

			for(p = head;p!=NULL;p = p->next)
			{
				
				fwrite(student,Size,1,fp);
	            fclose(fp);
			}

fclose(fp);*/
		}
	}while(choice!=0);

return 0;
}
