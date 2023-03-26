#ifndef _FILE
#define _FILE

#define STR_LEN 50

/*住户电费记录结构体*/
typedef struct Record
{
	int id;                         /*户号*/
	char name[STR_LEN];             /*户名*/
	char community[STR_LEN];        /*小区*/
	char date[STR_LEN];             /*日期*/
	int number;                     /*人数*/
	int join;                       /*是否参加峰谷计费*/
	double felectricity;            /*峰时电量*/
	double gelectricity;            /*谷时电量*/
	double electricity;             /*总电量*/
	double power_rate;              /*电费*/
} Record;

Record rec[STR_LEN];

/*从文件中加载住户信息*/
int readRecordFile(Record* rec);

#define sizerec sizeof(Record)

/*在文件中保存住户信息*/
void saveFile(Record* rec, int n);

#endif