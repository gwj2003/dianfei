#include<stdio.h>
#include"record.h"
#include"maincontrol.h"
#include"menu.h"
#include"record.h"

int count = 0;                 /*���ڼ����¼����*/
int change = 0;                /*�����ڸ��ļ�¼ʱȷ����ַ*/
int id = 0;                      /*�����ڸ��ļ�¼ʱȷ������*/

/*ѡ��С����ѯ��Ѽ�¼��Ϣ����*/
void runfindcommunity(int choice)
{
	switch (choice)
	{
	case 1:displayCommunityByDate();                 /*ѡ��������ʾС����Ϣ����*/
		break;
	case 2:displayCommunityByID();                   /*ѡ�񰴻�����ʾС����Ϣ����*/
		break;
	}
}

/*ѡ���ѯ��Ѽ�¼��Ϣ����*/
void runfind(int choice)
{
	switch (choice)
	{
	case 1:findRecord();                      /*ѡ���ѯ���˵�Ѽ�¼��Ϣ����*/
		break;
	case 2:findcommunity();                   /*ѡ���ѯС����Ѽ�¼��Ϣ����*/
		break;
	}
}

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
	case 1:find();                        /*ѡ���ѯ��Ѽ�¼��Ϣ����*/
		break;
	case 2:addRecord();                   /*ѡ�����ס����Ѽ�¼��Ϣ����*/
		break;
	case 3:removeRecord();                /*ѡ��ɾ��ס����Ѽ�¼��Ϣ����*/
		break;
	case 4:modify();                     /*ѡ���޸�ס����Ѽ�¼��Ϣ����*/
		break;
	}
}

/*ѡ���޸�ס����Ѽ�¼��Ϣ����*/
void runmodify(int choice)
{
	switch (choice)
	{
	case 1:modifyRecord();                /*�޸�ĳ���õ��¼*/
		printf(" �޸ĳɹ�");
		break;
	case 2:modifyname();                  /*�޸�С����*/
		printf(" �޸ĳɹ�");
		break;
	case 3:modifynumber();                /*�޸�ס������*/
		printf(" �޸ĳɹ�");
		break;
	case 4:modifyjoin();                  /*�޸��Ƿ�μӷ�ȼƷ�*/
		printf(" �޸ĳɹ�");
		break;
	}
}

/*ѡ������Ա����*/
void runstaff(int choice)
{
	switch (choice)
	{
	case 1:find();                        /*ѡ���ѯ��Ѽ�¼��Ϣ����*/
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
	case 1:changef();                    /*ѡ���޸ķ�ʱ��������*/
		break;
	case 2:changeg();                    /*ѡ���޸Ĺ�ʱ��������*/
		break;
	}
}

/*ѡ�����ݹ�����*/
void runexpansion(int choice)
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
	count = readRecordFile(rec);       /*��һ��ԭ�е��ļ����м�������*/
	menuMain();                        /*�����˵�*/
	return 0;
}