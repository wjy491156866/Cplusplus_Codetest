//21. 合并两个有序链表
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//方法一：归并排序合并过程，因为是有序链表，直接把当前链表的第一个数比较，然后合并。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {   
        if (l1 == NULL) return l2;  //如果其中一个有序链表为空，则返回另一个链表。
        if (l2 == NULL) return l1;
        ListNode* p1 = l1, * p2 = l2;   //给两个链表做个备份。
        ListNode* head = new ListNode(0);   //新建一个带头指针head的链表，第一位为0。
        ListNode* cur = head;   //再新建一个指针。
        while (p1 && p2)    //当有一个是空的情况下结束循环。
        {
            if (p1->val < p2->val)  //比较当前链表头一个数大小
            {
                cur->next = p1; //新链表的下一位给小的一方
                cur = cur->next;    //指针往下移
                p1 = p1->next;  //链表去掉头一位
            }
            else
            {
                cur->next = p2; //同上
                cur = cur->next;
                p2 = p2->next;
            }
            //如果有一个链表变空了，直接接上另一个链表。
            if (p1 == NULL) {cur->next = p2;}
            else {cur->next = p1;}
        }
        return head->next;  //返回头指针之后的链表        
    }
};


//方法二：递归法，因为是有序链表，直接把当前链表的第一个数比较，然后加入到新建的链表中。
//因为是递归，时间复杂度和空间复杂度较高。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {   
        if (l1 == NULL) return l2;  //如果其中一个有序链表为空，则返回另一个链表。
        if (l2 == NULL) return l1;
        ListNode* p1 = l1, * p2 = l2;   //给两个链表做个备份。
        ListNode* head;   //新建一个链表头指针。
        if (p1->val < p2->val)  //比较当前链表头一个数大小
        {
            head = new ListNode(p1->val);   //从头开始新建一个小的元素
            head->next = mergeTwoLists(p1->next , p2);  //下一个元素的决定由更新之后的链表递归作比较。
        }
        else
        {
            head = new ListNode(p2->val);   //同理
            head->next = mergeTwoLists(p1 , p2->next);
        }
        return head;  //返回头指针之后的链表        
    }
};

