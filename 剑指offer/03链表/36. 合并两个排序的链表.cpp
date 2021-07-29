/**
 * 算法
(二路归并) O(n)
新建头部的保护结点dummy，设置cur指针指向dummy。
若当前l1指针指向的结点的值val比l2指针指向的结点的值val小，则令cur的next指针指向l1，且l1后移；否则指向l2，且l2后移。
然后cur指针按照上一部设置好的位置后移。
循环以上步骤直到l1或l2为空。
将剩余的l1或l2接到cur指针后边。
时间复杂度
两个链表各遍历一次，所以时间复杂度为O(n)
*/
/**
 * 输入两个递增排序的链表，
 * 合并这两个链表并使新链表中的结点仍然是按照递增排序的。

样例
输入：1->3->5 , 2->4->5

输出：1->2->3->4->5->5
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        //cur记录尾结点
        ListNode *cur = dummy;
        //只要两个指针非空，则遍历
        while (l1 != NULL && l2 != NULL) {

            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = (l1 != NULL ? l1 : l2);
        //新的链表的头节点
        return dummy -> next;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(!l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next = (l1!=NULL?l1:l2);
        return dummy->next;
    }
};