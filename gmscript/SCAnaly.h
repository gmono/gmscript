#pragma once
#include "SCReaderBase.h"
#include "SCommandList.h"
//analy 接受一系列reader 并接受一个文本 返回一个commandlist
//注意 特殊command由analy处理 不经过reader 因此reader的前缀不能是这些特殊command的前缀
class SCAnaly
{
public:
	//接受一系列reader
	SCAnaly(Array<SCReaderBase *> &list);
	~SCAnaly();

	SCommandList *analy(string code);
};

