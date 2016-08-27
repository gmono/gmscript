#pragma once
#include <string>
using namespace std;
//虚拟机变量以string:SCValue存储
class SCValue
{
public:
	string id;//唯一变量名  一个SCValue可能与几个key对应  但是id只能有一个
	void *dataptr;//数据指针
	string type;//类型名
	//以下为元数据
};

