#include <stdio.h>
#include <stdlib.h>
#include "fail.h"
#include "maincontrol.h"

/*从文件中加载住户信息*/
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
		printf("读文件失败！\n");
		return 0;
	}
}

/*在文件中保存住户信息*/
void saveFile(Record* rec, int n)
{
	FILE* fp;
	fopen_s(&fp, "record.txt", "w");
	if (fp)                                    /*以写方式打开指定文件*/
	{
		fwrite(rec, sizerec, n, fp);           /*一次性向文件写入n条记录*/
		fclose(fp);                            /*然后退出*/
	}
	else
	{
		printf("读文件失败！\n");              /*若打开失败，输出提示信息*/
		exit(0);
		fclose(fp);
	}                                          /*关闭文件*/
}