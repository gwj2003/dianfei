#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "maincontrol.h"

extern int count;

/*���ļ��м���ס����Ϣ*/
int readRecordFile(Record* rec)//��Ҫ�޸ģ����ļ������ݶ����ڴ�
{
	FILE* fp;
	int i = 0;
	fopen_s(&fp, "record.txt", "r");
	if (fp)
	{
		while (!feof(fp))
		{
			i++;
			fscanf(fp, "%d%s%s%d%d%d%d%lf%lf%lf%lf",&rec[i].id,rec[i].name,rec[i].community, &rec[i].year, &rec[i].month, &rec[i].number, &rec[i].join, &rec[i]. felectricity, &rec[i]. gelectricity, &rec[i].electricity, &rec[i].power_rate);
			displaysame(i);
			displaydifferent(i);
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
		for (int i = 1; i <=  count; ++i)       /*���������Դ�д��*/
		{
			fprintf(fp, "%d ", rec[i].id);
			fprintf(fp, "%s ", rec[i].name);
			fprintf(fp, "%s ", rec[i].community);
			fprintf(fp, "%d ", rec[i].year);
			fprintf(fp, "%d ", rec[i].month);
			fprintf(fp, "%d ", rec[i].number);
			fprintf(fp, "%d ", rec[i].join);
			fprintf(fp, "%lf ", rec[i].felectricity);
			fprintf(fp, "%lf ", rec[i].gelectricity);
			fprintf(fp, "%lf ", rec[i].electricity);
			fprintf(fp, "%lf ", rec[i].power_rate);
		}
		fclose(fp);                            /*Ȼ���˳�*/
	}
	else
	{
		printf("���ļ�ʧ�ܣ�\n");              /*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                               /*ʵ���ϲ�����*/
		fclose(fp);                            /*�ر��ļ�*/
	}
}