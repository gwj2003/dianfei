#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "maincontrol.h"
#include"menu.h"

extern int count;
extern int change;

/*��������ʾС����Ϣ*/;
void displayCommunitRecordByDate()
{

}

/*��������ʾС����Ϣ*/
void displayCommunitRecordByID()
{

}

/*��ʾ��ͬס������*/
void displaysameTitle()
{
	printf("%-8s", "����");
	printf("%-8s", "����");
	printf("%-8s", "С��");
	printf("%-8s", "����");
	printf("%-8s", "�Ƿ����");
	printf("\n");
}

/*��ʾ��ͬס������*/
void displaydifferentTitle()
{
	printf("%-8s", "����");
	printf("%-16s", "��ʱ����");
	printf("%-16s", "��ʱ����");
	printf("%-16s", "�ܵ���");
	printf("%-16s", "���");
	printf("\n");
}

/*��ʾ�ظ�ס����Ϣ*/
void displaysame(int n)
{
	printf("%-8d", rec[n].id);
	printf("%-8s", rec[n].name);
	printf("%-8s", rec[n].community);
	printf("%-8d", rec[n].number);
	printf("%-8d", rec[n].join);
	printf("\n");
}

/*��ʾ���ظ�ס����Ϣ*/
void displaydifferent(int n)
{
	printf("%-8d", rec[n].date);
	printf("%-16lf", rec[n].felectricity);
	printf("%-16lf", rec[n].gelectricity);
	printf("%-16lf", rec[n].electricity);
	printf("%-16lf", rec[n].power_rate);
	printf("\n");
}

/*�༭ס����Ϣ*/
void editRecord()//û�и�������id���¼�¼��
{
	int id;
	printf("$ ¼��ס����Ϣ $\n");
	printf(" ���ţ�");
	scanf_s("%d", &rec[count].id);                 /*��������һ�еĻ���*/
	id = rec[count].id;                             /*��ֵ��id*/
	rec[count].id = 0;
	change = findRecordByID(rec, id);              /*Ѱ���Ƿ�������ͬ�Ļ���*/
	rec[count].id = id;
	if (change)//�˴��������Ϣ���ȱ���п��ܶ��ļ�ʱ������
	{
		printf(" ���и��û���Ϣ��\n");             /*�����ͬ����Ϣ*/
		displaysameTitle();
		displaysame(change);
		printf(" ���ڣ�");                         /*���벻ͬ����Ϣ*/
		scanf_s("%d", &rec[count].date);
		printf(" ��ʱ������");
		scanf_s("%lf", &rec[count].felectricity);
		printf(" ��ʱ������");
		scanf_s("%lf", &rec[count].gelectricity);
		change = 0;                               /*��change��Ϊ0*/
	}
	else
	{
		printf(" ������");
		scanf_s("%s", rec[count].name, 50);
		printf(" С����");
		scanf_s("%s", rec[count].community, 50);
		printf(" ���ڣ�");
		scanf_s("%d", &rec[count].date);
		printf(" ������");
		scanf_s("%d", &rec[count].number);
		printf(" �Ƿ�μӷ�ȼƷѣ�");
		scanf_s("%d", &rec[count].join);
		printf(" ��ʱ������");
		scanf_s("%lf", &rec[count].felectricity);
		printf(" ��ʱ������");
		scanf_s("%lf", &rec[count].gelectricity);/*�����ܵ��������*/
		rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
		rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
	}
}

/*���ס��ѡ��*/
void addRecord()
{
	printf("$ ���ס����Ϣ $\n");
	count++;
	editRecord(rec);
	printf("\n�ɹ����ס����\n");
}

/*ɾ��ס��ѡ��*/
void removeRecord()
{
	int id = 0;
	int date = 0;
	printf("$ ���뻧�ź����ڲ���Ҫɾ���ĵ�Ѽ�¼��Ϣ $\n");
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	printf(" �������ڣ�");
	scanf_s("%d", &date);
	int n = findRecordByIDdate(rec, id, date);
	if (n)
	{
		while (n < count)
		{
			rec[n] = rec[++n];            /*�ú�һ�����鸲��ǰһ������*/
		}
		count--;                          /*��¼����һ��*/
		printf("��ɾ��������Ϣ\n");
	}
	else
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
}

/*�޸�ס��ѡ��*/
void modifyRecord()
{
	int id = 0;
	int date = 0;
	printf("$ ���뻧�ź����ڲ���Ҫ�޸ĵĵ�Ѽ�¼��Ϣ $\n");
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	printf(" �������ڣ�");
	scanf_s("%d", &date);
	change = findRecordByIDdate(rec, id, date);
	if (change)
	{
		printf("$ �ҵ�����ס����Ϣ $\n");
		displaysameTitle();
		displaysame(change);
		displaydifferentTitle();
		displaydifferent(change);
		ask();
		change = 0;
	}
	else
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
}

/*�����Ƿ�μӷ�ȼƷ�*/
void changeif()
{
	printf(" �Ƿ�μӷ�ȼƷѣ�");
	scanf_s("%d", &rec[change].join);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*���ķ�ʱ����*/
void changef()
{
	printf(" ��ʱ������");
	scanf_s("%lf", &rec[change].felectricity);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*���Ĺ�ʱ����*/
void changeg()
{
	printf(" ��ʱ������");
	scanf_s("%lf", &rec[change].gelectricity);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*����ס��ѡ��*/
void findRecord()
{
	int id = 0;
	printf("$ �����Ų��ҵ�Ѽ�¼��Ϣ $\n");
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	int n = findRecordByID(rec, id);
	if (n)
	{
		printf("$ �ҵ�����ס����Ϣ $\n");
		displaysameTitle();
		displaysame(n);
		displaydifferentTitle();
		displaydifferent(n);
	}
	else
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
}

/*ͨ�����Ų���ס��ѡ��*/
int findRecordByID(Record* rec, int id)
{
	int i = 0;
	while (i <= count)
	{
		if (rec[i].id == id)
		{
			return i;
		}
		i++;
	}
	return 0;
}


/*ͨ�����ź����ڲ���ס��ѡ��*/
int findRecordByIDdate(Record* rec, int id, int date)
{
	int i = 0;
	while (i <= count)
	{
		if ((rec[i].id == id) && (rec[i].date == date))   /*��������ͬʱ����*/
		{
			return i;
		}
		i++;
	}
	return 0;
}



/*������С������*/
void UnList()
{

}

/*δ����С������*/
void List()
{

}

/*��������С������*/
void need()
{

}

/*����������С������*/
void unneeded()
{

}



/*�����ܵ��*/
double rate(double felectricity, double gelectricity, double electricity, int number, int join)
{
	switch (join)
	{
	case 1:
		return fgrate(felectricity, gelectricity, electricity, number);
	case 2:
		return unfgrate(electricity, number);
	}
	return 0;
}

/*���㲻�����ȵĵ��*/
double unfgrate(double electricity, int number)
{
	if (number >= 0 && number <= 4 && electricity >= 0 && number <= 230)
	{
		return(electricity * 0.5238);
	}
	else
		if (number >= 0 && number <= 4 && electricity > 231 && number <= 400)
		{
			return ((electricity - 230) * 0.5783) + 120.474;
		}
		else
			if (number >= 0 && number <= 4 && electricity > 400)
			{
				return ((electricity - 400) * 0.8288) + 218.785;
			}
			else
				if (number >= 5 && number <= 6 && electricity >= 0 && number <= 330)
				{
					return (electricity * 0.5238);
				}
				else
					if (number >= 5 && number <= 6 && electricity > 331 && number <= 500)
					{
						return ((electricity - 330) * 0.5783) + 172.854;
					}
					else
						if (number >= 5 && number <= 6 && electricity > 500)
						{
							return ((electricity - 500) * 0.8288) + 271.165;
						}
						else
							if (number >= 7 && electricity >= 0 && number <= 430)
							{
								return (electricity * 0.5238);
							}
							else
								if (number >= 7 && electricity > 431 && number <= 600)
								{
									return ((electricity - 430) * 0.5783) + 225.234;
								}
								else
									if (number >= 7 && electricity > 600)
									{
										return ((electricity - 600) * 0.8288) + 323.545;
									}
	return 0;
}

/*�����ȵ��*/
double fgrate(double felectricity, double gelectricity, double electricity, int number)
{

	if (number >= 0 && number <= 4 && electricity >= 0 && number <= 230)
	{
		return (0.5583 * felectricity) + (0.3583 * gelectricity);
	}
	else
		if (number >= 0 && number <= 4 && electricity > 231 && number <= 400)
		{
			return (0.5583 * felectricity) + (0.3583 * gelectricity) + ((electricity - 230) * 0.05);
		}
		else
			if (number >= 0 && number <= 4 && electricity > 400)
			{
				return (0.5583 * felectricity) + (0.3583 * gelectricity) + ((electricity - 400) * 0.3) + 8.5;
			}
			else
				if (number >= 5 && number <= 6 && electricity >= 0 && number <= 330)
				{
					return (0.5583 * felectricity) + (0.3583 * gelectricity);
				}
				else
					if (number >= 5 && number <= 6 && electricity > 331 && number <= 500)
					{
						return (0.5583 * felectricity) + (0.3583 * gelectricity) + ((electricity - 330) * 0.05);
					}
					else
						if (number >= 5 && number <= 6 && electricity > 500)
						{
							return (0.5583 * felectricity) + (0.3583 * gelectricity) + ((electricity - 500) * 0.3) + 8.5;
						}
						else
							if (number >= 7 && electricity >= 0 && number <= 430)
							{
								return (0.5583 * felectricity) + (0.3583 * gelectricity);
							}
							else
								if (number >= 7 && electricity > 431 && number <= 600)
								{
									return (0.5583 * felectricity) + (0.3583 * gelectricity) + ((electricity - 430) * 0.05);
								}
								else
									if (number >= 7 && electricity > 600)
									{
										return (0.5583 * felectricity) + (0.3583 * gelectricity) + ((electricity - 600) * 0.3) + 8.5;
									}
	return 0;
}