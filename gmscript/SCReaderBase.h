#pragma once
#include "SCommand.h"
//reader�Ļ���
class SCReaderBase
{
public:
	SCReaderBase();
	virtual ~SCReaderBase();
	//reader�ṩǰ׺���� ���������ʹ�ô�reader��ȡ
	//ǰ׺���ӳ�����
	//read��������ʱindex��û������ǰ׺
	Array<string> strlist;
	//�Ķ����� ����һ��command�б�ָ��
	//����scommand indexΪ����ʽ���� ����������indexΪanaly���������Ŀ�ʼ��ַ
	//�����б�����һ��reader��ȡ��ͬ���������
	//�����Ͽ���ʵ��һ��reader��ȡ����Դ�ļ� �����Ƽ���ô��
	virtual Array<SCommand *> read(string &str, uint32_t &index)=0;
};

