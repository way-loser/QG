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
		case 1://初始化栈
		{
			if (initLStack(s))
				printf("\n初始化栈成功\n");
			else
			{
				printf("\n初始化栈失败\n");
			}
			break;
		}
		case 2: //判断栈是否为空
		{
			if (isEmptyLStack(s)) {
				printf("\n栈不存在\n");
			}
			else {
				printf("\n栈存在\n");
			}
			break;
		}
		case 3: //得到栈顶元素
		{
			getTopLStack(s, e);
			break;
		}
		case 4://清空栈
		{	
			if (clearLStack(s))
				printf("\n栈清空成功\n");
			else
				printf("\n栈为空\n");
			break;

		}
		case 5://销毁栈
		{
			if (destroyLStack(s)){
				printf("\n栈销毁成功\n");
			}
			else {
				printf("\n栈为空\n");
			}

			break;
		}
		case 6://检测栈长度
		{
			if (LStackLength(s, length));
			else("\n栈为空\n");
			break;
		}
		case 7://入栈
		{	
			printf("输入入栈数字：");
			scanf("%d", &data);
			if (pushLStack(s,  data))
			printf("\n入栈成功\n");
			else
			printf("\n栈为空\n");
			break;
		}
		case 8://出栈
		{	
			if (popLStack(s,data))
			printf("\n出栈成功\n");
			else
			printf("\n栈为空\n");
			break;
		}
		case 9://退出
		{
			destroyLStack(s);
			break;
		}
		default: {
			printf("\n请重新输入数字！（1-9）\n");
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