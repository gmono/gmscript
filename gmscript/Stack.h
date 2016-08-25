#pragma once

#include <vector>
using namespace std;
typedef unsigned char byte;

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
	operator[](int64_t);
};

template<class T>
inline void Stack::push(T data)
{
	int32_t size = sizeof(data);
	byte *bda = &data;
	topptr -= size;
	for (int i = 0; i < size; i++)
	{
		topptr[i] = bda[i];//���Ƶ�ջ��
	}
}

template<class T>
inline T Stack::pop()
{
	return T();
}

template<class T>
inline T & Stack::top()
{
	// TODO: �ڴ˴����� return ���
}

template<class T>
inline Stack::operator[](int64_t)
{
}
