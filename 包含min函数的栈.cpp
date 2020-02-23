#include <iostream>
#include <stack>
using namespace std;

/*
由于这个栈中的元素有可能会被弹出，也就是那个较小的数字有可能会改变，所以我们还要保存次小，次次小等数字
因此本题中使用的就是一个smin栈来存放，压入的时候如果压入的数字此时smin栈是空的，或者此时的这个数字比smin的栈顶元素小
就将这个数组分别压入两个栈中，如果大的话，就只进入st栈，pop的时候，因为此时的smin栈的栈顶是当前的最小元素
所以如果st栈的栈顶元素与smin的栈顶元素相等的时候，此时如果pop操作，就必须将两个栈的栈顶元素都pop出去，此时的最小元素也就发生了变化。
最后求min元素，直接返回smin栈的栈顶元素就行了。
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