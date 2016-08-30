#pragma once
#include "SCValue.h"
class SCommandList
{
public:
	SCommandList();
	~SCommandList();

	dict partb;//CL参数符号表
	dict symtb;//CL内部符号表 //其中有self=dict() parent=nullptr
};

