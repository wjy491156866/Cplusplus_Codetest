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
        ListNode *prev = NULL;       //新建空节点
        ListNode *curr = head;      //新建指针指向头节点
        while (curr != NULL)        //当当前节点不是NULL时
        {
            ListNode *nexttemp = curr->next;        //保存当前节点的next
            curr->next = prev;      //当前节点的next改变方向
            prev = curr;        //前一节点指针后移
            curr = nexttemp;        //当前节点指针后移
        }
        return prev;        //最后指向头
    }
};

