#pragma once
#include <string>
#include "Array.h"
using namespace std;
class SCommand
{
public:
	SCommand();
	~SCommand();

	
	Array<uint32_t> supply;//�ṩ��������id�б�
	string scguid; //ִ����id
	uint32_t datalen;//���ݵĳ��� byte�� ���ڱȽ�����SCommand�Ƿ����
	void *dataptr; //ָ��������ݵ�ָ��
	Array<uint32_t> require;//�������������id�б�
};

