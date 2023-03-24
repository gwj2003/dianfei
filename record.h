#ifndef _RECORD
#define _RECORD

#include "maincontrol.h"

/*��������ʾС����Ϣ*/
void displayCommunitRecordByDate();

/*��������ʾС����Ϣ*/
void displayCommunitRecordByID();

/*��ʾס����Ϣ*/
void displayRecord(int n);


/*�༭ס����Ϣ*/
void editRecord();

/*���ס��ѡ��*/
void addRecord();

/*ɾ��ס��ѡ��*/
void removeRecord();

/*�޸�ס��ѡ��*/
void modifyRecord();

/*����ס��ѡ��*/
void findRecord();

/*ͨ�����Ų���ס��ѡ��*/
int findRecordByID(Record * p, int id);







/*С������������*/
void UnList();

/*С��δ������������*/
void List();

/*С��������������*/
void need();

/*С����������������*/
void unneeded();




/*�����ܵ��*/
double rate(double felectricity, double gelectricity, double electricity, int number, int join);

/*���㲻�����ȵĵ��*/
double unfgrate(double electricity, int number);

/*�����ȵĵ��*/
double fgrate(double felectricity, double gelectricity, double electricity, int number);

#endif