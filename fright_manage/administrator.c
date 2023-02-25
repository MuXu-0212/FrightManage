#include "vip.h"

//打印-
void print_(int num)
{
	for (int i=0; i<num; i++)
		printf("-");
	printf("\n");
}

//管理员操作界面
void admi_menu()
{
	// system("clear");
	print_(80);
	printf("\t   administrator\n");
	printf("\t1. increase new user\n");
	printf("\t2. delete a user\n");
	printf("\t3. revise user's information\n");
	printf("\t4. find user's information\n");
	printf("\t0. exit system\n");
	print_(80);

}

//管理员“添加”功能的菜单
void admi_add_menu() 
{
	print_(80);
	printf("\t   increase menu\n");
	printf("\t0. increase new administrator\n");
	printf("\t1. increase new common user\n");
	printf("\t2. increase new vip user\n");
	printf("\t3. exit add\n");
	print_(80);
}

//管理员添加用户，flag为用户级别
int admi_add_user(p_user h, int flag)
{
	user* new = (user*)malloc(sizeof(user));
	if (new == NULL)
	{
		printf("create by default!\n");
		return 0;
	}

	while (getchar()!='\n');

	char id[MAXSIZE_ID]={0};
	char pw[MAXSIZE_PW]={0};

	printf("input new id>");
	scanf("%[^\n]", id);
	while (getchar()!='\n');

	printf("input new pw>");
	scanf("%[^\n]", pw);
	while (getchar()!='\n');

	user* p=h;
	for (p=h; p->next != NULL; p=p->next);

	new->flag = flag;
	strcpy(new->id, id);
	strcpy(new->pw, pw);

	new->next = p->next;
	p->next = new;

	return 1;
}

//管理员添加功能
int admi_add(p_user h)
{
	int input=0;
	while (1)
	{
		// system("clear");
		printf("\n");
		admi_add_menu();
		printf("master, select a option>");
		scanf("%d", &input);

		if (input == 3)		//input=0为退出该选项
		{
			system("clear");
			return 1;
		}

		if (input == 0)
		{
			admi_add_user( h, input);
		}
		else if (input == 1)
		{
			admi_add_user( h, input);
		}else if(input == 2)
		{
			admi_add_user( h, input);
		}
		
		if (input >=0 && input <=2)
		{
			system("clear");
			printf("increase successfully!\n");
		}
		else
		{
			while (1)
			{
				printf("is keping to increase a new user?\n");
				printf("1.yes  2.no\n");
				scanf("%d", &input);
				if (input == 1)
				{
					break;
				}
				else if (input == 2)
				{
					return 1;
				}
				else
				{
					printf("input error, trying again!\n");
				}
			}
		}
	}
}

//删除用户功能
int admi_delete(p_user h)
{
	int flag=0;
	if (h->next == NULL)
	{
		printf("there have no information!\n");
		return 0;
	}

	char id[MAXSIZE_ID]={0};
	while (getchar()!='\n');

	while (1)
	{
		memset(id, 0, sizeof(id));
		printf("\ndelete user\n");
		printf("master, input user'id>");
		scanf("%[^\n]", id);
		while (getchar()!='\n');

		user* p=NULL;
		//遍历链表,找到需要删除的账号
		for (p=h; p->next->next!=NULL; p=p->next)
		{
			if ( !strcmp(p->next->id, id) )
			{
				flag=1;
				break;
			}
		} /*for (p=h; p->next->next!=NULL; p=p->next)*/

		if (flag)
		{
			user* temp = p->next;
			p->next = temp->next;
			free(temp);
			printf("remove succefully!\n\n");
			return 1;		
		}
		else
		{
			printf("error, input again!\n\n");
		}
	}
}

//管理员修改菜单
void admi_revise_menu()
{
	printf("\n");
	print_(80);
	printf("\t     revise menu\n");
	printf("\t1. adjust user's grade\n");
	printf("\t2. find user's information\n");
	printf("\t0. return to administrator\n");
	print_(80);
}

//管理员调整用户等级的菜单
void admi_revise_adjust_menu(char* str)
{
	print_(80);
	printf("\t    adjust user(%s)'grade\n", str);
	printf("\t0. to becomem administrator\n");
	printf("\t1. to become vip\n");
	printf("\t2. to become common\n");
	printf("\t3. return\n");
	print_(80);
}

//校验账号
int admi_revise_adjust_IdCompare(p_user h)
{
	getchar();
	char id[MAXSIZE_ID]={0};
	printf("input id that needs to be adjusted>");
	scanf("%[^\n]", id);
	while (getchar()!='\n');

	int input=0;
	user* p = h;
	while (p->next != NULL)
	{
		if (!strcmp(p->id, id))
		{
			admi_revise_adjust_menu(id);
			printf("master, select a option>");
			scanf("%d", &input);
			if (input >=0 && input <=2) /*0、1、2分别代表三个等级的用户*/
			{
				p->flag = input;
				system("clear");
				printf("master, this user'grade is revised!\n");
				return 0;
			} 
			else /*非法输入*/
			{
				printf("id doesn't matched!\n");
				printf("input again!\n\n");
				return 1;				
			}
		} /*if (!strcmp(p->id, id)) 账号匹配*/
		p=p->next;
	}
	printf("id doesn't matched!\n");
	printf("input again!\n\n");
	return 1;
}

//管理员调整用户等级的功能
int admi_revise_adjust(p_user h)
{
	int input=0;
	int ret = 1;

	while (ret)
	{
		ret = admi_revise_adjust_IdCompare( h);
	}
}

//账号信息查询
int admi_revise_find(p_user h)
{
	if (h->next == NULL)
	{
		printf("NULL！\n");
		return 1;
	}

	user* p = NULL;
	int i=0,j=0,k=0;
	int input=0;
	system("clear");

	print_(80);
	printf("grade\t\tid\t\tpw\t\t\n");

	p = h->next;
    while (p != NULL)
    {
    	if (p->flag == 0)
    	{
    		printf("master_%d\t%s\t\t%s\n", i+1, p->id, p->pw);
    		i++;
    	}
    	p=p->next;
    }

	p = h->next;
    while (p != NULL)
    {
    	if (p->flag == 1)
    	{
    		printf("vip_%d\t\t%s\t\t%s\n", j+1, p->id, p->pw);
    		j++;
    	}
    	p=p->next;
    }

    p = h->next;
    while (p != NULL)
    {
    	if (p->flag == 2)
    	{
    		printf("common_%d\t%s\t\t%s\n", k+1, p->id, p->pw);
    		k++;
    	}
    	p=p->next;
    }

	print_(80);

	while (1)
	{
		printf("1. exit\n");
		printf("input>");
		scanf("%d", &input);
		if (input == 1)
		{
			system("clear");
			return 1;
		}
		else
		{
			printf("master, error,input again!\n");
		}		
	}
    system("clear");
}



//管理员"修改"选择界面
int admi_revise(p_user h)
{
	int input = 0;
	while (1)
	{
		admi_revise_menu();
		printf("master, select a option>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				admi_revise_adjust( h);
				break;
			case 2:
				admi_revise_find( h);
				break;
			case 0:
				return 0;
			default:
				system("clear");
				printf("input error!\n");
				break;
		}
	}

}

//管理员模块
int administrator(p_user h)
{
	int input=0;
	while (1)
	{
		admi_menu();
		printf("master, select a option>");
		scanf("%d", &input);
		
		switch (input)
		{
			case 1:
				admi_add( h);
				break;
			case 2:
				admi_delete( h);
				break;
			case 3:
				admi_revise( h);
				break;
			case 4:
				admi_revise_find( h);
				break;
			case 0:
				system("clear");
				return 1;
			default:
				printf("input error!\n\n");
				break;
		}
	}
}


