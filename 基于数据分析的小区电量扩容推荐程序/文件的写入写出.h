#include"�����С����ͥ.h"
//�ļ��а�˳��д��һ����ͥ(��comWriteIn���ã����𵥶�����)
void famWriteIn(Family* fam,int n, FILE* fp);
//�ļ��а�˳��д��һ��С������admWriteIn���ã����𵥶�����)
void comWriteIn(Community* com,int n, FILE* fp);
//�ļ���д��һ�����ӣ�ֻ��Ҫ���������ʹ�÷�ʽ�������Ѿ���ʼ����ȫ��administration�����洢��ʽΪ������ͷ->С��ͷ1->С��1�ļ�ͥ1~n->С��ͷ2->С��1�ļ�ͥ1~n->����->С��ͷN->С��N�ļ�ͥ1~n��
void admWriteIn(Administration* adm);
//ȡ��community�������family����community��ļ�ͥheadָ�����Ŀn�Ž��������ļ������ݴ��루fp����֮ǰ��fileָ�������ȡ��������ʹ����㺯���������𵥶����ã�
void famReadFile(Community* com, FILE* fp);			/*����С���е�ͷָ��ͼ�ͥ����*/
//ȡ��administration�������community����administration���С��headָ�����Ŀn�Ž��������ļ������ݴ��루fp����֮ǰ��fileָ�������ȡ��������ʹ����㺯���������𵥶����ã�
void comReadFile(Administration*adm,  FILE* fp);
//ֱ�ӵ�������������Ϳ��Դ��ļ�����ק����ȫ�����ݿ�(ʹ�÷�ʽ������һ��Ԥ���adm�ĵ�ַ����Ҫ��ʼ�����ñ����������ʼ������ȡ��˳��Ϊ����ͷ->С��ͷ1->С��1�ļ�ͥ1~n->С��ͷ2->С��1�ļ�ͥ1~n->����->С��ͷN->С��N�ļ�ͥ1~n��
void admReadFile(Administration* adm);
