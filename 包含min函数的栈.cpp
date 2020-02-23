#include <iostream>
#include <stack>
using namespace std;

/*
�������ջ�е�Ԫ���п��ܻᱻ������Ҳ�����Ǹ���С�������п��ܻ�ı䣬�������ǻ�Ҫ�����С���δ�С������
��˱�����ʹ�õľ���һ��sminջ����ţ�ѹ���ʱ�����ѹ������ִ�ʱsminջ�ǿյģ����ߴ�ʱ��������ֱ�smin��ջ��Ԫ��С
�ͽ��������ֱ�ѹ������ջ�У������Ļ�����ֻ����stջ��pop��ʱ����Ϊ��ʱ��sminջ��ջ���ǵ�ǰ����СԪ��
�������stջ��ջ��Ԫ����smin��ջ��Ԫ����ȵ�ʱ�򣬴�ʱ���pop�������ͱ��뽫����ջ��ջ��Ԫ�ض�pop��ȥ����ʱ����СԪ��Ҳ�ͷ����˱仯��
�����minԪ�أ�ֱ�ӷ���sminջ��ջ��Ԫ�ؾ����ˡ�
*/
class Solution {
	stack<int> st;
	stack<int> smin;
public:
	void push(int value) {
		st.push(value);
		if (smin.empty())
		{
			smin.push(value);
		}
		if (smin.top() > value)
		{
			smin.push(value);
		}
	}
	void pop() {
		if (st.top() == smin.top())
			smin.pop();
		st.pop();
	}
	int top() {
		return st.top();
	}
	int min() {
		return smin.top();

	}
};

int main()
{




	return 0;
}