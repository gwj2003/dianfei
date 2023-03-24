#include <stdio.h>
#include <stdlib.h>
#include "fail.h"
#include "maincontrol.h"

extern int count;

/*���ļ��м���ס����Ϣ*/
int readRecordFile(Record* rec)
{
	FILE* fp;
	int i = 0;
	fopen_s(&fp, "record.txt", "r");
	if (fp)
	{
		while (!feof(fp))
		{
			i++;
			fread(rec, sizerec, 1, fp);
		}
		fclose(fp);
		return i;
	}
	else
	{
		printf("���ļ�ʧ�ܣ�\n");
		return 0;
	}
}

/*���ļ��б���ס����Ϣ*/
void saveFile(Record* rec, int count)
{
	FILE* fp;
	fopen_s(&fp, "record.txt", "w");
	if (fp)                                    /*��д��ʽ��ָ���ļ�*/
	{
		for (int i = 0; i < count; ++i)
		{
			fprintf(fp, "%d", rec[i].id);
			fprintf(fp, "%s", rec[i].name);
			fprintf(fp, "%s", rec[i].community);
			fprintf(fp, "%s", rec[i].date);
			fprintf(fp, "%d", rec[i].number);
			fprintf(fp, "%d", rec[i].join);
			fprintf(fp, "%lf", rec[i].felectricity);
			fprintf(fp, "%lf", rec[i].gelectricity);
			fprintf(fp, "%lf", rec[i].electricity);
			fprintf(fp, "%lf", rec[i].power_rate);
		}
		fclose(fp);                            /*Ȼ���˳�*/
	}
	else
	{
		printf("���ļ�ʧ�ܣ�\n");              /*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);
		fclose(fp);                            /*�ر��ļ�*/
	}
}