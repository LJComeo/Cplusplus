#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	string s;
	int i = 0;
	void Srtial(TreeNode *root)
	{
		if (root == NULL)
		{
			s += "#!";
			return;
		}
		s += to_string(root->val);
		s += "!";
		Srtial(root->left);
		Srtial(root->right);
	}
	char* Serialize(TreeNode *root)
	{
		Srtial(root);
		return (char *)s.data();
	}
	TreeNode* Deserialize(char *str)
	{
		s = str;
		return Deserial();
	}
	TreeNode* Deserial()
	{
		if (s.size() == 0)
			return NULL;
		if (s[i] == '!') {
			i++;
			if (i >= s.size())
				return NULL;
		}
		if (s[i] == '#'){
			i++;
			return NULL;
		}
		int num = 0;
		while (s[i] >= '0' && s[i] <= '9'){//这个数字不一定只是个位，所以需要转化一下
			num = num * 10 + s[i++] - '0';
		}
		TreeNode *root = new TreeNode(num);
		root->left = Deserial();
		root->right = Deserial();
		return root;
	}
};

int main()
{



	return 0;
}