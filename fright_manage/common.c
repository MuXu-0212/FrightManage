#include "vip.h"

//创建用户信息
userinfo* userinfo_create()
{
	userinfo* h = (userinfo*)malloc(sizeof(userinfo));

	if (h == NULL)
	{
		printf("普通用户信息创建失败!\n");
		return NULL;
	}
	h->next = NULL;

	return h;
}

//用户订票
int com_buy_strick(p_userinfo u, p_flight f, int flight_frequency)
{
	fflush(stdin);
	char input = 0;
	userinfo* new = (userinfo*)malloc(sizeof(userinfo));

	if (new == NULL)
	{
		printf("新订单创建失败!\n");
		return 0;
	}
	new->next = NULL;

	userinfo* p = NULL;
	for (p=u; p->next!=NULL; p=p->next);

	new->next = p->next;
	p->next = new;

	flight_info* q = NULL;

	for (q = f; q != NULL; q=q->next)
	{
		// printf("22222\n");
		// printf("flight_frequency:%d\n", q->flight_frequency);
		if (q->flight_frequency == flight_frequency)
		{
			// printf("%d\n", flight_frequency);
			new->flight_frequency = q->flight_frequency;
			strcpy(new->start, q->start);
			// printf("%s\n", u->start);
			strcpy(new->destination, q->destination);
			strcpy(new->data, q->data);
			new->strick_num++;

			while (1)
			{
				while (getchar()!='\n');
				printf("请选择舱位类型(头等舱为'f', 商务舱为'b', 经济舱为'e')>");
				scanf("%c", &input);
				//while (getchar()!='\n');
				// printf("11111\n");
				if (input == 'f' )
				{
					printf("该选项为VIP特有!\n");
				}
				else if (input == 'b' )
				{
					new->price = q->price[1];
					new->c = input;
					printf("购票成功!\n");
					break;
				}
				else if ( input == 'e')
				{
					new->price = q->price[2];
					new->c = input;
					printf("购票成功!\n");
					break;
				}
				else
				{
					// printf("inp0ut = a%ca\n", input);
					printf("\n\n输入错误, 请重新选择!\n");
				}
			} /*while(1)*/
		} /*if (q->flight_frequency == flight_frequency)*/
	} /*for (q = f; q->next != NULL; q=q->next)*/

	// printf("333333\n");
	return 0;
}

//连续购票
int com_buy_strick_continue(p_userinfo u, p_flight f, int flight_frequency)
{
	int input=0;
	com_buy_strick( u, f, flight_frequency);
	while (1)
	{
		printf("\n\n1.继续购票  0.退出\n");
		printf(">");
		scanf("%d", &input);
		if (input == 1 )
		{
			p_userinfo p = NULL;
			for (p=u; p->next!=NULL; p=p->next);
			p->strick_num = p->strick_num + 1;
		}
		else if (input == 0)
		{
			system("clear");
			return 1;
		}
		else
		{
			printf("输入错误,请重试!\n");
		}
	}

}



//用户购票功能
int com_buy(p_userinfo u, p_flight f)
{
	system("clear");
	int input = 0;

	p_flight p = NULL;
	for (p=f; p->next!=NULL; p=p->next); 

	while (1)
	{
		flight_print( f);  //打印航班信息, 该函数的声明定义在login文件;
		printf("请选择航班班次>");
		scanf("%d", &input);
		// printf("打印%d\n", input);
		for (int i=1; i<=p->flight_frequency; i++)
		{
			if (input == i)
			{
				com_buy_strick_continue( u, f, i);
				return 1;
			}
		}
		printf("选择错误,重新输入!\n\n");
	}	//while (1);

}

//查看功能
int com_find(p_userinfo u)
{
	int input = 0;
	userinfo* p = u;
	printf("班次\t数量\t起点\t\t终点\t\t日期\t\t价格\t舱位类型\n");
	for (p=u->next; p!=NULL; p=p->next)
	{
		printf("%d\t%d\t%s\t\t%s\t%s\t%.2f\t%c\n"
			, p->flight_frequency, p->strick_num, p->start, p->destination
			, p->data, p->price, p->c
			);
	}

	if (u->next == NULL)
	{
		print_(80);
		printf("暂无消息！\n");
		print_(80);
	}


	while (1)
	{
		print_(80);
		printf("0.退出\n>");
		scanf("%d", &input);
		if (input == 0)
		{
			system("clear");
			return 1;
		}
		printf("\n\n输入错误,请重试!\n");
	}
}

//修改个人信息的菜单
void com_revise_menu()
{
	print_(80);
	printf("\t\t 修改信息\n");
	printf("\t\t1.修改票数\n");
	printf("\t经费有限,2、3选项未开发\n");
	printf("\t\t2.改签(日期)\n");
	printf("\t\t3.改舱位\n");
	printf("\t\t0.退出\n");
	print_(80);
}

//用户修改票数功能
int com_revise_strick(p_userinfo u)
{
	if (u->next == NULL)
	{
		printf("\n\n表空!\n\n");
		return 0;
	}
	int input = 0;	//班次
	int flag = 0;
	userinfo* p = u;

	while (1)
	{
		printf("请选择班次>");
		scanf("%d", &input);
		while (getchar()!='\n');

		if (p->next->next==NULL)
		{
			flag = 1;
		}
		for ( p=u; p->next->next!=NULL; p=p->next)
		{
			// printf("111111\n");
			if (input == p->next->flight_frequency)
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			break;
		}
		else
		{
			printf("\n\n输入错误,请重试!\n");
		}
	}	/*while (1)*/

	while (1)
	{
		// fflush(stdin);
		// printf("\n\n");
		printf("班次\t数量\t起点\t\t终点\t\t日期\t\t价格\t舱位类型\n");
		printf("%d\t%d\t%s\t\t%s\t%s\t%.2f\t%c\n"
			, p->next->flight_frequency, p->next->strick_num, p->next->start, p->next->destination
			, p->next->data, p->next->price, p->next->c);
		printf("请输入票数(普通用户最多买5张票, vip最多20张票)>");
		int strick = 0;
		scanf("%d", &strick);

		if (strick <= 5 && strick>=1)
		{
			p->next->strick_num = strick;
			printf("\n\n");
			printf("班次\t数量\t起点\t\t终点\t\t日期\t\t价格\t舱位类型\n");
			printf("%d\t%d\t%s\t\t%s\t%s\t%.2f\t%c\n"
				, p->next->flight_frequency, p->next->strick_num, p->next->start, p->next->destination
				, p->next->data, p->next->price, p->next->c);
			return 1;
		}
		else if (strick == 0)
		{
			p->strick_num = strick;
			printf("\n\n");
			printf("班次\t数量\t起点\t\t终点\t\t日期\t\t价格\t舱位类型\n");
			printf("%d\t%d\t%s\t\t%s\t%s\t%.2f\t%c\n"
				, p->next->flight_frequency, p->next->strick_num, p->next->start, p->next->destination
				, p->next->data, p->next->price, p->next->c);

			userinfo* temp = p->next;
			p->next = temp->next;
			free(temp);
			printf("删除完毕!\n");
			
			return 1;
		}
		else
		{
			printf("输入错误,请重试!\n");
		}

	} /* while (1)*/

	return 1;
}


//修改个人信息功能
int com_revise(p_userinfo u)
{
	system("clear");
	int input = 0;

	while (1) 
	{
		com_revise_menu();
		printf("用户,请输入操作>");
		scanf("%d", &input);

		switch (input)
		{
			case 1:
				com_revise_strick( u);
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
			system("clear");
				return 1;
			default :
				printf("输入错误,请重试!\n");
		}		
	}

}

//用户删除历史信息功能(测试一,不用管)
// int com_delete(p_userinfo u)
// {
// 	if (u->next == NULL)
// 	{
// 		printf("信息为空!\n");
// 		return 0;
// 	}

// 	int input=0, flag=0;
// 	userinfo* p = NULL;

// 	while (1)
// 	{
// 		printf("\n\n");
// 		com_find( u);
// 		printf("请选择要删除的班次(0为退出)>");
// 		scanf("%d", &input);

// 		if (input == 0)
// 		{
// 			return 1;
// 		}

// 		if (p->next->next == NULL)
// 		{
// 			flag = 1;
// 		}
// 		else
// 		{
// 			for (p=u; p->next->next!=NULL; p=p->next)
// 			{
// 				if (input == p->next->flight_frequency)
// 				{
// 					flag = 1;
// 					break;
// 				}
// 			}			
// 		}


// 		if (flag)
// 		{
// 			break;
// 		}
// 		else
// 		{
// 			printf("重新输入!\n");
// 		}
// 	} /* while (1)*/

// 	userinfo* temp = p->next;
// 	p->next = temp->next;
// 	free(temp);
// 	printf("删除完毕!\n");
// 	return 1;
// }

//用户删除历史信息功能
int com_delete(p_userinfo u)
{
	if (u->next == NULL)
	{
		printf("表空！\n");
		return 0;
	}

	userinfo* temp = u;
	while (u->next != NULL)
	{
        temp = u->next;
        u->next = temp->next;
        free(temp); 
	}
	printf("删除完毕！\n\n");
	return 1;
}


//用户界面
int com_menu()
{
	print_(80);
	printf("\t   用户界面\n");
	printf("\t1. 购票\n");
	printf("\t2. 查看个人信息\n");
	printf("\t3. 修改个人信息\n");
	printf("\t4. 删除历史信息\n");
	printf("\t0. 退出登录\n");
	print_(80);
}


int common(p_userinfo u, p_flight f)
{
	int input=0;
	while (1)
	{
		com_menu();
		printf("用户,请选择操作>");
		scanf("%d", &input);
		
		switch (input)
		{
			case 1:
				com_buy( u, f);
				break;
			case 2:
				com_find( u);
				break;
			case 3:
				com_revise( u);
				break;
			case 4:
				com_delete( u);
				break;
			case 0:
				return 1;
			default:
				printf("选择错误, 重来!\n\n");
				break;
		}
	}
}