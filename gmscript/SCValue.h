#pragma once
#include <string>
#include <map>
using namespace std;
class SCValue;
typedef map<string, SCValue *> dict;//dict���Ͷ���
class SCValue
{
public:
	SCValue();
	~SCValue();
	string name;
	void *dataptr;
	uint32_t  length;
	uint32_t ptrsum;
	dict metadata;
};

