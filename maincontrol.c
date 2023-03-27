#include<stdio.h>
#include"record.h"
#include"maincontrol.h"
#include"menu.h"
#include"record.h"



/*选择身份*/
void runmenuMain(int choice)
{
	switch (choice)
	{
	case 1:
		statistician();
		break;
	case 2:
		staff();
		break;
	}
}

/*选择记录人员功能*/
void runstatistician(int choice)
{
	switch (choice)
	{
	case 1:findRecord();
		break;
	case 2:addRecord();
		break;
	case 3:removeRecord();
		break;
	case 4:modifyRecord();
		break;
	}
}

/*选择工作人员功能*/
void runstaff(int choice)
{
	switch (choice)
	{
	case 1:findRecord();
		break;
	case 2:expansion();
		break;
	}
}

/*选择修改功能*/
void  runchange(int choice)
{
	switch (choice)
	{
	case 1:changeif();
		break;
	case 2:changef();
		break;
	case 3:changeg();
		break;
	}
}
int main()
{
	int count = readRecordFile(rec);
	menuMain();
	return 0;
}