#pragma once
#include "SCValue.h"
#include "Array.h"
#include "SCommand.h"
//数据引用解析的优先级为 栈快速 fast  栈普通local  其他符号（sym command）
class SCommandList
{
public:
	SCommandList();
	~SCommandList();

	dict partb;//CL参数符号表
	dict symtb;//CL内部符号表 //其中有self=dict() parent=nullptr
	Array<SCommand *> list;//存储scommand的指针

	void *GetDataPtr(const string &name);//从符号获取数据指针 一般为执行器使用 一般优先级为 partb  symtb 如果指定了 pars.xx的格式 会直接限定访问partb 使用pars直接访问参数表 使用sym直接访问符号表 sym.xx为限定符号表访问
};

