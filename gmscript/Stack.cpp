#include "Stack.h"

Stack::Stack(size_t len)
{
	size_t pars[2]{ len,1024 * 1024 };//len���ȵ�Ŀ¼ 1M�ķ��䵥Ԫ ��4G��Ѱַ�ռ�
	this->data = new MultiVector<byte>(pars, 2);//
	this->downptr = len*1024 * 1024-1;//ָ���ַ��ĩβ ��һ��Ϊ�˱�����ʴ���
	this->topptr = downptr;
}

Stack::~Stack()
{
	delete this->data;
}
