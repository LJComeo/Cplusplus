#include <iostream>
using namespace std;
#if 0
int AddArgs(int n)
{
	int a = 1;
	n > 1 && (a = n + AddArgs(n - 1));
	return a;
}
int main()
{
	int tmp = AddArgs(10);
	cout << tmp << endl;

	return 0;
}
#endif

//方法2.这个方法主要依托的是静态成员变量的性质，他们的值不会随着函数的结束而消失，所以这样可以计算创建了多少个对象，利用这个功能我们今天的这个题也就可以完成了，具体代码的实现如下**
#if 1
class Add
{
public:
	Add()
	{
		s_m_a++;
		s_m_tmp += s_m_a;
	}
	static int s_m_a;
	static int s_m_tmp;
};


 int Add:: s_m_a;
 int Add::s_m_tmp;
int main()
{
	Add * a = new Add[10];
	cout << Add::s_m_tmp << endl;
	delete[] a;
	return 0;
}
#endif
