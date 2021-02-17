#pragma once
#include "common.h"

// solution class for lintcode

class LintSolution 
{
public:
	LintSolution() {};
private:
	// 1004 -- 最大平均值和的分组
	double largestSumOfAverages(vector<int>& A, int k);
	// 1217 -- 总汉明距离
	int totalHammingDistance(vector<int>& nums);
};

