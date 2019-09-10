//83. 删除排序链表中的重复元素
//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。


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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)   return NULL;        //如果头指针为空就是空链表
        ListNode* cur = head;       //创建一个新指针
        while (cur->next != NULL)       //指针的下一位不为空时执行
        {
            if (cur->val == cur->next->val)     //当指针的当前值与下一位的值相同
            {
                cur->next = cur->next->next;        //删除指针的下一位
            }
            else
                cur = cur->next;        //指针后移
        }
        return head;        //返回头指针
    }
};

