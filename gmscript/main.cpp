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
	return *ret;//ֻ�ܷ��ضѱ���������
}

//int main(int argc,char **argv)
//{
//	string code;
//	if (argc == 1)
//	{
//		//û�в��� ��ʼ�������
//		string line = "";
//		for (;;)
//		{
//			getline(cin, line);
//			if (line == "") break;//����Ϊ����
//			code.push_back('\n');
//			code.append(line);//������뼯��
//
//		}
//	}
//	else
//	{
//		string path(argv[1]);
//		code = getall(path);
//	}
//	//����Ϊ�õ������ı��Ĺ���
//	//����code���Ѿ��Ǵ�����
//
//
//}
#include "Stack.h"
//���ǲ���stack�Ĵ���
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