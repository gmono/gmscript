#include "SCommandList.h"



SCommandList::SCommandList()
{
	//��ӹ���dict
	dict *self = new dict();
	uint32_t len = sizeof(dict);
	SCValue *selfval = new SCValue((void *)self, len, ValueType::Dict);
	SCValue *parent = nullptr;//parent���� Ĭ��Ϊnullptr
	//����
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
