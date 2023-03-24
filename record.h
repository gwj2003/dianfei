#ifndef _RECORD
#define _RECORD

#include "maincontrol.h"

/*按日期显示小区信息*/
void displayCommunitRecordByDate();

/*按户号显示小区信息*/
void displayCommunitRecordByID();

/*显示住户信息*/
void displayRecord(int n);


/*编辑住户信息*/
void editRecord();

/*添加住户选项*/
void addRecord();

/*删除住户选项*/
void removeRecord();

/*修改住户选项*/
void modifyRecord();

/*查找住户选项*/
void findRecord();

/*通过户号查找住户选项*/
int findRecordByID(Record * p, int id);







/*小区已扩容名单*/
void UnList();

/*小区未扩容优先名单*/
void List();

/*小区急需扩容名单*/
void need();

/*小区不急需扩容名单*/
void unneeded();




/*计算总电费*/
double rate(double felectricity, double gelectricity, double electricity, int number, int join);

/*计算不参与峰谷的电费*/
double unfgrate(double electricity, int number);

/*计算峰谷的电费*/
double fgrate(double felectricity, double gelectricity, double electricity, int number);

#endif