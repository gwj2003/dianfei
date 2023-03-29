#ifndef _MAINCONTROL
#define _MAINCONTROL
#define _CRT_SECURE_NO_WARNINGS
/*选择按小区查询电费记录信息功能*/
void runfindcommunity(int choice);

/*选择查询电费记录信息功能*/
void runfind(int choice);

/*选择身份*/
void runmenuMain(int choice);

/*选择记录人员功能*/
void runstatistician(int choice);

/*选择工作人员功能*/
void runstaff(int choice);

/*选择修改功能*/
void  runchange(int choice);

/*选择扩容管理功能*/
void runexpansion(int choice);

#endif