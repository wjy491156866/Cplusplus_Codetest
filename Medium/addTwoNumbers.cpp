//2.两数相加
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL, *cur = NULL;
    int carry = 0;
    while (l1 || l2) { // 同时考虑两个链表，这样就只需要一个while循环
        int sum = carry; // 将当前要求的节点的值先置为进位的值（0 | 1）
        if (l1) { sum += l1->val; l1 = l1->next; } // 注意到是否链表已经到了边界了
        if (l2) { sum += l2->val; l2 = l2->next;  } // 同上
        if (!cur) { cur = head = new ListNode(sum); } // 如果我们求的链表还不存在（没有任何节点）
        else { cur->next = new ListNode(sum); cur = cur->next; } // 否则我们直接添加到链表的后面就行
        if (cur->val >= 10) { carry = 1; cur->val -= 10; } //当前节点的值如果>=10，则进位。
        else carry = 0;
    }
    if (carry == 1) cur->next = new ListNode(carry); //可能最高位还有进位。
    return head;
    }
};
