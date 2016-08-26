#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string &getall(string path)
{
	ifstream in(path);
	istreambuf_iterator<char> begin(in);
	istreambuf_iterator<char> end;
	string *ret = new string(begin, end);
	return *ret;//只能返回堆变量的引用
}

//int main(int argc,char **argv)
//{
//	string code;
//	if (argc == 1)
//	{
//		//没有参数 开始输入代码
//		string line = "";
//		for (;;)
//		{
//			getline(cin, line);
//			if (line == "") break;//此行为空行
//			code.push_back('\n');
//			code.append(line);//加入代码集中
//
//		}
//	}
//	else
//	{
//		string path(argv[1]);
//		code = getall(path);
//	}
//	//以上为得到代码文本的过程
//	//这里code里已经是代码了
//
//
//}
#include "MultiVector.h"
//这是测试multivector的代码
int main()
{
	size_t *pars = new size_t[2]{ 4 * 1024,1024 * 1024 };//两层表 总大小为 4k*1m=4g
	MultiVector<int64_t> *a = new MultiVector<int64_t>(pars, 2);//创建表
	MultiVector<int64_t> &as = *a;
	as[0] = 1;
	as[1000000] = 800;

	cout << as[0] <<endl<< as[1000000] <<endl<< as[1000];
	cin.get();
}