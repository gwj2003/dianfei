#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "maincontrol.h"
#include"menu.h"

extern int count;
extern int change;
extern int id;

/*显示相同住户标题*/
void displaysameTitle()
{
	printf("%-8s", "户号");
	printf("%-8s", "户名");
	printf("%-8s", "小区");
	printf("%-8s", "人数");
	printf("%-16s", "是否参与峰谷计价");
	printf("%-16s", "该小区是否已扩容");
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
	printf("%08d", rec[n].id);
	printf("%-8s", rec[n].name);
	printf("%-8s", rec[n].community);
	printf("%-8d", rec[n].number);
	printf("%-16d", rec[n].join);
	printf("%-16d", rec[n].list);
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

/*按日期显示小区信息*/;
void displayCommunityByDate()
{
	char com[STR_LEN] = { 0 };
	printf(" 输入小区名：");
	scanf_s("%s", com, 50);
	change = findCommunityname(rec, com);
	if (change)
	{
		printf(" 按日期显示小区电费记录信息\n");
		printf(" 1为已扩容，0为未扩容\n");
		printf(" 小区名：是否扩容：\n");
		printf(" %-8s", rec[change].community);
		printf("%-8d", rec[change].list);
		printf("\n");
		printf(" 年份:   月份：  峰时：          谷时：          总用电量：      电费：\n");
		int n = change;
		while (n)
		{
			int i = n;
			double f = 0.0, g = 0.0, all = 0.0, rate = 0.0;
			while (i <= count)
			{
				if ((strcmp(rec[i].community, com) == 0) && rec[n].year == rec[i].year && rec[n].month == rec[i].month)
				{
					rec[i].count = 0;
					f += rec[i].felectricity;
					g += rec[i].gelectricity;
					all += rec[i].electricity;
					rate += rec[i].power_rate;
					i++;
				}
				else
				{
					i++;
				}
			}
			printf(" %-8d", rec[n].year);
			printf("%-8d", rec[n].month);
			printf("%-16lf", f);
			printf("%-16lf", g);
			printf("%-16lf", all);
			printf("%-16lf", rate);
			printf("\n");
			n = findCommunityname(rec, com);
		}
		resetcount();
	}
	else
	{
		printf("住户信息中未找到该小区\n");
	}
	change = 0;
	id = 0;
}

/*按户号显示小区信息*/
void displayCommunityByID()
{
	char com[STR_LEN] = { 0 };
	printf(" 输入小区名：");
	scanf_s("%s", com, 50);
	change = findCommunityname(rec, com);
	if (change)
	{
		printf(" 按户号显示小区电费记录信息\n");
		printf(" 1为已扩容，0为未扩容\n");
		printf(" 小区名：是否扩容：\n");
		printf(" %-8s", rec[change].community);
		printf("%-8d", rec[change].list);
		printf("\n");
		printf(" 户号:   户名：  峰时：          谷时：          总用电量：      电费：\n");
		int n = change;
		while (n)
		{
			int i = n;
			id = rec[n].id;
			double f = 0.0, g = 0.0, all = 0.0, rate = 0.0;
			while (i <= count)
			{
				if (id == rec[i].id && rec[i].count)
				{
					rec[i].count = 0;
					f += rec[i].felectricity;
					g += rec[i].gelectricity;
					all += rec[i].electricity;
					rate += rec[i].power_rate;
					i++;
				}
				else
				{
					i++;
				}
			}
			printf(" %08d", rec[n].id);
			printf("%-8s", rec[n].name);
			printf("%-16lf", f);
			printf("%-16lf", g);
			printf("%-16lf", all);
			printf("%-16lf", rate);
			printf("\n");
			n = findCommunityname(rec, com);
		}
		resetcount();
	}
	else
	{
		printf("住户信息中未找到该小区\n");
	}
	change = 0;
	id = 0;
}

/*显示已扩容小区名单*/
void displayUnList()
{
	int n = 1;
	int i = 1;
	if (findlist())
	{
		printf("已扩容小区名单：\n");
		while (n <= count)
		{
			if (findCommunityname(rec, rec[n].community) && rec[n].list)
			{
				printf("%-8s\n", rec[n].community);
				i = n;
				while (i)
				{
					i = findCommunityname(rec, rec[n].community);
					rec[i].count = 0;
				}
				n++;
			}
			else
			{
				n++;
			}
		}
	}
	else
	{
		printf("住户信息中未找到已扩容小区\n");
	}
	resetcount();
}

/*显示未扩容小区名单*/
void displayList()
{
	int n = 1;
	int i = 1;
	if (findunlist())
	{
		printf("未扩容小区名单：\n");
		while (n <= count)
		{
			if (findCommunityname(rec, rec[n].community) && rec[n].list == 0)
			{
				printf("%-8s\n", rec[n].community);
				i = n;
				while (i)
				{
					i = findCommunityname(rec, rec[n].community);
					rec[i].count = 0;
				}
				n++;
			}
			else
			{
				n++;
			}
		}
	}
	else
	{
		printf("住户信息中未找到未扩容小区\n");
	}
	resetcount();
}

/*显示急需扩容小区名单*/
void displayneed()
{
	int i = 1;
	double a = 0.0;           /*统计小区月均超300度户数*/
	double b = 0.0;           /*统计小区户数*/
	double x = 0.0;           /*统计某户记录月份数*/
	int n = findunlist();
	int c = n;
	if (n)
	{
		printf("不急需扩容小区名单：\n");
		while (n)
		{
			while (c)
			{
				double all = 0.0;
				i = c;
				id = rec[c].id;
				while (i <= count)
				{
					if (id == rec[i].id && rec[i].count)
					{
						rec[i].count = 0;
						all += rec[i].electricity;
						i++;
						x++;
					}
					else
					{
						i++;
					}
				}
				if ((all / x) >= 300)
				{
					a++;
					b++;
				}
				else
				{
					b++;
				}
				c = findCommunityname(rec, rec[n].community);
			}
			if ((a / b) > 0.5)
			{
				printf("%-8s\n", rec[n].community);
			}
			a = 0.0;
			b = 0.0;
			x = 0.0;
			n = findunlist();
			c = findCommunityname(rec, rec[n].community);
		}
	}
	else
	{
		printf("住户信息中未找到未扩容小区\n");
	}
	resetcount();
}

/*显示不急需扩容小区名单*/
void displayunneeded()
{
	int i = 1;
	double a = 0.0;           /*统计小区月均超300度户数*/
	double b = 0.0;           /*统计小区户数*/
	double x = 0.0;           /*统计某户记录月份数*/
	int n = findunlist();
	int c = n;
	if (n)
	{
		printf("不急需扩容小区名单：\n");
		while (n)
		{
			while (c)
			{
				double all = 0.0;
				i = c;
				id = rec[c].id;
				while (i <= count)
				{
					if (id == rec[i].id && rec[i].count)
					{
						rec[i].count = 0;
						all += rec[i].electricity;
						i++;
						x++;
					}
					else
					{
						i++;
					}
				}
				if ((all / x) >= 300)
				{
					a++;
					b++;
				}
				else
				{
					b++;
				}
				c = findCommunityname(rec, rec[n].community);
			}
			if ((a / b) <= 0.5)
			{
				printf("%-8s\n", rec[n].community);
			}
			a = 0.0;
			b = 0.0;
			x = 0.0;
			n = findunlist();
			c = findCommunityname(rec, rec[n].community);
		}
	}
	else
	{
		printf("住户信息中未找到未扩容小区\n");
	}
	resetcount();
}

/*输入年月峰谷信息*/
void ynfg()
{
	do
	{
		printf(" 年份：");
		scanf_s("%d", &rec[count].year);
		if (2000 > rec[count].year || rec[count].year > 2023)
		{
			printf(" 请输入2000至2023之间的年份\n");
		}
	} while (2000 > rec[count].year || rec[count].year > 2023);
	do
	{
		printf(" 月份：");
		scanf_s("%d", &rec[count].month);
		if (1 > rec[count].month || rec[count].month > 12)
		{
			printf(" 请输入正确的月份\n");
		}
	} while (1 > rec[count].month || rec[count].month > 12);
	printf(" 峰时电量：");
	scanf_s("%lf", &rec[count].felectricity);
	printf(" 谷时电量：");
	scanf_s("%lf", &rec[count].gelectricity);
	rec[count].count = 1;
}

/*重置count信息*/
void resetcount()
{
	int i = 0;
	while (i <= count)
	{
		rec[i].count = 1;
		i++;
	}
}

/*添加住户选项*/
void addRecord()
{
	printf(" 添加住户信息\n");
	printf(" 正在录入住户信息……\n");
	count++;
	do
	{
		printf(" 户号：");
		scanf_s("%d", &rec[count].id);              /*先输入下一行的户号*/
		if (1 > rec[count].id || rec[count].id > 99999999)
		{
			printf(" 请输入小于八位的ID\n");
		}
	} while (1 > rec[count].id || rec[count].id > 99999999);
	change = findRecordID(rec, rec[count].id);     /*寻找是否已有相同的户号*/
	if (change)
	{
		printf(" 已有该用户信息：\n");             /*输出相同的信息*/
		displaysameTitle();
		displaysame(change);
		memcpy(rec[count].name, rec[change].name, STR_LEN);
		memcpy(rec[count].community, rec[change].community, STR_LEN);
		rec[count].number = rec[change].number;
		rec[count].join = rec[change].join;
		rec[count].list = rec[change].list;
		ynfg();
		rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
		rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[change].join);
		change = 0;                                /*把change改为0*/
	}
	else
	{
		printf(" 户名：");
		scanf_s("%s", rec[count].name, STR_LEN);
		printf(" 小区：");
		scanf_s("%s", rec[count].community, STR_LEN);
		ynfg();
		printf(" 人数：");
		scanf_s("%d", &rec[count].number);
		do
		{
			printf(" 是否参加峰谷计费：\n：");
			printf(" 1为参加，0为不参加\n");
			scanf_s("%d", &rec[count].join);
			if (0 == rec[count].join || 1 == rec[count].join)
			{
				printf(" 请输入0或1\n");
			}
		} while (0 == rec[count].join || 1 == rec[count].join);
		int n = findCommunityname(rec, rec[count].community);
		if (n)
		{
			rec[count].list = rec[n].list;
			rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
			rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
		}
		else
		{
			do
			{
				printf(" 该小区是否扩容：\n：");
				printf(" 1为已扩容，0为未扩容\n");
				scanf_s("%d", &rec[count].list);
				if (0 >rec[count].list || 1 < rec[count].list)
				{
					printf(" 请输入0或1\n");
				}
			} while (0 > rec[count].list || 1 < rec[count].list);
			rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
			rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
		}
	}
	printf("\n成功添加住户！\n\n");
}

/*删除住户选项*/
void removeRecord()
{
	int id = 0;
	int year = 0;
	int month = 0;
	printf(" 输入户号和日期查找要删除的电费记录信息 \n");
	do
	{
		printf(" 输入户号：");
		scanf_s("%d", &id);
		if (1 > id || id > 99999999)
		{
			printf(" 请输入小于八位的ID\n");
		}
	} while (1 > id || id > 99999999);
	do
	{
		printf(" 输入年份：");
		scanf_s("%d", &year);
		if (2000 > year || year > 2023)
		{
			printf(" 请输入2000至2023之间的年份\n");
		}
	} while (2000 > year || year > 2023);
	do
	{
		printf(" 输入月份：");
		scanf_s("%d", &month);
		if (1 > month || month > 12)
		{
			printf(" 请输入正确的月份\n");
		}
	} while (1 > month || month > 12);
	int n = findRecordByIDdate(rec, id, year, month);
	if (n)
	{
		while (n < count)
		{
			rec[n] = rec[++n];            /*用后一个数组覆盖前一个数组*/
		}
		count--;                          /*记录少了一行*/
		printf("\n已删除该条信息\n\n");
	}
	else
	{
		printf("住户信息中未找到该住户\n");
	}
}

/*修改某月用电记录*/
void modifyRecord()
{
	do
	{
		printf(" 输入户号：");
		scanf_s("%d", &id);
		if (1 > id || id > 99999999)
		{
			printf(" 请输入小于八位的ID\n");
		}
	} while (1 > id || id > 99999999);
	int year = 0;
	int month = 0;
	do
	{
		printf(" 输入年份：");
		scanf_s("%d", &year);
		if (2000 > year || year > 2023)
		{
			printf(" 请输入2000至2023之间的年份\n");
		}
	} while (2000 > year || year > 2023);
	do
	{
		printf(" 输入月份：");
		scanf_s("%d", &month);
		if (1 > month || month > 12)
		{
			printf(" 请输入正确的月份\n");
		}
	} while (1 > month || month > 12);
	change = findRecordByIDdate(rec, id, year, month);
	if (change)
	{
		printf(" 找到以下住户信息 \n");
		displaysameTitle();
		displaysame(change);
		displaydifferentTitle();
		displaydifferent(change);
		askfg();
		change = 0;
		printf(" 修改成功\n");
	}
	else
	{
		printf("住户信息中未找到该住户\n");
	}
}

/*修改小区名*/
void modifyname()
{
	do
	{
		printf(" 输入户号：");
		scanf_s("%d", &id);
		if (1 > id || id > 99999999)
		{
			printf(" 请输入小于八位的ID\n");
		}
	} while (1 > id || id > 99999999);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("住户信息中未找到该住户\n");
	}
	else
	{
		printf(" 请输入小区名：");
		int i = change;
		while (i <= count)
		{
			if (rec[i].id == id)
			{
				scanf_s("%s", &rec[i].community, STR_LEN);
				i++;
			}
			else
			{
				i++;
			}
		}
		printf(" 修改成功\n");
	}
}

/*修改住户人数*/
void modifynumber()
{
	do
	{
		printf(" 输入户号：");
		scanf_s("%d", &id);
		if (1 > id || id > 99999999)
		{
			printf(" 请输入小于八位的ID\n");
		}
	} while (1 > id || id > 99999999);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("住户信息中未找到该住户\n");
	}
	else
	{
		printf(" 请输入住户人数：");
		scanf_s("%d", &rec[change].number);
		int i = change;
		while (i <= count)
		{
			if (rec[i].id == id)
			{
				rec[i].power_rate = rate(rec[i].felectricity, rec[i].gelectricity, rec[i].electricity, rec[change].number, rec[i].join);
				i++;
			}
			else
			{
				i++;
			}
		}
		printf(" 修改成功\n");
	}
}

/*修改是否参加峰谷计费*/
void modifyjoin()
{
	do
	{
		printf(" 输入户号：");
		scanf_s("%d", &id);
		if (1 > id || id > 99999999)
		{
			printf(" 请输入小于八位的ID\n");
		}
	} while (1 > id || id > 99999999);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("住户信息中未找到该住户\n");
	}
	else
	{
		do
		{
			printf(" 1为参加，0为不参加\n");
			printf(" 是否参加峰谷计费：\n ");
			scanf_s("%d", &rec[count].join);
			if (0 > rec[count].join || 1 <  rec[count].join)
			{
				printf(" 请输入0或1\n");
			}
		} while (0 > rec[count].join || 1 < rec[count].join);
		int i = change;
		while (i <= count)
		{
			if (rec[i].id == id)
			{
				rec[i].power_rate = rate(rec[i].felectricity, rec[i].gelectricity, rec[i].electricity, rec[i].number, rec[change].join);
				i++;
			}
			else
			{
				i++;
			}
		}
		printf(" 修改成功\n");
	}
}

/*修改小区是否扩容*/
void modifylist()
{
	char com[STR_LEN] = { 0 };
	printf(" 输入小区名：");
	scanf_s("%s", com, 50);
	change = findCommunityname(rec, com);
	int n = change;
	if (change)
	{
		printf(" 小区名：是否扩容：\n");
		printf(" %-8s", rec[change].community);
		printf("%-8d", rec[change].list);
		printf("\n");
		do
		{
			printf(" 1为已扩容，0为未扩容\n");
			printf(" 是否扩容：\n ");
			scanf_s("%d", &rec[count].list);
			if (0 > rec[count].list || 1 < rec[count].list)
			{
				printf(" 请输入0或1\n");
			}
		} while (0 >rec[count].list || 1 < rec[count].list);
		while (n)
		{
			rec[n].list = rec[count].list;
			rec[n].count = 0;
			n = findCommunityname(rec, rec[n].community);
		}
		n = change;
		while (n < count)
		{
			rec[n].count = 1;
			n++;
		}
		printf(" 修改成功\n");
	}
	else
	{
		printf("住户信息中未找到该小区\n");
	}
	change = 0;
	id = 0;
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
	double f = 0.0, g = 0.0, all = 0.0, rate = 0.0, x = 0.0;
	printf(" 按户号查找电费记录信息\n");
	do
	{
		printf(" 输入户号：");
		scanf_s("%d", &id);
		if (1 > id || id > 99999999)
		{
			printf(" 请输入小于八位的ID\n");
		}
	} while (1 > id || id > 99999999);
	int n = findRecordByID(rec, id);
	int i = n;
	if (!i)
	{
		printf(" 住户信息中未找到该住户\n");
	}
	else
	{
		printf(" 1为参加、已扩容，0为未扩容、不参加\n");
		printf(" 找到以下住户信息\n");
		displaysameTitle();
		displaysame(n);
		displaydifferentTitle();
		while (i <= count)
		{
			if (rec[i].id == id)
			{
				displaydifferent(i);
				f += rec[i].felectricity;
				g += rec[i].gelectricity;
				all += rec[i].electricity;
				rate += rec[i].power_rate;
				x++;
				i++;
			}
			else
			{
				i++;
			}
		}
		printf("%-16s", "总");
		printf("%-16lf", f);
		printf("%-16lf", g);
		printf("%-16lf", all);
		printf("%-16lf", rate);
		printf("\n");
		printf("%-16s", "月均");
		printf("%-16lf", (f / x));
		printf("%-16lf", (g / x));
		printf("%-16lf", (all / x));
		printf("%-16lf", (rate / x));
		printf("\n");
	}
	id = 0;
}

/*通过户号查找已有住户选项*/
int findRecordID(Record* rec, int id)
{
	int i = 1;
	while (i < count)
	{
		if (rec[i].id == id)
		{
			return i;
		}
		i++;
	}
	return 0;
}

/*通过户号查找住户选项*/
int findRecordByID(Record* rec, int id)
{
	int i = 1;
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

/*通过小区名查找*/
int findCommunityname(Record* rec, char* com)
{
	int i = 1;
	while (i <= count)
	{
		if ((strcmp(rec[i].community, com) == 0) && rec[i].count)
		{
			return i;
		}
		i++;
	}
	return 0;
}

/*查找是否有小区扩容*/
int findlist()
{
	int i = 1;
	while (i <= count)
	{
		if (rec[i].list == 1 && rec[i].count)
		{
			return i;
		}
		i++;
	}
	return 0;
}

/*查找是否有小区未扩容*/
int findunlist()
{
	int i = 1;
	while (i <= count)
	{
		if (rec[i].list == 0 && rec[i].count)
		{
			return i;
		}
		i++;
	}
	return 0;
}

/*计算总电费*/
double rate(double felectricity, double gelectricity, double electricity, int number, int join)
{
	switch (join)
	{
	case 0:
		return unfgrate(electricity, number);
	case 1:
		return fgrate(felectricity, gelectricity, electricity, number);
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