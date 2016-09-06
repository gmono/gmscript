#pragma once
#include <set>
#include "Array.h"
#include "SCValue.h"
using namespace std;
struct ExecPar
{
	ValueType type;//数据类型
	bool isscval;//是否为SCValue指针 否则为数据指针
	void *data;//数据指针
};
class SCommandList;
//执行器的基础类
//约定：执行器从不保存execpar内的任何内容
class SCExecBase
{
public:
	SCExecBase();
	virtual ~SCExecBase();

	set<string> exguids;//这是执行器的guid列表 可以有多个scguid对应到这个执行器（但是一个scommand只能有一个guid）
	virtual void exec(Array<ExecPar> &pars,SCommandList *currlist)=0;//pars为参数列表 其中的每个成员都是一个数据引用 curlist为当前解析的scommandlist
};

