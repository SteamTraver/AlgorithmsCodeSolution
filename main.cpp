#include"LeetCodeSolution.h"
//#include"Lint"

int main()
{
	Solution S;

	/*ListNode s1 = ListNode(1);
	ListNode s2 = ListNode(2);
	ListNode s3 = ListNode(3);*/
	//ListNode s4 = ListNode(4);
	//ListNode s5 = ListNode(5);
	//ListNode s6 = ListNode(6);
	//ListNode s7 = ListNode(7);
	//ListNode s8 = ListNode(8);
	//ListNode s9 = ListNode(9);
	//ListNode s10 = ListNode(10);


	/*s1.next = &s2;
	s2.next = &s3;*/
	//s3.next = &s4;
	//s4.next = &s5;
	//s5.next = &s6;
	//s6.next = &s7;
	//s7.next = &s8;
	//s8.next = &s9;
	//s9.next = &s10;


	//ListNode* head = &s1;
	//cout << "Before reversed with K group: \n";
	//outputlist(head);
	//cout << endl;
	////ListNode* tmp = S.reverseList(head);
	//cout << "After being reversed with k==3 group : \n";
	//outputlist(S.swapPairs(head));


	//vector<int> temprary = { 55,38,53,81,61,93,97,32,43,78};
	//
	//vector<int> res = S.dailyTemperatures(temprary);
	//cout << "Result is : \n";
	//for (int& t : res)
	//{
	//	cout << t << " ";
	//}
	//cout << endl;

	vector<int> test = {-7,-8,7,5,7,1,6,0};
	int k = 4;
	vector<int> res = S.maxSlidingWindow(test, k);
	for (int& g : res)
	{
		cout << g << " ";
	}
	cout << endl;

	// slash the code 

	return 0;
}