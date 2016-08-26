#pragma once

#include "MultiVector.h" //多重映射表
#include "ToolsFuns.h"//工具函数集
using namespace std;
typedef unsigned char byte;
//此栈为模拟硬件栈 地址从高到低扩展 因此随机访问时 负数为向栈扩展方面访问 正数为向栈中访问
//此类中用有符号64位整数作为索引 因此注意不要越界 避免引起未知后果
class Stack
{
public:
	//len以M为单位 最大长度4294967296MB 不超过2^63（64位有符号整数的最大值）
	Stack(size_t len);
	~Stack();

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
	T& at(int64_t);

	template<class T>
	int64_t size()
	{
		//栈大小
		int64_t ret = (downptr - topptr) / sizeof(*(new T()));
		return ret;
	}
private:
	MultiVector<byte> *data;//数据表
	int64_t topptr;//栈顶索引
	int64_t downptr;//栈底索引 为了防止top和pop的错误 在出栈或访问越界时提供检测



};

template<class T>
inline void Stack::push(T var)
{
	//入栈 数据类型不定 以byte为单位操作
	size_t size = sizeof(var);//得到data的大小
	//首先操作栈顶
	topptr -= size;
	byte *varptr = (byte *)&var;//得到指针
	dmemcpy(*this->data, topptr, varptr, 0, size);//复制数据
}

template<class T>
inline T Stack::pop()
{
	
	T ret;
	size_t size = sizeof(ret);//获取数据类型大小
	 //越界检测
	if (topptr + size > downptr) throw "出栈越界";
	//
	byte *retptr = (byte *)&ret;
	dmemcpy(retptr, 0, *this->data, topptr, size);//复制到变量
	topptr += size;//降低栈顶
	return ret;
}

template<class T>
inline T & Stack::top()
{
	int64_t dstptr = topptr + sizeof(*(new T()))-1;//得到最多要取到的索引
	if (dstptr<0 || dstptr>downptr) throw "栈顶访问越界";
	return *(T *)&(*data)[topptr];
	// TODO: 在此处插入 return 语句
}

template<class T>
inline T & Stack::at(int64_t index)
{
	int64_t size = sizeof(*(new T()));
	int64_t dstptr = topptr + (size*index);//得到目的索引
	
	if (dstptr<0 || dstptr>downptr) throw "随机访问越界";
	//以上为越界检测
	return *(T *)&(*data)[dstptr];
	// TODO: 在此处插入 return 语句
}
