#pragma once

#include <vector>
using namespace std;
typedef unsigned char byte;
//此栈为模拟硬件栈 地址从高到低扩展
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
	T& operator[](int64_t);
};