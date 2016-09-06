#pragma once
#include <string>
#include <map>
#include "Array.h"
using namespace std;
class SCValue;
typedef map<string, SCValue *> dict;//dict类型定义 对符号表而言 如果SCValue为nullptr代表此变量为空 脚本内此变量为nullptr若不存在这个符号则为undefine
typedef pair<string, SCValue *> kvc;//键值对类型定义
typedef unsigned char byte;
//元类型定义 元类型是有限的任何自定义类型都是元类型的一种 例如 任何结构体都是dict 任何构造器都是clist
enum ValueType:int64_t {
	CommandList,
	Dict,
	Command,
	Arr, //数组 不与Array类冲突
	Number,
	Int,UInt,
	Double,
	Float256,
	String,
	Char,
	None //未确定的类型
};
class SCValue
{
public:
	SCValue(void *ptr,uint32_t len,ValueType mtype,dict *meta=nullptr,string name=string());
	~SCValue();
	SCValue *GetNewPtr();//获取一个指向同一SCValue的指针时只能使用这个函数
	void DeletePtr();//删除一个对此对象的引用
	void Scan();//扫描自己的引用计数如果 引用计数为0就释放自己
	string name; //自定义类型名
	ValueType mvaltype;//元类型标记
	Array<byte> data;//数据
	uint32_t ptrsum;
	dict metadata;
};

