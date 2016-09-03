#pragma once
#include "SCValue.h"
#include "Array.h"
#include "SCommand.h"
class SCommandList
{
public:
	SCommandList();
	~SCommandList();

	dict partb;//CL参数符号表
	dict symtb;//CL内部符号表 //其中有self=dict() parent=nullptr
	Array<SCommand *> list;//存储scommand的指针
};

