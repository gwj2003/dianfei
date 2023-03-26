#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "maincontrol.h"
#include"menu.h"

extern int count;

int findRecordByID(Record* rec, int id);
/*按日期显示小区信息*/;
void displayCommunitRecordByDate()
{

}

/*按户号显示小区信息*/
void displayCommunitRecordByID()
{

}

/*显示住户信息*/
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

/*编辑住户信息*/
void editRecord()
{
	printf("$ 录入住户信息 $\n");
	printf(" 户号：");
	scanf_s("%d", &rec[count].id);
	printf(" 户名：");
	scanf_s("%s", rec[count].name, 50);
	printf(" 小区：");
	scanf_s("%s", rec[count].community, 50);
	printf(" 日期：");
	scanf_s("%s", rec[count].date, 50);
	printf(" 人数：");
	scanf_s("%d", &rec[count].number);
	printf(" 是否参加峰谷计费：");
	scanf_s("%d", &rec[count].join);
	printf(" 峰时电量：");
	scanf_s("%lf", &rec[count].felectricity);
	printf(" 谷时电量：");
	scanf_s("%lf", &rec[count].gelectricity);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*添加住户选项*/
void addRecord()
{
	printf("$ 添加住户信息 $\n");
	printf(" 输入户号：");
	editRecord(rec);
	printf("\n成功添加住户！\n");
}

/*删除住户选项*/
void removeRecord()
{

}

/*修改住户选项*/
void modifyRecord()
{

}

/*查找住户选项*/
void findRecord()
{
	int id = 0;
	printf("$ 按户号查找电费记录信息 $\n");
	printf(" 输入户号：");
	scanf_s("%d", &id);
	if (findRecordByID(rec, id))
	{
		printf("$ 找到以下住户信息 $\n");
		displayRecord(id);
	}
	else
	{
		printf("住户信息中未找到该住户\n");
		displayRecord(id);
	}
}

/*通过户号查找住户选项*/
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







/*小区已扩容名单*/
void UnList()
{

}

/*小区未扩容名单*/
void List()
{

}

/*小区急需扩容名单*/
void need()
{

}

/*小区不急需扩容名单*/
void unneeded()
{

}



/*计算总电费*/
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

/*计算不参与峰谷的电费*/
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

/*计算峰谷电费*/
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