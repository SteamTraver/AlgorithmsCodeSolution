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

// related defination: -- ��ؽṹ�Ķ���
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

// �����࣬���ж���ListNode��ظ�������
class ListNodeUtility
{
public:
    ListNodeUtility() {};

    // �������
    static void outputList(const ListNode* head);
    // ����������ֵ��������˳������һ��������
    static ListNode* generateList(const std::initializer_list<int>& list_args);
};

// �����������Ķ��壺

struct TreeNode
{
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};
