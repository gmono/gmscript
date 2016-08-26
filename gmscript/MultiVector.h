#pragma once
//多重映射表
#include <iostream>
template<class ValueType>
class MultiVector
{
public:
	//pars为每一层的大小 laycount为层数 也是pars数组的大小  isinit指示是否初始化为0
	//最后一层才保存基本数据
	MultiVector(size_t *pars, int laycount,bool isinit=false);
	~MultiVector();
	ValueType &operator[](uint64_t index);
private:

	size_t len;//表长度
	bool isdata; //是否为数据表
	union Table
	{

		MultiVector<ValueType> **upptr; //上层映射表的指针表
		ValueType *dataptr;//数据表指针
	};
	Table table;//表数据

	int64_t mulfac=1;//除数 寻址因子
	//以下为表创建因子 上层表才用得到
	size_t *mpars; //用于创建下层表的参数
	bool misinit;
	int mlaycount;//参数数量 也是下层表的层数
	//以下为符号重载

	
};

template<class ValueType>
MultiVector<ValueType>::MultiVector(size_t *pars, int laycount, bool isinit)
{
	if (laycount == 0) throw "参数错误";
	len = *pars;//当前表大小
	if (laycount > 1)
	{
		//这里保存下层表创建因子
		this->mlaycount = laycount - 1; //保存下层表参数个数
		this->mpars = new size_t[this->mlaycount];//创建空间
		memcpy(this->mpars, pars + 1, sizeof(*(new ValueType()))*this->mlaycount);//复制下层表创建参数
		this->misinit = isinit;
		//
		isdata = false;//非数据表
		table.upptr = new MultiVector<ValueType>*[len] {nullptr};//创建指针表 全部没创建
																 //以下是处理寻址因子的部分
		for (int i = 1; i < laycount; ++i)
		{
			mulfac *= pars[i];//连续乘
		}
	}
	else
	{
		isdata = true;
		if (isinit)
			table.dataptr = new ValueType[len]{ 0 };//开一个数据空间 初始化为0
		else table.dataptr = new ValueType[len];//开一个数据空间 不初始化
	}
}

template<class ValueType>
MultiVector<ValueType>::~MultiVector()
{
	if (isdata)
	{
		delete[] table.dataptr;//删除数据表
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			if (table.upptr[i] != nullptr)
				delete table.upptr[i];//删除上层表
		}
		delete[] table.upptr;//删除指针表
	}
}

template<class ValueType>
ValueType & MultiVector<ValueType>::operator[](uint64_t index)
{
	if (isdata)
	{
		return table.dataptr[index];//如果是数据表就返回数据引用
	}
	else
	{
		size_t upindex = index / mulfac; //上层表索引
		size_t downindex = index%mulfac;//下层表索引
		MultiVector<ValueType> *temptab = table.upptr[upindex];//得到目的表
		if (temptab == nullptr) {
			temptab = new MultiVector<ValueType>(mpars, mlaycount, misinit);//创建一个新表
			table.upptr[upindex] = temptab;//保存指针
		}
		ValueType &ret = (*temptab)[downindex];
		return ret;
	}
}