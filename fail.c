#include <stdio.h>
#include <stdlib.h>
#include "fail.h"
#include "maincontrol.h"

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
void saveFile(Record* rec, int n)
{
	FILE* fp;
	fopen_s(&fp, "record.txt", "w");
	if (fp)                                    /*��д��ʽ��ָ���ļ�*/
	{
		fwrite(rec, sizerec, n, fp);           /*һ�������ļ�д��n����¼*/
		fclose(fp);                            /*Ȼ���˳�*/
	}
	else
	{
		printf("���ļ�ʧ�ܣ�\n");              /*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);
		fclose(fp);
	}                                          /*�ر��ļ�*/
}