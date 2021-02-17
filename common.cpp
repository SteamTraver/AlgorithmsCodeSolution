#include "common.h"

void AuxiliaryUtility::outputList(ListNode* head)
{
    if (!head) {
        cout << "Empty List, Return. \n";
        return;
    }
	ListNode* head_backup = head;
	while (head_backup != NULL) {
		cout << head_backup->val;
		if (head_backup->next)
			cout << "-->";
		head_backup = head_backup->next;
	}
}