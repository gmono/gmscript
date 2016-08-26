#pragma once
//����ӳ���
#include <iostream>
template<class ValueType>
class MultiVector
{
public:
	//parsΪÿһ��Ĵ�С laycountΪ���� Ҳ��pars����Ĵ�С  isinitָʾ�Ƿ��ʼ��Ϊ0
	//���һ��ű����������
	MultiVector(size_t *pars, int laycount,bool isinit=false);
	~MultiVector();
	ValueType &operator[](uint64_t index);
private:

	size_t len;//����
	bool isdata; //�Ƿ�Ϊ���ݱ�
	union Table
	{

		MultiVector<ValueType> **upptr; //�ϲ�ӳ����ָ���
		ValueType *dataptr;//���ݱ�ָ��
	};
	Table table;//������

	int64_t mulfac=1;//���� Ѱַ����
	//����Ϊ�������� �ϲ����õõ�
	size_t *mpars; //���ڴ����²��Ĳ���
	bool misinit;
	int mlaycount;//�������� Ҳ���²��Ĳ���
	//����Ϊ��������

	
};

template<class ValueType>
MultiVector<ValueType>::MultiVector(size_t *pars, int laycount, bool isinit)
{
	if (laycount == 0) throw "��������";
	len = *pars;//��ǰ���С
	if (laycount > 1)
	{
		//���ﱣ���²��������
		this->mlaycount = laycount - 1; //�����²���������
		this->mpars = new size_t[this->mlaycount];//�����ռ�
		memcpy(this->mpars, pars + 1, sizeof(*(new ValueType()))*this->mlaycount);//�����²��������
		this->misinit = isinit;
		//
		isdata = false;//�����ݱ�
		table.upptr = new MultiVector<ValueType>*[len] {nullptr};//����ָ��� ȫ��û����
																 //�����Ǵ���Ѱַ���ӵĲ���
		for (int i = 1; i < laycount; ++i)
		{
			mulfac *= pars[i];//������
		}
	}
	else
	{
		isdata = true;
		if (isinit)
			table.dataptr = new ValueType[len]{ 0 };//��һ�����ݿռ� ��ʼ��Ϊ0
		else table.dataptr = new ValueType[len];//��һ�����ݿռ� ����ʼ��
	}
}

template<class ValueType>
MultiVector<ValueType>::~MultiVector()
{
	if (isdata)
	{
		delete[] table.dataptr;//ɾ�����ݱ�
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			if (table.upptr[i] != nullptr)
				delete table.upptr[i];//ɾ���ϲ��
		}
		delete[] table.upptr;//ɾ��ָ���
	}
}

template<class ValueType>
ValueType & MultiVector<ValueType>::operator[](uint64_t index)
{
	if (isdata)
	{
		return table.dataptr[index];//��������ݱ�ͷ�����������
	}
	else
	{
		size_t upindex = index / mulfac; //�ϲ������
		size_t downindex = index%mulfac;//�²������
		MultiVector<ValueType> *temptab = table.upptr[upindex];//�õ�Ŀ�ı�
		if (temptab == nullptr) {
			temptab = new MultiVector<ValueType>(mpars, mlaycount, misinit);//����һ���±�
			table.upptr[upindex] = temptab;//����ָ��
		}
		ValueType &ret = (*temptab)[downindex];
		return ret;
	}
}