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

// related defination: -- ��ؽṹ�Ķ���
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

// �����࣬���ж�����ظ�������
class AuxiliaryUtility
{
public:
	AuxiliaryUtility() {};

	// �������
	void outputList(ListNode* head);
};

// �����������Ķ��壺

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};