#include <iostream>
using namespace std;

class Person
{
	int a;
public:
	Person()
	{
		cout << "我是父类" << endl;
	}
	virtual void print()//使用dynamic_cast的时候，父类必须有虚函数，因为父类的虚函数可以被子类继承虚函数表，通过这个虚表来知道继承关系
	{
		cout << "父类::print" << endl;
	}
};

class Son : public Person
{
	int b;
public:
	Son()
	{
		cout << "我是子类" << endl;
	}
};

int main()
{
	Person* p = new Son;
	Son *s = dynamic_cast<Son*>(p);
	return 0;
}