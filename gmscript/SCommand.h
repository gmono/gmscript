#pragma once
#include <string>
#include "Array.h"
using namespace std;
//command本身只是记录信息
//特殊scommand的scguid为 d开头的字符串 正常的为{开头的guid
//特殊scommand有直接给出的数据引用 包括 df fast数据引用 dl local(stack)数据引用 dp 参数符号表数据引用
//ds 内部符号表数据引用 dg 全局符号表数据引用
//fast数据引用中 dataptr直接指向数据本身 而不是SCValue对象
//符号表数据引用中 dataptr指向string对象 string对象记录符号
//程序中直接给出的数据 如数字 字符串等都为const数据引用 scguid由c开头 dataptr直接指向数据
//const引用使用后会被直接释放 
//处理scommand由执行器完成
class SCommand
{
public:
	SCommand();
	~SCommand();

	
	Array<Array<uint32_t>> supply;//提供数据类型id列表 内层为可容许的数据类型 外层为需求的多个数据提供者 例如 make 需要两个提供者 两个数据类型都为string
	string scguid; //执行者id
	uint32_t datalen;//数据的长度 byte计 用于比较两个SCommand是否相等
	void *dataptr; //指向具体数据的指针
	Array<uint32_t> require;//请求的数据类型id列表
};

