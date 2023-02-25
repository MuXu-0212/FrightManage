#ifndef __vip_h_
#define __vip_h_

#include "common.h"



extern userinfo* userinfo_create(); ////创建用户信息

extern int vip_buy(p_userinfo u, p_flight f); //用户购票功能
extern int vip_find(p_userinfo u); //用户查看功能


extern int vip_buy_strick(p_userinfo u, p_flight f \
	, int flight_frequency); //用户订票
extern int vip_buy_strick_continue(p_userinfo u, p_flight f \
	, int flight_frequency);//连续购票

extern void vip_revise_menu();//修改个人信息的菜单
extern int vip_revise(p_userinfo u); //用户修改个人信息功能

extern int vip_delete(p_userinfo u); //删除历史信息功能

extern int vip_menu(); //用户界面
extern int vip(p_userinfo u, p_flight f);

#endif