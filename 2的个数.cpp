#include <iostream>
using namespace std;

/*
��λ��2�ĸ�������λ<2:high*1  =2:high*1+low+1 >2:(high+1)*1
ʮλ��2�ĸ�����ʮλ<2:high*10  =2:high*10+low+1 >2:(high+1)*10
��λ��2�ĸ�������λ<2:high*100  =2:high*100+low+1 >2:(high+1)*100
*/

class Count2 {
public:
	int countNumberOf2s(int n)
	{
		int count = 0;
		int high = 0, w;
		int low = 0;
		int i = -1;
		do
		{
			i++;
			int m = pow(10, i);
			high = n / m;
			w = high % 10;
			high /= 10;
			if (i == 0)
				low = 0;
			else
				low = n % m;
			if (w < 2)
				count += high*pow(10, i);
			else if (w == 2)
				count += high*pow(10, i) + low + 1;
			else
				count += (high + 1)*pow(10, i);
		} while (high != 0);
		return count;
	}
};

int main()
{



	return 0;
}