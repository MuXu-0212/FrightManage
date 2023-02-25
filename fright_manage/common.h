#ifndef __common_h_
#define __common_h_

#include "administrator.h"

#define MAXSIZE_START 30
#define MAXSIZE_DESTINATION 30
#define MAXSIZE_DATA 30

extern userinfo* userinfo_create(); ////创建用户信息

extern int com_buy(p_userinfo u, p_flight f); //用户购票功能
extern int com_find(p_userinfo u); //用户查看功能


extern int com_buy_strick(p_userinfo u, p_flight f \
	, int flight_frequency); //用户订票
extern int com_buy_strick_continue(p_userinfo u, p_flight f \
	, int flight_frequency);//连续购票

extern void com_revise_menu();//修改个人信息的菜单
extern int com_revise(p_userinfo u); //用户修改个人信息功能

extern int com_delete(p_userinfo u); //删除历史信息功能

extern int com_menu(); //用户界面
extern int common(p_userinfo u, p_flight f);

#endif