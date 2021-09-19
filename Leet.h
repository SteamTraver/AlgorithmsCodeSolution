#pragma once
#include "common.h"

// solution class for leetcode
class LeetSolution 
{
public:
    LeetSolution() {};
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    // solu 2
    int lengthOfLongestSubstring(string s);

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    inline double findMedianTwoArrays(const vector<int>& nums1, const vector<int>& nums2);
    inline double findMedian(const vector<int>& v);
    // solu 4
    string longestPalindrome(string s);
    // solu 5
    SNode* reverselist(SNode* phead);
    // solu 6
    string convert(string s, int numRows);
    void quicksort(int* a, int l, int r);
    // solu 20 -- ��Ч������
    bool isValid(string s);
    // solu 24 -- ���������ڵ�
    ListNode* swapPairs(ListNode* head);
    //solu 25 -- K��һ�鷭ת����
    ListNode* reverseKGroup(ListNode* head, int k);
    //��תһ������
    ListNode* reverseList(ListNode* head);

#pragma region Unsolved
    //solu 739
    vector<int> dailyTemperatures(vector<int>& T);
    //solu 230
    int kthSmallest(TreeNode* root, int k);
#pragma endregion
    
    //solu 239
    vector<int> maxSlidingWindow(vector<int>& nums, int k);;

    //solu 147 -- ��������в�������
    ListNode* insertionSortList(ListNode* head);
};
