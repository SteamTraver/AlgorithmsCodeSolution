#pragma once
#ifndef LINT_H_
#define LINT_H_

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


using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::deque;
using std::array;
using std::bitset;


class LintSolution {
public:

#pragma region 1004
	// 1004 -- 最大平均值和的分组
	double largestSumOfAverages(vector<int>& A, int k)
	{
		if (k == 1&&!A.empty())
		{
			return (std::accumulate(A.begin(), A.end(),0) / A.size());
		}

	}
#pragma endregion

#pragma region 1217

	// 1217 -- 总汉明距离
	int totalHammingDistance(vector<int>& nums)
	{
		// nums 为空
		if (!nums.size())
			return 0;

		// 解题思路:
		// 一开始是这样想的：枚举出一个vector中的所有二元组，然后依次计算其距离。想办法进行缓存之前计算过的每组计算过的。
		// 这样及其容易出错。真正的解法，再看了参考之后给出：
		// 参数是vector<int>，一个int是32位的。把原vector中的每个数，按其二进制形式竖着排下来。例如：nums == [4,14,2]

		// 4: [24个0] 0 1 0 0
		// 14:[24个0] 1 1 1 0
		// 2: [24个0] 0 0 1 0
		// 每行共32位。

		// 重点：竖着看，每行的第n位即每列，出现1的次数->count1；出现0的次数->count0。二者相乘，令 p = count0 * count1;
		// p 则是 nums中的所有数，在第n位的汉明距离。循环结束后，然后返回32个p累加的和即可。
		// 为何p是汉明距离，因为汉明距离得是[1,0]的pair。当我们得出了count0/count1，那么有多少对[1,0]呢？二者相乘即可。

		// 代码解释:

		// 代码中最重要的是" count1 += (v >> i) & 1 "这一行。>>是右移运算。把数v右移，然后左边补0，然后返回其移位后的拷贝值 r。
		// &是 与 运算。代码里让 r 和 1(0000 0001) 进行位与运算。只有当r的最右位是1时，与1的&运算才能得到结果1，否则是零。
		// i控制每次移位的位数。v则每次移动i位。需要注意的是，v进行移位运算之后，v的值并没有改变——即每次v的移动，都是重新开始，而不是在上一次右移的基础上再次右移i位。 


		int sum = 0;
		auto size = nums.size();
		for (int i = 0; i < 32; i++)
		{
			int count1 = 0;
			for (int& v : nums)
			{
				count1 += (v >> i) & 1;
			}
			int count0 = size - count1;
			sum += count1 * count0;
		}
		return sum;
	}
#pragma endregion


};
#endif // !LINT_H_

