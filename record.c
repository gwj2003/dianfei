#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "maincontrol.h"
#include"menu.h"

extern int count;
extern int change;
extern int id;

/*��ʾ��ͬס������*/
void displaysameTitle()
{
	printf("%-8s", "����");
	printf("%-8s", "����");
	printf("%-8s", "С��");
	printf("%-8s", "����");
	printf("%-8s", "�Ƿ����");
	printf("%-8s", "�Ƿ�����");
	printf("\n");
}

/*��ʾ��ͬס������*/
void displaydifferentTitle()
{
	printf("%-8s", "���");
	printf("%-8s", "�·�");
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
	printf("%-8d", rec[n].list);
	printf("\n");
}

/*��ʾ���ظ�ס����Ϣ*/
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

/*��������ʾС����Ϣ*/;
void displayCommunityByDate()
{
	char com[STR_LEN] = { 0 };
	printf(" ����С������");
	scanf_s("%s", com, 50);
	change = findCommunityname(rec, com);
	if (change)
	{
		printf("$ ��������ʾС����Ѽ�¼��Ϣ $\n");
		printf(" С�������Ƿ����ݣ�\n");
		printf(" %-8s", rec[change].community);
		printf("%-8d", rec[change].list);
		printf("\n");
		printf(" ���:   �·ݣ�  ��ʱ��          ��ʱ��          ���õ�����      ��ѣ�\n");
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
		printf("ס����Ϣ��δ�ҵ���С��\n");
	}
	change = 0;
	id = 0;
}

/*��������ʾС����Ϣ*/
void displayCommunityByID()
{
	char com[STR_LEN] = { 0 };
	printf(" ����С������");
	scanf_s("%s", com, 50);
	change = findCommunityname(rec, com);
	if (change)
	{
		printf("$ ��������ʾС����Ѽ�¼��Ϣ $\n");
		printf(" С�������Ƿ����ݣ�\n");
		printf(" %-8s", rec[change].community);
		printf("%-8d", rec[change].list);
		printf("\n");
		printf(" ����:   ������  ��ʱ��          ��ʱ��          ���õ�����      ��ѣ�\n");
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
			printf(" %-8d", rec[n].id);
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
		printf("ס����Ϣ��δ�ҵ���С��\n");
	}
	change = 0;
	id = 0;
}

/*��ʾ������С������*/
void displayUnList()
{
	int n = 1;
	int i = 1;
	if (findlist())
	{
		printf("������С��������\n");
		while (n <=count)
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
		printf("ס����Ϣ��δ�ҵ�������С��\n");
	}
	resetcount();
}

/*��ʾδ����С������*/
void displayList()
{
	int n = 1;
	int i = 1;
	if (findunlist())
	{
		printf("δ����С��������\n");
		while (n <=count)
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
		printf("ס����Ϣ��δ�ҵ�δ����С��\n");
	}
	resetcount();
}

/*��ʾ��������С������*/
void displayneed()
{
	int i = 1;
	double a = 0.0;/*ͳ��С���¾���300������*/
	double b = 0.0;/*ͳ��С������*/
	double x = 0.0;/*ͳ��ĳ����¼�·���*/
	int n = findunlist();
	int c = n;
	if (n)
	{
		printf("����������С��������\n");
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
		printf("ס����Ϣ��δ�ҵ�δ����С��\n");
	}
	resetcount();
}

/*��ʾ����������С������*/
void displayunneeded()
{
	int i = 1;
	double a = 0.0;/*ͳ��С���¾���300������*/
	double b = 0.0;/*ͳ��С������*/
	double x = 0.0;/*ͳ��ĳ����¼�·���*/
	int n = findunlist();
	int c = n;
	if (n)
	{
		printf("����������С��������\n");
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
		printf("ס����Ϣ��δ�ҵ�δ����С��\n");
	}
	resetcount();
}

/*�������·����Ϣ*/
void ynfg()
{
	printf(" ��ݣ�");
	scanf_s("%d", &rec[count].year);
	printf(" �·ݣ�");
	scanf_s("%d", &rec[count].month);
	printf(" ��ʱ������");
	scanf_s("%lf", &rec[count].felectricity);
	printf(" ��ʱ������");
	scanf_s("%lf", &rec[count].gelectricity);
	rec[count].count = 1;
}

/*����count��Ϣ*/
void resetcount()
{
	int i = 0;
	while (i <= count)
	{
		rec[i].count = 1;
		i++;
	}
}

/*���ס��ѡ��*/
void addRecord()
{
	printf("$ ���ס����Ϣ $\n");
	count++;
	printf("$ ¼��ס����Ϣ $\n");
	printf(" ���ţ�");
	scanf_s("%d", &rec[count].id);                 /*��������һ�еĻ���*/                     
	change = findRecordByID(rec, rec[count].id);   /*Ѱ���Ƿ�������ͬ�Ļ���*/
	if (change)
	{
		printf(" ���и��û���Ϣ��\n");             /*�����ͬ����Ϣ*/
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
		change = 0;                               /*��change��Ϊ0*/
	}
	else
	{
		printf(" ������");
		scanf_s("%s", rec[count].name, STR_LEN);
		printf(" С����");
		scanf_s("%s", rec[count].community, STR_LEN);
		ynfg();
		printf(" ������");
		scanf_s("%d", &rec[count].number);
		printf(" �Ƿ�μӷ�ȼƷѣ�");
		scanf_s("%d", &rec[count].join);
		int n = findCommunityname(rec, rec[count].community);
		if (n)
		{
			rec[count].list = rec[n].list;/*�����ܵ��������*/
			rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
			rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
		}
		else
		{
			printf(" �Ƿ����ݣ�");
			scanf_s("%d", &rec[count].list);/*�����ܵ��������*/
			rec[count].electricity = rec[count].felectricity + rec[count].gelectricity;
			rec[count].power_rate = rate(rec[count].felectricity, rec[count].gelectricity, rec[count].electricity, rec[count].number, rec[count].join);
		}
	}
	printf("\n�ɹ����ס����\n");
}

/*ɾ��ס��ѡ��*/
void removeRecord()
{
	int id = 0;
	int year = 0;
	int month = 0;
	printf("$ ���뻧�ź����ڲ���Ҫɾ���ĵ�Ѽ�¼��Ϣ $\n");
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	printf(" ������ݣ�");
	scanf_s("%d", &year);
	printf(" �����·ݣ�");
	scanf_s("%d", &month);
	int n = findRecordByIDdate(rec, id, year, month);
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

/*�޸�ĳ���õ��¼*/
void modifyRecord()
{

	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	int year = 0;
	int month = 0;
	printf(" ������ݣ�");
	scanf_s("%d", &year);
	printf(" �����·ݣ�");
	scanf_s("%d", &month);
	change = findRecordByIDdate(rec, id, year, month);
	if (change)
	{
		printf("$ �ҵ�����ס����Ϣ $\n");
		displaysameTitle();
		displaysame(change);
		displaydifferentTitle();
		displaydifferent(change);
		askfg();
		change = 0;
	}
	else
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
}

/*�޸�С����*/
void modifyname()
{
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
	else
	{
		printf(" ������С������");
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
	}
}

/*�޸�ס������*/
void modifynumber()
{
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
	else
	{
		printf(" ������ס��������");
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
	}
}

/*�޸��Ƿ�μӷ�ȼƷ�*/
void modifyjoin()
{
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	change = findRecordByID(rec, id);
	if (!change)
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
	else
	{
		printf(" �Ƿ�μӷ�ȼƷѣ�");
		scanf_s("%d", &rec[change].join);
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
	}
}

/*�޸�С���Ƿ�����*/
void modifylist()
{
	char com[STR_LEN] = { 0 };
	printf(" ����С������");
	scanf_s("%s", com, 50);
	change = findCommunityname(rec, com);
	int n = change;
	if (change)
	{
		printf(" С�������Ƿ����ݣ�\n");
		printf("%-8s", rec[change].community);
		printf("%-8d", rec[change].list);
		printf("\n");
		printf(" �Ƿ����ݣ�");
		scanf_s("%d", &rec[count].list);
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
	}
	else
	{
		printf("ס����Ϣ��δ�ҵ���С��\n");
	}
	change = 0;
	id = 0;
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
	double f = 0.0, g = 0.0, all = 0.0, rate = 0.0, x = 0.0;
	printf("$ �����Ų��ҵ�Ѽ�¼��Ϣ $\n");
	printf(" ���뻧�ţ�");
	scanf_s("%d", &id);
	int n = findRecordByID(rec, id);
	int i = n;
	if (!i)
	{
		printf("ס����Ϣ��δ�ҵ���ס��\n");
	}
	else
	{
		printf("$ �ҵ�����ס����Ϣ $\n");
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
		printf("%-16s", "��");
		printf("%-16lf", f);
		printf("%-16lf", g);
		printf("%-16lf", all);
		printf("%-16lf", rate);
		printf("\n");
		printf("%-16s", "�¾�");
		printf("%-16lf", (f / x));
		printf("%-16lf", (g / x));
		printf("%-16lf", (all / x));
		printf("%-16lf", (rate / x));
		printf("\n");
	}
	id = 0;
}

/*ͨ�����Ų���ס��ѡ��*/
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

/*ͨ�����ź����ڲ���ס��ѡ��*/
int findRecordByIDdate(Record* rec, int id, int year, int month)
{
	int i = 0;
	while (i <= count)
	{
		if ((rec[i].id == id) && (rec[i].year == year) && (rec[i].month == month))   /*��������ͬʱ����*/
		{
			return i;
		}
		i++;
	}
	return 0;
}

/*ͨ��С��������*/
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

/*�����Ƿ���С������*/
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

/*�����Ƿ���С��δ����*/
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

/*�����ܵ��*/
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