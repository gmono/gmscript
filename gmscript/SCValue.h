#pragma once
#include <string>
#include <map>
#include "Array.h"
using namespace std;
class SCValue;
typedef map<string, SCValue *> dict;//dict���Ͷ��� �Է��ű���� ���SCValueΪnullptr����˱���Ϊ�� �ű��ڴ˱���Ϊnullptr�����������������Ϊundefine
typedef pair<string, SCValue *> kvc;//��ֵ�����Ͷ���
typedef unsigned char byte;
//Ԫ���Ͷ��� Ԫ���������޵��κ��Զ������Ͷ���Ԫ���͵�һ�� ���� �κνṹ�嶼��dict �κι���������clist
enum ValueType:int64_t {
	CommandList,
	Dict,
	Command,
	Arr, //���� ����Array���ͻ
	Number,
	Int,UInt,
	Double,
	Float256,
	String,
	Char,
	None //δȷ��������
};
class SCValue
{
public:
	SCValue(void *ptr,uint32_t len,ValueType mtype,dict *meta=nullptr,string name=string());
	~SCValue();
	SCValue *GetNewPtr();//��ȡһ��ָ��ͬһSCValue��ָ��ʱֻ��ʹ���������
	void DeletePtr();//ɾ��һ���Դ˶��������
	void Scan();//ɨ���Լ������ü������ ���ü���Ϊ0���ͷ��Լ�
	string name; //�Զ���������
	ValueType mvaltype;//Ԫ���ͱ��
	Array<byte> data;//����
	uint32_t ptrsum;
	dict metadata;
};

