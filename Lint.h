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
	// 1004 -- ���ƽ��ֵ�͵ķ���
	double largestSumOfAverages(vector<int>& A, int k)
	{
		if (k == 1&&!A.empty())
		{
			return (std::accumulate(A.begin(), A.end(),0) / A.size());
		}

	}
#pragma endregion

#pragma region 1217

	// 1217 -- �ܺ�������
	int totalHammingDistance(vector<int>& nums)
	{
		// nums Ϊ��
		if (!nums.size())
			return 0;

		// ����˼·:
		// һ��ʼ��������ģ�ö�ٳ�һ��vector�е����ж�Ԫ�飬Ȼ�����μ�������롣��취���л���֮ǰ�������ÿ�������ġ�
		// �����������׳��������Ľⷨ���ٿ��˲ο�֮�������
		// ������vector<int>��һ��int��32λ�ġ���ԭvector�е�ÿ�����������������ʽ���������������磺nums == [4,14,2]

		// 4: [24��0] 0 1 0 0
		// 14:[24��0] 1 1 1 0
		// 2: [24��0] 0 0 1 0
		// ÿ�й�32λ��

		// �ص㣺���ſ���ÿ�еĵ�nλ��ÿ�У�����1�Ĵ���->count1������0�Ĵ���->count0��������ˣ��� p = count0 * count1;
		// p ���� nums�е����������ڵ�nλ�ĺ������롣ѭ��������Ȼ�󷵻�32��p�ۼӵĺͼ��ɡ�
		// Ϊ��p�Ǻ������룬��Ϊ�����������[1,0]��pair�������ǵó���count0/count1����ô�ж��ٶ�[1,0]�أ�������˼��ɡ�

		// �������:

		// ����������Ҫ����" count1 += (v >> i) & 1 "��һ�С�>>���������㡣����v���ƣ�Ȼ����߲�0��Ȼ�󷵻�����λ��Ŀ���ֵ r��
		// &�� �� ���㡣�������� r �� 1(0000 0001) ����λ�����㡣ֻ�е�r������λ��1ʱ����1��&������ܵõ����1���������㡣
		// i����ÿ����λ��λ����v��ÿ���ƶ�iλ����Ҫע����ǣ�v������λ����֮��v��ֵ��û�иı䡪����ÿ��v���ƶ����������¿�ʼ������������һ�����ƵĻ������ٴ�����iλ�� 


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

