#include"SolutionTemplate.h"

template<typename T = char,size_t size>
size_t sizeofarray(T(&a)[size])
{
	return size;
}

int main()
{
	Solution S;

	/*vector<int> v1 = {1};
	vector<int> v2 = {};

	cout << "median number of two vectors : " << S.findMedianSortedArrays(v1, v2);*/

	int test[] = { 1,74,14,15,10,9,78,42,31,56,20,19,30 };
	S.quicksort(test, 0, 12);

	cout << "after sorted.\n";
	for (int i = 0; i < 13; i++)
	{
		cout << test[i] << "\t";
	}
	cout << endl;

	return 0;
}