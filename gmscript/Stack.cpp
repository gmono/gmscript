#include "Stack.h"

Stack::Stack(size_t len)
{
	size_t pars[2]{ 4 * 1024,1024 * 1024 };//4K��Ŀ¼ 1M�ķ��䵥Ԫ ��4G��Ѱַ�ռ�
	this->data = new MultiVector<byte>(pars, 2);//
	this->downptr = 4 * 1024 * 1024 * 1024-1;//ָ���ַ��ĩβ
	this->topptr = downptr;
}

Stack::~Stack()
{
	delete this->data;
}
