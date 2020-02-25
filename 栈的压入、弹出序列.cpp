#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		int n = popV.size();
		stack<int> st;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			while (st.empty() || st.top() != popV[i])
			{
				st.push(pushV[j++]);
				if (j > n)
					return false;
			}
			st.pop();//一旦辅助栈的栈顶元素与当前该弹栈的元素相同，就弹出这个元素
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};


int main()
{
	Solution s;
	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2{ 4, 5, 3, 2, 1 };
	cout << s.IsPopOrder(v1, v2) << endl;


	return 0;
}