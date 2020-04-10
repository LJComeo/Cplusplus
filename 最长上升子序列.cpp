#include <iostream>
#define SIZE 1001

using namespace std;

int main()
{
	int i, j, n, top, temp;
	int stack[SIZE];
	top = 0;
	stack[0] = -1;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> temp;
			if (temp > stack[top])
			{
				stack[++top] = temp;
			}
			else
			{
				int low = 1, high = top;
				int mid;
				while (low <= high)
				{
					mid = (low + high) / 2;
					if (temp > stack[mid])
					{
						low = mid + 1;
					}
					else
					{
						high = mid - 1;
					}
				}
				stack[low] = temp;//ʹ�ö��ֲ����ҵ�stack�о���temp�����λ�ã�ֱ�Ӹ���
				//�����ҵķ���������ÿ�ε�λ�÷��õ����ֶ���������������У�������һ��λ�����������
				//��������ķ����Ϳ��Եõ������������
			}
		}

		cout << top << endl;
		top = 0;
	}
	return 0;
}