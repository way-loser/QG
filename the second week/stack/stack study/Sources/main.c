#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"


int main() {
	int input = 0;
	ElemType *length = 0;
	ElemType data = 0;
	ElemType* e = 0;
	LinkStack *s;
	s= (LinkStackPtr)malloc(sizeof(StackNode));
	s->top = NULL;
	s->count = -1;
	do
	{
		printf("\n\n");
		StackTraverse(s);
		input = menu();
		switch (input) {
		case 1://��ʼ��ջ
		{
			if (initLStack(s))
				printf("\n��ʼ��ջ�ɹ�\n");
			else
			{
				printf("\n��ʼ��ջʧ��\n");
			}
			break;
		}
		case 2: //�ж�ջ�Ƿ�Ϊ��
		{
			if (isEmptyLStack(s)) {
				printf("\nջ������\n");
			}
			else {
				printf("\nջ����\n");
			}
			break;
		}
		case 3: //�õ�ջ��Ԫ��
		{
			getTopLStack(s, e);
			break;
		}
		case 4://���ջ
		{	
			if (clearLStack(s))
				printf("\nջ��ճɹ�\n");
			else
				printf("\nջΪ��\n");
			break;

		}
		case 5://����ջ
		{
			if (destroyLStack(s)){
				printf("\nջ���ٳɹ�\n");
			}
			else {
				printf("\nջΪ��\n");
			}

			break;
		}
		case 6://���ջ����
		{
			if (LStackLength(s, length));
			else("\nջΪ��\n");
			break;
		}
		case 7://��ջ
		{	
			printf("������ջ���֣�");
			scanf("%d", &data);
			if (pushLStack(s,  data))
			printf("\n��ջ�ɹ�\n");
			else
			printf("\nջΪ��\n");
			break;
		}
		case 8://��ջ
		{	
			if (popLStack(s,data))
			printf("\n��ջ�ɹ�\n");
			else
			printf("\nջΪ��\n");
			break;
		}
		case 9://�˳�
		{
			destroyLStack(s);
			break;
		}
		default: {
			printf("\n�������������֣���1-9��\n");
			break;
		}

		}

		/*	break;*/
	} while (input != 9);
	char c;
	c = getchar();
	system("cls");
	return 0;
}