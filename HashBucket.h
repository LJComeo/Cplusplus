#pragma once
#include <vector>
using namespace std;
/*��ϣ���ģ��ʵ�֣���HashMap��ʵ���ж��˵��������ʵ�֣��Լ������������޸�*/
namespace ljc{

	template<class T>
	class HashBucketNode//�ڵ���
	{
		T m_val;
		HashBucketNode<T> * m_next;

		HashBucketNode(const T & val = T()) :
			m_val(val),
			m_next(nullptr)
		{}

		template<class K, class V, class KeyofValue, class HF>
		//KeyofValue���õ�value��Ӧ��keyֵ��
		friend class HashBucket;
	};

	class dealInt
	{
	public:
		int operator()(int n)//�º���(С��������)
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

		class iterator//�ڲ���(��������)
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

			V& operator*()//ָ���������ֵ������Ҫȡ&
			{
				return m_node->m_val;//ֱ�ӷ��ؽ���val
			}

			V* operator->()//����һ��ָ�룬������->�Ķ�����ָ��
			{
				return &m_node->m_val;//ֱ�ӷ���val�ĵ�ַ
			}

			iterator operator++()//ǰ��++
			{
				int val = m_node->m_val;//�ȱ������ڵ�val�������������keyofvalue�õ���һ��bucketno��ֵ
				m_node = m_node->m_next;//��ǰ��node�ı������ΪҪ��ֹ�����һ��Ͱ��++��Ч������������Ļ���ʹ����+1֮�󲻽���ѭ����Ҳ�ܱ�֤node���Ѿ��ı���ģ�Ҳ������ǰ����node��һ��
				if (!m_node)//������ڵĽ�㲻���ڽ��룻�����ھ�ֱ�ӷ����ˣ����Ǵ�ʱ�Ľ��Ҳ���Ѿ��ӹ���
				{
					int bucketno = m_hb->hashFunc(KeyofValue()(val)) + 1;//���ȵõ���һ��bucketno��ֵ
					for (; bucketno < m_hb->capacity(); bucketno++)//ͨ�������ҵ���һ���ǿյ�Ͱ
					{
						if (m_hb->m_data[bucketno])
						{
							m_node = m_hb->m_data[bucketno];//�ҵ�֮��++���ֵ�����������Ͱ��ͷ���
							break;
						}
					}
				}

				return *this;//������ǰ��++�����Է��ص���++֮���ֵ
			}

			iterator operator++(int)//����++
			{
				iterator<K, V, KeyofValue, HF> tmp = *this;
				++(*this);
				return tmp;
			}

			iterator operator--()//ǰ��--
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

		/*1��Count �ж�ĳһ��Keyֵ�Ƿ��ڹ�ϣ����
		2��BucketCount ����Ͱ�ĸ���
		3��BucketSize ����ĳ��Ͱ�е�Ԫ�ظ���*/
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