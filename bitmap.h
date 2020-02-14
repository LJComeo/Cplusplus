#pragma once
#include <vector>
using namespace std;

class bitset
{
public:
	bitset(size_t bitCount)
		: _bit((bitCount >> 5) + 1), _bitCount(bitCount)//右移5位相当于除以32，每个int可以存32个数据
	{}
	// 将which比特位置1
	void set(size_t which)
	{
		if (which > _bitCount)
		{
			return;
		}

		size_t index = which / 32;
		size_t bits = which % 32;

		_bit[index] |= 1u << bits;
	}
		// 将which比特位置0
	void reset(size_t which)
	{
		if (which > _bitCount)
		{
			return;
		}

		size_t index = which / 32;
		size_t bits = which % 32;

		_bit[index] &= ~(1u << bits);
	}
		// 检测位图中which是否为1
	bool test(size_t which)
	{
		if (which > _bitCount)
		{
			return;
		}

		size_t index = which / 32;
		size_t bits = which % 32;

		return _bit[index] >> bits & 1;
	}
	size_t size()const
	{
		return _bitCount;
	}

private:
	vector<int> _bit;
	size_t _bitCount;//总位数的大小
};
