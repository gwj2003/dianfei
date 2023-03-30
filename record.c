#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "maincontrol.h"
#include"menu.h"

extern int count;
extern int change;

/*按日期显示小区信息*/;
void displayCommunitByDate()
{

}

/*按户号显示小区信息*/
void displayCommunitByID()
{
	char com;
	printf("$ 按户号显示小区电费记录信息 $\n");
	printf(" 输入小区名：");
	scanf_s("%s", &com, 50);
	int n = findCommunitBy(rec, com);
	if (n)
	{
		printf(" 小区名：");
		printf("%-8s", rec[n].community);
		printf("户号:        户名:        \n");
	}
	else
	{
		printf("住户信息中未找到该小区\n");
	}
}

/*通过小区名查找*/
int findCommunitBy(Record* rec, char* com)
{
	int i = 0;
	while (i <= count)
	{
		int n = strcmp(&rec[i].community, com);
		if (!n)
		{
			return i;
		}
		i++;
	}
	return 0;
}

/*显示相同住户标题*/
void displaysameTitle()
{
	printf("%-8s", "户号");
	printf("%-8s", "户名");
	printf("%-8s", "小区");
	printf("%-8s", "人数");
	printf("%-8s", "是否参与");
	printf("\n");
}

/*显示不同住户标题*/
void displaydifferentTitle()
{
	printf("%-8s", "年份");
	printf("%-8s", "月份");
	printf("%-16s", "峰时电量");
	printf("%-16s", "谷时电量");
	printf("%-16s", "总电量");
	printf("%-16s", "电费");
	printf("\n");
}

/*显示重复住户信息*/
void displaysame(int n)
{
	printf("%-8d", rec[n].id);
	printf("%-8s", rec[n].name);
	printf("%-8s", rec[n].community);
	printf("%-8d", rec[n].number);
	printf("%-8d", rec[n].join);
	printf("\n");
}

/*显示不重复住户信息*/
void displaydifferent(int n)
{
	printf("%-8d", rec[n].year);
	printf("%-8d", rec[n].month);
	printf("%-16lf", rec[n].felectricity);
	printf("%-16lf", rec[n].gelectricity);
	printf("%-16lf", rec[n].electricity);
	printf("%-16lf", rec[n].power_rate);
	printf("\n");
}

/*编辑住户信息*/
void editRecord()
{
	int id;
	printf("$ 录入住户信息 $\n");
	printf(" 户号：");
	scanf_s("%d", &rec[count].id);                 /*先输入下一行的户号*/
	id = rec[count].id;                            /*赋值给id*/
	rec[count].id = 0;
	change = findRecordByID(rec, id);              /*寻找是否已有相同的户号*/
	rec[count].id = id;
	if (change)
	{
		printf(" 已有该用户信息：\n");             /*输出相同的信息*/
		displaysameTitle();
		displaysame(change);
		memcpy(rec[count].name, rec[change].name, STR_LEN);
		memcpy(rec[count].community, rec[change].community, STR_LEN);
		rec[count].number = rec[change].number;
		rec[count].join = rec[change].join;
		printf(" 年份：");
		scanf_s("%d", &rec[count].year);
		printf(" 月份：");
		scanf_s("%d", &rec[count].month);
		printf(" 峰时电量：");
		scanf_s("%lf", &rec[count].felectricity);
		printf(" 谷时电量：");
		scanf_s("%lf", &rec[count].gelectricity);
		rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
		rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[change].join);
		change = 0;                               /*把change改为0*/
	}
	else
	{
		printf(" 户名：");
		scanf_s("%s", rec[count].name, 50);
		printf(" 小区：");
		scanf_s("%s", rec[count].community, 50);
		printf(" 年份：");
		scanf_s("%d", &rec[count].year);
		printf(" 月份：");
		scanf_s("%d", &rec[count].month);
		printf(" 人数：");
		scanf_s("%d", &rec[count].number);
		printf(" 是否参加峰谷计费：");
		scanf_s("%d", &rec[count].join);
		printf(" 峰时电量：");
		scanf_s("%lf", &rec[count].felectricity);
		printf(" 谷时电量：");
		scanf_s("%lf", &rec[count].gelectricity);/*计算总电量、电费*/
		rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
		rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
	}
}

/*添加住户选项*/
void addRecord()
{
	printf("$ 添加住户信息 $\n");
	count++;
	editRecord(rec);
	printf("\n成功添加住户！\n");
}

/*删除住户选项*/
void removeRecord()
{
	int id = 0;
	int year = 0;
	int month = 0;
	printf("$ 输入户号和日期查找要删除的电费记录信息 $\n");
	printf(" 输入户号：");
	scanf_s("%d", &id);
	printf(" 输入年份：");
	scanf_s("%d", &year);
	printf(" 输入月份：");
	scanf_s("%d", &month);
	int n = findRecordByIDdate(rec, id, year, month);
	if (n)
	{
		while (n < count)
		{
			rec[n] = rec[++n];            /*用后一个数组覆盖前一个数组*/
		}
		count--;                          /*记录少了一行*/
		printf("已删除该条信息\n");
	}
	else
	{
		printf("住户信息中未找到该住户\n");
	}
}

/*修改住户选项*/
void modifyRecord()
{
	int id = 0;
	int year = 0;
	int month = 0;
	printf("$ 输入户号和日期查找要修改的电费记录信息 $\n");
	printf(" 输入户号：");
	scanf_s("%d", &id);
	printf(" 输入年份：");
	scanf_s("%d", &year);
	printf(" 输入月份：");
	scanf_s("%d", &month);
	change = findRecordByIDdate(rec, id, year, month);
	if (change)
	{
		printf("$ 找到以下住户信息 $\n");
		displaysameTitle();
		displaysame(change);
		displaydifferentTitle();
		displaydifferent(change);
		ask();
		change = 0;
	}
	else
	{
		printf("住户信息中未找到该住户\n");
	}
}

/*更改是否参加峰谷计费*/
void changeif()
{
	printf(" 是否参加峰谷计费：");
	scanf_s("%d", &rec[change].join);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*更改峰时电量*/
void changef()
{
	printf(" 峰时电量：");
	scanf_s("%lf", &rec[change].felectricity);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*更改谷时电量*/
void changeg()
{
	printf(" 谷时电量：");
	scanf_s("%lf", &rec[change].gelectricity);
	rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
	rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
}

/*查找住户选项*/
void findRecord()
{
	int id = 0;
	printf("$ 按户号查找电费记录信息 $\n");
	printf(" 输入户号：");
	scanf_s("%d", &id);
	int n = findRecordByID(rec, id);
	int add = n;
	if (!add)
	{
		printf("住户信息中未找到该住户\n");
	}
	else
	{
		printf("$ 找到以下住户信息 $\n");
		displaysameTitle();
		displaysame(n);
		displaydifferentTitle();
		while (add <= count)
		{
			if (rec[add].id == id)
			{
				displaydifferent(add);
				add++;
			}
			else
			{
				add++;
			}

		}
	}
}

/*通过户号查找住户选项*/
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


/*通过户号和日期查找住户选项*/
int findRecordByIDdate(Record* rec, int id, int year, int month)
{
	int i = 0;
	while (i <= count)
	{
		if ((rec[i].id == id) && (rec[i].year == year) && (rec[i].month == month))   /*两个条件同时满足*/
		{
			return i;
		}
		i++;
	}
	return 0;
}



/*已扩容小区名单*/
void UnList()
{

}

/*未扩容小区名单*/
void List()
{

}

/*急需扩容小区名单*/
void need()
{

}

/*不急需扩容小区名单*/
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