#include <iostream>
using namespace std;

class Person
{
	int a;
public:
	Person()
	{
		cout << "���Ǹ���" << endl;
	}
	virtual void print()//ʹ��dynamic_cast��ʱ�򣬸���������麯������Ϊ������麯�����Ա�����̳��麯����ͨ����������֪���̳й�ϵ
	{
		cout << "����::print" << endl;
	}
};

class Son : public Person
{
	int b;
public:
	Son()
	{
		cout << "��������" << endl;
	}
};

int main()
{
	Person* p = new Son;
	Son *s = dynamic_cast<Son*>(p);
	return 0;
}