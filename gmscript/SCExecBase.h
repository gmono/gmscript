#pragma once
#include <set>
#include "Array.h"
using namespace std;
struct ExecPar
{
	void *dataptr=nullptr;
	bool isdata = false;//�Ƿ�Ϊֱ����������
};
//ִ�����Ļ�����
class SCExecBase
{
public:
	SCExecBase();
	virtual ~SCExecBase();

	set<string> exguids;//����ִ������guid�б� �����ж��scguid��Ӧ�����ִ����������һ��scommandֻ����һ��guid��
	virtual void exec(Array<ExecPar> &pars)=0;//parsΪ�����б� ���е�ÿ����Ա����һ���������ã�������SCValue ָ���ֱ�ӵ����ݶ���ָ��)
};

