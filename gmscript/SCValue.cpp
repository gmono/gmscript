#include "SCValue.h"




SCValue::SCValue(void * ptr, uint32_t len, ValueType mtype, dict * meta, string name)
{
	this->name = name;
	data.dataptr = (byte *)ptr;
	data.length = len;
	mvaltype = mtype;
	metadata = *meta;//复制元数据
}

SCValue::~SCValue()
{
	//不用删除数据
}

SCValue * SCValue::GetNewPtr()
{
	this->ptrsum++;
	return this;
}

void SCValue::DeletePtr()
{
	this->ptrsum--;
	if (this->ptrsum == 0) delete this;
}

void SCValue::Scan()
{
	if (this->ptrsum == 0) delete this;
}
