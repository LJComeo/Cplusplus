#include <iostream>
using namespace std;

#if 0

class Test
{
	int m_a;
	char m_c;
public:
	Test(int a = 0, char c = '\0') :
		m_a(a),
		m_c(c)
	{}

	Test(char c) :
		Test(0, c)
	{}
	void show()
	{
		cout << m_a << ' ' << m_c << endl;
	}
};
//委派构造：就是在一个构造函数中调用其他的构造函数
	//委派构造函数的作用就是能够减少程序员书写构造函数的时间

int main()
{
	Test t('a');
	t.show();

	return 0;
}
#endif

#if 0
class Test
{
	int m_a;
public:
	Test() = default;//函数后面加上default，就是显式缺省函数;让编译器生成默认的函数
	Test(const Test &a) = delete;//删除默认函数，加上delete之后，编译器不会生成默认的函数
	Test & operator = (const Test &a) = delete;

	Test(int a) :
		m_a(a)
	{}
};

int main()
{
	Test t1;
}
#endif

#if 1
#include <vector>
//移动构造函数
/*
移动构造函数：参数是右值引用;
右值分为：纯右值与将亡右值->纯右值就是单纯的常量，将亡右值就是临时变量等；
判断右值的方法：不能取地址的就是右值
但是由于系统提供的移动构造函数所执行的是一个浅拷贝，即拷贝结束之后传进来的对象就没有了，但是我们还要用
所以我们就通常自己实现这个移动构造函数。
move函数可以将一个值，强制的转换成右值
forward函数将一个值转化成左值或者右值(完美转发就是使用了forward的这个特性)
为什么要使用右值：使用右值就是因为要与移动语义结合，减少无必要的资源开支来提高代码效率
移动语义就是将一个对象中的资源移动到另外一个对象中
完美转发：
通用引用：使用模板
template <tyoename T>
T func(T &&t)
{}
里面使用了引用折叠：&& + && = && 、&& + & = &
完美转发就是完美的将参数不变的传递给函数模板中调用的另外一个参数，参数类型不能发生变化
*/
class String
{
	char *m_str;
public:
	static int s_m_Ccount;
	static int s_m_Mcount;

	String(char *str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}

	String(const String & s) :
		m_str(new char[strlen(s.m_str) + 1])
	{
		s_m_Ccount++;
		strcpy(m_str, s.m_str);
	}


	String(String && s) :
		m_str(s.m_str)
	{
		s_m_Mcount++;
		s.m_str = nullptr;
	}

	String & operator = (const String & s)
	{
		if (this != &s)
		{
			char *ptmp = new char[strlen(s.m_str) + 1];
			strcpy(ptmp, s.m_str);
			delete[]m_str;
			m_str = ptmp;
		}
		return *this;
	}

	~String()
	{
		if (m_str)
		{
			delete[]m_str;
		}
	}

	void show()
	{
		cout << m_str << endl;
	}
};

int String::s_m_Ccount = 0;
int String::s_m_Mcount = 0;

String getString(char *str)
{
	return String(str);
}

int main()
{
	vector<String> vs;
	vs.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		vs.push_back(String("cai"));
	}

	cout << String::s_m_Ccount << endl;
	cout << String::s_m_Mcount << endl;
	return 0;
}
#endif

#if 1
//lambda表达式
#include <string>
#include <algorithm>

struct Goods
{
	string _name;
	double _price;
};

struct compare
{
	bool operator()(Goods & gl, Goods & gr)
	{
		return gl._price <= gr._price;
	}
};

int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "香蕉", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), compare());
	return 0;
}

int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "香蕉", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods & gl, const Goods & gr)->bool
													{
														return gl._price <= gr._price;

													}
	);
	return 0;
}
/*
上面这个函数里面[]以及后面的东西就是一个lambda表达式，lambda是以[]开始的表达式
lambda表达式出现的原因就是：我们现在经常会使用仿函数，但是这种重新定义类，然后实现()重载的方法还是过于麻烦
为了解决这种问题，C++11引入了lambda表达式进行优化。
lambda表达式的用法：
1.[]中存放的是捕捉列表，捕捉列表只能上一层栈的变量，全局变量不能捕捉，但是可以使用
2.()中的参数列表，一般可以省略，但是有mutable的时候就不能省略
3.mutable：lambda函数默认是const函数，使用mutable可以解除常量性
4.->返回值类型
5.{函数体}
捕捉列表的说明：
[var]:值传递捕捉变量
[=]:值传递捕捉父作用域的所有变量
[&var]:引用传递捕捉变量
[&]:引用传递捕捉父作用域的所有变量
[this]:值传递捕捉this指针
也可以传递多个：[=,&var]

lambda表达式底层是仿函数，可以赋值给函数指针
*/
#endif

#if 1
//线程库
//仿照Linux线程学习
#endif

#if 1

int main()
{
	int a = 0;
	char c = 'a';

	decltype (a + c) d;

	return 0;
}



#endif
