#include "Stack.h"




Stack::Stack(size_t len)
{
	dataptr = new byte[len];
	topptr = dataptr + len;//ָ��ջ�� 
}

Stack::~Stack()
{
}
