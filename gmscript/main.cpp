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
#include "MultiVector.h"
//���ǲ���multivector�Ĵ���
int main()
{
	size_t *pars = new size_t[2]{ 4 * 1024,1024 * 1024 };//����� �ܴ�СΪ 4k*1m=4g
	MultiVector<int64_t> *a = new MultiVector<int64_t>(pars, 2);//������
	MultiVector<int64_t> &as = *a;
	as[0] = 1;
	as[1000000] = 800;

	cout << as[0] <<endl<< as[1000000] <<endl<< as[1000];
	cin.get();
}