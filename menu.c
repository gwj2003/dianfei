#include<stdio.h>
#include "menu.h"
#include "maincontrol.h"
#include "record.h"
 
extern int count;
extern int change;
extern int id;

/*���˵�*/
void menuMain()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|          �������ݷ�����С�����������Ƽ�ϵͳ            |\n");
		printf("|               ��ӭ����ѡ���������                     |\n");
		printf("|                [1] �������ͳ��Ա                      |\n");
		printf("|                [2] ���繫˾������Ա                    |\n");
		printf("|                [3] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
			runmenuMain(choice);
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
	saveFile(rec, count);        /*���ļ��б���ס����Ϣ*/
}

/*������ݼ�¼��Ա*/
void statistician()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|                 ������ݼ�¼��Ա                       |\n");
		printf("|                ��ѡ����Ҫִ�еĹ���                    |\n");
		printf("|                [1] ��ѯ��Ѽ�¼��Ϣ                    |\n");
		printf("|                [2] ���ס����Ѽ�¼��Ϣ                |\n");
		printf("|                [3] ɾ��ס����Ѽ�¼��Ϣ                |\n");
		printf("|                [4] �޸ĵ�Ѽ�¼��Ϣ                    |\n");
		printf("|                [5] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 5)
		{
			runstatistician(choice);
		}
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}

/*ѡ���޸ĵ�Ѽ�¼��Ϣ����*/
void modify()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|                   �޸ĵ�Ѽ�¼��Ϣ                     |\n");
		printf("|                   ��ѡ���޸ĵķ�ʽ                     |\n");
		printf("|                [1] �޸�ĳ��ĳ���õ��¼                |\n");
		printf("|                [2] �޸��Ƿ�μӷ�ȼƷ�                |\n");
		printf("|                [3] �޸�ס������                        |\n");
		printf("|                [4] �޸�С����                          |\n");
		printf("|                [5] �޸�С���Ƿ�����                    |\n");
		printf("|                [6] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >=0 && choice <= 6)
		{
			runmodify(choice);
			id = 0;
		}
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}

/*���繫˾������Ա*/
void staff()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|                 ���繫˾������Ա                       |\n");
		printf("|                ��ѡ����Ҫִ�еĹ���                    |\n");
		printf("|                [1] ��ѯ��Ѽ�¼��Ϣ                    |\n");
		printf("|                [2] ���ݹ���                            |\n");
		printf("|                [3] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
		{
			runstaff(choice);
		}
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}

/*ѯ��Ҫ�޸�ʲô*/
void askfg()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|                 �޸ĵ�Ѽ�¼��Ϣ                       |\n");
		printf("|         ��ѡ���޸ķ�ʱ�õ������ǹ�ʱ�õ���             |\n");
		printf("|                [1] �޸ķ�ʱ����                        |\n");
		printf("|                [2] �޸Ĺ�ʱ����                        |\n");
		printf("|                [3] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
		{
			runchange(choice);
		}
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}

/*ѡ���ѯ��Ѽ�¼��Ϣ����*/
void find()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|                 ��ѯ��Ѽ�¼��Ϣ                       |\n");
		printf("|                  ��ѡ����β�ѯ                        |\n");
		printf("|                [1] �����Ų�ѯ                          |\n");
		printf("|                [2] ��С����ѯ                          |\n");
		printf("|                [3] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
		{
			runfind(choice);
		}
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}

/*ѡ�������ʾС����Ѽ�¼��Ϣ����*/
void findcommunity()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|                 ��ʾС����Ѽ�¼��Ϣ                   |\n");
		printf("|                    ��ѡ����ʾ��ʽ                      |\n");
		printf("|                [1] ��������ʾ                          |\n");
		printf("|                [2] ��������ʾ                          |\n");
		printf("|                [3] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
		{
			runfindcommunity(choice);
		}
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}

/*���ݹ���*/
void expansion()
{
	int choice;
	do
	{
		printf("+--------------------------------------------------------+\n");
		printf("|                                                        |\n");
		printf("|                     ���ݹ���                           |\n");
		printf("|                  ��ѡ���ѯ��ʽ                        |\n");
		printf("|                [1] ��ѯ������С��                      |\n");
		printf("|                [2] ��ѯδ����С��                      |\n");
		printf("|                [3] ��ѯ��������С��                    |\n");
		printf("|                [4] ��ѯ����������С��                  |\n");
		printf("|                [5] ����                                |\n");
		printf("|                [0] ����                                |\n");
		printf("|                                                        |\n");
		printf("+--------------------------------------------------------+\n");
		printf("\n");
		printf(" ��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 5)
		{
			runexpansion(choice);
		}
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}