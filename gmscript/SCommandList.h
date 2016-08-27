#pragma once
#include <vector>
#include "SCommand.h"
#include <map>
#include "SCValue.h"
using namespace std;
class SCommandList
{
	//SCommand列表
	vector<SCommand *> *comlist = nullptr;//SCommand列表
	map<string, SCValue *> *localvales = nullptr;//这是本地变量表 通过 clistname.objname访问
};