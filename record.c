#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "maincontrol.h"
#include"menu.h"

extern int count;

int findRecordByID(Record* rec, int id);
/*��������ʾС����Ϣ*/;
void displayCommunitRecordByDate()
{

}

/*��������ʾС����Ϣ*/
void displayCommunitRecordByID()
{

}

/*��ʾס����Ϣ*/
void displayRecord(int n)
{
	printf("%d\n", rec[n].id);
	printf("%s\n", rec[n].name);
	printf("%s\n", rec[n].community);
	printf("%s\n", rec[n].date);
	printf("%d\n", rec[n].number);
	printf("%d\n", rec[n].join);
	printf("%lf\n", rec[n].felectricity);
	printf("%lf\n", rec[n].gelectricity);
	printf("%lf\n", rec[n].electricity);
	printf("%lf\n", rec[n].power_rate);
}

/*�༭ס����Ϣ*/
void editRecord()
{
	printf("$ ¼��ס����Ϣ $\n");
	printf(" ���ţ�");
	scanf_s("%d", &rec[count].id);
	printf(" ������");
	scanf_s("%s", rec[count].name, 50);
	printf(" С����");
	scanf_s("%s", rec[count].community, 50);
	printf(" ���ڣ�");
	scanf_s("%s", rec[count].date, 50);
	printf(" ������");
	scanf_s("%d", &rec[count].number);
	printf(" �Ƿ�μӷ�ȼƷѣ�");
	scanf_s("%d", &rec[count].join);
	printf(" ��ʱ������");
	scanf_s("%lf", &rec[count].felectricity);
	printf(" ��ʱ������");
	scanf_s("%lf", &rec[count].gelectricity);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*���ס��ѡ��*/
void addRecord()
{
	printf("$ ���ס����Ϣ $\n");
	printf(" ���뻧�ţ�");
	editRecord(rec);
	printf("\n�ɹ����ס����\n");
}

/*ɾ��ס��ѡ��*/
void removeRecord()
{

}

/*�޸�ס��ѡ��*/
void modifyRecord()
{

}

/*����ס��ѡ��*/
void findRecord()
{
	int id = 0;
	printf("$ �����Ų��ҵ�Ѽ�¼��Ϣ $\n");
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	if (findRecordByID(rec, id))
	{
		printf("$ �ҵ�����ס����Ϣ $\n");
		displayRecord(id);
	}
	else
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
		displayRecord(id);
	}
}

/*ͨ�����Ų���ס��ѡ��*/
int findRecordByID(Record* rec, int id)
{
	int i = 1;
	int n = readRecordFile(rec);
	while (i<= n)
	{
		if (rec[i].id == id)
		{
			i++;
		}
		return i;
	}
	return 0;
}







/*С������������*/
void UnList()
{

}

/*С��δ��������*/
void List()
{

}

/*С��������������*/
void need()
{

}

/*С����������������*/
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