#pragma once
//以下为指令集定义
enum GMPS {
	ld = 0, //加载一个地址到特定的地址存储器 格式 ld 存储器id 地址
	load=1,//加载一个地址存储器指向的地址的数据到特定的数据寄存器 load 数据id 地址id
	set=2, //设置特定的一个数据存储器的值 格式 set 存储器id 值
	save=3, //将特定数据存储器内的数据存储到特定地址存储器存储的地址 save 地址id 数据id
	//以下是加减乘除
	add=4,//加法 add 目的dataid 来源dataid
	sub=5,//减法 sub 目的 来源
	mul=6,//乘法  mul 目的 来源
	div=7,//除法 div 目的 来源
	//
	mov=8,//移动一个数据存储器(dataer)到另一个数据存储器
	lmov=9,//移动 per到另一个per（地址寄存器)

	//以上为标准指令 以下为simd指令
	slld=10,//加载一个值到 simd地址开始标记中
	sld=11,//加载一个值到 simd数据开始标记中
	sllen=12,//加载一个值到 simd长度寄存器中
	sto=13,//正向 从地址到数据 加载
	sfr=14,//反向 从数据到地址 加载
	
	sadd=15, //以下为simd基础计算指令 此时simd数据寄存器为来源 地址寄存器为目的
	ssub=16,
	smul=17,
	div=18,

	random=19,//加速指令 随机数 random 数据id
};