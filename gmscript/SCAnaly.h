#pragma once
#include "SCReaderBase.h"
#include "SCommandList.h"
//analy ����һϵ��reader ������һ���ı� ����һ��commandlist
class SCAnaly
{
public:
	//����һϵ��reader
	SCAnaly(Array<SCReaderBase *> &list);
	~SCAnaly();

	SCommandList *analy(string code);
};

