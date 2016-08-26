#pragma once

#include "MultiVector.h" //����ӳ���
#include "ToolsFuns.h"//���ߺ�����
using namespace std;
typedef unsigned char byte;
//��ջΪģ��Ӳ��ջ ��ַ�Ӹߵ�����չ ����������ʱ ����Ϊ��ջ��չ������� ����Ϊ��ջ�з���
//���������з���64λ������Ϊ���� ���ע�ⲻҪԽ�� ��������δ֪���
class Stack
{
public:
	//len��MΪ��λ ��󳤶�4294967296MB ������2^63��64λ�з������������ֵ��
	Stack(size_t len);
	~Stack();

	//topptr-
	template<class T>
	void push(T data);
	//topptr+
	template<class T>
	T pop();

	template<class T>
	T &top();

	//ջ���� ��ջ����ʼ ������
	template<class T>
	T& operator[](int64_t);
private:
	MultiVector<byte> *data;//���ݱ�
	int64_t topptr;//ջ������
	int64_t downptr;//ջ������ Ϊ�˷�ֹtop��pop�Ĵ��� �ڳ�ջ�����Խ��ʱ�ṩ���



};

template<class T>
inline void Stack::push(T data)
{
	//��ջ �������Ͳ��� ��byteΪ��λ����
	size_t size = sizeof(data);//�õ�data�Ĵ�С
	//���Ȳ���ջ��
	topptr -= size;
	dmemcpy(data, topptr, &data, 0, size);//��������
}

template<class T>
inline T Stack::pop()
{
	
	T ret;
	size_t size = sizeof(ret);//��ȡ�������ʹ�С
	 //Խ����
	if (topptr + size > downptr) throw "��ջԽ��";
	//
	dmemcpy(&ret, 0, data, topptr, size);//���Ƶ�����
	topptr += size;//����ջ��
	return T();
}

template<class T>
inline T & Stack::top()
{
	return data[topptr];
	// TODO: �ڴ˴����� return ���
}

template<class T>
inline T & Stack::operator[](int64_t index)
{
	int64_t dstptr = topptr + index;//�õ�Ŀ������
	if (dstptr<0 || dstptr>downptr) throw "�������Խ��";
	//����ΪԽ����
	return data[dstptr];
	// TODO: �ڴ˴����� return ���
}
