#pragma once
#include "SCValue.h"
#include "Array.h"
#include "SCommand.h"
//�������ý��������ȼ�Ϊ ջ���� fast  ջ��ͨlocal  �������ţ�sym command��
class SCommandList
{
public:
	SCommandList();
	~SCommandList();

	dict partb;//CL�������ű�
	dict symtb;//CL�ڲ����ű� //������self=dict() parent=nullptr
	Array<SCommand *> list;//�洢scommand��ָ��

	void *GetDataPtr(const string &name);//�ӷ��Ż�ȡ����ָ�� һ��Ϊִ����ʹ�� һ�����ȼ�Ϊ partb  symtb ���ָ���� pars.xx�ĸ�ʽ ��ֱ���޶�����partb ʹ��parsֱ�ӷ��ʲ����� ʹ��symֱ�ӷ��ʷ��ű� sym.xxΪ�޶����ű����
};

