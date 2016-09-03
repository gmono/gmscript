#pragma once
#include "SCValue.h"
class TransPort
{
	//传输辅助函数 isval指示是否采用值传递（复制一个新对象） 默认值传递
	static void Trans(SCValue *&to, SCValue *from, bool isval=true)
	{
		if (!isval)
		{
			//引用传递
			to = from;
			to->ptrsum++;//多了一个引用
		}
		else
		{
			SCValue *nptr = new SCValue(*from);//创建一个新的
			nptr->data = from->data;//复制数据
			nptr->ptrsum = 1;//复制的对象所以只有一个引用
			delete to;//删除原有对象（包括数据）
			to = nptr;//赋值 目标指针和nptr相同
			//赋值完成
		}
	}
};