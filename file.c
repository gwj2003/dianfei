#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "maincontrol.h"

extern int count;

/*从文件中加载住户信息*/
int readRecordFile(Record* rec)//需要修改，将文件的内容读入内存
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
		printf("读文件失败！\n");
		return 0;
	}
}

/*在文件中保存住户信息*/
void saveFile(Record* rec, int count)
{
	FILE* fp;
	fopen_s(&fp, "record.txt", "w");
	if (fp)                                    /*以写方式打开指定文件*/
	{
		for (int i = 1; i <=  count; ++i)       /*所有数据以此写入*/
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
		fclose(fp);                            /*然后退出*/
	}
	else
	{
		printf("读文件失败！\n");              /*若打开失败，输出提示信息*/
		exit(0);                               /*实际上不可能*/
		fclose(fp);                            /*关闭文件*/
	}
}