#pragma once
#include <string>
#include "Array.h"
using namespace std;
class SCommand
{
public:
	SCommand();
	~SCommand();

	
	Array<uint32_t> supply;//提供数据类型id列表
	string scguid; //执行者id
	uint32_t datalen;//数据的长度 byte计 用于比较两个SCommand是否相等
	void *dataptr; //指向具体数据的指针
	Array<uint32_t> require;//请求的数据类型id列表
};

