#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<array>
#include<numeric>
#include<xutility>
#include<bitset>
#include<memory>

using namespace std;

// related defination: -- 相关结构的定义
struct SNode
{
	int		data;
	SNode*	next;
	SNode(int n) :data(n), next(NULL) {};
};

//* Definition for singly-linked list.
struct ListNode {
	int			val;
	ListNode*	next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 辅助类，集中定义相关辅助函数
class AuxiliaryUtility
{
public:
	AuxiliaryUtility() {};

	// 链表输出
	void outputList(ListNode* head);
};

// 二叉搜索树的定义：

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};