#include<stdio.h>
#include "menu.h"
#include "maincontrol.h"
#include "record.h"

int count = 0;                 /*���ڼ����¼����*/
int change = 0;                /*�����ڸ��ļ�¼ʱȷ����ַ*/

/*���˵�*/
void menuMain()
{
	int choice;
	do
	{
		printf("$ С�����������Ƽ�ϵͳ $\n\n");
		printf("[1] �������ͳ��Ա\n");
		printf("[2] ���繫˾������Ա\n");
		printf("[0] ����\n");
		printf("\n");
		printf("��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 2)
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
		printf("\n$ ������ݼ�¼��Ա $\n");
		printf("[1] ��ѯ��Ѽ�¼��Ϣ\n");
		printf("[2] ���ס����Ѽ�¼��Ϣ\n");
		printf("[3] ɾ��ס����Ѽ�¼��Ϣ\n");
		printf("[4] �޸�ס����Ѽ�¼��Ϣ\n");
		printf("[0] ����\n");
		printf("\n");
		printf("��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 4)
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

/*���繫˾������Ա*/
void staff()
{
	int choice;
	do
	{
		printf("\n$ ���繫˾������Ա $\n");
		printf("[1] ��ѯ��Ѽ�¼��Ϣ\n");
		printf("[2] ���ݹ���\n");
		printf("[0] ����\n");
		printf("\n");
		printf("��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 2)
			runstaff(choice);
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}

/*ѯ��Ҫ�޸�ʲô*/
void ask()
{
	int choice;
	do
	{
		printf("[1] �޸��Ƿ�μӷ�ȼƷ�\n");
		printf("[2] �޸ķ�ʱ����\n");
		printf("[3] �޸Ĺ�ʱ����\n");
		printf("[0] ����\n");
		printf("\n");
		printf("��ѡ��");
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

/*���ݹ���*/
void expansion()
{
	int choice;
	do
	{
		printf("[1] �鿴������С��\n");
		printf("[2] �鿴δ����С��\n");
		printf("[3] �鿴��������С��\n");
		printf("[4] �鿴����������С��\n");
		printf("[0] ����\n");
		printf("\n");
		printf("��ѡ��");
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 4)
			runexpansion(choice);
		else
		{
			printf("\n");
			printf("����������\n\n");
		}
	} while (choice);
}