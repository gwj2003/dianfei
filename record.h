#ifndef _RECORD
#define _RECORD

#include "maincontrol.h"
#include "file.h"

/*��������ʾС����Ϣ*/
void displayCommunityByDate();

/*��������ʾС����Ϣ*/
void displayCommunityByID();

/*ͨ��С��������*/
int findCommunityname(Record* rec,char* com);

/*��ʾ��ͬס������*/
void displaysameTitle();

/*��ʾ��ͬס������*/
void displaydifferentTitle();

/*��ʾ�ظ�ס����Ϣ*/
void displaysame(int n);

/*��ʾ���ظ�ס����Ϣ*/
void displaydifferent(int n);

/*�༭ס����Ϣ*/
void editRecord();

/*���ס��ѡ��*/
void addRecord();

/*ɾ��ס��ѡ��*/
void removeRecord();

/*�޸�ĳ���õ��¼*/
void modifyRecord();

/*�޸�С����*/
void modifyname();

/*�޸�ס������*/
void modifynumber();

/*�޸��Ƿ�μӷ�ȼƷ�*/
void modifyjoin();

/*�޸�С���Ƿ�����*/
void modifylist();

/*���ķ�ʱ����*/
void changef();

/*���Ĺ�ʱ����*/
void changeg();

/*����ס��ѡ��*/
void findRecord();

/*ͨ�����Ų���ס��ѡ��*/
int findRecordByID(Record* p, int id);

/*ͨ�����ź����ڲ���ס��ѡ��*/
int findRecordByIDdate(Record* p, int id,int year,int month);

/*������С������*/
void UnList();

/*δ����С������*/
void List();

/*�����Ƿ���С������*/
int findlist();

/*�����Ƿ���С��δ����*/
int findunlist();

/*��������С������*/
void need();

/*����������С������*/
void unneeded();




/*�����ܵ��*/
double rate(double felectricity, double gelectricity, double electricity, int number, int join);

/*���㲻�����ȵĵ��*/
double unfgrate(double electricity, int number);

/*�����ȵĵ��*/
double fgrate(double felectricity, double gelectricity, double electricity, int number);

#endif