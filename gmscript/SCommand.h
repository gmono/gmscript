#pragma once
#include <string>
#include "Array.h"
using namespace std;
//command本身只是记录信息
//数据引用为特殊command 请求数据为空 数据指针指向数据实体 提供数据类型为目标数据类型
//数据引用通常由对栈对象或栈快速对象的引用得到  对于栈对象其scguid为data 快速对象为fast 指针分别指向scvalue和具体数据
//对符号表数据的引用 scguid为"sym” 数据指针指向string对象 内容为符号名字
//数据引用的处理scommand由执行器完成
class SCommand
{
public:
	SCommand();
	~SCommand();

	
	uint32_t supply;//提供数据类型id
	string scguid; //执行者id
	uint32_t datalen;//数据的长度 byte计 用于比较两个SCommand是否相等
	void *dataptr; //指向具体数据的指针
	Array<Array<uint32_t>> require;//请求的数据类型id列表 内层为可容许的数据类型 外层为需求的多个数据提供者 例如 make 需要两个提供者 两个数据类型都为string
};

