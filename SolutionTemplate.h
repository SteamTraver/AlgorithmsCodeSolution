#pragma once
#ifndef SOLUTIONTEMPLATE_H_
#define SOLUTIONTEMPLATE_H_

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::vector;

// related defination: -- ��ؽṹ�Ķ���
struct SNode
{
	int		data;
	SNode* next;
	SNode(int n) :data(n), next(NULL) {};
};

//* Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// auxilliary functions -- ��������

// �������һ������
void outputlist(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val;
		if (head->next)
			cout << "-->";
		head = head->next;
	}
}

class Solution {
public:
	// solu 1
	// �ȶ���������ִ���пղ���
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL || l2 == NULL)
			return (l1 == NULL) ? l2 : ((l2 == NULL) ? l1 : NULL);

		// ������������б���

		ListNode* result = new ListNode(0);
		ListNode* backup = result;

		//bool first = true;
		bool carry = false;
		while (carry||l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL && l2 == NULL && carry)
			{
				result->next = new ListNode(1);
				result = result->next;
				carry = false;
				break;
			}
			int tmp = (l1 != NULL && l2 != NULL) ? l1->val + l2->val :
				((l1 == NULL) ? l2->val : l1->val);

			if (tmp >= 9)
			{
				if (carry)
				{
					result->next = new ListNode(tmp - 9);
				}
				else
				{
					result->next = new ListNode(tmp - 10);
				}
				result = result->next;
				carry = true;
			}
			else
			{
				if (carry)
				{
					result->next = new ListNode(tmp + 1);
					carry = false;
				}
				else
				{
					result->next = new ListNode(tmp);
				}
				result = result->next;
			}
			(l1 != NULL && l2 != NULL) ? (l1 = l1->next, l2 = l2->next) :
				((l1 == NULL) ? l2 = l2->next : l1 = l1->next);
		}

		//while (carry || l1 != NULL || l2 != NULL)
		//{
		//	//���Ȳ鿴�Ƿ��λ
		//}
		return backup->next;
	}
	// solu 2
	int lengthOfLongestSubstring(string s) {

		// ���ַ����ʹ�СΪ1���ַ���
		if (s.empty() || s.size() == 1)
		{
			return (s.empty()) ? 0 : 1;
		}
		int n = s.length(), ans = 0;
		int* index = new int[128];

		for (int i = 0; i < 128; i++)
			index[i] = 0;

		for (int j = 0, i = 0; j < n; j++) {
			// i�ĸ��¹��̣�
			// ֻ�е�ǰ�ַ����ظ�����һ��Ҳ���ظ�ʱ��iһֱ��0��
			// �����ظ�������flagֵ;
			i = std::max(index[s[j]], i);

			// ans�ĸ��¹��̣���ǰ�ַ�һֱ���ظ�ʱ����i ʼ��Ϊ0��ans��ֵ�㶨����
			// ��������ظ���i��ֵ��Ϊ0������i��ֵ����� j,���ֵ������ s[j]��s[j-1]���ظ��ġ�
			// ���ֵ���֣����ʽ j-i+1��ֵ��1 ��Ȼ�޷��ı�ans��ֵ��
			ans = std::max(ans, j - i + 1);

			//��index�����У���ÿ���ַ���Ӧ������Ԫ�ص�ֵ�� ���ã�flag = ֵΪԭʼ�ַ�������+1��
			// �� index[s[j]] = flag��
			index[s[j]] = j + 1;
		}
		//��󷵻�ans
		return ans;

	}
	// solu 3

	// �������鶼������ģ��ѳ��Ƚ�С��������뵽���Ƚϴ�������С���������Ҫһ����ʱ�临�Ӷȣ�
	// ÿ�β��룬����¼�ϴεĲ���λ�ã������´β��롣
	// ��ȴ��һ�β��룬�������Ҫ�Ƚ�m�Σ��ҵ�����Ҫ����Ԫ�ص�Ԫ�ص�ǰһλ�á�Ȼ��ִ�в���,�Ҽ�¼λ�á�

	// ���ò���ķ�����������һ������/vector����¼ÿ��Ԫ��Ӧ������һ��vectorӦ�ó��ֵ�λ�á�����֮���ÿ��Ԫ��
	// ���±궼+1���±����������棬�����ñ�ķ�ʽ��
	// Ȼ���ڳ������Ѱ����λ���Ĺ����У�ʹ�õ��±�ֵ���顣�����ͱ����˲��������
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		if (nums1.empty() && !nums2.empty())
			return findMedian(nums2);
		else if (!nums1.empty() && nums2.empty())
			return findMedian(nums1);
		else 
			return findMedianTwoArrays(nums1, nums2);
	}
	inline double findMedianTwoArrays(const vector<int>& nums1, const vector<int>& nums2)
	{
		//int* temp_arr = new int[nums1.size() + nums2.size()];
		vector<int> save;
		for (auto it1 = nums1.begin(), it2 = nums2.begin(); (it1 != nums1.end() || it2 != nums2.end());)
		{
			if (it1 != nums1.end() && it2 != nums2.end())
			{
				(*it1 <= *it2) ? (save.push_back(*it1), it1++) : (save.push_back(*it2), it2++);
			}
			else
			{
				if (it1 == nums1.end())
				{
					while (it2!=nums2.end())
					{
						save.push_back(*it2);
						it2++;
					}
				}
				else
				{
					while (it1 != nums1.end())
					{
						save.push_back(*it1);
						it1++;
					}
				}
			}
		}
		return findMedian(save);
	}
	inline double findMedian(const vector<int>& v)
	{
		int s = v.size();
		if (s == 1)
		{
			return double(v[0]);
		}
		if (s % 2)//��Ϊ��
		{
			return double(v[s / 2]);
		}
		else
		{
			return (double(v[s / 2]) + double(v[s/2 /*-1*/ ])) / 2;//may wrong
		}
	}
	// solu 4
	string longestPalindrome(string s) {

	}
	// solu 5
	SNode* reverselist(SNode* phead)
	{
		if (phead == NULL)
			return NULL;
		if (phead->next == NULL)
			return phead;

		// ���ڽڵ�������Ϊ2������:
		SNode* l = phead;
		SNode* m = l->next;

		while (m)
		{
			SNode* r = NULL;
			if (m->next)
				r = m->next;
			//����ֵ
			m->next = l;
			l = m;
			m = r;
		}
		phead->next = NULL;
		return l;
	}

	// solu 6
	string convert(string s, int numRows) {
		// ��ʼ�����ж�
		// sΪ��
		size_t length = s.size();
		if (!length)
			return s;
		// numRows����length��ʱ�򣬷���ԭs������s��ʱ�򣬷���ʲô��
		if (numRows <= 1 || numRows > length)
			return s;

		unsigned int* temp_arr = new unsigned int [length];

		// may not need to fill temp_arr
		for (size_t i = 0; i < length; i++)
			temp_arr[i] = 0;

		// cost little space

		// �ó�����ֵ->�ֽⲽ��ֵ->���ղ���ֵȡ�����±�->�洢��Ŀ������->������ȡ

		// ����ֵ delta
		unsigned int delta = (numRows - 1) * 2;
		unsigned int index = 0;
		bool i_changed = false;
		// �ֽⲽ��ֵ -- ����ֵ�ֽ�֮��ֻ��������ʽ����֮�͵��ڲ���ֵ

		// process:
		// ��Ҫ����ѭ�������ѭ���� (i=0;i<numRows;i++)����ѭ����
		// �ڲ�ѭ���������ݣ��������temp_arr������λ��ʵʱ���¡�
		for (size_t i = 0; i < numRows; i++)
		{
			unsigned int arr[] = { delta - (i * 2),delta - (delta - (i * 2)) };

			unsigned int backup = i;

			(!i) ? temp_arr[index] = i : (i_changed)?temp_arr[++index] = i:0;
			unsigned int pick = 0;
			while (true)
			{
				unsigned int value = i + arr[pick];
				if (value >= length)
					break;
				else
				{
					if (!arr[pick])
					{
						pick = (pick) ? 0 : 1;
						continue;
					}
					else
					{
						i = value;
						index++;
						temp_arr[index] = i;
						(!pick) ? pick = 1 : pick = 0;
					}
				}

			}
			i = backup;
			i_changed = true;
		}



		// at last

		string result = "";
		for (size_t i = 0; i < length; i++)
		{
			result += s[temp_arr[i]];
		}
		return result;
	}

	void quicksort(int* a, int l, int r)
	{
		if (!a || l > r)
			return;
		int i = l, j = r, key = a[1];
		while (i<j)
		{
			for (; i<j&&a[j] >= key; j--)
				;
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			for (; i < j && a[i] >= key; i++)
				;
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = key;
		quicksort(a, l, i - 1);
		quicksort(a, i + 1, r);
	}

	// solu 20 -- ��Ч������

	bool isValid(string s) {

	}

	// solu 24 -- ���������ڵ�
	ListNode* swapPairs(ListNode* head) {
		//�пղ���
		if (!head)
			return NULL;
		//����ֻ��һ���ڵ�
		if (!head->next)
			return head;
		//����ڵ���ڵ���2

		ListNode* prev = head;
		ListNode* curr = head;
		ListNode* next = NULL;

		ListNode* lp = prev;
		ListNode* lr = prev;
		bool set = false;
		//���
		for (int i = 1;; i++)
		{
			if (!curr)
				break;
			if (!(i % 2))
			{
				(i == 2) ? head->next = NULL,head = curr:NULL;
				lr->next = curr;
				next = curr->next;
				curr->next = prev;
				curr = next;
				if(i==2)
					lp->next = next;
				else
				{
					lp = prev;
					lp->next = curr;
					lr = lr->next;
				}
				set = true;
			}
			if (set)
			{
				std::swap(lr, lp);
				prev = curr;
				set = false;
				continue;
			}
			if(curr)
				curr = curr->next;
			else
			{
				break;
			}
		}
		return head;
	}
	//solu 25 -- K��һ�鷭ת����

	ListNode* reverseKGroup(ListNode* head, int k)
	{
		//�пղ���
		if (!head)
			return NULL;
		//����ԭʼ����ֻ��һ���ڵ㡢����K = 0���򷵻�ԭʼ����
		if (!head->next || !k || k == 1)
			return head;
		//��K���ڽڵ����ʱ�����ؿ�
		int count = 0;
		ListNode* p = head;
		for (; p; p = p->next)
			count++;
		if (k > count)
			return head;
		//������ڵ���Ŀ���ڵ���2��KֵΪ[1,n](nΪ������)ʱ�����������²�����

		ListNode* l = head;
		ListNode* m = head;
		ListNode* r = NULL;
		ListNode* b = NULL;
		ListNode* res = NULL;
		ListNode* link = NULL;
		ListNode* prev = l;

		bool set = false;
		for (int i = 1;; ++i)
		{
			//��������K���ڵ�ʱ
			if (i >= k && !(i % k))
			{
				r = m->next;
				//ȡ��һ�α�������mΪ��ת֮�����ʼ�ڵ�
				if (i == k)
					res = m;
				else
				{
					prev->next = m;
					prev = m;
				}
				//��n�Σ�n����1

				//�����ƶ�m����Ҫ��ת�ĵڶ����ڵ���

				m = l->next;
				link = l;
				link->next = r;
				std::swap(link, prev);

				//����-ʵ�ֽڵ㷭ת
				while (true)
				{
					b = m->next;
					m->next = l;
					l = m;
					m = b;
					if (m == r)
					{
						set = true;
						break;
					}
				}
				l = m;
			}
			if (!m || !m->next)
				break;
			if (set)
			{
				set = false;
				continue;
			}
			m = m->next;
		}
		return res;

		//1��m�Ĳ���
		//2���˵�end������

	}
	//��תһ������

	ListNode* reverseList(ListNode* head)
	{
		if (!head)
			return NULL;
		if (!head->next)
			return head;

		ListNode* prev = head;
		ListNode* curr = prev->next;
		ListNode* next = NULL;

		while (curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			//if (j == NULL)
			//	break;
		}
		head->next = NULL;
		return prev;
	}

};

#endif // !SOLUTIONTEMPLATE_H_