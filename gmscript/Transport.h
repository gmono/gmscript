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
		}
		else
		{
			SCValue *nptr = new SCValue(*from);//创建一个新的
			nptr->data = from->data;//复制数据
			delete to;//删除原有对象（包括数据）
			to = nptr;//赋值 目标指针和nptr相同
			//赋值完成
		}
	}
};