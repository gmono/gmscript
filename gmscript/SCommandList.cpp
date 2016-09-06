#include "SCommandList.h"



SCommandList::SCommandList()
{
	//添加固有dict
	dict *self = new dict();
	uint32_t len = sizeof(dict);
	SCValue *selfval = new SCValue((void *)self, len, ValueType::Dict);
	SCValue *parent = nullptr;//parent对象 默认为nullptr
	//加入
	symtb.insert(kvc("self", selfval));
	symtb.insert(kvc("parent", parent));
}


SCommandList::~SCommandList()
{
}

void * SCommandList::GetDataPtr(const string & name)
{
	return nullptr;
}
