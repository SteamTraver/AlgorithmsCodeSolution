#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <array>
#include <numeric>
#include <xutility>
#include <bitset>
#include <memory>
#include <cassert>
#include <initializer_list>

using namespace std;

// related defination: -- 相关结构的定义
struct SNode
{
    SNode(int n) : data(n), next(NULL) {};
    int     data;
    SNode*  next;
};

//* Definition for singly-linked list.
struct ListNode
{
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(-1), next(nullptr) {}
    ~ListNode()
    {
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
    }
    int         val;
    ListNode*   next;
    ListNode* link(ListNode* other) 
    {
        assert(this);
        this->next = other;
        return other;
    }
};

// 辅助类，集中定义ListNode相关辅助函数
class ListNodeUtility
{
public:
    ListNodeUtility() {};

    // 链表输出
    static void outputList(const ListNode* head);
    // 传入若干数值，按照其顺序生成一个单链表
    static ListNode* generateList(const std::initializer_list<int>& list_args);
};

// 二叉搜索树的定义：

struct TreeNode
{
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};
