#include<stdio.h>
#include"record.h"
#include"maincontrol.h"
#include"menu.h"
#include"record.h"

int count = 0;                           /*���ڼ����¼����*/
int change = 0;                          /*�����ڸ��ļ�¼ʱȷ����ַ*/
int id = 0;                              /*�����ڸ��ļ�¼ʱȷ������*/

/*ѡ��С����ѯ��Ѽ�¼��Ϣ����*/
void runfindcommunity(int choice)
{
	switch (choice)
	{
	case 1:displayCommunityByDate();     /*ѡ��������ʾС����Ϣ����*/
		break;
	case 2:displayCommunityByID();       /*ѡ�񰴻�����ʾС����Ϣ����*/
		break;
	case 3:
		system("cls");                  /*����*/
		break;
	}
}

/*ѡ���ѯ��Ѽ�¼��Ϣ����*/
void runfind(int choice)
{
	switch (choice)
	{
	case 1:findRecord();                 /*ѡ���ѯ���˵�Ѽ�¼��Ϣ����*/
		break;
	case 2:findcommunity();              /*ѡ���ѯС����Ѽ�¼��Ϣ����*/
		break;
	case 3:
		system("cls");                  /*����*/
		break;
	}
}

/*ѡ�����*/
void runmenuMain(int choice)
{
	switch (choice)
	{
	case 1:
		statistician();                 /*ѡ���˼�¼��Ա�����*/
		break;
	case 2:
		staff();                        /*ѡ���˹�����Ա�����*/
		break;
	case 3:
		system("cls");                  /*����*/
		break;
	}
}

/*ѡ���¼��Ա����*/
void runstatistician(int choice)
{
	switch (choice)
	{
	case 1:find();                      /*ѡ���ѯ��Ѽ�¼��Ϣ����*/
		break;
	case 2:addRecord();                 /*ѡ�����ס����Ѽ�¼��Ϣ����*/
		break;
	case 3:removeRecord();              /*ѡ��ɾ��ס����Ѽ�¼��Ϣ����*/
		break;
	case 4:modify();                    /*ѡ��ס����Ѽ�¼��Ϣ����*/
		break;
	case 5:
		system("cls");                  /*����*/
		break;
	}
}

/*ѡ���޸�ס����Ѽ�¼��Ϣ����*/
void runmodify(int choice)
{
	switch (choice)
	{
	case 1:modifyRecord();              /*�޸�ĳ���õ��¼*/
		break;
	case 2:modifyjoin();                /*�޸��Ƿ�μӷ�ȼƷ�*/
		break;
	case 3:modifynumber();              /*�޸�ס������*/
		break;
	case 4:modifyname();                /*�޸�С����*/
		break;
	case 5:modifylist();                /*�޸�С���Ƿ�����*/
		break;
	case 6:
		system("cls");                  /*����*/
		break;
	}
}

/*ѡ������Ա����*/
void runstaff(int choice)
{
	switch (choice)
	{
	case 1:find();                      /*ѡ���ѯ��Ѽ�¼��Ϣ����*/
		break;
	case 2:expansion();                 /*ѡ�����ݹ�����*/
		break;
	case 3:
		system("cls");                  /*����*/
		break;
	}
}

/*ѡ���޸Ĺ���*/
void  runchange(int choice)
{
	switch (choice)
	{
	case 1:changef();                   /*ѡ���޸ķ�ʱ��������*/
		break;
	case 2:changeg();                   /*ѡ���޸Ĺ�ʱ��������*/
		break;
	case 3:
		system("cls");                  /*����*/
		break;
	}
}

/*ѡ�����ݹ�����*/
void runexpansion(int choice)
{
	switch (choice)
	{
	case 1:displayUnList();            /*ѡ��������С������*/
		break;
	case 2:displayList();              /*ѡ��δ����С������*/
		break;
	case 3:displayneed();              /*ѡ��������С������*/
		break;
	case 4:displayunneeded();          /*ѡ�񲻼�������С������*/
		break;
	case 5:
		system("cls");                  /*����*/
		break;
	}
}

/*������*/
int main()
{
	system("title �������ݷ�����С�����������Ƽ�ϵͳ");
	count = readRecordFile(rec);       /*��һ��ԭ�е��ļ����м�������*/
	menuMain();                        /*�����˵�*/
	return 0;
}