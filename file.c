#include <stdio.h>
#include <stdlib.h>
#include "file.h"
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
			fscanf_s(fp, "%d ", &rec[i].id);
			fscanf_s(fp, "%s ", rec[i].name, STR_LEN);
			fscanf_s(fp, "%s ", rec[i].community, STR_LEN);
			fscanf_s(fp, "%d ", &rec[i].year);
			fscanf_s(fp, "%d ", &rec[i].month);
			fscanf_s(fp, "%d ", &rec[i].number);
			fscanf_s(fp, "%d ", &rec[i].join);
			fscanf_s(fp, "%d ", &rec[i].list);
			fscanf_s(fp, "%lf ", &rec[i].felectricity);
			fscanf_s(fp, "%lf ", &rec[i].gelectricity);
			fscanf_s(fp, "%lf ", &rec[i].electricity);
			fscanf_s(fp, "%lf ", &rec[i].power_rate);
			fscanf_s(fp, "%d ", &rec[i].count);
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
			fprintf(fp, "%d ", rec[i].list);
			fprintf(fp, "%lf ", rec[i].felectricity);
			fprintf(fp, "%lf ", rec[i].gelectricity);
			fprintf(fp, "%lf ", rec[i].electricity);
			fprintf(fp, "%lf ", rec[i].power_rate);
			fprintf(fp, "%d ", rec[i].count);
			fprintf(fp, "\n ");
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