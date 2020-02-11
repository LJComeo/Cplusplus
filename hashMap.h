/*哈希开散列实现*/
#pragma
#include <iostream>
#include <vector>
using namespace std;

namespace ljc
{
template<class T>
class HashBucketNode//桶结点类
{
	T m_val;
	HashBucketNode<T> * m_next;

	HashBucketNode(const T & val = T()) :
		m_val(val),
		m_next(nullptr)
	{}

	template<class T, class SW = dealInt>
	friend class HashSet

};

class dealInt
{
public:
	int operator()(int n)
	{
		return n;
	}
};

template<class T,class SW = dealInt>
class HashSet
{
	vector<HashBucketNode<T> *> m_data;
	//m_data中保存的是结点，所以我们用m_data[hashnum]取出来的是结点
	size_t m_size;

	static long long s_m_primeTable[30];//素数表
	int m_primePos;
public:
	HashSet(size_t capacity = s_m_primeTable[0]) :
		m_data(capacity, nullptr),
		m_size(0),
		m_primePos(0)
	{}

private:
	int hashFunc(const T & key)
	{
		SW func;
		return func(key) % capacity();
	}

	size_t capacity()
	{
		return s_m_primeTable[m_primePos];
	}
	void  checkCapacity()
	{
		if (m_size == capacity())
		{
			int mcapa = capacity();
			vector<HashBucketNode<T> *> tmp(s_m_primeTable[++m_primePos], nullptr);
			m_data.swap(tmp);
			m_size = 0;

			int i;
			HashBucketNode<T> * cur;
			for (i = 0; i < mcapa; i++)
			{
				for (cur = tmp[i]; cur; cur = cur->m_next)
				{
					insert(cur->m_val);
				}
			}
		}
	}
public:
	bool insert(const T & val)
	{
		checkCapacity();

		int hashnum = hashFunc(val);
		HashBucketNode<T> * tmp;

		if (m_data[hashnum])
		{
			for (tmp = m_data[hashnum]; tmp; tmp = tmp->m_next)
			{
				if (tmp->m_val = val)
				{
					return false;
				}
			}
		}

		tmp = new HashBucketNode<T>(val);

		tmp->m_next = m_data[hashnum];//让tmp的next等于（旧头或者空）
		m_data[hashnum] = tmp;//让现在的头等于tmp

		m_size++;
		return true;
	}

	bool erase(const T & val)
	{
		int hashnum = hashFunc(val);//先将这个位置找到
		HashBucketNode<T> * tmp;

		if (!m_data[hashnum])
		{
			return false;
		}

		if (m_data[hashnum]->m_val == val)//头删
		{
			tmp = m_data[hashnum];
			m_data[hashnum] = tmp->m_next;
			delete tmp;

			m_size--;
			return true;
		}
		else//后删
		{
			for (tmp = m_data[hashnum]; tmp->m_next; tmp = tmp->m_next)//遍历这个桶
			{
				if (tmp->m_next->m_val == val)
				{
					HashBucketNode<T> * cur;
					cur = tmp->m_next;
					tmp->m_next = cur->m_next;
					delete cur;

					m_size--;
					return true;
				}
			}
			return false;
		}
	}

	HashBucketNode<T> * find(const T & val)
	{
		int hashnum = hashFunc(val);

		HashBucketNode<T> * cur;

		for (cur = m_data[hashnum]; cur; cur = cur->m_next)
		{
			if (cur->m_val == val)
			{
				return cur;
			}
		}
		return nullptr;
	}

	void clear()
	{
		HashBucketNode<T> * tmp;
		for (auto & head : m_data)
		{
			while (head)
			{
				tmp = head;
				head = head->m_next;
				delete tmp;
			}
		}
		m_size = 0;
	}


};
template<class T, class SW>
long long HashSet<T, SW>::s_m_primeTable[30] = 
{
	11, 23, 47, 89, 179,
	353, 709, 1409, 2819, 5639,
	11273, 22531, 45061, 90121, 180233,
	360457, 720899, 1441807, 2883593, 5767169,
	11534351, 23068673, 46137359, 92274737, 184549429,
	369098771, 738197549, 1476395029, 2952790016u, 4294967291u
};
};