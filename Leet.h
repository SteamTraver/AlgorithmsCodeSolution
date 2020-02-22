#pragma once
#ifndef LEET_H_
#define LEET_H_

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<array>

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::deque;
using std::array;
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

// 二叉搜索树的定义：

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class LeetSolution {
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
		size_t n = s.length(), ans = 0;
		size_t* index = new size_t[128];

		for (int i = 0; i < 128; i++)
			index[i] = 0;

		for (size_t j = 0, i = 0; j < n; j++) {
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

	// solu 6
	string convert(string s, int numRows) {
		// 初始条件判断
		// s为空
		size_t length = s.size();
		if (!length)
			return s;
		// numRows等于length的时候，返回原s，大于s的时候，返回什么？
		if (numRows <= 1 || numRows > length)
			return s;

		unsigned int* temp_arr = new unsigned int [length];

		// may not need to fill temp_arr
		for (size_t i = 0; i < length; i++)
			temp_arr[i] = 0;

		// cost little space

		// 得出步进值->分解步进值->按照步进值取数组下标->存储到目标数组->遍历读取

		// 步进值 delta
		unsigned int delta = (numRows - 1) * 2;
		unsigned int index = 0;
		bool i_changed = false;
		// 分解步进值 -- 步进值分解之后只有两种形式，其之和等于步进值

		// process:
		// 需要两个循环，外层循环对 (i=0;i<numRows;i++)进行循环；
		// 内层循环填入数据，被填入的temp_arr的索引位置实时更新。
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

	// solu 20 -- 有效的括号

	bool isValid(string s) {
		
		size_t size = s.size();
		if (!size)
			return true;
		//直接排除长度为奇数的括号字符串
		if (size % 2 == 1)
			return false;
		//长度为2也快速返回

		bool valid = true;

		
		//类栈数组 -- 初始化
		char* char_arr = new char[size+1];
		for (int i = 0; i < size; i++)
			char_arr[i] = '\0';

		// 按照原字符串进行配置
		for (int t = 0,i = 0,j = i + 1; t < size; t++)
		{
			if (char_arr[i] == '\0')
				char_arr[i] = s[t];
			else
			{
				if (char_arr[i] == '(' && s[t] == ')' ||
					char_arr[i] == '[' && s[t] == ']' ||
					char_arr[i] == '{' && s[t] == '}')
				{
					char_arr[i] = '\0';
					(i > 0) ? (j = i, i--) : 0;
				}
				else
				{
					char_arr[j] = s[t];
					i = j;
					j++;
				}
			}
		}
		// 最后的返回结果
		for (int i = 0; i < size; i++)
		{
			if (char_arr[i] != '\0')
			{
				valid = false;
				break;
			}
		}

		return valid;
	}

	// solu 24 -- 两两交换节点
	ListNode* swapPairs(ListNode* head) {
		//判空操作
		if (!head)
			return NULL;
		//链表只有一个节点
		if (!head->next)
			return head;
		//链表节点大于等于2

		ListNode* prev = head;
		ListNode* curr = head;
		ListNode* next = NULL;

		ListNode* lp = prev;
		ListNode* lr = prev;
		bool set = false;
		//结果
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
	//solu 25 -- K个一组翻转链表

	ListNode* reverseKGroup(ListNode* head, int k)
	{
		//判空操作
		if (!head)
			return NULL;
		//假设原始链表只有一个节点、或者K = 0，则返回原始链表。
		if (!head->next || !k || k == 1)
			return head;
		//当K大于节点个数时：返回空
		int count = 0;
		ListNode* p = head;
		for (; p; p = p->next)
			count++;
		if (k > count)
			return head;
		//当链表节点数目大于等于2、K值为[1,n](n为链表长度)时。即进入以下操作。

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
			//遍历到第K个节点时
			if (i >= k && !(i % k))
			{
				r = m->next;
				//取第一次遍历到的m为翻转之后的起始节点
				if (i == k)
					res = m;
				else
				{
					prev->next = m;
					prev = m;
				}
				//第n次，n大于1

				//重新移动m到需要翻转的第二个节点上

				m = l->next;
				link = l;
				link->next = r;
				std::swap(link, prev);

				//遍历-实现节点翻转
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

		//1、m的步进
		//2、端点end的连接

	}
	//翻转一个链表

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

	//solu 739 
	// 这道题目的解答不能使用循环，当vector内部的数据太多时（例如3000）
	// 就会超出时间限制。故此，应当采用其他的方式：stack或者使用数组模拟stack。
	vector<int> dailyTemperatures(vector<int>& T) {
		if (T.size() == 1)
		{
			return vector<int>(1,0);
		}
		// 新建两个数组：temp用来存储结果数据，arr用来模拟栈。
		int* temp = new int[T.size()];
		for (int i = 0; i < T.size(); i++)
			temp[i] = 0;
		int* arr = new int[T.size()];

		// 先将arr的第一个值设置为0
		arr[0] = 0; 
		int flag = 0;
		// 对原vector进行遍历
		for (int i = 1, j = 0; (i < T.size() && j < T.size()); i++)
		{
			if (T[i] > T[arr[j]])
			{
				temp[i - 1] = i - arr[j];
				arr[j] = i;
				// 循环需要设置
				flag = j - 1;
				while (flag>=0&&T[arr[j]]>T[arr[flag]])
				{
					temp[arr[flag]] = arr[j] - arr[flag];
					arr[flag] = i;
					j = flag;
					flag--;
				}
			}
			else
			{
				arr[++j] = i;
			}
		}
		vector<int> resvec;
		for (int i = 0; i < T.size(); i++)
		{
			resvec.push_back(temp[i]);
		}
		delete []arr;
		delete[] temp;
		return resvec;
	}

	//solu 230
	int kthSmallest(TreeNode* root, int k) {
		// 对该二叉搜索树进行中序遍历，第K个元素即是第K个最小的元素。

		// 首先对输入进行有效性判断。
		if (!root || k < 0)
		{
			return EXIT_SUCCESS;
		}
		// 输入有效，进行中序遍历(Inorder Traversal)

		
	}
	
	//solu 239
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	// 下面是使用容器的解法，效率不高

		/*
		// vector为空亦或k<0，返回一个空vector。
		if (!nums.size() || k < 0)
			return vector<int>(0);

		// k==1 时。返回原vector
		if (k == 1)
		{
			return nums;
		}

		// k==nums.size()时,返回整个vector的最大值。
		if (k == nums.size())
		{
			auto res =  std::max_element(nums.begin(),nums.end());
			return vector<int>(1, *res);
		}
		// 使用一个deque来容纳数据。
		deque<int> window;
		// 第一种解法，使用deque.
		// 通过k值来构造队列数据
		// 使用一个vector来返回数据
		vector<int>result;
		for (int i = 0; i < k; i++)
		{
			window.push_back(nums[i]);
		}
		result.push_back(*std::max_element(window.begin(), window.end()));
		// 使用队列来模拟双端队列。
		// 编写针对这种队列求最大值的算法。
		// 对剩下的数据进行遍历
		int loop_times = nums.size() - k;
		for (int i = 0; i < loop_times; i++)
		{
			// push进新的元素
			window.push_back(nums[i + k]);
			// pop 掉尾端
			window.pop_front();
			// 数据操作结束之后，求每次获得的最大值
			result.push_back(*std::max_element(window.begin(), window.end()));
		}
		return result;
		*/

		/*
		// 下面的方法，时间复杂度仍然很高，因为做了许多重复的比较。
		// 不需要使用数组来代替容器实现压入-弹出过程。
		// 直接使用两个移动的指针/下标 标志出窗口的左右两界即可。
		// 再借助比较函数来获取两界之间的最大值。
		// 比较大小的函数--借用std::max()。


		// vector为空亦或k<0，返回一个空vector。
		if (!nums.size() || k < 0)
			return vector<int>(0);

		// k==1 时。返回原vector
		if (k == 1)
		{
			return nums;
		}
		// k==nums.size()时,返回整个vector的最大值。
		if (k == nums.size())
		{
			auto res = std::max_element(nums.begin(), nums.end());
			return vector<int>(1, *res);
		}

		// 其他情况
		vector<int> result;
		int delta = k - 1;
		// 循环，获取相应的边界值。
		for (int i = 0; i < nums.size() - delta; i++)
		{
			int j = i + delta;
			int temp = 0;
			for (int ite = i; ite <= j; ite++)
			{
				if (nums[ite] > temp)
					temp = nums[ite];
			}
			result.push_back(temp);
		}
		return result;
	}
	*/

	// 第三种方法:时间复杂度超过100%的提交
		// 内存消耗小于92%的提交。

		// vector为空亦或k<0，返回一个空vector。
		
		if (!nums.size() || k < 0)
			return vector<int>(0);

		// k==1 时。返回原vector
		if (k == 1)
		{
			return nums;
		}
		// k==nums.size()时,返回整个vector的最大值。
		if (k == nums.size())
		{
			auto res = std::max_element(nums.begin(), nums.end());
			return vector<int>(1, *res);
		}
		vector<int> result;
		int delta = k - 1;
		int tag = 0;

		for (int i = 0; i <= nums.size() - k; i++)
		{
			int j = i + delta;
			//刚开始进入循环时
			// 需要调试
			if (!i||i>tag)
			{
				for (int ite = i+1,k = i; ite <= j; ite++)
				{
					if (nums[ite] > nums[k])
					{
						k = ite;
					}
					tag = k;
				}
				// 找到第一次/后面的不知道第几次的最大值的下标为ite
				result.push_back(nums[tag]);
				continue;// 结束后面的循环，直接进入下一个比较。
			}
			// 后面的处理步骤
			// 未越界的情况下
			if (i<=tag)
			{
				// 新来的小于老大
				if (nums[j] < nums[tag])
				{
					result.push_back(nums[tag]);//老大再进去
					continue;
				}
				// 新来的大于老大
				else
				{
					result.push_back(nums[j]);
					//重置tag
					tag = j;
				}

			}
			
		}

		return result;
		
	}


};

#endif // !LEET_H_