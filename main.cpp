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
    LeetSolution leet;

    initializer_list<int> list_args = { 5,6,9,4,3,7,8,10,5,95,61,21 };


    //ListNode<int> l1(5);
    //ListNode<int> l2(6);
    //ListNode<int> l3(9);
    //ListNode<int> l4(4);
    //ListNode<int> l5(3);
    //ListNode<int> l6(7);
    //ListNode<int> l7(8);


    //l1.link(&l2)->link(&l3)->link(&l4)->link(&l5)->link(&l6)->link(&l7);

    //ListNode<int>* head = &l1;

    ListNode* head = AuxiliaryUtility::generateList(list_args);

    cout << "before sort : \n";
    AuxiliaryUtility::outputList(head);
    cout << "\nafter sorted : \n";
    ListNode* newlist = leet.insertionSortList(head);
    AuxiliaryUtility::outputList(newlist);

    delete newlist;

    return 0;
}

