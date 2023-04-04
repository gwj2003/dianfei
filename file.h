#ifndef _FILE
#define _FILE

#define STR_LEN 50

/*ס����Ѽ�¼�ṹ��*/
typedef struct Record
{
	int id;                         /*����*/
	char name[STR_LEN];             /*����*/
	char community[STR_LEN];        /*С��*/
	int year;                       /*���*/
	int month;                      /*�·�*/
	int number;                     /*����*/
	int join;                       /*�Ƿ�μӷ�ȼƷ�,1Ϊ�μ�0Ϊ���μ�*/
	int list;                       /*�Ƿ�����,1Ϊ������0Ϊδ����*/
	double felectricity;            /*��ʱ����*/
	double gelectricity;            /*��ʱ����*/
	double electricity;             /*�ܵ���*/
	double power_rate;              /*���*/
	int count;
} Record;

Record rec[STR_LEN];

/*���ļ��м���ס����Ϣ*/
int readRecordFile(Record* rec);

#define sizerec sizeof(Record)     /*����ṹ�峤��*/

/*���ļ��б���ס����Ϣ*/
void saveFile(Record* rec, int n);

#endif