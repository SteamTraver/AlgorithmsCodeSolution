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

// related defination: -- 相关结构的定义
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

// auxilliary functions -- 辅助函数

// 遍历输出一个链表：
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

// test examples 

//SNode s0 = SNode(0);
//SNode s1 = SNode(1);
//SNode s2 = SNode(2);
//SNode s3 = SNode(3);
//SNode s4 = SNode(4);
//SNode s5 = SNode(5);
//SNode s6 = SNode(6);
//SNode s7 = SNode(7);
//
//s0.next = &s1;
//s1.next = &s2;
//s2.next = &s3;
//s3.next = &s4;
//s4.next = &s5;
//s5.next = &s6;
//s6.next = &s7;
//

////////////////////////////////////////////////////////////////

class Solution {
public:
	// solu 1
	// 先对两个链表执行判空操作
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL || l2 == NULL)
			return (l1 == NULL) ? l2 : ((l2 == NULL) ? l1 : NULL);

		// 对两个链表进行遍历

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
		//	//首先查看是否进位
		//}
		return backup->next;
	}
	// solu 2
	int lengthOfLongestSubstring(string s) {

		// 空字符串和大小为1的字符串
		if (s.empty() || s.size() == 1)
		{
			return (s.empty()) ? 0 : 1;
		}
		int n = s.length(), ans = 0;
		int* index = new int[128];

		for (int i = 0; i < 128; i++)
			index[i] = 0;

		for (int j = 0, i = 0; j < n; j++) {
			// i的更新过程：
			// 只有当前字符不重复且上一次也不重复时，i一直是0。
			// 假如重复，返回flag值;
			i = std::max(index[s[j]], i);

			// ans的更新过程：当前字符一直不重复时，，i 始终为0，ans的值恒定增长
			// 假如出现重复：i的值不为0，但是i的值最大是 j,最大值条件是 s[j]和s[j-1]是重复的。
			// 最大值出现，表达式 j-i+1的值是1 仍然无法改变ans的值。
			ans = std::max(ans, j - i + 1);

			//在index数组中，对每个字符对应的数组元素的值， 设置：flag = 值为原始字符串索引+1；
			// 即 index[s[j]] = flag；
			index[s[j]] = j + 1;
		}
		//最后返回ans
		return ans;

	}
	// solu 3

	// 两个数组都是有序的，把长度较小的数组插入到长度较大的数组中。（插入需要一定的时间复杂度）
	// 每次插入，都记录上次的插入位置，便于下次插入。
	// 除却第一次插入，最长可能需要比较m次，找到大于要插入元素的元素的前一位置。然后执行插入,且记录位置。

	// 不用插入的方法。另外用一个数组/vector，记录每个元素应该在另一个vector应该出现的位置。在其之后的每个元素
	// 的下标都+1，下标可能用数组存，可能用别的方式。
	// 然后在程序遍历寻找中位数的过程中，使用到下标值数组。这样就避免了插入操作。
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
		if (s % 2)//奇为真
		{
			return double(v[s / 2]);
		}
		else
		{
			return (double(v[s / 2]) + double(v[s / 2 - 1])) / 2;
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

		// 对于节点数至少为2的链表:
		SNode* l = phead;
		SNode* m = l->next;

		while (m)
		{
			SNode* r = NULL;
			if (m->next)
				r = m->next;
			//逆向赋值
			m->next = l;
			l = m;
			m = r;
		}
		phead->next = NULL;
		return l;
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
};

#endif // !SOLUTIONTEMPLATE_H_