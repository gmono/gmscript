#pragma once
#include "SCommand.h"
//reader的基类
class SCReaderBase
{
public:
	SCReaderBase();
	virtual ~SCReaderBase();
	//reader提供前缀符号 如果符合则使用此reader读取
	//前缀检测从长到短
	//read函数调用时index并没有跳过前缀
	Array<string> strlist;
	//阅读函数 返回一个command列表指针
	//返回scommand index为返回式参数 函数结束后index为analy继续分析的开始地址
	//返回列表允许一个reader读取不同的命令并返回
	//理论上可以实现一个reader读取整个源文件 但不推荐这么做
	virtual Array<SCommand *> read(string &str, uint32_t &index)=0;
};

