#include "SCValue.h"




SCValue::SCValue(void * ptr, uint32_t len, dict * meta, string name)
{
	this->name = name;
	data.dataptr = (byte *)ptr;
	data.length = len;
	metadata = *meta;//����Ԫ����
}

SCValue::~SCValue()
{
	//����ɾ������
}

SCValue * SCValue::GetNewPtr()
{
	this->ptrsum++;
	return this;
}

void SCValue::Scan()
{
	if (this->ptrsum == 0) delete this;
}
