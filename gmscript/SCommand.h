#pragma once
#include <string>
#include "Array.h"
using namespace std;
//command����ֻ�Ǽ�¼��Ϣ
//��������Ϊ����command ��������Ϊ�� ����ָ��ָ������ʵ�� �ṩ��������ΪĿ����������
//��������ͨ���ɶ�ջ�����ջ���ٶ�������õõ�  ����ջ������scguidΪdata ���ٶ���Ϊfast ָ��ֱ�ָ��scvalue�;�������
//�Է��ű����ݵ����� scguidΪ"sym�� ����ָ��ָ��string���� ����Ϊ��������
//�������õĴ���scommand��ִ�������
class SCommand
{
public:
	SCommand();
	~SCommand();

	
	uint32_t supply;//�ṩ��������id
	string scguid; //ִ����id
	uint32_t datalen;//���ݵĳ��� byte�� ���ڱȽ�����SCommand�Ƿ����
	void *dataptr; //ָ��������ݵ�ָ��
	Array<Array<uint32_t>> require;//�������������id�б� �ڲ�Ϊ��������������� ���Ϊ����Ķ�������ṩ�� ���� make ��Ҫ�����ṩ�� �����������Ͷ�Ϊstring
};

