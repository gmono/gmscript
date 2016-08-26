#pragma once

#include "MultiVector.h" //����ӳ���
using namespace std;
typedef unsigned char byte;
//��ջΪģ��Ӳ��ջ ��ַ�Ӹߵ�����չ
class Stack
{
public:
	//len��byteΪ��λ ��󳤶�Ϊ4GB
	Stack(size_t len);
	~Stack();
	MultiVector<byte> *data;//���ݱ�
	int64_t topptr;//ջ������
	int64_t downptr;//ջ������ Ϊ�˷�ֹtop��pop�Ĵ���
	//topptr-
	template<class T>
	void push(T data);
	//topptr+
	template<class T>
	T pop();

	template<class T>
	T &top();

	//ջ���� ��ջ����ʼ ������
	template<class T>
	T& operator[](int64_t);
};