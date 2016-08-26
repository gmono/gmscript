#pragma once

#include "MultiVector.h" //多重映射表
using namespace std;
typedef unsigned char byte;
//此栈为模拟硬件栈 地址从高到低扩展
class Stack
{
public:
	//len以byte为单位 最大长度为4GB
	Stack(size_t len);
	~Stack();
	MultiVector<byte> *data;//数据表
	int64_t topptr;//栈顶索引
	int64_t downptr;//栈低索引 为了防止top和pop的错误
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