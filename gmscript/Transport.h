#pragma once
#include "SCValue.h"
class TransPort
{
	//���丨������ isvalָʾ�Ƿ����ֵ���ݣ�����һ���¶��� Ĭ��ֵ����
	static void Trans(SCValue *&to, SCValue *from, bool isval=true)
	{
		if (!isval)
		{
			//���ô���
			to = from->GetNewPtr();
		}
		else
		{
			SCValue *nptr = new SCValue(*from);//����һ���µ�
			nptr->data = from->data;//��������
			nptr->ptrsum = 1;//���ƵĶ�������ֻ��һ������
			to->DeletePtr();//ɾ��һ������
			to = nptr;//��ֵ Ŀ��ָ���nptr��ͬ
			//��ֵ���
		}
	}
};