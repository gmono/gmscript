#pragma once
#include "SCReaderBase.h"
#include "SCommandList.h"
//analy ����һϵ��reader ������һ���ı� ����һ��commandlist
//ע�� ����command��analy���� ������reader ���reader��ǰ׺��������Щ����command��ǰ׺
class SCAnaly
{
public:
	//����һϵ��reader
	SCAnaly(Array<SCReaderBase *> &list);
	~SCAnaly();

	SCommandList *analy(string code);
};

