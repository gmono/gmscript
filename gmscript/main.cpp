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

int main(int argc,char **argv)
{
	string code;
	if (argc == 1)
	{
		//û�в��� ��ʼ�������
		string line = "";
		for (;;)
		{
			getline(cin, line);
			if (line == "") break;//����Ϊ����
			code.push_back('\n');
			code.append(line);//������뼯��

		}
	}
	else
	{
		string path(argv[1]);
		code = getall(path);
	}
	//����Ϊ�õ������ı��Ĺ���
	//����code���Ѿ��Ǵ�����


}