//160. 相交链表
//编写一个程序，找到两个单链表相交的起始节点。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)  return NULL;        //有一个为空，则为空
        ListNode *pA = headA, *pB = headB;    //两个指针分别指向两个链表的头
        while(pA != pB)   //当两个指针指向不相同时
        {
            pA = pA == NULL ? headB : pA->next;   //a链表指针不断的后移，直到结束之后移到b链表上，然后继续后移；
            pB = pB == NULL ? headA : pB->next;   //b链表指针不断的后移，直到结束之后移到a链表上，然后继续后移；
        }
        return pA;    //最后两指针会同时指向同一地址，跳出循环返回值。
    }
};
