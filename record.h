#ifndef _RECORD
#define _RECORD

#include "maincontrol.h"
#include "file.h"

/*显示相同住户标题*/
void displaysameTitle();

/*显示不同住户标题*/
void displaydifferentTitle();

/*显示重复住户信息*/
void displaysame(int n);

/*显示不重复住户信息*/
void displaydifferent(int n);

/*按日期显示小区信息*/
void displayCommunityByDate();

/*按户号显示小区信息*/
void displayCommunityByID();

/*显示已扩容小区名单*/
void displayUnList();

/*显示未扩容小区名单*/
void displayList();

/*显示急需扩容小区名单*/
void displayneed();

/*显示不急需扩容小区名单*/
void displayunneeded();

/*输入年月峰谷信息*/
void ynfg();

/*重置count信息*/
void resetcount();

/*添加住户选项*/
void addRecord();

/*删除住户选项*/
void removeRecord();

/*修改某月用电记录*/
void modifyRecord();

/*修改小区名*/
void modifyname();

/*修改住户人数*/
void modifynumber();

/*修改是否参加峰谷计费*/
void modifyjoin();

/*修改小区是否扩容*/
void modifylist();

/*更改峰时电量*/
void changef();

/*更改谷时电量*/
void changeg();

/*查找住户选项*/
void findRecord();

/*通过户号查找已有住户选项*/
int findRecordID(Record* p, int id);

/*通过户号查找住户选项*/
int findRecordByID(Record* p, int id);

/*通过户号和日期查找住户选项*/
int findRecordByIDdate(Record* p, int id,int year,int month);

/*通过小区名查找*/
int findCommunityname(Record* rec, char* com);

/*通过小区名查找已有*/
int findCommunityByname(Record* rec, char* com);

/*查找是否有小区扩容*/
int findlist();

/*查找是否有小区未扩容*/
int findunlist();

/*计算总电费*/
double rate(double felectricity, double gelectricity, double electricity, int number, int join);

/*计算不参与峰谷的电费*/
double unfgrate(double electricity, int number);

/*计算峰谷的电费*/
double fgrate(double felectricity, double gelectricity, double electricity, int number);

#endif