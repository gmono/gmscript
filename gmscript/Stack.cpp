#include "Stack.h"

Stack::Stack(size_t len)
{
	size_t pars[2]{ len,1024 * 1024 };//len长度的目录 1M的分配单元 共4G的寻址空间
	this->data = new MultiVector<byte>(pars, 2);//
	this->downptr = len*1024 * 1024-1;//指向地址最末尾 减一是为了避免访问错误
	this->topptr = downptr;
}

Stack::~Stack()
{
	delete this->data;
}
