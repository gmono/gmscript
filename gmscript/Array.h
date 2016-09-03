#pragma once
#include <cstdint>
#include "ToolsFuns.h"
template<class T>
struct Array
{
	uint32_t length=0;//数据长度 以sizeof T为单位
	T *dataptr=nullptr; //数据指针
	Array(const Array<T> &data)
	{
		if (dataptr != nullptr) delete[] dataptr;
		dataptr = new T[data.length];
		dmemcpy(*dataptr, 0, *data.dataptr, 0, data.length);//复制数据
	}
	Array(Array<T> &&data)
	{
		//移动构造函数
		if (dataptr != nullptr) delete[] dataptr;
		this->dataptr = data.dataptr;
		this->length = data.length;
	}
	Array<T> &operator=(Array<T> &data)
	{
		//复制
		Array<T> *temp = new Array<T>(data);//复制构造
		length = temp->length;
		dataptr = temp->dataptr;

		temp->dataptr = nullptr;//为了不释放数据
		delete temp;//释放对象 （不会释放数据）
	}
	Array() = default;
	~Array()
	{
		//析构
		if (dataptr != nullptr) delete[] dataptr;
	}
};
template<class VT>
class LArray :public Array<VT>
{
	LArray(uint32_t start, uint32_t end)
	{
		setlimit(start, end-start+1);
	}
	Larray(uint32_t start,uint32_t len)
	{
		setlimit(start,len );
	}
	LArray(Array<VT> &&data):Array<VT>(data)
	{
		//move构造
		mstart = start;
	}
	

	//这里放限定数组访问函数
	//原array为直接访问数据指针
	VT &operator[](uint32_t index)
	{
		if (index<mstart ) throw "限定数组访问错误";
		return this->dataptr[index + mstart];
	}
private:
	void setlimit(uint32_t start,uint32_t len)
	{
		mstart = start;
		dataptr = new VT[len];//限定数组自动分配空间
		length = len;
	}
	uint32_t mstart;
};