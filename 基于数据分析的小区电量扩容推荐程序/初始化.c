#include"�����С����ͥ.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�����еĻ�������һ�飨�£�����
void addDate(Family* fam)
{
	int choose;
	do
	{
		int year, month;
		printf("�������ͥ%s�������ݵĲɼ�ʱ�䣺\n��ݣ�",fam->famName);
		scanf_s("%d", &year);
		printf("�·ݣ�");
		scanf_s("%d", &month);
		if (year < 2021 || year>2022 || month < 1 || month>12)//ʱ����
		{
			printf("ʱ����������򳬷����������ڷ�Χ2021��1��-2022��12���ʱ�䣩\n����������\n");
			addDate(fam);
		}
		else
		{
			printf("%d��%d�µķ�ʱ�õ���Ϊ��", year, month);
			scanf_s("%d", fam->famPeak[year - 2021] + (month - 1));
			printf("%d��%d�µĹ�ʱ�õ���Ϊ��", year, month);
			scanf_s("%d", fam->famValley[year - 2021] + (month - 1));
			printf("�Ƿ������ü�ͥ�����룿\n");//�˳�bug
			printf("######## 1. ��   ########\n");
			printf("######## 0. ��   ########\n");
			scanf_s("%d", &choose);
		}
	} while (choose);
}

//�Զ��������ݣ�һ����ͥ����������
void autoAddDate(Family* fam)
{
	srand((unsigned long)time(0));
	for(int year=2021;year<2023;year++)
		for (int month = 1; month <= 12; month++)
		{
			*(fam->famPeak[year - 2021] + (month - 1) )= rand() % (150) + 50;
			*(fam->famValley[year - 2021] + (month - 1)) = rand() % (50) + 50;
		}
}
//�½�һ���ջ�
Family* buildFamily(Community* com,char* name)
{
	Family* f = (com->head);
	Family* p;
	for (int i = 0; i < com->n-1; i++)
		f = f->next;
	p = (Family*)malloc(sizeof(Family) * 1);
	if (p == NULL)
	{
		printf("�ڴ�����ʧ��");
		return NULL;
	}
	else
	{
		int i, j;//��ʼ�����������õ���Ϊ0
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 12; j++)
			{
				p->famPeak[i][j] = 0;
				p->famValley[i][j] = 0;
			}
		}
		printf("%s", name);
		strcpy_s(p->famName ,21, name);
		p->num = com->n+1;
		p->famName;
		p->next = NULL;
		if (com->n == 0)
			com->head = p;
		else
			f->next = p;
		printf("%s��%s�ĵ�%d�� ������\n", p->famName, com->comName,com->n+1);//����ɾ��
		return f;
	}
}

//�Զ�������com��n����ͥ,������ʼ���ȣ���Ȼ��0����û������
void autoBuildFamily(Community* com)
{
	for(int k=0;k<com->n;k++)					//ѭ��com.n�Σ���n�μ�����
	{
		Family* f = (com->head);
		Family* p;							//��p���潨��һ�������ڵ㣬˼·ͬ��ʼ����name��num��nextΪ�գ���autoadd�ӵ磬ÿ��kһ��
		for (int i = 0; i < k - 1; i++)
			f = f->next;
		p = (Family*)malloc(sizeof(Family) * 1);
		if (p == NULL)
		{
			printf("�ڴ�����ʧ��");
			return NULL;
		}
		else
		{
			p->num = k + 1;
			autoAddDate(p);
			int a = p->num % 10, c = p->num / 100, b = (p->num - 100 * c) / 10;
			p->famName[0] = 0x30 + c;
			p->famName[1] = 0x30 + b;
			p->famName[2] = 0x30 + a;
			p->next = NULL;
			if (k == 0)
				com->head = p;
			else
				f->next = p;
			//printf("%s��%s�ĵ�%d�� ������\n", p->famName, com->comName, k+ 1);//����ɾ��
		}
	}
}

//�½�һ����С��,����ͷָ֮��
Community* buildCommunity(Administration *adm,char* name)
{
	Community* p = (adm)->head;							//p��Զָ���
	Community* q;
	for (int i = 0; i < (adm)->n-1; i++)		p = (p)->next;
	q = (Community*)malloc(sizeof(Community) * 1);
	if (q == NULL)
	{
		printf("�ڴ�����ʧ��");
		return NULL;
	}
	else
	{
		(q)->head = NULL;
		strcpy_s((q)->comName,21 , name);
		(q)->n = 0;
		(q)->next = NULL;
		if (adm->n == 0)
			adm->head = q;
		else
			p->next = q;
		return q;
	}
}

//�Զ����ӽ�һ����С������ͥ���ݸ������,�����Լ���������ѭ��
void autoBuildCommunity(Administration* adm, char* name)
{
	srand((unsigned int)time(0));					
	Community* p = (adm)->head;							
	Community* q;
	for (int i = 0; i < adm->n - 1; i++)		p = (p)->next;
	q = (Community*)malloc(sizeof(Community) * 1);
	if (q == NULL)
		{
			printf("�ڴ�����ʧ��");
			return NULL;
		}
	else
		{
		q->head = NULL;
		q->n = 50;//(rand() % 1 + 50);						//����50-100������������ļ�ͥ����ע���ȳ�ʼ����
		strcpy_s((q)->comName, 21, name);
		(q)->next = NULL;
		autoBuildFamily(q);								//���������ɵ��Ѿ�����С���ˣ�ѭ�����γ�����
			if (adm->n == 0)
				adm->head = q;
			else
				p->next = q;
		}
	adm->n++;
}

//�½�һ����adm,������
Administration* buildAdministration()
{
	Administration* adm;
	adm = (Administration*)malloc(sizeof(Administration) * 1);
	if (adm == NULL)
	{
		printf("�ڴ�����ʧ��");
		return NULL;
	}
	else
	{
		adm->head=NULL;
		adm->n = 0;
		adm->kn = 0;
		return adm;
	}
}

//ֱ���½���adm,�ⲿ����С����num
void autoBuildAdministration(int num)
{
	Administration* adm = (Administration*)malloc(sizeof(Administration) * 1);
	if (adm == NULL)
	{
		printf("�ڴ�����ʧ��");
		return NULL;
	}
	else
	{
		adm->n = num;
		adm->kn = 0;
		adm->head = NULL;
		for (int i = 1; i <= num; i++)					//ѭ��num�Σ�����num����С����ȥ��С�����Դ��������
		{
			char name[20];
			int a = i % 10, c = i / 100, b = (i- 100 * c) / 10;
			name[0] = 0x30 + c;
			name[1] = 0x30 + b;
			name[2] = 0x30 + a;
			autoBuildCommunity(adm, name);					//ÿ�ζ���һ����С����ȥ
			adm->n++;
		}
	}

}
//��adm���С��
void initAdministration(Administration* adm)
{
	while (1)
	{
		char name[20];
		int check = 0;
		Community* p = adm->head;
		printf("��������¼��С�������֣�");
		scanf_s("%s", name, 20);
		for (int i = 0; i < adm->n; i++)
		{
			if (strcmp(name, p->comName)==0)
			{
				printf("��С�����ѱ�ռ�ã����������룡\n");
				check++;
			}
			else
				p = p->next;
		}
		if (check == 0)
		{
			buildCommunity(adm, name);
			adm->n++;
			printf("С��%s�½��ɹ�\n����С��%d��\n",name,adm->n);
			system("pause");
			break;
		}
	}		
}

//��com�ڼӼ�ͥ
void initCommunity(Community* com)//��com�ڼӼ�ͥ
{
	
	while (1)
	{
		char name[20];
		int check = 0;
		Family* p = com->head;
		printf("��������¼���ͥ�����֣�");
		scanf_s("%s", name, 20);
		for (int i = 0; i < com->n; i++)
		{
			if (strcmp(name, p->famName) == 0)
			{
				printf("�û����ѱ�ռ�ã����������룡\n");
				check++;
				printf("%d", check);
			}
			else
				p = p->next;
		}
		if (check == 0)
		{
			buildFamily(com, name);
			com->n++;
			printf("���м�ͥ%d��\n", com->n);
			break;
		}
	}
}


