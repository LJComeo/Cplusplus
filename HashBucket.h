#pragma once
#include <vector>
using namespace std;
/*哈希表的模拟实现，比HashMap的实现中多了迭代器类的实现，以及各个函数的修改*/
namespace ljc{

	template<class T>
	class HashBucketNode//节点类
	{
		T m_val;
		HashBucketNode<T> * m_next;

		HashBucketNode(const T & val = T()) :
			m_val(val),
			m_next(nullptr)
		{}

		template<class K, class V, class KeyofValue, class HF>
		//KeyofValue：得到value对应的key值；
		friend class HashBucket;
	};

	class dealInt
	{
	public:
		int operator()(int n)//仿函数(小括号重载)
		{
			return n;
		}
	};

	template<class K, class V, class KeyofValue, class HF = dealInt>
	class HashBucket
	{
		vector<HashBucketNode<V> *> m_data;
		size_t m_size;

		static long long s_m_primeTable[30];
		int m_primePos;
	public:
		HashBucket(size_t capacity = s_m_primeTable[0]) :
			m_data(capacity, nullptr),
			m_size(0),
			m_primePos(0)
		{}

		class iterator//内部类(迭代器类)
		{
		public:
			HashBucket<K, V, KeyofValue, HF> * m_hb;
			HashBucketNode<V> * m_node;

			iterator(HashBucketNode<V> * node = nullptr,
				HashBucket<K, V, KeyofValue, HF> * hbpos = nullptr) :
				m_node(node),
				m_hb(hbpos)
			{}

			iterator(const iterator & it) :
				m_node(it.m_node),
				m_hb(it.m_hb)
			{}

			V& operator*()//指针可以做左值，所以要取&
			{
				return m_node->m_val;//直接返回结点的val
			}

			V* operator->()//返回一个指针，将操作->的对象变成指针
			{
				return &m_node->m_val;//直接返回val的地址
			}

			iterator operator++()//前置++
			{
				int val = m_node->m_val;//先保存现在的val，方便后面利用keyofvalue得到下一个bucketno的值
				m_node = m_node->m_next;//提前将node改变就是因为要防止是最后一个桶，++无效的情况，这样的话即使下面+1之后不进入循环，也能保证node是已经改变过的，也就是提前先让node走一下
				if (!m_node)//如果现在的结点不存在进入；不存在就直接返回了，但是此时的结点也是已经加过的
				{
					int bucketno = m_hb->hashFunc(KeyofValue()(val)) + 1;//首先得到下一个bucketno的值
					for (; bucketno < m_hb->capacity(); bucketno++)//通过遍历找到下一个非空的桶
					{
						if (m_hb->m_data[bucketno])
						{
							m_node = m_hb->m_data[bucketno];//找到之后，++后的值就是现在这个桶的头结点
							break;
						}
					}
				}

				return *this;//由于是前置++，所以返回的是++之后的值
			}

			iterator operator++(int)//后置++
			{
				iterator<K, V, KeyofValue, HF> tmp = *this;
				++(*this);
				return tmp;
			}

			iterator operator--()//前置--
			{
				int val = m_node->m_val;
				int tmp = m_hb->hashFunc(KeyofValue()(val));
				for (m_node = m_hb->m_data[tmp]; m_node->m_next->m_val != val; m_node = m_node->m_next);
				if (!m_node)
				{
					int bucketno = tmp - 1;
					for (; bucketno >= 0; bucketno--)
					{
						if (m_hb->m_data[bucketno])
						{
							for (m_node = m_hb->m_data[bucketno]; m_node->m_next; m_node = m_node->m_next);
							break;
						}
					}
				}

				return *this;
			}

			bool operator==(const iterator & data) const
			{
				return m_node == data.m_node && m_hb == data.m_hb;
			}

			bool operator!=(const iterator & data) const
			{
				return m_node != data.m_node || m_hb != data.m_hb;
			}
		};


	private:
		int hashFunc(const K & key)
		{
			HF func;
			return func(key) % capacity();
		}

		void checkCapacity()
		{
			if (m_size == capacity())
			{
				int mcapa = capacity();
				vector<HashBucketNode<V> *> tmp(s_m_primeTable[++m_primePos], nullptr);
				m_data.swap(tmp);
				m_size = 0;

				int i;
				HashBucketNode<V> * cur;
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
		iterator begin()
		{
			int bucketno = 0;
			for (; bucketno < capacity(); bucketno++)
			{
				if (m_data[bucketno])
				{
					return iterator(m_data[bucketno], this);
				}
			}

			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}


		iterator insert(const V & val)
		{
			checkCapacity();

			int hashnum = hashFunc(KeyofValue()(val));
			HashBucketNode<V> * tmp;

			if (m_data[hashnum])
			{
				for (tmp = m_data[hashnum]; tmp; tmp = tmp->m_next)
				{
					if (tmp->m_val == val)
					{
						return end();
					}
				}
			}

			tmp = new HashBucketNode<V>(val);

			tmp->m_next = m_data[hashnum];
			m_data[hashnum] = tmp;

			m_size++;
			return iterator(m_data[hashnum], this);
		}

		iterator erase(const V & val)
		{
			int hashnum = hashFunc(KeyofValue()(val));
			HashBucketNode<V> * tmp;

			if (!m_data[hashnum])
			{
				return end();
			}

			if (m_data[hashnum]->m_val == val)
			{
				iterator res(m_data[hashnum], this);
				++res;

				tmp = m_data[hashnum];
				m_data[hashnum] = tmp->m_next;
				delete tmp;

				m_size--;
				return res;
			}
			else
			{
				for (tmp = m_data[hashnum]; tmp->m_next; tmp = tmp->m_next)
				{
					if (tmp->m_next->m_val == val)
					{
						iterator res(tmp->m_next, this);
						++res;

						HashBucketNode<V> * cur;
						cur = tmp->m_next;
						tmp->m_next = cur->m_next;
						delete cur;

						m_size--;
						return res;
					}
				}
				return end();
			}
		}

		iterator find(const V & val)
		{
			int hashnum = hashFunc(KeyofValue()(val));

			HashBucketNode<V> * cur;
			for (cur = m_data[hashnum]; cur; cur = cur->m_next)
			{
				if (cur->m_val == val)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		void clear()
		{
			HashBucketNode<V> * tmp;
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

		size_t capacity()
		{
			return s_m_primeTable[m_primePos];
		}

		/*1、Count 判断某一个Key值是否在哈希表里
		2、BucketCount 返回桶的个数
		3、BucketSize 返回某个桶中的元素个数*/
	};

	template<class K, class V, class KeyofValue, class HF>
	long long HashBucket<K, V, KeyofValue, HF>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u
	};

};