#ifndef __login_h_
#define __login_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE_ID 30
#define MAXSIZE_PW 30

#define MAXSIZE_START 30	//航班起点
#define MAXSIZE_DESTINATION 30	//航班终点
#define MAXSIZE_DATA 30		//日期
#define MAXSIZE_CLASS 3	    //座舱类型


int FlightFrequency; //班次

/*账号登录信息结构体*/
typedef struct user{
	char id[MAXSIZE_ID];
	char pw[MAXSIZE_PW];
	int flag; /*有三个值,0为管理员,1为会员,2为普通用户*/
	struct user* next;
}user,* p_user;

/*航班信息结构体*/
typedef struct flight_info
{
	int flight_frequency;	//班次
	char start[MAXSIZE_START]; //起点
	char destination[MAXSIZE_DESTINATION]; //终点
	char data[MAXSIZE_DATA]; //日期
	float price[3]; //三种价格
	char class[MAXSIZE_CLASS];/*舱位类型,头等舱F(First Class), 
					    商务舱B(Bussiness Class),
					    经济舱E经济舱(Economy Class or Coach)*/
	struct flight_info* next; 
}flight_info, *p_flight;

/*用户信息结构体*/
typedef struct userinfo{
	int flight_frequency;	//班次
	int strick_num;	//订购数量
	char start[MAXSIZE_START]; //起点
	char destination[MAXSIZE_DESTINATION]; //终点
	char data[MAXSIZE_DATA]; //日期
	float price; //三种价格
	int flag; //0为普通用户, 1为VIP用户
	char c; /*舱位类型,头等舱F(First Class), 
					    商务舱B(Bussiness Class),
					    经济舱E(Economy Class or Coach)*/	
	struct userinfo* next; 
}userinfo,* p_userinfo;

/*--------------------航班部分--------------------*/
extern flight_info* flight_create(); //创建航班信息的头节点
extern int flight_add(flight_info* f); //增加航班信息
extern void flight_print(flight_info* f); //打印航班信息

//航班信息自动添加  //程序内部,手动定义两个航班
extern int  flight_auto_add(flight_info* f, float F, float B, float E, 
 int flight_frequency, char* start, char* destination, char* data);



/*--------------------用户部分--------------------*/

extern user* user_create(void); //创建账号信息
extern userinfo* userinfo_create(); //创建用户信息

//尾插法新增用户
extern int user_TailAdd(p_user h, char* id, char* pw, int flag); 


extern char* hide_password(char* pw); //隐藏用户输入的密码
extern int login_print(int flag, p_user p);//登录情况打印
extern int compare_IdAndPw(p_user h, char* id, char* pw);//登录信息校验

extern int user_login(p_user person);//用户登录

extern int ManageSystem();


#endif