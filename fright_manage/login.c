#include "vip.h"


/*--------------------航班部分--------------------*/
//创建航班信息的头节点
flight_info* flight_create()
{
	flight_info* h = (flight_info*)malloc(sizeof(flight_info));

	if (h == NULL)
	{
		printf("航班创建失败!\n");
		return NULL;
	}

	memset(h->start, 0, sizeof(h->start));
	memset(h->destination, 0, sizeof(h->destination));
	memset(h->data, 0, sizeof(h->data)); 

	h->next = NULL;
	return h;
}

//增加航班信息
int  flight_add(flight_info* f)
{
	flight_info* new = (flight_info*)malloc(sizeof(flight_info));

	if (new == NULL)
	{
		printf("增加失败！\n");
		return 0;
	}

	int i = 0;
	char c = 0;
	char str[MAXSIZE_START] = {0};
	float price = 0;
	char class[MAXSIZE_CLASS]={'F', 'B', 'E'};

	for (i=0; i<MAXSIZE_CLASS; i++)
	{
		printf("输入%d等舱的价格(按头等舱、商务舱、经济舱的顺序)>", i+1);
		scanf("%f", &price);
		new->price[i]=price;
	}

	for (i=0; i<MAXSIZE_CLASS; i++)
	{
		new->class[i]=class[i];
	}

	printf("输入班次>");
	scanf("%d", &i);
	new->flight_frequency = i;

	while (getchar()!='\n');
	printf("输入起点>");
	scanf("%[^\n]", str);
	while (getchar()!='\n');
	strcpy(new->start, str);

	memset(str, 0, sizeof(str));

	printf("输入终点>");
	scanf("%[^\n]", str);
	while (getchar()!='\n');
	strcpy(new->destination, str);

	memset(str, 0, sizeof(str));

	printf("输入日期>");
	scanf("%[^\n]", str);
	while (getchar()!='\n');
	strcpy(new->data, str);	
    
	flight_info* p = NULL;

	for (p = f; p->next != NULL; p=p->next);

	new->next = p->next;
	p->next = new;

	return 1;

}


//航班信息自动添加
int  flight_auto_add(flight_info* f, float F, float B, float E, 
	int flight_frequency, char* start, char* destination, char* data)
{
	flight_info* new = (flight_info*)malloc(sizeof(flight_info));

	if (new == NULL)
	{
		printf("增加失败！\n");
		return 0;
	}

	char class[MAXSIZE_CLASS]={'F', 'B', 'E'};

	new->flight_frequency = flight_frequency;

	strcpy(new->start, start);
	strcpy(new->destination, destination);
	strcpy(new->data, data);

	new->price[0]=F;
	new->price[1]=B;
	new->price[2]=E;


	new->class[0] = class[0];
	new->class[1] = class[1];
	new->class[2] = class[2];

    
	flight_info* p = NULL;

	for (p = f; p->next != NULL; p=p->next);

	new->next = p->next;
	p->next = new;

	FlightFrequency++;

	return 1;

}


//打印航班信息
void flight_print(flight_info* f)
{
	flight_info* p = NULL;
	int i=0;

	printf("班次\t起点\t终点\t\t日期\t\t舱位类型及价格\n");
	for (p = f->next; p != NULL; p=p->next)
	{
		printf("%d\t%s\t%s\t%s\t", 
			p->flight_frequency, p->start, p->destination,
			p->data);

		for (i=0; i<MAXSIZE_CLASS; i++)
		{
			printf("%c\t", p->class[i]);
		}
		printf("\n\t\t\t\t\t\t");
		for (i=0; i<MAXSIZE_CLASS; i++)
		{
			printf("%.2f\t", p->price[i]);
		}

		printf("\n");
	}
}









/*--------------------用户部分--------------------*/



user* user_create(void)
{
    user* head = (user*)malloc(sizeof(user));
    if (head == NULL)
    {
    	printf("创建失败!\n");
    	return NULL;
    }

    memset(head->id, 0, sizeof(head->id));
    memset(head->pw, 0, sizeof(head->pw));
    head->next=NULL;
    head->flag=0;
    return head;
}

//尾插法新增用户
//h为用户数据库, id为新增账号, pw为新增密码, 
//flag区分普通用户、会员、管理员、
int user_TailAdd(p_user h, char* id, char* pw, int flag)
{
	user* new = (user*)malloc(sizeof(user));
	if (new == NULL)
	{
		printf("新账号创建失败!\n");
		return 0;
	}

	user* p = NULL;
	for (p=h; p->next!=NULL; p=p->next);
    
    new->next = p->next;
    p->next = new;
    strcpy(new->id, id);
    strcpy(new->pw, pw);
    new->flag=flag;

    printf("添加成功!\n");
    return 1;
}


//隐藏用户输入的密码
char* hide_password(char* pw)
{
	char c=0;
	int i=0;
	system("stty -echo");
	while (1)
	{
		c = getchar();
        if (c == '\n' 
        	|| c == '\r')
        {
        	break;
        }
        putchar('*');
        pw[i++] = c;
	}

	pw[i] = '\0';
	printf("\n%s\n\n\n", pw);
	system("stty echo");
	return pw;
}

//登录情况打印
int login_print(int flag, p_user p)
{
	if (flag == 0 || p == NULL)
	{
        printf("信息有误！\n");
        return 0;
	}
	else
	{
		// system("clear");
		printf("登入成功！\n");
		switch (p->flag)
		{
			case 2:
				printf("用户,您好！\n");
				return 2;
			case 1:
				printf("会员,您好！\n");
				return 1;
			case 0:
				printf("welcome to coming, master!\n");
				return 0;
		}	
	
	}
}

//登录信息校验
int compare_IdAndPw(p_user h, char* id, char* pw)
{
	user* p=h;
	int flag=0;

	for (p=h->next; p!= NULL; p=p->next)
	{
		if (!strcmp(p->id, id)
			&& !strcmp(p->pw, pw))
		{
			flag = 1;
			break;
		}
	}

	return login_print( flag, p);
}


//用户登录
int user_login(p_user person)
{
	int i=3;
	char id[MAXSIZE_ID]={0};
	char pw[MAXSIZE_PW]={0};

	while (i--)
	{
		memset(id, 0, sizeof(id));
		memset(pw, 0, sizeof(pw));

		//system("clear");
		printf("请输入账号>\n");
		scanf("%[^\n]", id);
		while (getchar()!='\n');

		printf("请输入密码>\n");
		hide_password( pw);

		int ret = compare_IdAndPw( person, id, pw) ;
        if (ret)
        {
        	return ret;
        }

        //system("clear");

        if (i != 0)
        {
        	printf("还有%d次输入机会\n\n", i);
        }
        else
        {
        	printf("次数用尽,登录失败!\n");
        }
	}

}

int ManageSystem()
{
//用户信息库
	//flag=2代表该结构体信息为普通用户等级信息(普通,VIP,管理员)
	user* person = user_create();
	user_TailAdd(person, "111", "111", 2);

	//flag=1代表该结构体信息为会员信息
	user_TailAdd(person, "222", "222", 1);

	//flag=0代表该结构体信息为管理员信息
	user_TailAdd(person, "333", "333", 0);


//航班信息库
	//创建航班信息
	flight_info* f = flight_create();

//程序内部,手动定义两个航班
	flight_auto_add( f, 789, 456, 123, 1, "wuhan", "shanghai", "23/02/18");
	flight_auto_add( f, 789, 456, 123, 2, "wuhan", "beijing ", "23/02/19");

	system("clear");

	// flight_add( f); //管理员添加航班
	// flight_print( f);  //打印航班信息

//建立用户隐私库
	userinfo* u = userinfo_create();

	switch (user_login(person))
	{
		case 0:
	    	administrator(person);
	    	break;
	    case 1:
	    	vip( u, f);	
	    	break;	
	    case 2:
	    	common( u, f);
	    	break;
	}


    return 1;
}