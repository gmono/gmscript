#pragma once
#include "SCommandList.h"
//执行器类 接受一个commandlist并执行
class SCRunner
{
public:
	SCRunner();
	~SCRunner();

	void Run(SCommandList &list);//此类处理数据引用
};

