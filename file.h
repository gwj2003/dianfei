#ifndef _FILE
#define _FILE

#define STR_LEN 50

/*住户电费记录结构体*/
typedef struct Record
{
	int id;                         /*户号*/
	char name[STR_LEN];             /*户名*/
	char community[STR_LEN];        /*小区*/
	int year;                       /*年份*/
	int month;                      /*月份*/
	int number;                     /*人数*/
	int join;                       /*是否参加峰谷计费,1为参加0为不参加*/
	int list;                       /*是否扩容,1为已扩容0为未扩容*/
	double felectricity;            /*峰时电量*/
	double gelectricity;            /*谷时电量*/
	double electricity;             /*总电量*/
	double power_rate;              /*电费*/
	int count;                      /*判断该数据是否已统计过*/
} Record;

Record rec[STR_LEN];

/*从文件中加载住户信息*/
int readRecordFile(Record* rec);

/*在文件中保存住户信息*/
void saveFile(Record* rec, int n);

#endif