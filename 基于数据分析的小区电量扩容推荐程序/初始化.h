#include"�����С����ͥ.h"
#pragma once
void addDate(Family *fam);//�����еĻ�������һ�飨�£�����
Family* buildFamily(Community* com,char*name);//�½�һ����
Community* buildCommunity(Administration* adm);//�½�һ��С��
Administration* buildAdministration();
void initCommunity(Community* com);//��С������Ӽ�ͥ
void initAdministration(Administration* adm);//����������С��

void autoAddDate(Family* fam);//�Զ���������
void autoBuildFamily(Community* com);//�Զ����ɼ�ͥ
void autoBuildCommunity(Administration* adm, char* name);//�Զ����ӽ�һ����С������ͥ�������,�����Լ�����
void autoBuildAdministration(int num);//ֱ���½���adm,�ⲿ����С����





