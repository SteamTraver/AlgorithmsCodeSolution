#include"SolutionTemplate.h"

template<typename T = char,size_t size>
void sizeofarray(T(&a)[size])
{
	return size;
}

int main()
{
	Solution S;

	vector<int> v1 = {1};
	vector<int> v2 = {};

	cout << "median number of two vectors : " << S.findMedianSortedArrays(v1, v2);

	return 0;
}