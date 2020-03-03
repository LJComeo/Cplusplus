#include <iostream>
using namespace std;

/*
个位的2的个数，个位<2:high*1  =2:high*1+low+1 >2:(high+1)*1
十位的2的个数，十位<2:high*10  =2:high*10+low+1 >2:(high+1)*10
百位的2的个数，百位<2:high*100  =2:high*100+low+1 >2:(high+1)*100
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