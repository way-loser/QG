# QG训练营学习笔记

## 第一周周记

******



### 第一天3.18

QG大小组培训，回来先发布班级作业推文，完成了部分作业，下载好了typora，阅读本周任务

*****



### 第二天3.19

学习typora热键，





《大话数据结构》书本已到，确认目标：书本p84

1，链表学习
尾插法建立单链表（翁恺）

```c
//建立结构
typedef struct note
{
	int data;
	struct note *next;
}node;
//建立链表
int main() {
	int number;

	node *head = NULL;//初始化head

	do{
		scanf("%d", &number);
		if (number != -1) {
			node *p = (node*)malloc(sizeof(node));//动态分配内存
			p->data=number;
			p->next=NULL;
			node *last = head;//从头遍历，从head走到p所指向的上一个数据的next
			if (last) {
				while (last->next)
					last = last->next;//遍历
				last->next = p;//遍历结束，将此时p所指向的赋给next，使其连接
			}
			else {
				head = p;//开始时head要指向第一个数据
			}
		}
	} while (number != -1);
	return 0;
}
```

研读了CSDN中关于[单链表](https://so.csdn.net/so/search?q=单链表&spm=1001.2101.3001.7020)ADT和双链表ADT

模仿了[单链表ADT和双链表ADT](https://blog.csdn.net/weixin_45824303/article/details/105273820?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164769330316780271550106%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164769330316780271550106&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-105273820.142^v2^pc_search_result_control_group,143^v4^control&utm_term=%E5%8D%95%E9%93%BE%E8%A1%A8ADT&spm=1018.2226.3001.4187)中的思路



学会了创建链表

完成空链表的创建

****



### 第三天3.20

开始学习链表的功能，

看着CSDN里的学写了一早上代码，发现自己连输入判断都不会自己写。。。。

尝试写入各功能

```c
*L=(*L)->next
```

卡了我半个钟。。。

下午没太阳去打球，练习了全场跑位及站位防守，预期目标在班赛中打进10分



晚上回来继续

单链表插入标准语句 

```
s->next=p->next;
p->next=s;
```

