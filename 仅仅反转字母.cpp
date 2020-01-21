#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string reverseOnlyLetters(string S)
	{
		int n = S.size();
		stack<char> tmp;
		string cur(S);
		for (int i = 0; i < n; i++)
		{
			if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
			{
				tmp.push(S[i]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if ((cur[i] >= 'A' && cur[i] <= 'Z') || (cur[i] >= 'a' && cur[i] <= 'z'))
			{
				cur[i] = tmp.top();
				tmp.pop();
			}
		}
		return cur;
	}
};


int main()
{
	Solution s;
	string S = "ab-cd";
	cout << s.reverseOnlyLetters(S) << endl;

	return 0;
}