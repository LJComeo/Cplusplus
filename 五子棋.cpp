#include <iostream>
#include <vector>
using namespace std;

bool JudgeIsFin(vector<string>& map)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			if (map[i][j] == '.')
				continue;
			int right = 1, down = 1, right_down = 1, left_down = 1;
			for (int k = 1; k < 5; k++)
			{
				if (j < 16 && map[i][j] == map[i][j + k])
					right++;
				if (i < 16 && map[i][j] == map[i + k][j])
					down++;
				if (i < 16 && j < 16 && map[i][j] == map[i + k][j + k])
					right_down++;
				if (i < 16 && j > 3 && map[i][j] == map[i + k][j - k])
					left_down++;
			}
			if (right == 5 || down == 5 || right_down == 5 || left_down == 5)
				return true;
		}
	}
	return false;
}

//int main1()
//{
//	vector<string> map(20);
//	while (cin >> map[0])
//	{
//		for (int i = 1; i < map.size(); i++)
//		{
//			cin >> map[i];
//		}
//		if (JudgeIsFin(map))
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}