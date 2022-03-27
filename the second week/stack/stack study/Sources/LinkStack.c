#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h" 
//��ջ
//#ifndef STACK_H_INCLUDED
//#define STACK_H_INCLUDED


//��ʼ��ջ
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top) {
		return ERROR;
	}
	s->top->next=NULL;
	s->count = 0;
	return	SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){

	if (!s->top )//&& s->count==-1)
		return SUCCESS;
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType e){
	if (isEmptyLStack(s)) {
		printf("ջΪ��");
		return ERROR;				//�ж�ջ�Ƿ�Ϊ��
	}
	else {
		e = s->top->data;			//ջ��ֵ����e
		if(e!= -842150451)
		printf("ջ��Ԫ��Ϊ��%d", e);
		return e;
	}
}

//���ջ
Status clearLStack(LinkStack *s){
	if (isEmptyLStack(s))
		return ERROR;		//�ж�ջ�Ƿ�Ϊ��
	LinkStackPtr p;
	while (s->count!=0) {
		p = s->top;				//ջ����㸳ֵ��p
		s->top = s->top->next;	//ջ��ָ��top����һλ
		s->count--;
		free(p);				//ɾ����ջ

		printf("%d", s->count);	//�鿴count��ֵ
	}
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
	if (isEmptyLStack(s))
		return ERROR;		//�ж�ջ�Ƿ�Ϊ��
	LinkStackPtr p;
	while (s->top) {
		p = s->top;				//ջ����㸳ֵ��p
		s->top = s->top->next;	//ջ��ָ��top����һλ
		s->count--;
		free(p);				//ɾ����ջ
	}	

		s->top = NULL;
		s->count = -1;					//����ջ
	//	free(s);
		return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int length){
	if (isEmptyLStack(s))
		return ERROR;		//�ж�ջ�Ƿ�Ϊ��
	length = s->count;
	printf( "ջ����Ϊ%d",length);	//���ջ����
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
							//���ٿռ���½ڵ�
	p->data = data;			//���ݵ���
	p->next = s->top;		//��ԭջ��ָ�򸳸��½���next
	s->top = p;				//ջ��ָ��ָ���½ڵ�
	s->count++;				//������+1
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if (!s->top)
		return ERROR;		//�ж�ջ�Ƿ�Ϊ��
	LinkStackPtr p;
	data = s->top->data;
	p = s->top;				//ջ����㸳ֵ��p
	s->top = s->top->next;	//ջ��ָ��top����һλ
	free(p);				//ɾ����ջ
	s->count--;
	return SUCCESS;
}

/*����ջ������Ԫ��*/
Status StackTraverse(LinkStack *s)
{	
	if (isEmptyLStack(s))
			return ERROR;	
	LinkStackPtr p;
	ElemType e;
	p = s->top;
	printf("\nջ��Ԫ���У����Ϊջ������\n");
	while (p) {
		e = p->data;
		if (e!= -842150451) {
			//��ֹe����ָ�븳ֵ
			printf(" %d ", e);
		}
		p = p->next;
	}
	printf("\n");
	return SUCCESS;
}

//��ʼ�˵�
int menu() {
	int choice1 = 0;
	int choice2 = 0;
	printf("************************\n");
	printf("        ��ջ        \n");
	printf("1.��ʼ��ջ\n");
	printf("2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("3.�õ�ջ��Ԫ��\n");
	printf("4.���ջ \n");
	printf("5.����ջ  \n");
	printf("6.���ջ����  \n");
	printf("7.��ջ\n");
	printf("8.��ջ\n");
	printf("9.�˳�      \n");
	printf("************************\n");
	printf("�����Ӧ����:\n");
	scanf("%d", &choice1);
	////�����ж�
	//while (choice1 != '\n') {
	//	choice1 = getchar();
	//	if (choice1 == '\n') {
	//		choice2 = choice1;
	//		if (choice2 >= '1' && choice2 <= '9') {
	//			return choice2;
	//		}
	//		else {
	//			printf("��������ȷ���֣�1~9��");
	//		}
	//	}
	//}
	return choice1;
}

//#endif 
