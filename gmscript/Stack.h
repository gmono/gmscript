#pragma once

#include <vector>
using namespace std;
typedef unsigned char byte;
//��ջΪģ��Ӳ��ջ ��ַ�Ӹߵ�����չ
class Stack
{
public:
	Stack(size_t len);
	~Stack();
	byte *dataptr;
	byte *topptr;//ջ�Ӹߵ��� 
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