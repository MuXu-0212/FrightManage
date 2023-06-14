#ifndef __administrator_h_
#define __administrator_h_
#include "login.h"

extern void print_(int num); //打印-


extern void admi_menu(); //管理员操作菜单


extern void admi_add_menu(); //管理员“添加”功能的菜单
extern int admi_add(p_user h); //管理员添加功能
extern int admi_add_user(p_user h, int flag); //管理员添加用户，flag为用户级别


extern int admi_delete(p_user h); //删除用户功能


extern void admi_revise_menu(); //管理员修改菜单
extern int admi_revise(p_user h); //管理员"修改"选择界面
extern int admi_revise_adjust_IdCompare(p_user h); //校验账号
extern void admi_revise_adjust_menu(char* str);
extern int admi_revise_adjust(p_user h);   //管理员调整用户等级的功能
extern int admi_revise_find(p_user h); //账号信息查询


extern int administrator(p_user h); //管理员模块





#endif