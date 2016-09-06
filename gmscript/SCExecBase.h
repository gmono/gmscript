#pragma once
#include <set>
#include "Array.h"
#include "SCValue.h"
using namespace std;
struct ExecPar
{
	ValueType type;//��������
	bool isscval;//�Ƿ�ΪSCValueָ�� ����Ϊ����ָ��
	void *data;//����ָ��
};
class SCommandList;
//ִ�����Ļ�����
//Լ����ִ�����Ӳ�����execpar�ڵ��κ�����
class SCExecBase
{
public:
	SCExecBase();
	virtual ~SCExecBase();

	set<string> exguids;//����ִ������guid�б� �����ж��scguid��Ӧ�����ִ����������һ��scommandֻ����һ��guid��
	virtual void exec(Array<ExecPar> &pars,SCommandList *currlist)=0;//parsΪ�����б� ���е�ÿ����Ա����һ���������� curlistΪ��ǰ������scommandlist
};

