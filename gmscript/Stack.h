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
	byte *topptr;//栈从高到低 
	//topptr-
	template<class T>
	void push(T data);
	//topptr+
	template<class T>
	T pop();

	template<class T>
	T &top();

	//栈索引 从栈顶开始 允许负数
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
		topptr[i] = bda[i];//复制到栈中
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
	// TODO: 在此处插入 return 语句
}

template<class T>
inline Stack::operator[](int64_t)
{
}
