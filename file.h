#ifndef _FILE
#define _FILE

#define STR_LEN 50

/*ס����Ѽ�¼�ṹ��*/
typedef struct Record
{
	int id;                         /*����*/
	char name[STR_LEN];             /*����*/
	char community[STR_LEN];        /*С��*/
	char date[STR_LEN];             /*����*/
	int number;                     /*����*/
	int join;                       /*�Ƿ�μӷ�ȼƷ�*/
	double felectricity;            /*��ʱ����*/
	double gelectricity;            /*��ʱ����*/
	double electricity;             /*�ܵ���*/
	double power_rate;              /*���*/
} Record;

Record rec[STR_LEN];

/*���ļ��м���ס����Ϣ*/
int readRecordFile(Record* rec);

#define sizerec sizeof(Record)

/*���ļ��б���ס����Ϣ*/
void saveFile(Record* rec, int n);

#endif