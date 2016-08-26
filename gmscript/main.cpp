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
#include "Stack.h"
//这是测试stack的代码
int main()
{
	Stack stack(4);
	stack.push<int>(5);
	stack.push<int>(40);

	int a = stack.pop<int>();
	int b = stack.pop<int>();
	stack.push<int>(5);
	stack.push<int>(40);

	int c=stack.at<int>(1);
	int d = stack.at<int>(0);
	cout << a << endl << b << endl<<c<<endl<<d<<endl;
	cin.get();
}