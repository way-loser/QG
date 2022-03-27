#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h" 
//链栈
//#ifndef STACK_H_INCLUDED
//#define STACK_H_INCLUDED


//初始化栈
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top) {
		return ERROR;
	}
	s->top->next=NULL;
	s->count = 0;
	return	SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){

	if (!s->top )//&& s->count==-1)
		return SUCCESS;
	else
		return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType e){
	if (isEmptyLStack(s)) {
		printf("栈为空");
		return ERROR;				//判断栈是否为空
	}
	else {
		e = s->top->data;			//栈顶值赋给e
		if(e!= -842150451)
		printf("栈顶元素为：%d", e);
		return e;
	}
}

//清空栈
Status clearLStack(LinkStack *s){
	if (isEmptyLStack(s))
		return ERROR;		//判断栈是否为空
	LinkStackPtr p;
	while (s->count!=0) {
		p = s->top;				//栈顶结点赋值给p
		s->top = s->top->next;	//栈顶指针top后移一位
		s->count--;
		free(p);				//删除出栈

		printf("%d", s->count);	//查看count的值
	}
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s){
	if (isEmptyLStack(s))
		return ERROR;		//判断栈是否为空
	LinkStackPtr p;
	while (s->top) {
		p = s->top;				//栈顶结点赋值给p
		s->top = s->top->next;	//栈顶指针top后移一位
		s->count--;
		free(p);				//删除出栈
	}	

		s->top = NULL;
		s->count = -1;					//销毁栈
	//	free(s);
		return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int length){
	if (isEmptyLStack(s))
		return ERROR;		//判断栈是否为空
	length = s->count;
	printf( "栈长度为%d",length);	//输出栈长度
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
							//开辟空间给新节点
	p->data = data;			//数据导入
	p->next = s->top;		//将原栈顶指向赋给新结点的next
	s->top = p;				//栈顶指针指向新节点
	s->count++;				//计数器+1
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if (!s->top)
		return ERROR;		//判断栈是否为空
	LinkStackPtr p;
	data = s->top->data;
	p = s->top;				//栈顶结点赋值给p
	s->top = s->top->next;	//栈顶指针top后移一位
	free(p);				//删除出栈
	s->count--;
	return SUCCESS;
}

/*遍历栈中所有元素*/
Status StackTraverse(LinkStack *s)
{	
	if (isEmptyLStack(s))
			return ERROR;	
	LinkStackPtr p;
	ElemType e;
	p = s->top;
	printf("\n栈中元素有（左边为栈顶）：\n");
	while (p) {
		e = p->data;
		if (e!= -842150451) {
			//防止e被空指针赋值
			printf(" %d ", e);
		}
		p = p->next;
	}
	printf("\n");
	return SUCCESS;
}

//开始菜单
int menu() {
	int choice1 = 0;
	int choice2 = 0;
	printf("************************\n");
	printf("        链栈        \n");
	printf("1.初始化栈\n");
	printf("2.判断栈是否为空\n");
	printf("3.得到栈顶元素\n");
	printf("4.清空栈 \n");
	printf("5.销毁栈  \n");
	printf("6.检测栈长度  \n");
	printf("7.入栈\n");
	printf("8.出栈\n");
	printf("9.退出      \n");
	printf("************************\n");
	printf("输入对应数字:\n");
	scanf("%d", &choice1);
	////输入判断
	//while (choice1 != '\n') {
	//	choice1 = getchar();
	//	if (choice1 == '\n') {
	//		choice2 = choice1;
	//		if (choice2 >= '1' && choice2 <= '9') {
	//			return choice2;
	//		}
	//		else {
	//			printf("请输入正确数字（1~9）");
	//		}
	//	}
	//}
	return choice1;
}

//#endif 
