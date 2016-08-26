#pragma once
//工具函数 数据复制 
//参数：目标数组 复制目标开始位置 来源数组 复制来源开始位置 复制长度
//数组也就是实现了[]运算符的对象
//返回：实际复制的数量
template<class DSTArrayType,class SRCArrayType>
uint64_t dmemcpy(DSTArrayType &dst, uint64_t dstart, SRCArrayType &src, uint64_t sstart, uint64_t len)
{
	uint64_t ret = 0; //复制的数量
	try
	{
		for (int i = 0; i < len; i++)
		{
			dst[dstart + i] = src[sstart + i];//复制
			ret++; //数量+1
		}
	}
	catch (...)
	{
		return ret;//当发生任何异常时,返回当前复制的数量
	}
	return ret;
}