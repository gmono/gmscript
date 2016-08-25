#pragma once
//脚本解释器核心类 其每个对象代表一个脚本执行上下文
#include <iostream>
#include <map>
using namespace std;
typedef unsigned char byte;
struct Value
{
	byte *ptr;//变量指针
	int len;//变量大小
};

class ScriptCore
{
public:
	//ScriptCore初始化
	//stacklen:初始栈大小 （栈会自动扩展）
	ScriptCore(int stacklen=4*1024*1024);
	~ScriptCore();

private:
	byte *stackptr = nullptr;
	map<string, Value *> gsymbols;//全局符号表 每个符号对应一个value变量

};

