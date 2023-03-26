//        
//                  ���ӷ�������bug
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                       0\ = / 0
//                    ___ / `---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .' / --.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='


#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s on line %d\n", __FILE__, GetLastError(), api, __LINE__);}
#include"�����С����ͥ.h"
#include"�ļ���д��д��.h"
#include"��ʼ��.h"
#include"���.h"
//#define filePath "D:\\׿��\\�������ݷ�����С�����������Ƽ����� - 2.0\\�û�����.dat"			//һ���ǵü����ţ�������������~��


void MyCls(HANDLE) ;
inline void clrscr(void)
{
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
MyCls(hStdOut);
return;
}
void MyCls(HANDLE hConsole)
{
COORD coordScreen={0,0};//�����������귵�ص���Ļ���Ͻ�����
BOOL bSuccess;
DWORD cCharsWritten;
CONSOLE_SCREEN_BUFFER_INFO csbi;//���滺������Ϣ
DWORD dwConSize;//��ǰ�����������ɵ��ַ���
bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//��û�������Ϣ
PERR(bSuccess,"GetConsoleScreenBufferInfo");
dwConSize=csbi.dwSize.X * csbi.dwSize.Y;//�����������ַ���Ŀ
//�ÿո���仺����
bSuccess=FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
PERR(bSuccess,"FillConsoleOutputCharacter");
bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//��û�������Ϣ
PERR(bSuccess,"ConsoleScreenBufferInfo");
//��仺��������
bSuccess=FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
PERR(bSuccess,"FillConsoleOutputAttribute");
//��귵����Ļ���Ͻ�����
bSuccess=SetConsoleCursorPosition(hConsole,coordScreen);
PERR(bSuccess,"SetConsoleCursorPosition");
return;
}


void menu();
void menuA();
void menuB();
void menuAA();
void menuAB();
void menuBA();
void fmenuA(Administration* adm);
void fmenuB(Administration* adm);
void fmenuAA(Administration* adm);//���������ǳ�ª�Ĳ˵�����
void fmenuAB(Administration* adm);
void fmenuBA(Administration* adm);
void fmenuBAB(Family *fam);
void fmenuBAA(Community *com);
void menuBAA();
void menuBAB();
void fmenuAAA(Community *com);
void menuAAA();
void fmenuAAB(Administration *adm);
void fmenuABA(Administration *adm);
void fmenuABB(Administration* adm);
void WindowC(int startX, int startY, int width, int height);
void WindowM(int startX, int startY, int width, int height);
void WindowL(int startX, int startY, int width, int height);
void tan();
void back();


/*void fmenuBB();//����
//��������Ҫ���ľ��庯�������ͼ*/
int main()
{
	int choice;
	Administration* adm=buildAdministration();
	FILE* fp;
	while (1)
	{
		errno_t err = fopen_s(&fp, filePath, "r");
		if (err)
		{
			printf("�ļ���ʧ��menu\n�����½��ļ�\n");
			if ((err = fopen_s(&fp, filePath, "w"))==0)
			{
				fclose(fp);
				admWriteIn(adm);
			}
		}
		else
		{
			fclose(fp);
			admReadFile(adm);
			break;
		}
	}/*�ļ�����*/
	do
	{
		gotoxy(0, 0);
		system("cls");
		menu();                    /*��ʾ��ʼ�˵�*/
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 2)
			switch (choice)
			{
			case 1:

				fmenuA(adm);             /* 1. ��ʾ�õ�����ͳ��Ա�˵�*/
				break;
			case 2:
				fmenuB(adm);    /* 2. ������Ϣ����*/
				break;

			case 0:  break;
			}    /*ѡ��ʼ�˵���Ӧ�Ĺ���*/
		else
			printf("�������������롣\n");
	} while (choice);
	admWriteIn(adm);
	free(adm);
	return 0;
}
//ѡ�� �õ�����ͳ��Ա �ĺ���
void fmenuA(Administration* adm)
{
	int choice;
	do
	{
		gotoxy(0, 0);
		system("cls");
		menuA();
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 2)
			switch (choice)
			{
			case 1:
				fmenuAA(adm);
				break;
			case 2:
				fmenuAB(adm);
				break;

			case 0:  break;
			}
		else
		{
			printf("�������������롣\n");
			system("puase");
		}
	} while (choice);
}
//ѡ�� ���繫˾������Ա �ĺ���
void fmenuAA(Administration* adm)
{
	int choice;
	do
	{
		gotoxy(0, 0);
		system("cls");

		menuAA();
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
			switch (choice)
			{
			case 1:
			{
				Community* goal = findCommunity(adm);
				if (goal != NULL)
					fmenuAAA(goal); // ѡ��С�� �ĺ���          
				system("pause");
				break;
			}
				
			case 2:
			{
				initAdministration(adm); //�����С�� �ĺ���
				break;
			}
			case 3:
			{
				while (1)
				{
					char name[20];
					int check = 0;
					Community* p = adm->head;
					printf("��������¼��С�������֣�");
					scanf_s("%s", name, 20);
					for ( int i = 0; i < adm->n; i++)
					{
						if (strcmp(name, p->comName) == 0)
						{
							printf("��С�����ѱ�ռ�ã����������룡\n");
							check++;
						}
						else
							p = p->next;
					}
					if (check == 0)
					{
						autoBuildCommunity(adm, name);
						printf("С��%s�½��ɹ�\n����С��%d��\n", name, adm->n);
						system("pause");
						break;
					}
				}
			}
			case 0:  break;
			}
		else
		{
			system("puase");
			printf("�������������롣\n");
		}
	} while (choice);
}
//ѡ�� ������С���ڽ��м�ͥ����
void fmenuAAA(Community *com)
{
	int choice;
	do
	{
		gotoxy(0, 0);
		system("cls");
		menuAAA();
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
			switch (choice)
			{
			case 1://�����м�ͥ������
			{
				Family* fam1;
				fam1 = findFamily(com);
				if (fam1 == NULL)
					break;
				addDate(fam1);
				break;
			}
			case 2://�����¼�ͥ
			{
				initCommunity(com);
				break;
			}
			case 3://�Զ����ı��ͥ���ݣ����ǣ�
			{
				Family* fam1;
				fam1 = findFamily(com);
				if (fam1 == NULL)
					break;
				autoAddDate(fam1);
				break;
			}
			case 0:  break;
			}
		else
		{
			system("puase");
			printf("�������������롣\n");
		}
	} while (choice);
}

void fmenuAAB(Administration *adm)
{
	Community* newcom = buildCommunity(adm);
	Community* p = adm->head;
	while (1)
	{
		if (p->next != NULL)
			p = p->next;
		else
			break;
		p = newcom;
	}
}

//ѡ�� �鿴ͳ�Ʊ��� �ĺ���
void fmenuAB(Administration* adm)
{
	int choice;
	do
	{
		gotoxy(0, 0);
		system("cls");
		menuAB();
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 2)
			switch (choice)
			{
			case 1:
				fmenuABA(adm);
				/* //�����ͥͳ�Ʊ���ĺ���   */         
				break;
			case 2:
				fmenuABB(adm);
				/*; //����С��ͳ�Ʊ���ĺ���  */ 
				break;

			case 0:  break;
			}
		else
		{
			printf("�������������롣\n");
			system("puase");
		}
	} while (choice);
}

void fmenuABA(Administration *adm)
{
	Community* com = findCommunity(adm);
	int choice;
	if (com==NULL)
		system("pause");
	else 
	{
		Family* fam = findFamily(com);
		if(fam==NULL)
			system("pause");
		else 
		{
			do
			{
				gotoxy(0, 0);
				system("cls");
				menuBAB();
				scanf_s("%d", &choice);
				if (choice >= 0 && choice <= 4)
				{
					switch (choice)
					{
					case 1:
					{
						clrscr();
						printf("��ͥ�����õ�����\n");
						formFamMonthEle(fam);
						//gotoxy(0,getMaxxy)
						break;
					}
					case 2:
					{
						clrscr();
						printf("��ͥ���ܵ�ѱ�\n");
						formFamMonthFee(fam);
						break;
					}
					case 3:
						clrscr();
						printf("��ͥ���ܵ�����\n");
						formFamYearTotalEle(fam);
						break;
					case 4:
						clrscr();
						printf("��ͥ���ܵ�ѣ�\n");
						formFamYearTotalFee(fam);
						break;
					case 0:  break;
					}
					system("pause");
				}
				else
				{
					printf("�������������롣\n");
					system("puase");
				}
			} while (choice);
		}
	}
}

void fmenuABB(Administration* adm)
{
	Community* com = findCommunity(adm);
	if (com == NULL)
	{
		printf("����ʧ�ܣ��޸�С��");
		system("pause");
	}
	else
	{
		int choice;
		do
		{
			gotoxy(0, 0);
			system("cls");
			menuBAA();
			scanf_s("%d", &choice);
			if (choice >= 0 && choice <= 6)
			{
				switch (choice)
				{
				case 1:
					clrscr();
					printf("С����ʱ������\n");
					formComPeak(com);

					break;
				case 2:
					clrscr();
					printf("С����ʱ������\n");
					formComValley(com);

					break;

				case 3:
					clrscr();
					printf("С�������õ�����\n");
					formComMonthTotalEle(com);
					break;

				case 4:
					clrscr();
					printf("С�����ܵ�ѱ�\n");
					formComMonthTotalFee(com);
					break;
				case 5:
					clrscr();
					printf("С�������õ�����\n");
					formComYearTotalEle(com);
					break;
				case 6:
					clrscr();
					printf("С�����ܵ�ѱ�\n");
					formComYearTotalFee(com);

					break;
				case 0:  break;
				}
				system("pause");
			}
			else
			{
				printf("�������������롣\n");
				system("puase");
			}
		} while (choice);
	}
}

void fmenuB(Administration* adm)
{
	int choice;
	do
	{
		clrscr();
		gotoxy(0, 0);
		//system("cls");
		menuB();
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
			switch (choice)
			{
			case 1:
				fmenuBA(adm);     //��ѯ�õ�����  */      
				break;
			case 2:
			{
				printf("����������С������������");
				scanf_s("%d", &adm->kn);
				break;
			}
			case 3:
				FindKuoRongCommunity(adm);
				system("pause");
				break;
			case 0:  break;
			}
		else
		{
			printf("�������������롣\n");
			system("puase");
		}
			system("cls");
	} while (choice);
}

//ѡ�� ��ѯ�õ����� �ĺ���
void fmenuBA(Administration* adm)
{
	int choice;
	do
	{
		gotoxy(0, 0);
		system("cls");
		menuBA();
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 3)
		{
			switch (choice)
			{
			case 1:
			{
				Community* goal = findCommunity(adm);
				if (goal == NULL)
					system("pause");
				else
					fmenuBAA(goal);
				/*       //��ѯС������*/
				break;
			}
			case 2:
			{
				Community* goal = findCommunity(adm);
				if (goal == NULL)
					system("pause");
				else
				{
					Family* goal2 = findFamily(goal);
					if (goal2 == NULL)
						system("pause");
					else
						fmenuBAB(goal2);
					/*      //��ѯ��ͥ����*/
				}
				break;
}
			case 3:
				FindKuoRongCommunity(adm);
				/*;*/
				break;

			case 0:  break;
			}
		}
		else
		{
			printf("�������������롣\n");
			system("puase");
		}
	} while (choice);
}

void fmenuBAA(Community *com)
{
	int choice;
	do
	{
		gotoxy(0, 0);
		system("cls");
		menuBAA();
		scanf_s("%d", &choice);
		
		if (choice >= 0 && choice <= 6)
		{
			switch (choice)
			{
			case 1:
				clrscr();
				printf("С����ʱ������\n");
				formComPeak(com);

				break;
			case 2:
				clrscr();
				printf("С����ʱ������\n");
				formComValley(com);

				break;

			case 3:
				clrscr();
				printf("С�������õ�����\n");
				formComMonthTotalEle(com);
				break;

			case 4:
				clrscr();
				printf("С�����ܵ�ѱ�\n");
				formComMonthTotalFee(com);
				break;
			case 5:
				clrscr();
				printf("С�������õ�����\n");
				formComYearTotalEle(com);
				break;
			case 6:
				clrscr();
				printf("С�����ܵ�ѱ�\n");
				formComYearTotalFee(com);

				break;
			case 0:  break;
			}
			system("pause");
		}
		else
		{
			printf("�������������롣\n");
			system("puase");
		}
		} while (choice);
}

void fmenuBAB(Family *fam)
{
	int choice;
	do
	{
		gotoxy(0, 0);
		system("cls");
		menuBAB();
		scanf_s("%d", &choice);
		if (choice >= 0 && choice <= 4)
		{
			switch (choice)
			{
			case 1:
			{
				clrscr();
				printf("��ͥ�����õ�����\n");
				formFamMonthEle(fam);
				break;
			}
			case 2:
			{
				clrscr();
				printf("��ͥ���ܵ�ѱ�\n");
				formFamMonthFee(fam);
				break;
			}
			case 3:
				clrscr();
				printf("��ͥ���ܵ�����\n");
				formFamYearTotalEle(fam);
				break;
			case 4:
				clrscr();
				printf("��ͥ���ܵ�ѣ�\n");
				formFamYearTotalFee(fam);
				break;
			case 0:  break;
			}
			system("pause");
		}
		else
		{
			printf("�������������롣\n");
			system("puase");
		}
		} while (choice);
}

void WindowC(int startX, int startY, int width, int height)    //�������������βηֱ�Ϊ��������Ͻǵĺ�������
{                                                              //��Ŀ�� ��ĸ߶�
	int i = 0, j = 0;
	//����
	gotoxy(startX, startY);
	printf("�q");
	for (i = 0; i < width; i++)
	{
		printf("��");
	}
	printf("�r");
	//��
	for (i = 0; i < height; i++)
	{
		gotoxy(startX, startY + 1 + i);
		printf("��");
	}
	//��
	for (i = 0; i < height; i++)
	{
		gotoxy(startX + 1 + width, startY + 1 + i);
		printf("��");
	}
	//��
	gotoxy(startX, startY + 1 + height);
	printf("�t");
	gotoxy(startX + 2, startY + 1 + height);
	for (i = 0; i <= width - 2; i++)
	{
		printf("��");
	}
	printf("�s");
	gotoxy(0, 0);

}
void WindowM(int startX, int startY, int width, int height)  //
{
	int i = 0, j = 0;
	//����
	gotoxy(startX, startY);
	printf("��");
	for (i = 0; i < width; i++)
	{
		printf("-");
	}
	printf("��");

	//��
	gotoxy(startX, startY + 1 + height);
	printf("��");
	gotoxy(startX + 2, startY + 1 + height);
	for (i = 0; i <= width - 2; i++)
	{
		printf("-");
	}
	printf("��");
	gotoxy(0, 0);

}
void WindowL(int startX, int startY, int width, int height)  //��ֱ����  �βηֱ�Ϊ��������Ͻǵĺ������� ��Ŀ�� ��ĸ߶�
{
	int i = 0, j = 0;
	//����
	gotoxy(startX, startY);
	printf("��");
	for (i = 0; i < width; i++)
	{
		printf("��");
	}
	printf("��");
	//��
	for (i = 0; i < height; i++)
	{
		gotoxy(startX, startY + 1 + i);
		printf("��");
	}
	//��
	for (i = 0; i < height; i++)
	{
		gotoxy(startX + 1 + width, startY + 1 + i);
		printf("��");
	}
	//��
	gotoxy(startX, startY + 1 + height);
	printf("��");
	gotoxy(startX + 2, startY + 1 + height);
	for (i = 0; i <= width - 2; i++)
	{
		printf("��");
	}
	printf("��");
	gotoxy(0, 0);

}

void tan()
{
	gotoxy(7, 3);
	printf("��");
	gotoxy(84, 3);
	printf("��");
	gotoxy(7, 32);
	printf("��");
	gotoxy(84, 32);
	printf("��");
}
void back()
{
	gotoxy(7, 4);
	printf("������0������");
}




void menu()         /*��ʼ�˵�����*/
{
	tan();
	gotoxy(28, 8);
	printf("���������ݷ�����С�����������Ƽ�����");
	gotoxy(28, 6);
	WindowL(5, 2, 80, 30);
	WindowC(31, 15, 20, 1);
	WindowC(31, 19, 20, 1);
	gotoxy(36, 13);
	printf("��ѡ�������ݣ�");
	gotoxy(33, 16);
	printf("1.�õ�����ͳ��Ա");
	gotoxy(33, 20);
	printf("2.���繫˾����Ա");
	gotoxy(33, 24);
	printf("�����ˣ���˼�� ����Զ ����");
	gotoxy(2, 34);

}

void menuA()     /*2���õ�����ͳ��Ա�˵�����*/
{
	WindowL(5, 2, 80, 30);//���Ļ���
	tan();
	gotoxy(24, 3);
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�����õ�����ͳ��Ա��");
	WindowC(31, 15, 20, 1);
	WindowC(31, 19, 20, 1);
	WindowM(25, 24, 30, 5);
	gotoxy(31, 13);
	printf("��ѡ����Ҫ���еĲ�����");
	gotoxy(31, 9);
	printf("������0������ѡ����ݣ�");
	gotoxy(33, 16);
	printf("1.¼���õ�����");
	gotoxy(33, 20);
	printf("2.�鿴ͳ�Ʊ���");
	gotoxy(29, 26);
	printf("���ǧ��������ȫ��һ����");
	gotoxy(29, 28);
	printf("����淶�����������ᣡ");
	gotoxy(2, 34);

}

void menuB()     /*3�����繫˾����Ա�˵�����*/
{
	WindowL(5, 2, 80, 34);
	gotoxy(7, 3);
	printf("��");
	gotoxy(84, 3);
	printf("��");
	gotoxy(7, 36);
	printf("��");
	gotoxy(84, 36);
	printf("��");
	gotoxy(24, 3);
	
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�������繫˾����Ա��");
	WindowC(31, 15, 20, 1);
	WindowC(31, 19, 20, 1);
	WindowC(31, 23, 20, 1);
	WindowM(23, 29, 34, 5);
	gotoxy(31, 13);
	printf("��ѡ����Ҫ���еĲ�����");
	gotoxy(31, 9);
	printf("������0������ѡ����ݣ�");
	gotoxy(33, 16);
	printf("1.��ѯ�õ�����");
	gotoxy(33, 20);
	printf("2.����������������");
	gotoxy(33, 24);
	printf("3.�������С������");
	gotoxy(25, 32);
	printf("��֤���װ�ð�ȫ���ɿ����������ϸ�");
	gotoxy(2, 40);

}

void menuAA()    /*4��¼���õ����ݲ˵�����*/
{
	WindowL(5, 2, 80, 34);
	back();
	gotoxy(7, 3);
	printf("��");
	gotoxy(84, 3);
	printf("��");
	gotoxy(7, 36);
	printf("��");
	gotoxy(84, 36);
	printf("��");
	gotoxy(24, 3);
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�����õ�����ͳ��Ա��");
	WindowC(31, 15, 20, 1);
	WindowC(31, 19, 20, 1);
	WindowC(31, 23, 20, 1);
	WindowM(23, 28, 34, 5);
	gotoxy(31, 13);
	printf("��ѡ����Ҫ���еĲ�����");
	gotoxy(31, 9);
	printf("��¼���õ�����");
	gotoxy(33, 16);
	printf("1.ѡ������С��");
	gotoxy(33, 20);
	printf("2.�����С��");
	gotoxy(33, 24);
	printf("3.�Զ��½�С��");
	gotoxy(29, 30);
	printf("�������͹ۡ���ƽ��������");
	gotoxy(29, 34);
	printf("��Ū�����١��������ܶϣ�");
	gotoxy(2, 38);

}

void menuAB()    /*5���鿴ͳ�Ʊ���˵�����*/
{
	WindowL(5, 2, 80, 30);
	back();
	tan();
	gotoxy(24, 3);
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�����õ�����ͳ��Ա��");
	WindowC(31, 15, 20, 1);
	WindowC(31, 19, 20, 1);
	WindowM(23, 24, 34, 5);
	gotoxy(31, 13);
	printf("��ѡ����Ҫ��ѯ�����ݣ�");
	gotoxy(31, 9);
	printf("���鿴ͳ�Ʊ���");
	gotoxy(33, 16);
	printf("1.�鿴��ͥͳ�Ʊ���");
	gotoxy(33, 20);
	printf("2.�鿴С��ͳ�Ʊ���");
	gotoxy(29, 26);
	printf("�������͹ۡ���ƽ��������");
	gotoxy(29, 28);
	printf("��Ū�����١��������ܶϣ�");
	gotoxy(2, 34);

}

void menuBA()    /*6����ѯ�õ����ݲ˵�����*/
{
	WindowL(5, 2, 80, 30);
	back();
	tan();
	gotoxy(24, 3);
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�������繫˾����Ա��");
	WindowC(31, 15, 20, 1);
	WindowC(31, 19, 20, 1);
	WindowM(23, 24, 34, 5);
	gotoxy(31, 13);
	printf("��ѡ����Ҫ��ѯ�����ݣ�");
	gotoxy(31, 9);
	printf("����ѯ�õ�����");
	gotoxy(33, 16);
	printf("1.��ѯС������");
	gotoxy(33, 20);
	printf("2.��ѯ��ͥ����");
	gotoxy(24, 27);
	printf("������ͻ����ý���������õ����Ҫ��");
	gotoxy(2, 34);

}

void menuBAA()
{
	WindowL(5, 2, 80, 38);
	back();
	gotoxy(7, 3);
	printf("��");
	gotoxy(84, 3);
	printf("��");
	gotoxy(7, 40);
	printf("��");
	gotoxy(84, 40);
	printf("��");
	gotoxy(24, 3);
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�������繫˾����Ա��");
	WindowC(31, 15, 21, 1);
	WindowC(31, 19, 21, 1);
	WindowC(31, 23, 21, 1);
	WindowC(31, 27, 21, 1);
	WindowC(31, 31, 21, 1);
	WindowC(31, 35, 22, 1);
	gotoxy(31, 13);
	printf("��ѡ����Ҫ��ѯ�����ݣ�");
	gotoxy(31, 9);
	printf("����ѯС������");
	gotoxy(33, 16);
	printf("1.��ѯС����ʱ�õ���");
	gotoxy(33, 20);
	printf("2.��ѯС����ʱ�õ���");
	gotoxy(33, 24);
	printf("3.��ѯС�����õ���");
	gotoxy(33, 28);
	printf("4.��ѯС�����ܵ��");
	gotoxy(33, 32);
	printf("5.��ѯС�����ܵ���");
	gotoxy(33, 36);
	printf("6.��ѯС�����ܵ�ѱ�");

	gotoxy(2, 34);
}

void menuBAB()
{
	WindowL(5, 2, 80, 30);
	back();
	tan();
	gotoxy(24, 3);
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�������繫˾����Ա��");
	WindowC(31, 15, 21, 1);
	WindowC(31, 19, 21, 1);
	WindowC(31, 23, 21, 1);
	WindowC(31, 27, 21, 1);
	

	gotoxy(31, 13);
	printf("��ѡ����Ҫ��ѯ�����ݣ�");
	gotoxy(31, 9);
	printf("����ѯ��ͥ����");
	gotoxy(33, 16);
	printf("1.��ѯ��ͥĳ���õ���");
	gotoxy(33, 20);
	printf("2.��ѯ��ͥĳ�µ��");
	gotoxy(33, 24);
	printf("3.��ѯ��ͥĳ�����");
	gotoxy(33, 28);
	printf("4.��ѯ��ͥĳ����");
	

	gotoxy(2, 34);
}


//void menuBAB()
//{
//	printf("######## 1. ��ѯ��ͥĳ���õ���   ########\n");
//	printf("######## 2. ��ѯ��ͥĳ�µ��   ########\n");
//	printf("######## 3. ��ѯ��ͥĳ�����   ########\n");
//	printf("######## 4. ��ѯ��ͥĳ����   ########\n");
//	printf("######## 0. �����ϲ�˵�   ########\n");
//}

void menuAAA()
{
	WindowL(5, 2, 80, 30);
	back();
	tan();
	gotoxy(31, 9);
	printf("����Ӽ�ͥ����");
	gotoxy(24, 3);
	printf("----�������ݷ�����С�����������Ƽ�����-----");
	gotoxy(28, 8);
	printf("����ǰ���Ϊ�����õ�����ͳ��Ա��");
	WindowC(31, 15, 23, 1);
	WindowC(31, 19, 15, 1);
	WindowC(31, 23, 25, 1);
	gotoxy(31, 13);
	printf("��ѡ����Ҫ���еĲ�����");
	gotoxy(33, 16);
	printf("1.�����м�ͥ�м������� ");
	gotoxy(33, 20);
	printf("2.�½��¼�ͥ");
	gotoxy(33, 24);
	printf("3.�����м�ͥ�Զ��������");
	gotoxy(2, 34);
}

/*int mai()
{
	int choice;
	Administration* adm = buildAdministration();
	FILE* fp;
	while (1)
	{
		errno_t err = fopen_s(&fp, filePath, "r");
		if (err)
		{
			printf("�ļ���ʧ��menu\n�����½��ļ�\n");
			if ((err = fopen_s(&fp, filePath, "w")) == 0)
			{
				fclose(fp);
				admWriteIn(adm);
			}
		}
		else
		{
			fclose(fp);
			admReadFile(adm);
			break;
		}
	}//�ļ�����
	printf("%p\n", adm);
	printf("%p\n", adm->head);
	printf("%d\n", adm->n);
	printf("%s\n", adm->head->comName);//310de
	printf("%d\n", adm->head->n);
	printf("%s\n", adm->head->next->comName);//311�Ļ�����
	printf("%d\n", adm->head->next->n);
	printf("%s\n", adm->head->head->famName);
	printf("%s\n", adm->head->head->next->famName);
}*/

int mai()
{
	//srand((unsigned int)time(0));
	//int rand_number = rand() % 150 + 50;
	//printf("%d\n", rand_number);

	//Community* com1 = (Community*)malloc(sizeof(Community) * 1);
	//com1->n = 20;
	//autoBuildFamily(com1);
	//formComMonthTotalEle(com1);

	Family* fam=(Family*)malloc(sizeof(Family)*1);
	autoAddDate(fam);
	formFamMonthEle(fam);
	free(fam);
}