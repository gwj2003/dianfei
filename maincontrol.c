#include<stdio.h>
#include"record.h"
#include"maincontrol.h"
#include"menu.h"
#include"record.h"



/*ѡ�����*/
void runmenuMain(int choice)
{
	switch (choice)
	{
	case 1: 
		statistician();                    /*ѡ���˼�¼��Ա�����*/
		break;
	case 2:
		staff();                           /*ѡ���˹�����Ա�����*/
		break;
	}
}

/*ѡ���¼��Ա����*/
void runstatistician(int choice)
{
	switch (choice)
	{
	case 1:findRecord();                  /*ѡ���ѯ��Ѽ�¼��Ϣ����*/
		break;
	case 2:addRecord();                   /*ѡ�����ס����Ѽ�¼��Ϣ����*/
		break;
	case 3:removeRecord();                /*ѡ��ɾ��ס����Ѽ�¼��Ϣ����*/
		break;
	case 4:modifyRecord();                /*ѡ���޸�ס����Ѽ�¼��Ϣ����*/
		break;
	}
}

/*ѡ������Ա����*/
void runstaff(int choice)
{
	switch (choice)
	{
	case 1:findRecord();                  /*ѡ���ѯ��Ѽ�¼��Ϣ����*/
		break;
	case 2:expansion();                   /*ѡ�����ݹ�����*/
		break; 
	}
}

/*ѡ���޸Ĺ���*/
void  runchange(int choice)
{
	switch (choice)
	{ 
	case 1:changeif();                   /*ѡ���޸��Ƿ�μӷ�ȼƷѹ���*/
		break;
	case 2:changef();                    /*ѡ���޸ķ�ʱ��������*/
		break;
	case 3:changeg();                    /*ѡ���޸Ĺ�ʱ��������*/
		break;
	}
}

/*ѡ�����ݹ�����*/
void runexpansion(choice)
{
	switch (choice)
	{
	case 1:UnList();                   /*ѡ��������С������*/
		break;
	case 2:List();                     /*ѡ��δ����С������*/
		break;
	case 3:need();                     /*ѡ��������С������*/
		break;
	case 4:unneeded();                 /*ѡ�񲻼�������С������*/
		break;
	}
}

/*������*/
int main()
{
	int count = readRecordFile(rec);     /*��һ��ԭ�е��ļ����м�������*/
	menuMain();                          /*�����˵�*/
	return 0;
}