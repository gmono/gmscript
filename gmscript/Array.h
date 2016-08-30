#pragma once
#include <cstdint>
#include "ToolsFuns.h"
template<class T>
struct Array
{
	uint32_t length=0;//���ݳ��� ��sizeof TΪ��λ
	T *dataptr=nullptr; //����ָ��
	Array(const Array<T> &data)
	{
		if (dataptr != nullptr) delete[] dataptr;
		dataptr = new T[data.length];
		dmemcpy(*dataptr, 0, *data.dataptr, 0, data.length);//��������
	}
	Array(Array<T> &&data)
	{
		//�ƶ����캯��
		if (dataptr != nullptr) delete[] dataptr;
		this->dataptr = data.dataptr;
		this->length = data.length;
	}
	Array<T> &operator=(Array<T> &data)
	{
		//����
		Array<T> *temp = new Array<T>(data);//���ƹ���
		length = temp->length;
		dataptr = temp->dataptr;

		temp->dataptr = nullptr;//Ϊ�˲��ͷ�����
		delete temp;//�ͷŶ��� �������ͷ����ݣ�
	}
	Array() = default;
	~Array()
	{
		//����
		if (dataptr != nullptr) delete[] dataptr;
	}
};