#include<stdio.h>
#include"record.h"
#include"maincontrol.h"
#include"menu.h"
#include"record.h"

int count = 0;                           /*用于计算记录条数*/
int change = 0;                          /*用于在更改记录时确定地址*/
int id = 0;                              /*用于在更改记录时确定户号*/

/*选择按小区查询电费记录信息功能*/
void runfindcommunity(int choice)
{
	switch (choice)
	{
	case 1:displayCommunityByDate();     /*选择按日期显示小区信息功能*/
		break;
	case 2:displayCommunityByID();       /*选择按户号显示小区信息功能*/
		break;
	case 3:
		system("cls");                  /*清屏*/
		break;
	}
}

/*选择查询电费记录信息功能*/
void runfind(int choice)
{
	switch (choice)
	{
	case 1:findRecord();                 /*选择查询个人电费记录信息功能*/
		break;
	case 2:findcommunity();              /*选择查询小区电费记录信息功能*/
		break;
	case 3:
		system("cls");                  /*清屏*/
		break;
	}
}

/*选择身份*/
void runmenuMain(int choice)
{
	switch (choice)
	{
	case 1:
		statistician();                 /*选择了统计人员的身份*/
		break;
	case 2:
		staff();                        /*选择了工作人员的身份*/
		break;
	case 3:
		system("cls");                  /*清屏*/
		break;
	}
}

/*选择记录人员功能*/
void runstatistician(int choice)
{
	switch (choice)
	{
	case 1:find();                      /*选择查询电费记录信息功能*/
		break;
	case 2:addRecord();                 /*选择添加住户电费记录信息功能*/
		break;
	case 3:removeRecord();              /*选择删除住户电费记录信息功能*/
		break;
	case 4:modify();                    /*选择住户电费记录信息功能*/
		break;
	case 5:
		system("cls");                  /*清屏*/
		break;
	}
}

/*选择修改住户电费记录信息功能*/
void runmodify(int choice)
{
	switch (choice)
	{
	case 1:modifyRecord();              /*修改某月用电记录*/
		break;
	case 2:modifyjoin();                /*修改是否参加峰谷计费*/
		break;
	case 3:modifynumber();              /*修改住户人数*/
		break;
	case 4:modifyname();                /*修改小区名*/
		break;
	case 5:modifylist();                /*修改小区是否扩容*/
		break;
	case 6:
		system("cls");                  /*清屏*/
		break;
	}
}

/*选择工作人员功能*/
void runstaff(int choice)
{
	switch (choice)
	{
	case 1:find();                      /*选择查询电费记录信息功能*/
		break;
	case 2:expansion();                 /*选择扩容管理功能*/
		break;
	case 3:
		system("cls");                  /*清屏*/
		break;
	}
}

/*选择修改功能*/
void  runchange(int choice)
{
	switch (choice)
	{
	case 1:changef();                   /*选择修改峰时电量功能*/
		break;
	case 2:changeg();                   /*选择修改谷时电量功能*/
		break;
	case 3:
		system("cls");                  /*清屏*/
		break;
	}
}

/*选择扩容管理功能*/
void runexpansion(int choice)
{
	switch (choice)
	{
	case 1:displayUnList();            /*选择已扩容小区名单*/
		break;
	case 2:displayList();              /*选择未扩容小区名单*/
		break;
	case 3:displayneed();              /*选择急需扩容小区名单*/
		break;
	case 4:displayunneeded();          /*选择不急需扩容小区名单*/
		break;
	case 5:
		system("cls");                  /*清屏*/
		break;
	}
}

/*主函数*/
int main()
{
	system("title 基于数据分析的小区电量扩容推荐系统");
	count = readRecordFile(rec);       /*数一下原有的文件中有几行数据*/
	menuMain();                        /*打开主菜单*/
	return 0;
}