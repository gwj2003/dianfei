#include<stdio.h>
#include<string.h>
#include"�����С����ͥ.h"
//#include"���.h"
#define xform 50
#define yform 250
//���㺯��
//��ͥ���ݼ���
//����ĳ��ͥÿ��ÿ���õ���
void calFamMonthEle(Family *fam,int *famMonthEle)
{
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			*(famMonthEle+(year*12)+month) = fam->famPeak[year][month] + fam->famValley[year][month];
		}
	}
}
//����ĳ��ͥÿ��ÿ���õ�����
void formFamMonthEle(Family* fam)
{
	gotoxy(xform, 247);
	printf("�ü�ͥ��ÿ��ÿ���õ��������£�");
	int famMonthEle[2][12] = { 0 };
	calFamMonthEle(fam, famMonthEle);
	for (int i = -1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 12 * 2 + 1; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform + 7, yform + 2 * i - 1);
		for (int j = 1; j <= 2; j++)
		{
			gotoxy(xform +j*7, yform + 2 * i - 1);
			printf("%7d", famMonthEle[j-1][i-1]);
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("%5d��", i);
	}
	gotoxy(xform + 7 * 1, yform - 1);
	printf("  2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("  2022\n");
}
//����ĳ��ͥÿ��ÿ�µ��
void calFamMonthFee(Family *fam, double *famMonthFee)
{
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			*(famMonthFee+(year*12)+month)= fam->famPeak[year][month] * peakFee + fam->famValley[year][month] * valleyFee;
		}
	}
}
//����ĳ��ͥÿ��ÿ�µ�ѱ�
void formFamMonthFee(Family* fam)
{
	gotoxy(xform, 247);
	printf("�ü�ͥ��ÿ��ÿ�µ�ѱ����£�");
	double famMonthFee[2][12] = { 0 };
	calFamMonthFee(fam, famMonthFee);
	for (int i = -1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 12 * 2 + 1; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform + 7, yform + 2 * i - 1);
		for (int j = 1; j <= 2; j++)
		{
			gotoxy(xform + j * 7, yform + 2 * i - 1);
			printf("%7.1lf", famMonthFee[j - 1][i - 1]);
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("%5d��", i);
	}
	gotoxy(xform + 7 * 1, yform - 1);
	printf("  2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("  2022\n");
}
//����ĳ��ͥĳ�����õ���
void calFamYearTotalEle(Family *fam,int *famYearTotalEle, int *famMonthEle)
{
	calFamMonthEle(fam, famMonthEle);
	for (int year = 0; year < 2; year++)
	{
		for (int i = 0; i < 12; i++)
		{
			*(famYearTotalEle+year) += *(famMonthEle+(year*12) + i);
		}
	}
}
//����ĳ��ͥÿ�����õ�����
void formFamYearTotalEle(Family* fam)
{
	gotoxy(xform, 247);
	printf("�ü�ͥ��ÿ���õ��������£�");
	int famYearTotalEle[2] = { 0 };
	int famMonthEle[2][12] = { 0 };
	calFamYearTotalEle(fam, famYearTotalEle, famMonthEle);
	for (int i = -1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 3; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform + 7*i, yform + 1);
		for (int j = 0; j < 2; j++)
		{
			printf("%7d", famYearTotalEle[j]);
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i-1);
		printf("   ����");
	}
	gotoxy(xform+ 7, yform - 1);
	printf("   2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("   2022\n");
}
//����ĳ��ͥÿ���ܵ��
void calFamYearTotalFee(Family *fam, double *famYearTotalFee, double *famMonthFee)
{
	calFamMonthFee(fam, famMonthFee);
	for (int year = 0; year < 2; year++)
	{
		for (int i = 0; i < 12; i++)
		{
			*(famYearTotalFee+year) += *(famMonthFee+year*12+i);
		}
	}
}
//����ĳ��ͥÿ���ܵ�ѱ�
void formFamYearTotalFee(Family* fam)
{
	gotoxy(xform, 247);
	printf("�ü�ͥ��ÿ���ܵ�ѱ����£�");
	double famYearTotalFee[2] = { 0 };
	double famMonthFee[2][12] = { 0 };
	calFamYearTotalFee(fam, famYearTotalFee, famMonthFee);
	for (int i = -1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 3; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform + 7 * i, yform + 1);
		for (int j = 0; j < 2; j++)
		{
			printf("%7.1lf", famYearTotalFee[j]);
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("   ����");
	}
	gotoxy(xform + 7, yform - 1);
	printf("   2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("   2022\n");
}

//С�����ݼ���

//����ĳС��ÿ�·�ʱ�õ���
void calComPeak(Community *com, int *comPeak)
{
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			Family* p = com->head;
			for (int i = 0; i < com->n; i++)
			{
				*(comPeak+year*12+month) += p->famPeak[year][month];
				p = p->next;
			}
			*(comPeak + year * 12 + month) = (*(comPeak + year * 12 + month));
		}
	}
}
//����ĳС��ÿ�·�ʱ�õ�����
void formComPeak(Community* com)
{
	gotoxy(xform, 247);
	printf("��С����ÿ�·�ʱ�õ��������£�");
	int comPeak[2][12] = { 0 };
	calComPeak(com, comPeak);
	for (int i = -1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 12 * 2 + 1; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform + 7, yform + 2 * i - 1);
		for (int j = 1; j <= 2; j++)
		{
			gotoxy(xform + j * 7, yform + 2 * i - 1);
			printf("%7d", comPeak[j - 1][i - 1]);
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("%5d��", i);
	}
	gotoxy(xform + 7 * 1, yform - 1);
	printf("  2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("  2022\n");
}
//����ĳС��ÿ�¹�ʱ�õ���
void calComValley(Community *com, int *comValley)
{
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			Family* p = com->head;
			for (int i = 0; i < com->n; i++)
			{
				*(comValley+year*12+month) += p->famValley[year][month];
				p = p->next;
			}
			*(comValley + year * 12 + month) = (*(comValley + year * 12 + month)) / 10000;
		}
	}
}
//����ĳС��ÿ�¹�ʱ�õ�����
void formComValley(Community* com)
{
	gotoxy(xform, 247);
	printf("��С����ÿ�¹�ʱ�õ��������£�");
	int comValley[2][12] = { 0 };
	calComValley(com, comValley);
	for (int i = -1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 12 * 2 + 1; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform + 7, yform + 2 * i - 1);
		for (int j = 1; j <= 2; j++)
		{
			gotoxy(xform + j * 7, yform + 2 * i - 1);
			printf("%7d", comValley[j - 1][i - 1]);
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("%5d��", i);
	}
	gotoxy(xform + 7 * 1, yform - 1);
	printf("  2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("  2022\n");
}
//����ĳС��ÿ�����õ���
void calComMonthTotalEle(Community *com,int *comMonthTotalEle)
{
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			Family* p = com->head;
			for (int i = 0; i < com->n; i++)
			{
				*(comMonthTotalEle+year*12+month) += (p->famPeak[year][month]+p->famValley[year][month]);
				p = p->next;
			}
			*(comMonthTotalEle + year * 12 + month) = (*(comMonthTotalEle + year * 12 + month)) / 10000;
		}
	}
	
}
//����ĳС��ÿ�����õ�����
void formComMonthTotalEle(Community* com)
{
	gotoxy(xform, 247);
	printf("��С����ÿ�����õ��������£�");
	int comMonthTotalEle[2][12] = { 0 };
	calComMonthTotalEle(com,comMonthTotalEle);
	for (int i = -1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 12 * 2 + 1; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform + 7, yform + 2 * i - 1);
		for (int j = 1; j <= 2; j++)
		{
			gotoxy(xform + j * 7, yform + 2 * i - 1);
			printf("%7d", comMonthTotalEle[j - 1][i - 1]);
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("%5d��", i);
	}
	gotoxy(xform + 7 * 1, yform - 1);
	printf("  2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("  2022\n");
}
//����ĳС��ÿ���ܵ��
void calComMonthTotalFee(Community* com, double *comMonthTotalFee)
{
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			Family* p = com->head;
			for (int i = 0; i < com->n; i++)
			{
				*(comMonthTotalFee+year*12+month) += (p->famPeak[year][month] * peakFee + p->famValley[year][month] * valleyFee);
				p = p->next;
			}
			*(comMonthTotalFee + year * 12 + month) = (*(comMonthTotalFee + year * 12 + month)) / 10000;
		}
	}
}
//����ĳС��ÿ���ܵ�ѱ��
void formComMonthTotalFee(Community *com)
{
	gotoxy(xform, yform-3);
	printf("��С����ÿ���ܵ�ѱ����£�");
	double comMonthTotalFee[2][12] = { 0 };
	calComMonthTotalFee(com, comMonthTotalFee);
	for (int i = -1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 12 * 2 + 1; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform + 7, yform + 2 * i - 1);
		for (int j = 1; j <= 2; j++)
		{
			gotoxy(xform + j * 7, yform + 2 * i - 1);
			printf("%7.2lf", comMonthTotalFee[j - 1][i - 1]);
		}
	}
	for (int i = 1; i < 12 + 1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("%5d��", i);
	}
	gotoxy(xform + 7 * 1, yform - 1);
	printf("  2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("  2022\n");
}
//����ĳС��ÿ�����õ���
void calComYearTotalEle(Community *com,int *comYearTotalEle,int *comMonthTotalEle)
{
	calComMonthTotalEle(com, comMonthTotalEle);
	for (int year = 0; year < 2; year++)
	{
		for (int i = 0; i < 12; i++)
		{
			*(comYearTotalEle+year) += *(comMonthTotalEle+year*12+i);
		}
		*(comYearTotalEle + year) = (*(comYearTotalEle + year)) / 10000;
	}
}
//����ĳС��ÿ�����õ���
void formComYearTotalEle(Community* com)
{
	gotoxy(xform,yform-3);
	printf("��С����ÿ�����õ��������£�");
	int comYearTotalEle[2] = { 0 };
	int comMonthTotalEle[2][12] = { 0 };
	calComYearTotalEle(com, comYearTotalEle, comMonthTotalEle);
	for (int i = -1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 3; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform + 7 * i, yform + 1);
		for (int j = 0; j < 2; j++)
		{
			printf("%7d", comYearTotalEle[j]);
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("   ����");
	}
	gotoxy(xform + 7, yform - 1);
	printf("   2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("   2022\n");
}
//����ĳС��ÿ���ܵ��
void calComYearTotalFee(Community *com,double *comYearTotalFee,double *comMonthTotalFee)
{
	calComMonthTotalFee(com, comMonthTotalFee);
	for (int year = 0; year < 2; year++)
	{
		for (int i = 0; i < 12; i++)
		{
			*(comYearTotalFee + year) += *(comMonthTotalFee+year*12+i);
		}
		*(comYearTotalFee + year) = (*(comYearTotalFee + year)) / 10000;
	}
}
//����ĳС��ÿ���ܵ�ѱ�
void formComYearTotalFee(Community* com)
{
	gotoxy(xform, yform-3);
	printf("��С�������ܵ�ѱ����£�");
	double comYearTotalFee[2] = { 0 };
	double comMonthTotalFee[2][12] = { 0 };
	calComYearTotalFee(com, comYearTotalFee, comMonthTotalFee);
	for (int i = -1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < 3; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform + 7 * i, yform + 1);
		for (int j = 0; j < 2; j++)
		{
			printf("%7.2lf", comYearTotalFee[j]);
		}
	}
	for (int i = 1; i < 2; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("   ����");
	}
	gotoxy(xform + 7, yform - 1);
	printf("   2021");
	gotoxy(xform + 7 * 2, yform - 1);
	printf("   2022\n");
}
//����ĳС��ÿ��ƽ���õ���
double calAverageELe(Community *com)
{
	int comYearTotalEle[2] = { 0 };
	int comMonthTotalEle[2][12] = { 0 };
	calComYearTotalEle(com, comYearTotalEle, comMonthTotalEle);
	double average;
	average= (comYearTotalEle[0]+comYearTotalEle[1]) / 2;
	printf("��С��ÿ��ÿ��ƽ���õ���Ϊ��%lf", average);
	return average;
}
//����ĳС��ÿ��ƽ�����
double calAverageFee(Community *com)
{
	double average;
	int comYearTotalFee[2] = { 0 };
	int comMonthTotalFee[2][12] = { 0 };
	calComMonthTotalFee(com, comYearTotalFee, comMonthTotalFee);
	average = (comYearTotalFee[0] + comYearTotalFee[1]) / 2;
	printf("��С��ÿ��ÿ��ƽ�����Ϊ��%lf", average);
	return average;
}

int calComTotalPeak(Community *com)//����ĳС�������ڵķ�ʱ�õ�����
{
	int comPeak[2][12] = { 0 };
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			Family* p = com->head;
			for (int i = 0; i < com->n; i++)
			{
				comPeak[year][month] += p->famPeak[year][month];
				p = p->next;
			}
		}
	}
	int total = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			total += comPeak[i][j];
		}
	}
	return total;
}
int calComTotalValley(Community *com)//����ĳС�������ڵĹ�ʱ�õ�����
{
	int comValley[2][12] = { 0 };
	for (int year = 0; year < 2; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			Family* p = com->head->next;
			for (int i = 0; i < com->n; i++)
			{
				comValley[year][month] += p->famValley[year][month];
				p = p->next;
			}
		}
	}
	int total = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			total += comValley[i][j];
		}
	}
	return total;
}


//������
//��ʱ�õ�������
void sortComPeak(Administration *adm)
{
	if (adm->head == NULL)
	{
		printf("����Ϊ�գ�ð������ʧ��\n");
		return NULL;
	}
	else
	{

		Community* p = adm->head; //�ƶ�ָ��
		Community* q = p->next;
		int pComTotalPeak = calComTotalPeak(p);
		int qComTotalPeak = calComTotalPeak(q);
		//��Ҫ����(n-1)�α���,���� 3 2 1 ��ô������Ԫ��1�ƶ�����һ��λ������Ҫ����3-1=2���ƶ�  
		for (int i = 0; i < adm->n - 1; i++)
		{
			//���ﲻ����pMove != NULL ��Ϊ����Ƚ���pMove-date ��pMove-next-date�Ƚϡ�������pMove-next != NULL
			//pMove-next���pMove�ȵ���NULL
			while (p->next != NULL)
			{
				if (pComTotalPeak > qComTotalPeak)//�����Ƚ�,ÿ�ζ���С�ķŵ�ǰ�档Ȼ�������ƶ��������Ƚ�
				{
					//ֻҪ�����������ڵ��Ԫ��ֵ�Ϳ�����
					char midName[20];
					strcpy_s(midName, 21,p->comName);
					strcpy_s(p->comName,21,q->comName);
					strcpy_s(q->comName,21,midName);
					int midN = p->n;
					p->n = q->n;
					q->n = midN;
					Family* midHead = p->head;
					p->head = q->head;
					q->head = midHead;
				}
				p = p->next;             //�ƶ�ָ��������±Ƚ�

			}
			//printf("��%d���������:\n",i+1);
			//Print_all_ListNode(phead);
			//ÿ�α���������pMove�����ƶ�������ͷ��,����һ�������Ƚ�,һ����Ҫn-1�������Ƚ�
			p = adm->head;
		}
	}
}
//���Ʒ�ʱ�õ��������
void formSortComPeak(Administration* adm)
{
	gotoxy(xform, yform-3);
	printf("��ʱ������������£�");
	sortComPeak(adm);
	Community* p = adm->head;
	for (int i = -1; i < adm->n+1; i++)
	{
		gotoxy(xform,yform + 2 * i);
		for (int j = 0; j < 2 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(xform + i * 7, yform);
		for (int j = -1; j < (adm->n+1) * 2 - 1; j++)
		{
			gotoxy(xform + i * 7, yform + j);
			printf("|");
		}
	}
	for (int i = 1; i < adm->n+1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("%7s", p->comName);
		gotoxy(xform + 7, yform + 2 * i - 1);
		printf("%7d", calComTotalPeak(p));
		p = p->next;
	}
	for (int i = 1; i < adm->n+1; i++)
	{
		gotoxy(xform, yform + 2 * i - 1);
		printf("  %d", i);
	}
	gotoxy(xform+ 1, yform - 1);
	printf("С��");
	gotoxy(xform + 7 + 1, yform - 1);
	printf("����");
}
//ÿ�µ����������
void sortComFee(Administration *adm)
{
	int year, month;
	printf("������������ݵĲɼ�ʱ�䣺\n��ݣ�");
	scanf_s("%d", &year);
	printf("�·ݣ�");
	scanf_s("%d", &month);
	if (year < 2021 || year>2022 || month < 1 || month>12)//ʱ����
	{
		printf("ʱ����������򳬷����������ڷ�Χ2021��1��-2022��12���ʱ�䣩\n����������\n");
		sortComAverageFee(adm);
	}
	else
	{
		Community* head0 = (Community*)malloc(sizeof(Community) * 1);
		head0->next = adm->head;
		Community* p = head0->next, * pre;
		Community* r = p->next;
		p->next = NULL;
		p = r;
		while (p != NULL)
		{
			r = p->next;
			pre = head0;
			int preNextComMonthTotalFee[2][12] = { 0 };
			int pComMonthTotalFee[2][12] = { 0 };
			calComMonthTotalFee(pre->next, preNextComMonthTotalFee);
			calComMonthTotalFee(p->next, pComMonthTotalFee);
			while (pre->next != NULL && preNextComMonthTotalFee[year - 1][month - 1] < pComMonthTotalFee[year - 1][month - 1])
			{
				pre = pre->next;
				int preNextComMonthTotalFee[2][12] = { 0 };
				calComMonthTotalFee(pre->next, preNextComMonthTotalFee);
			}
			p->next = pre->next;
			pre->next = p;
			p = r;
		}
		free(head0);
	}
}
//����ÿ�µ�����������
void formSortComFee(Administration *adm)
{
	int month;
	int year;
	printf("����Ҫ��һ�꣬���·ݵ�С��������������������һ����ݺ��·ݣ�����2022.2)");
	scanf_s("%d.%d", &year,&month);
	sortComFee(adm, year, month);
	Community* head0 = (Community*)malloc(sizeof(Community) * 1);
	head0->next = adm->head;
	Community* p = head0->next, * pre;
	gotoxy(xform, 527);
	printf("ÿ�µ�����������£�");
	for (int i = -1; i < adm->n + 1; i++)
	{
		gotoxy(xform, 530 + 2 * i);
		for (int j = 0; j < 3 * 7; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 7, 530);
		for (int j = -1; j < (adm->n+1) * 2 - 1; j++)
		{
			gotoxy(xform + i * 7, 530 + j);
			printf("|");
		}
	}
	for (int i = 1; i < adm->n + 1; i++)
	{
		gotoxy(xform + 7, 530 + 2 * i - 1);
		printf("%7s", p->comName);
		gotoxy(xform + 7 * 2, 530 + 2 * i - 1);
		int monthFee[2][12] = { 0 };
		calComMonthTotalFee(p, monthFee);
		printf("%7d", monthFee[year-2021][month-1]);
		p = p->next;
	}
	for (int i = 1; i < adm->n+1; i++)
	{
		gotoxy(xform,530 + 2 * i - 1);
		printf("  %d", i);
	}
	gotoxy(xform + 7 + 1, 530 - 1);
	printf("%С��");
	gotoxy(xform + 7 * 2 + 1, 530 - 1);
	printf("���");
	free(head0);
}
//С��ÿ��ƽ����������
void sortComAverageEle(Administration *adm)
{
	Community* head0 = (Community*)malloc(sizeof(Community) * 1);
	head0->next = adm->head;
	Community* p = head0->next, * pre;
	Community* r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = adm->head;
		int preNextAverageEle = calAverageELe(pre->next);
		int pAverageEle = calAverageELe(p);
		while (pre->next != NULL && preNextAverageEle<pAverageEle)
		{
			pre = pre->next;
			int preNextAverageEle = calAverageELe(pre->next);
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
//����С��ÿ��ƽ�����������
void formSortComAverageEle(Administration* adm)
{
	gotoxy(xform, 447);
	printf("�ü�ͥ��ÿ��ÿ���õ��������£�");
	sortComAverageEle(adm);
	Community* head0 = (Community*)malloc(sizeof(Community) * 1);
	head0->next = adm->head;
	Community* p = head0->next, * pre;
	for (int i = -1; i < adm->n+1; i++)
	{
		gotoxy(xform, 450 + 2 * i);
		for (int j = 0; j < 3 * 10; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 10, 450);
		for (int j = -1; j < (adm->n+1) * 2 - 1; j++)
		{
			gotoxy(xform + i * 10, 450 + j);
			printf("|");
		}
	}
	for (int i = 1; i < adm->n+1; i++)
	{
		gotoxy(xform + 10, 450 + 2 * i - 1);
		printf("%7s   ", p->comName);
		gotoxy(xform + 10 * 2, 450 + 2 * i - 1);
		printf("%10lf", calAverageELe(p));
	}
	for (int i = 1; i < adm->n+1; i++)
	{
		gotoxy(xform, 450 + 2 * i - 1);
		printf("    %d", i);
	}
	gotoxy(xform + 10 + 1, 450 - 1);
	printf("  С��");
	gotoxy(xform + 10 * 2 + 1, 450 - 1);
	printf("ƽ������");
	free(head0);
}
//ÿ��ƽ���������
void sortComAverageFee(Administration *adm)
{
	Community* head0 = (Community*)malloc(sizeof(Community) * 1);
	head0->next = adm->head;
	Community* p = head0->next, * pre;
	Community* r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = head0;
		double preNextAverageFee = calAverageFee(pre->next);
		double pAverageFee = calAverageFee(p);
		while (pre->next != NULL && preNextAverageFee<pAverageFee)
		{
			pre = pre->next;
			double preNextAverageFee = calAverageFee(pre->next);
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	free(head0);
}
//����С��ÿ��ƽ����������
void formSortComAverage(Administration* adm)
{
	gotoxy(xform, 487);
	printf("�ü�ͥ��ÿ��ÿ���õ��������£�");
	sortComAverageFee(adm);
	Community* head0 = (Community*)malloc(sizeof(Community) * 1);
	head0->next = adm->head;
	Community* p = head0->next, * pre;
	for (int i = -1; i < adm->n + 1; i++)
	{
		gotoxy(xform, 490 + 2 * i);
		for (int j = 0; j < 3 * 10; j++)
		{
			printf("_");
		}
	}
	for (int i = 0; i < 3 + 1; i++)
	{
		gotoxy(xform + i * 10, 490);
		for (int j = -1; j < (adm->n + 1) * 2 - 1; j++)
		{
			gotoxy(xform + i * 10, 490 + j);
			printf("|");
		}
	}
	for (int i = 1; i < adm->n + 1; i++)
	{
		gotoxy(xform + 10, 490 + 2 * i - 1);
		printf("%7s   ", p->comName);
		gotoxy(xform + 10 * 2, 490 + 2 * i - 1);
		printf("%10lf", calAverageFee(p));
	}
	for (int i = 1; i < adm->n + 1; i++)
	{
		gotoxy(xform, 490 + 2 * i - 1);
		printf("    %d", i);
	}
	gotoxy(xform + 10 + 1, 490 - 1);
	printf("  С��");
	gotoxy(xform + 10 * 2 + 1, 490 - 1);
	printf("ƽ�����");
	free(head0);
}
Community* findCommunity(Administration *adm)//��С��
{
	char goal[20];
	char f[20];
	int y = 0;//��֤�Ƿ��ҵ�
	printf("������С������");
	scanf_s("%s", goal,20);
	Community* p = adm->head;
	for (int i = 0; i < adm->n; i++)
	{
		if (strcmp(goal,p->comName)==0)
		{
			y = 1;
			break;
		}
		else
		{
			p = p->next;
		}
	}
	if (y == 1)
	{
		return p;
	}
	else
	{
		printf("�޸�С��\n");
		system("puase");
		return NULL;
	}
}
Family* findFamily(Community* com)//�Ҽ�ͥ
{
	char goal[20];
	int y = 0;//��֤�Ƿ��ҵ�
	printf("�������ͥ����");
	scanf_s("%s", goal,20);
	Family* p = com->head;
	for (int i = 0; i < com->n; i++)
	{
		if (strcmp(goal,p->famName)==0)
		{
			y = 1;
			break;
		}
		else
		{
			p = p->next;
		}
	}
	if (y == 1)
	{
		return p;
	}
	else
	{
		printf("�޸ü�ͥ\n");
		return NULL;
	}
}
//����С����������õ���
int calComTotalEle(Community* com)
{
	int comYearTotalEle[2] = { 0 };
	int comMonthTotalEle[2][12] = { 0 };
	calComYearTotalEle(com, comYearTotalEle, comMonthTotalEle);
	int total = 0;
	for (int i = 0; i < 2; i++)
	{
		total += comYearTotalEle[i];
	}
	return total;
}
//�г��������ݵ�С����������
void FindKuoRongCommunity(Administration* adm)
{
	Community* head0 = (Community*)malloc(sizeof(Community) * 1);
	head0->next = adm->head;
	head0->n = 0;
	Community* p = head0->next, * pre;
	Community* r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = head0;
		int preNextComTotalPeak = calComTotalEle(pre->next);
		int pComTotalPeak = calComTotalEle(p);
		while (pre->next != NULL && preNextComTotalPeak < pComTotalPeak)
		{
			pre = pre->next;
			preNextComTotalPeak = calComTotalPeak(pre->next);
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	p = head0->next;
	for (int i = 0; i < adm->n - adm->kn; i++)
	{
		if (p->next != NULL)
		{
			p = p->next;
		}
	}
	printf("����Ϊ����С��������\n");
	while (p != NULL)
	{
		printf("%s\n", p->comName);
		p = p->next;
	}
	free(head0);
}
