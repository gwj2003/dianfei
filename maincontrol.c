#include<stdio.h>
#include"record.h"
#include"maincontrol.h"
#include"menu.h"
#include"record.h"
#include "fail.h"



/*ѡ�����*/
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

/*ѡ���¼��Ա����*/
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

/*ѡ������Ա����*/
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

int main()
{
	int n = readRecordFile(rec);
	menuMain();
	saveFile(rec, n);
	return 0;
}