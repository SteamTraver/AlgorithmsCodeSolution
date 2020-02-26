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

// ���õ������㷨ʵ��:
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
	// 1��ð������ -- �������ÿ��Ԫ��
#pragma region BubbleSort
	// iֻ�����ڲ�ѭ����ִ�д�����j���ִ��size-1�Ρ�
	// ÿ��jִ��֮�󣬶���һ��Ԫ�ر��ڷ�����ȷ��λ�á�j��ÿ��ִ�д���һ�εݼ���
	// �Ż���ʽ�� ���ñ�־�����ı������� ��һ���ڲ�ѭ��û�з���������֤�����������Ѿ������ˡ�
	// ���� bool ���� changed == false�� ��ô��һ�ֵ� �ⲿѭ�������ж�ʧЧ�����ѭ��Ҳ�����Ͻ�����

	// �ռ临�Ӷȣ� o(1)
	// ʱ�临�Ӷȣ� 
	// 1����õ������������sorted��ֻ��Ҫ���� n-1 �αȽϣ�ʱ�临�Ӷ�o(n)
	// 2�������������������������飬��Ҫ���� n(n-1)/2 �αȽϡ�ʱ�临�Ӷ��� o(n2)
	// 3�������������£� ƽ��ʱ�临�Ӷ��� o(n2)

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

	// 2���������� -- ���ϵؽ���δ�ź���������뵽�Ѿ��ź���Ĳ���
	// �����ð������ǰ��ÿ������֮������β��������ġ�
	// ���ڲ�������ÿ������֮������ǰ��������ġ�
	// ʱ�临�Ӷȵ�����/�/һ�����������ð��������ͬ��
#pragma region InsertionSort
	// ���ѭ��size�Σ���ÿ��Ԫ�أ���ͨ���ڴ�ѭ��ȥ����Ѱ�ұȵ�ǰi��ָ��Ԫ�ظ����Ԫ�ء�
	// ��ǰiָ���Ԫ����curr���档һ������curr��ߴ��ڱ�curr���Ԫ�أ�iλ�õ�Ԫ�ػᱻ���ǡ�
	// ͬʱ�����������㣬j�������ƶ����ظ��������̡�

	// �ռ临�Ӷȣ�o(1)
	// ʱ�临�Ӷȣ� ����o(n)���o(n2)��ƽ��Ϊo(n2)

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