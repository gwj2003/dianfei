#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "maincontrol.h"
#include"menu.h"

extern int count;
extern int change;
extern int id;

/*按日期显示小区信息*/;
void displayCommunityByDate()
{
	
}

/*按户号显示小区信息*/
void displayCommunityByID()
{
	change = findCommunityname(rec);
	printf("$ 按户号显示小区电费记录信息 $\n");
	if (change)
	{
		printf(" 小区名：");
		printf("%-8s", rec[change].community);
		printf("\n");
		printf(" 户号:   户名：  峰时：          谷时：          总用电量：      电费：\n");
		int n = 0, x = 0;
		double f = 0.0, g = 0.0, all = 0.0, rate = 0.0;
		n = change;
		id = rec[n].id;
		while (n <= count)
		{
			if (rec[n].id == id)
			{

				f += rec[n].felectricity;
				g += rec[n].gelectricity;
				all += rec[n].electricity;
				rate += rec[n].power_rate;
				x++;
				n++;
			}
			else
			{
				n++;
			}
		}
		printf(" %-8s", rec[change].name);
		printf("%-8d", rec[change].id);
		printf("%-16lf", f);
		printf("%-16lf", g);
		printf("%-16lf", all);
		printf("%-16lf", rate);
		printf("%\n");
	}
	else
	{
		printf("住户信息中未找到该小区\n");
	}
}

/*通过小区名查找*/
int findCommunityname(Record* rec)
{
	int i = 1;
	char com[STR_LEN] = { 0 };
	printf(" 输入小区名：");
	scanf_s("%s", &com, 50);
	while (i <= count)
	{
		if (strcmp(rec[i].community, com) == 0);
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
		scanf_s("%s", rec[count].name, STR_LEN);
		printf(" 小区：");
		scanf_s("%s", rec[count].community, STR_LEN);
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

/*修改某月用电记录*/
void modifyRecord()
{

	printf(" 输入户号：");
	scanf_s("%d", &id);
	int year = 0;
	int month = 0;
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



/*修改小区名*/
void modifyname()
{
	printf(" 输入户号：");
	scanf_s("%d", &id);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("住户信息中未找到该住户\n");
	}
	else
	{
		printf(" 请输入小区名：");
		scanf_s("%s", &rec[change].community, STR_LEN);
	}
}

/*修改住户人数*/
void modifynumber()
{
	printf(" 输入户号：");
	scanf_s("%d", &id);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("住户信息中未找到该住户\n");
	}
	else
	{
		printf(" 请输入住户人数：");
		scanf_s("%d", &rec[change].number);
		int add = change;
		while (add <= count)
		{
			if (rec[add].id == id)
			{
				rec[add].power_rate = rate(rec[add].felectricity, rec[add].gelectricity, rec[add].electricity, rec[change].number, rec[add].join);
				add++;
			}
			else
			{
				add++;
			}
		}
	}
}

/*修改是否参加峰谷计费*/
void modifyjoin()
{
	printf(" 输入户号：");
	scanf_s("%d", &id);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("住户信息中未找到该住户\n");
	}
	else
	{
		printf(" 是否参加峰谷计费：");
		scanf_s("%d", &rec[change].join);
		int add = change;
		while (add <= count)
		{
			if (rec[add].id == id)
			{
				rec[add].power_rate = rate(rec[add].felectricity, rec[add].gelectricity, rec[add].electricity, rec[add].number, rec[change].join);
				add++;
			}
			else
			{
				add++;
			}
		}
	}
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
	int x = 0;
	double f = 0.0, g = 0.0, all = 0.0, rate = 0.0;
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
				f += rec[add].felectricity;
				g += rec[add].gelectricity;
				all += rec[add].electricity;
				rate += rec[add].power_rate;
				x++;
				add++;
			}
			else
			{
				add++;
			}
		}
		printf("%-16s", "总");
		printf("%-16lf", f);
		printf("%-16lf", g);
		printf("%-16lf", all);
		printf("%-16lf", rate);
		printf("%\n");
		printf("%-16s", "月均");
		printf("%-16lf", (f / x));
		printf("%-16lf", (g / x));
		printf("%-16lf", (all / x));
		printf("%-16lf", (rate / x));
		printf("%\n");
	}
	id = 0;
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