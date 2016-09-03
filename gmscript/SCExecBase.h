#pragma once
#include <set>
#include "Array.h"
using namespace std;
struct ExecPar
{
	void *dataptr=nullptr;
	bool isdata = false;//是否为直接数据引用
};
//执行器的基础类
class SCExecBase
{
public:
	SCExecBase();
	virtual ~SCExecBase();

	set<string> exguids;//这是执行器的guid列表 可以有多个scguid对应到这个执行器（但是一个scommand只能有一个guid）
	virtual void exec(Array<ExecPar> &pars)=0;//pars为参数列表 其中的每个成员都是一个数据引用（可以是SCValue 指针和直接的数据对象指针)
};

