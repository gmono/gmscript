#pragma once
#include <vector>
#include "SCommand.h"
#include <map>
#include "SCValue.h"
using namespace std;
class SCommandList
{
	//SCommand�б�
	vector<SCommand *> *comlist = nullptr;//SCommand�б�
	map<string, SCValue *> *localvales = nullptr;//���Ǳ��ر����� ͨ�� clistname.objname����
};