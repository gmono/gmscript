#pragma once
#include <string>
#include "Array.h"
using namespace std;
//command����ֻ�Ǽ�¼��Ϣ
//����scommand��scguidΪ d��ͷ���ַ��� ������Ϊ{��ͷ��guid
//����scommand��ֱ�Ӹ������������� ���� df fast�������� dl local(stack)�������� dp �������ű���������
//ds �ڲ����ű��������� dg ȫ�ַ��ű���������
//fast���������� dataptrֱ��ָ�����ݱ��� ������SCValue����
//���ű����������� dataptrָ��string���� string�����¼����
//������ֱ�Ӹ��������� ������ �ַ����ȶ�Ϊconst�������� scguid��c��ͷ dataptrֱ��ָ������
//const����ʹ�ú�ᱻֱ���ͷ� 
//����scommand��ִ�������
class SCommand
{
public:
	SCommand();
	~SCommand();

	
	Array<Array<uint32_t>> supply;//�ṩ��������id�б� �ڲ�Ϊ��������������� ���Ϊ����Ķ�������ṩ�� ���� make ��Ҫ�����ṩ�� �����������Ͷ�Ϊstring
	string scguid; //ִ����id
	uint32_t datalen;//���ݵĳ��� byte�� ���ڱȽ�����SCommand�Ƿ����
	void *dataptr; //ָ��������ݵ�ָ��
	Array<uint32_t> require;//�������������id�б�
};

