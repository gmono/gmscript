#pragma once
//�ű������������� ��ÿ���������һ���ű�ִ��������
#include <iostream>
#include <map>
using namespace std;
typedef unsigned char byte;
struct Value
{
	byte *ptr;//����ָ��
	int len;//������С
};

class ScriptCore
{
public:
	//ScriptCore��ʼ��
	//stacklen:��ʼջ��С ��ջ���Զ���չ��
	ScriptCore(int stacklen=4*1024*1024);
	~ScriptCore();

private:
	byte *stackptr = nullptr;
	map<string, Value *> gsymbols;//ȫ�ַ��ű� ÿ�����Ŷ�Ӧһ��value����

};

