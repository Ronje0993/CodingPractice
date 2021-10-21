class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *chkptA = head;
	ListNode *chkptB = head;

	while (n > 1){
		chkptB = chkptB->next;
		n--;
	}
	
	if (chkptB->next == nullptr) return head->next;

	ListNode *prev = nullptr;

	while(chkptB->next != nullptr){
		prev = chkptA;
		chkptA= chkptA->next;
		chkptB= chkptB->next;
	}

	prev->next= chkptA->next;

	return head;
	
    }
};


