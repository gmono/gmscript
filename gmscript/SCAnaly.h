#pragma once
#include "SCReaderBase.h"
#include "SCommandList.h"
//analy 接受一系列reader 并接受一个文本 返回一个commandlist
class SCAnaly
{
public:
	//接受一系列reader
	SCAnaly(Array<SCReaderBase *> &list);
	~SCAnaly();

	SCommandList *analy(string code);
};

