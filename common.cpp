#include "common.h"
void AuxiliaryUtility::outputList(const ListNode* head)
{
    if (!head) {
        cout << "Empty List, Return. \n";
        return;
    }
    const ListNode* head_backup = head;
    while (head_backup != NULL) {
        cout << head_backup->val;
        if (head_backup->next)
            cout << "-->";
        head_backup = head_backup->next;
    }
}

ListNode* AuxiliaryUtility::generateList(const std::initializer_list<int>& list_args)
{
    const auto size = list_args.size();
    if (size == 0){
        return nullptr;
    }
    auto begin = list_args.begin();
    ListNode* first = new ListNode(*begin);
    begin++;
    ListNode* result = first;

    for (; begin != list_args.end(); begin++) {
        ListNode* node = new ListNode(*begin);
        first = first->link(node);
    }
    return result;
}
