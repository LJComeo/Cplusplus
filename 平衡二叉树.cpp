#include <iostream>
using namespace std;

class TreeNode
{
public:
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode* m_parent;
	int m_data;
	int m_bf;

	TreeNode(const int& data) :
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr),
		m_data(data),
		m_bf(0)
	{}
};

class Solution {
public:
	int getHighth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		int left = getHighth(pRoot->m_left) + 1;
		int right = getHighth(pRoot->m_right) + 1;

		return left > right ? left : right;
	}

	bool IsBalanced_Solution(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;

		int left = getHighth(pRoot->m_left);
		int right = getHighth(pRoot->m_right);

		if (abs(left - right) > 1)//��֤ƽ�����ӵĲ�ֵ�ľ���ֵ������1
			return false;
		return IsBalanced_Solution(pRoot->m_left) && IsBalanced_Solution(pRoot->m_right);//��֤������������ƽ�������
	}
};

int main1()
{


	return 0;
}