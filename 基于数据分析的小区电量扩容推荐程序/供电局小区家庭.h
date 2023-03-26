#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define filePath "�û�����.dat"			//һ���ǵü����ţ�������������~��
#define startyear 2021
#pragma once
#define peakFee 0.54
#define valleyFee 0.36
typedef struct family		//��ͥ��
{
	char famName[20];		//��ͥ��
	int famPeak[2][12];		//��ͥÿ�·�ʱ�õ���
	int famValley[2][12];	//��ͥÿ�¹�ʱ�õ���
	int num;//�ڼ����˼ң������Ϊ��ַ����1��ʼ�����
	struct family* next;	//����ָ��
}Family;

typedef struct community	//С����(�ڵ�)
{
	Family* head;           //��ָ֮ͥ��
	char comName[20];		//С����
	int n;					//��ͥ��
	struct community* next;	//����ָ��
}Community;

typedef struct administration
{
	Community* head;//����ֹ�Ͻ��С��ָ֮��
	int n;//С����Ŀ
	int kn;//����С����Ŀ��Ĭ��0��ͨ��ѡ��BB���룩
}Administration;


//ȡֵ����
//��ʼ��50����ͥ
//void inputFamMonth(Family fam, int year, int month);//ȡ��ĳ��ͥĳ�·�ʱ����ʱ�õ���
//���㺯��
//��ͥ���ݼ���
void calFamMonthEle(Family *fam, int* famMonthEle);//����ĳ��ͥÿ��ÿ���õ���
void calFamMonthFee(Family *fam, double* famMonthFee);//����ĳ��ͥÿ��ÿ�µ��
void calFamYearTotalEle(Family* fam, int* famYearTotalEle, int* famMonthEle);//����ĳ��ͥÿ�����õ���
void calFamYearTotalFee(Family* fam, double* famYearTotalFee, double* famMonthFee);//����ĳ��ͥÿ���ܵ��
//С�����ݼ���
void calComPeak(Community *com, int* comPeak);//����ĳС��ÿ�·�ʱ�õ���
void calComValley(Community *com, int* comValley);//����ĳС��ÿ�¹�ʱ�õ���
void calComMonthTotalEle(Community *com, int* comMonthTotalEle);//����ĳС��ÿ�����õ���
void calComMonthTotalFee(Community *com, int* comMonthTotalFee);//����ĳС��ÿ���ܵ��
void calComYearTotalEle(Community *com, int* comYearTotalEle, int* comMonthTotalEle);//����ĳС��ÿ�����õ���
void calComYearTotalFee(Community *com, double* comYearTotalFee, double* comMonthTotalFee);//����ĳС��ÿ���ܵ��
double calAverageELe(Community *com);//����ĳС��ÿ��ƽ���õ���
double calAverageFee(Community *com);//����ĳС��ÿ��ƽ�����
int calComTotalPeak(Community *com);//����ĳС�������ڵķ�ʱ�õ�����
int calComTotalValley(Community *com);//����ĳС�������ڵĹ�ʱ�õ�����
//Community FindCommunity(Administration adm);
//�Ʊ���
//��ͥ���ݱ��
void formFamMonthEle(Family* fam);//����ĳ��ͥÿ��ÿ���õ���
void formFamMonthFee(Family* fam);//����ĳ��ͥÿ��ÿ�µ��
void formFamYearTotalEle(Family* fam);//����ĳ��ͥÿ�����õ���
void formFamYearTotalFee(Family* fam);//����ĳ��ͥÿ���ܵ��
//С�����ݱ��
void formComPeak(Community* com);//����ĳС��ÿ�·�ʱ�õ���
void formComValley(Community* com);//����ĳС��ÿ�¹�ʱ�õ���
void formComMonthTotalEle(Community* com);//����ĳС��ÿ�����õ���
void formComMonthTotalFee(Community* com);//����ĳС��ÿ���ܵ��
void formComYearTotalEle(Community* com);//����ĳС��ÿ�����õ���
void formComYearTotalFee(Community* com);//����ĳС��ÿ���ܵ��
//������
void sortComPeak(Administration* adm);//��ʱ�õ�������
void formSortComPeak(Administration* adm);//���Ʒ�ʱ�õ��������
void sortComFee(Administration* adm, int year, int month);//ÿ�µ����������
void formSortComFee(Administration* adm);//����ÿ�µ�����������
void sortComAverageEle(Administration* adm);//С��ÿ��ƽ����������
void formSortComAverageEle(Administration* adm);//����С��ÿ��ƽ�����������
void sortComAverageFee(Administration *adm);//ÿ��ƽ���������
void formSortComAverage(Administration* adm);//����С��ÿ��ƽ����������
Community* findCommunity(Administration *adm);//��С��
Family* findFamily(Community*com);//�Ҽ�ͥ

//�������ݺ���
void FindKuoRongCommunity(Administration* adm);

