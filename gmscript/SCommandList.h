#pragma once
#include "SCValue.h"
#include "Array.h"
#include "SCommand.h"
class SCommandList
{
public:
	SCommandList();
	~SCommandList();

	dict partb;//CL�������ű�
	dict symtb;//CL�ڲ����ű� //������self=dict() parent=nullptr
	Array<SCommand *> list;//�洢scommand��ָ��
};

