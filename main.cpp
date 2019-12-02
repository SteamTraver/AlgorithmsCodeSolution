#include"SolutionTemplate.h"

int main()
{
	Solution S;

	ListNode s1 = ListNode(1);
	ListNode s2 = ListNode(2);
	ListNode s3 = ListNode(3);
	ListNode s4 = ListNode(4);
	ListNode s5 = ListNode(5);
	ListNode s6 = ListNode(6);
	ListNode s7 = ListNode(7);

	s1.next = &s2;
	s2.next = &s3;
	s3.next = &s4;
	s4.next = &s5;
	s5.next = &s6;
	s6.next = &s7;

	ListNode* head = &s1;
	cout << "Before reversed with K group: \n";
	outputlist(head);
	cout << endl;

	return 0;
}