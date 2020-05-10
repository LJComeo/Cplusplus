#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


unordered_map<string, int> msi;

void set(int m, int n)
{
	msi.insert(pair<string,int>(to_string(m),n));
}
int get(int n)
{
	int ret = -1;
	ret = msi[to_string(n)];//�ҵ����ֵ
	if (ret == 0)
	{
		msi.erase(to_string(n));
		return -1;
	}
	//����״̬
	msi.erase(to_string(n));
	msi.insert(pair<string, int>(to_string(ret), n));
	return ret;
}


int main1()
{
	int N, K;
	while (cin >> N >> K)
	{
		int x, m, n, y;
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			if (x == 1)
			{
				cin >> m >> n;//��Ҫset
				set(m, n);
				if (msi.size() > K)
					msi.erase(msi.begin());
				
			}
			else
			{
				cin >> y;//��Ҫget
				cout << get(y) << endl;
			}
		}
	}

	return 0;
}