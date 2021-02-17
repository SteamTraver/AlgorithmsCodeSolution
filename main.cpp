#include "Leet.h"
#include "Lint.h"
#include "AlgorithmsTemplate.h"

/*
#pragma region ReWrite

// bubblesort

template<typename T = int, int size>
void bubblesort(T(&arr)[size])
{
	bool changed = true;
	for (int i = 0; i < size - 1 && changed; i++)
	{
		changed = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j + 1], arr[j]);
				changed = true;
			}
		}
	}
}

// insectionsort

template<typename T = int, int size>
void insectionsort(T(&arr)[size])
{
	for (int i = 1, j, current; i < size; i++)
	{
		current = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > current; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = current;
	}
}



#pragma endregion

*/
int main()
{
	LeetSolution* leet = new LeetSolution();
	AuxiliaryUtility* aux = new AuxiliaryUtility();

	ListNode l1(5);
	ListNode l2(6);
	ListNode l3(9);
	ListNode l4(4);
	ListNode l5(3);
	ListNode l6(7);
	ListNode l7(8);


	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;

	ListNode* head = &l1;

	cout << "before sort : \n";
	aux->outputList(head);
	cout << "\nafter sorted : \n";
	ListNode* newlist = leet->insertionSortList(head);
	aux->outputList(newlist);

	return 0;
}

