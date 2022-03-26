#include <stdio.h>
#include<stdlib.h>
//定义结构
typedef struct note
{
	int data;
	struct note *next;

}node,*linkedlist;

//开始菜单
int menu() {
	int choice1=0;
	printf("************************\n");
	printf("        单链表ADT        \n");
	printf("1.创建空链表\n");
	printf("2.遍历链表  \n");
	printf("3.加入结点  \n");
	printf("4,删除结点  \n");
	printf("5.插入结点  \n");
	printf("6.销毁链表  \n");
	printf("7.奇偶调换  \n");
	printf("8.查找中点  \n");
	printf("9.退出      \n");
	printf("输入对应数字:\n");
	scanf("%d", &choice1);
	printf("************************\n");
	return choice1;
}


//判断输入
//int judge(int choice2) {
//	char word;
//	word =(char)choice2;
//
//	if (word < 49 || word > 57) {
//		printf("请输入表内整数:");
//
//	}
//}

//创建链表
int setuplist(linkedlist *L) {//定义二级指针*L
	linkedlist list;
	list = (linkedlist)malloc(sizeof(node));
	list->next = NULL;
	*L = list;//L为指向结构体指针的指针
			//(*L)为指向node结构体的指针！！！
	return 1;
}

//遍历链表
void traverlist(linkedlist L) {
	linkedlist r; 
	r = L->next;//让r指向链表L的指针部分
	while (r != NULL) {
		printf("\t%d\t", r->data);//输出数据
		r = r->next;//让r继续走
	}
	printf("\n遍历完成\n");
}

//加入结点
int addlist(node *p, int data) {
	linkedlist current = p;
	linkedlist new = (linkedlist)malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
	return 1;
}

//删除结点
int delete(linkedlist *L, int i, linkedlist *e) {
	int j = 1;
	linkedlist p, q;
	p = *L;
	if (p == NULL) {
		printf("\n链表为空，无法删除\n");
	}
	else {
		while (p->next && j < i) {
			p = p->next;
			++j;
		}
		if (!(p->next) || j > i) {
			printf("第i个元素不存在");
			return 0;//第i个元素不存在
		}
		q = p->next;
		p->next = q->next;
		e = q->data;
		free(q);
		return 1;
	}
}
//销毁链表
void destroy(linkedlist *L) 
{
	linkedlist r;
	while (*L != NULL) {
		r = *L;
		*L = (*L)->next;
		free(r);
	}
}
//插入结点
int insert(node *L, int i, int e) {
	int j;
	linkedlist p, s;
	p = L;
	j = 1;
	while (p&&j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)return 0;
	s = (linkedlist)malloc(sizeof(node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

int main(void) 
{
	int input = 0;
	int num=0;

	linkedlist head = NULL; 


	do
	{
		input = menu();
	/*	judge(input);*/
		switch (input) {
		case 1://创建链表
		{
			if (setuplist(&head))
 				printf("\n空链表创建成功\n");
			else
			{
				printf("\n空链表创建失败\n");
			}
			break;
		}
		case 2: //遍历链表
		{
			if (head == NULL || head->next == NULL) {
				printf("\n链表不存在\n");
			}
			else {
				traverlist(head);
			}
			break;
		}
		case 3: //加入结点
		{
			if (head == NULL) {
				printf("\n链表为空，请先创建链表\n");
			}
			else {
				printf("\n请输入数据:\n");
				scanf("%d", &num);
				if (addlist(head, num)) {
					printf("\n数据加入成功\n");

				}
				else {
					printf("\n数据加入失败\n");

				}
			}
			break;
		}
		case 4://删除结点
		{	if (head == NULL) {
			printf("\n链表为空，请先创建链表\n");
		}
		else {
			int *e = head;
			printf("\n请输入要删除的结点位置:\n");
			scanf("%d", &num);
			if (delete(&head, num, *e)) {
				printf("\n数据删除成功\n");

			}
			else {
				printf("\n数据删除失败\n");
			}
		}
			break;

		}
		case 5://插入结点
		{
			int i, e;
			if (head == NULL) {
				printf("\n链表为空，请先创建链表\n");
			}
			else 
			{
				printf("\n请输入要插入的结点位置:\n");
				scanf("%d", &i);
				printf("\n请输入要插入数字:\n");
				scanf("%d", &e);
				if (insert(head, i, e)) {
					printf("\n数据加入成功\n");

				}
				else {
					printf("\n数据加入失败\n");

				}
			
			}
			break;
		}
		case 6://销毁链表
		{
			destroy(&head);
			printf("\n链表销毁完成\n");
			break;
		}
		case 7://奇偶调换（还不会）
		{
			printf("\n这涉及到我的知识盲区了T_T，马上学！\n");
			break;
		}
		case 8://查找中点（还不会）
		{
			printf("\n这涉及到我的知识盲区了T_T，马上学！\n");
			break;
		}
		case 9://退出
		{
			destroy(&head);
			break;
		}
		default:{
			printf("\n请重新输入数字！（1-9）\n");
			break;
		}

		}

	/*	break;*/
	} while (input != 9);

	return 0;
}
