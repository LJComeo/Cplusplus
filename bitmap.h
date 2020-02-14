#pragma once
#include <vector>
using namespace std;

class bitset
{
public:
	bitset(size_t bitCount)
		: _bit((bitCount >> 5) + 1), _bitCount(bitCount)//����5λ�൱�ڳ���32��ÿ��int���Դ�32������
	{}
	// ��which����λ��1
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
		// ��which����λ��0
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
		// ���λͼ��which�Ƿ�Ϊ1
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
	size_t _bitCount;//��λ���Ĵ�С
};
