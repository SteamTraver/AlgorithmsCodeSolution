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

//using BigInt = unsigned long long;
//
//BigInt evenOperation(BigInt number) {
//    return number / 2;
//}
//
//BigInt oddOperation(BigInt number) {
//    return number * 3 + 1;
//}

int main()
{
    //LeetSolution leet;
    //initializer_list<int> list_args = { 5,6,9,4,3,7,8,10,5,95,61,21 };
    //ListNode* head = ListNodeUtility::generateList(list_args);

    //cout << "before sort : \n";
    //ListNodeUtility::outputList(head);
    //cout << "\nafter sorted : \n";
    //ListNode* newlist = leet.insertionSortList(head);
    //ListNodeUtility::outputList(newlist);

    //delete newlist;

    //cout << "Input any positive number(integer) you think." << endl;
    //BigInt number = 0;
    //cin >> number;

    //cout << "number your input is : " << number << std::endl;
    //cout << "max of BigInt is : " << std::numeric_limits<unsigned long long>::max();
    //while (true)
    //{
    //    if (number % 2 == 0) {
    //        number = evenOperation(number);
    //    }
    //    else {
    //        number = oddOperation(number);
    //    }
    //    cout << "\nnumber is " << number << endl;
    //    if (number == 1) {
    //        break;
    //    }
    //}
    //return 0;


    double square_number = 0.0;
    cout << "Input a square number (>=0)\n";
    cin >> square_number;
    if (square_number < 0) {
        cout << "Invalid square number, no square root of < 0.\n";
        return EXIT_SUCCESS;
    }

    double guess = 1.0;
    double quotient = 0.0;

    while (std::abs(guess* guess - square_number) > 0.001)
    {
        quotient = square_number / guess;
        guess = (quotient + guess) / 2;
    }

    cout << "sqaure root of " << square_number << " is : " << guess
        << endl;
    return EXIT_SUCCESS;
}

