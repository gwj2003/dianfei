#include"�����С����ͥ.h"
//�ļ��а�˳��д��һ����ͥ(��comWriteIn���ã����𵥶�����)
void famWriteIn(Family* fam,int n, FILE* fp)
{
	if (fp == NULL)
	{
		printf("�ļ���ʧ��:fam\n");					    /*����ʧ�������ʾ��Ϣ*/
		exit(0);
	}
	else
	{
		printf("�ļ��򿪳ɹ�:fam\n" );
		Family* p = fam;			
		for (int i = 0; i < n; i++)
		{
			printf("��ʼдfam%s\n",p->famName);
			fwrite(p, sizeof(Family), 1, fp);						/*һ�������ļ�д��һ��family��¼���ں�һ��family��2�ꡢ24���µ�����*/
			if (p->next != NULL)
			{
				p = p->next;
			}
			printf("д��һ��fam,��%d����ͥ\n", i);
		}
	}
}
//�ļ��а�˳��д��һ��С������admWriteIn���ã����𵥶�����)
void comWriteIn(Community* com,int n, FILE* fp)
{
	if (fp == NULL)
	{
		printf("�ļ���ʧ��:com\n");					    /*����ʧ�������ʾ��Ϣ*/
		exit(0);
	}
	else
	{
		printf("�ļ��򿪳ɹ�:com\n");
		Community* p = com;
		for (int i = 0; i < n; i++)
		{
			printf("��ʼдcom��%s����%d��fam\n", p->comName,p->n);
			fwrite(p, sizeof(Community), 1, fp);
			famWriteIn(p->head, p->n, fp);
			printf("д��com%s,��%d��С��\n",p->comName, i+1);
			if (p->next != NULL)
			{
				p = p->next;
			}
		}
	}
}
//�ļ���д��һ�����ӣ�ֻ��Ҫ���������ʹ�÷�ʽ�������Ѿ���ʼ����ȫ��administration�����洢��ʽΪ������ͷ->С��ͷ1->С��1�ļ�ͥ1~n->С��ͷ2->С��1�ļ�ͥ1~n->����->С��ͷN->С��N�ļ�ͥ1~n��
void admWriteIn(Administration* adm)
{
	FILE* fp;
	errno_t err = fopen_s(&fp, filePath, "wb");					/*�ǵ��ڹ����.h������ļ�·���ĳ��Լ���*/
	if (err==0)//����򿪳ɹ�
	{	
		fwrite(adm, sizeof(Administration), 1, fp);		 /*�������Ŀռ�����ļ����adm*/
		comWriteIn(adm->head, adm->n, fp);				 /*��ʼ��fp��adm���������community*/
		fclose(fp);
	}
	else
	{
		printf("�ļ���ʧ��:adm-w\n");							 /*����ʧ�������ʾ��Ϣ*/
		exit(0);
	}
	printf("д�����");
}


//ȡ��community�������family����community��ļ�ͥheadָ�����Ŀn�Ž��������ļ������ݴ��루fp����֮ǰ��fileָ�������ȡ��������ʹ����㺯���������𵥶����ã�
void famReadFile(Community* com, FILE* fp)			/*����С���е�ͷָ��ͼ�ͥ����*/
{
	if (fp == NULL)
	{
		printf("�ļ���ʧ��:fam\n");						/*����ʧ�������ʾ��Ϣ*/
		exit(0);
	}
	else
	{
		printf("�ļ��򿪳ɹ�:fam\n");						/*����ʧ�������ʾ��Ϣ*/
		for (int i = 0; i < com->n; i++)
		{
			Family* p1 = com->head;							//p->next��Զָ���
			Family* q1;
			for (int j = 0; j < i - 1; j++)		p1 = (p1)->next;
			q1 = (Family*)malloc(sizeof(Family) * 1);
			if (q1 == NULL)
			{
				printf("�ڴ�����ʧ��");
			}
			else
			{
				fread(q1, sizeof(Family), 1, fp);
				if (i == 0)
					com->head = q1;
				else
					p1->next = q1;
			}
			printf("����һ��fam���ǵ�%d������%s\n", i+1,q1->famName);
		}
	}
}
//ȡ��administration�������community����administration���С��headָ�����Ŀn�Ž��������ļ������ݴ��루fp����֮ǰ��fileָ�������ȡ��������ʹ����㺯���������𵥶����ã�
void comReadFile(Administration * adm, FILE* fp)
{
	if (fp == NULL)
	{
		printf("�ļ���ʧ��:com\n");					    /*����ʧ�������ʾ��Ϣ*/
		exit(0);
	}
	else
	{
		printf("�ļ��򿪳ɹ�:com\n");
		for ( int i = 0; i < adm->n; i++)
		{
			Community* p = adm->head;							//p->next��Զָ���
			Community* q;
			for (int j = 0; j < i - 1; j++) { p = (p)->next; }
			q = (Community*)malloc(sizeof(Community) * 1);
			if (q == NULL)
			{
				printf("�ڴ�����ʧ��");
			}
			else
			{
				printf("��ʼ��com\n");
				fread(q, sizeof(Community), 1, fp);	
				printf("С��%s��%d����ͥ\n", q->comName,q->n);
				famReadFile(q,fp);
				if (i == 0)
					adm->head = q;
				else
					p->next = q;
			}
			printf("����һ��com,��%d��С��\n",i+1);

		}
	}
}
//ֱ�ӵ�������������Ϳ��Դ��ļ�����ק����ȫ�����ݿ�(ʹ�÷�ʽ������һ��Ԥ���adm�ĵ�ַ����Ҫ��ʼ�����ñ����������ʼ������ȡ��˳��Ϊ����ͷ->С��ͷ1->С��1�ļ�ͥ1~n->С��ͷ2->С��1�ļ�ͥ1~n->����->С��ͷN->С��N�ļ�ͥ1~n��
void admReadFile(Administration* adm)
{
	FILE* fp;
	errno_t err = fopen_s(&fp, filePath, "rb");					/*�ǵ��ڹ����.h������ļ�·���ĳ��Լ���*/	
	if (err!=0)
	{
		printf("�ļ���ʧ��:adm-r\n");							 /*����ʧ�������ʾ��Ϣ*/
		exit(0);
	}
	else
	{
		printf("��ʼ��adm");
		//adm = (Administration*)malloc(sizeof(Administration) * 1);
		fread(adm, sizeof(Administration), 1, fp);		 /*�������Ŀռ�����ļ����adm*/
		printf("��%d��С��\n", adm->n);
		//comReadFile(adm->head, adm->n, fp);				 /*��ʼ��fp��adm���������community*/
		if (fp == NULL)
		{
			printf("�ļ���ʧ��:com\n");					    /*����ʧ�������ʾ��Ϣ*/
			exit(0);
		}
		else
		{
			printf("�ļ��򿪳ɹ�:com\n");
			for (int i = 0; i < adm->n; i++)
			{
				Community* p = adm->head;							//p->next��Զָ���
				Community* q;
				for (int j = 0; j < i - 1; j++) { p = (p)->next; }
				q = (Community*)malloc(sizeof(Community) * 1);
				if (q == NULL)
				{
					printf("�ڴ�����ʧ��");
				}
				else
				{
					printf("��ʼ��com\n");
					fread(q, sizeof(Community), 1, fp);
					printf("С��%s��%d����ͥ\n", q->comName, q->n);
					//famReadFile(q, fp);
					if (fp == NULL)
					{
						printf("�ļ���ʧ��:fam\n");						/*����ʧ�������ʾ��Ϣ*/
						exit(0);
					}
					else
					{
						printf("�ļ��򿪳ɹ�:fam\n");						/*����ʧ�������ʾ��Ϣ*/
						for (int i = 0; i < q->n; i++)
						{
							Family* p1 = q->head;							//p->next��Զָ���
							Family* q1;
							for (int j = 0; j < i - 1; j++)		p1 = (p1)->next;
							q1 = (Family*)malloc(sizeof(Family) * 1);
							if (q1 == NULL)
							{
								printf("�ڴ�����ʧ��");
							}
							else
							{
								fread(q1, sizeof(Family), 1, fp);
								if (i == 0)
									q->head = q1;
								else
									p1->next = q1;
							}
							printf("����һ��fam���ǵ�%d������%s\n", i + 1, q1->famName);
						}
					}

					if (i == 0)
						adm->head = q;
					else
						p->next = q;
				}
				printf("����һ��com,��%d��С��\n", i + 1);

			}
		}

		fclose(fp);
	}
}
