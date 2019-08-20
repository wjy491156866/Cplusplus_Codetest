//206. 反转链表
//反转一个单链表。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *nexttemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexttemp;
        }
        return prev;
    }
};

