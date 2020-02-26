#pragma once
#ifndef ALGORITHMSTEMPLATE_H_
#define ALGORITHMSTEMPLATE_H_

#include<algorithm>
#include<vector>
#include<stack>
#include<xutility>
#include<memory>

using std::vector;
using std::max;
using std::swap;
using std::begin;
using std::end;
using std::stack;

// 常用的排序算法实现:
namespace BaseAlgorithms
{
	template<typename T,size_t size>
	constexpr size_t array_size(T(&)[size])
	{
		return size;
	}
}
class  SortAlgorithms
{
public:
	// 1、冒泡排序 -- 逐个排列每个元素
#pragma region BubbleSort
	// i只控制内层循环的执行次数，j最多执行size-1次。
	// 每次j执行之后，都有一个元素被摆放在正确的位置。j的每轮执行次数一次递减。
	// 优化形式： 设置标志交换的变量。当 上一次内部循环没有发生交换，证明整个向量已经有序了。
	// 所以 bool 变量 changed == false， 那么下一轮的 外部循环条件判断失效，外层循环也将马上结束。

	// 空间复杂度： o(1)
	// 时间复杂度： 
	// 1、最好的情况：数组是sorted，只需要进行 n-1 次比较，时间复杂度o(n)
	// 2、最坏的情况：逆序排序整个数组，需要进行 n(n-1)/2 次比较。时间复杂度是 o(n2)
	// 3、数组杂乱无章： 平均时间复杂度是 o(n2)

	// version 1: accept reference of an array
	template<typename T = int, size_t size>
	void bubblesortRefVer(T(&arr)[size])
	{
		bool changed = true;
		for (size_t i = 0; i < size - 1 && changed; i++)
		{
			changed = false;
			for (size_t j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
					changed = true;
				}
			}
		}
	}
	// version 2: accept pointer of array
	template<typename T = int>
	void bubblesortPoiVer(T* arr)
	{
		if (arr != nullptr)
		{
			size_t size = sizeof(arr) / sizeof(*arr);
			bool changed = true;
			for (size_t i = 0; i < size - 1 && changed; i++)
			{
				changed = false;
				for (size_t j = 0; j < size - i - 1; j++)
				{
					if (arr[j] > arr[j + 1])
					{
						swap(arr[j], arr[j + 1]);
						changed = true;
					}
				}
			}
		}
	}
#pragma endregion

	// 2、插入排序 -- 不断地将尚未排好序的数插入到已经排好序的部分
	// 相较于冒泡排序，前者每次排序之后，数组尾端是有序的。
	// 对于插入排序，每轮排序之后数组前端是有序的。
	// 时间复杂度的最优/最坏/一般的条件，与冒泡排序相同。
#pragma region InsertionSort
	// 外层循环size次，对每个元素，都通过内存循环去向左寻找比当前i所指的元素更大的元素。
	// 当前i指向的元素由curr保存。一旦发现curr左边存在比curr大的元素，i位置的元素会被覆盖。
	// 同时假如条件满足，j再向左移动。重复上述过程。

	// 空间复杂度：o(1)
	// 时间复杂度： 最优o(n)，最坏o(n2)，平均为o(n2)

	template<typename T = int,int size>
	void insertionsort(T(&arr)[size])
	{
		for (int i = 1, j; i < size; i++)
		{
			T curr = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > curr; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = curr;
		}
	}
#pragma endregion



};


#endif // !ALGORITHMSTEMPLATE_H_