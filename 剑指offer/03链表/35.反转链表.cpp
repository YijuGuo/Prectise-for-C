
//迭代
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
    ListNode* reverseList(ListNode* head) {
        //考点：单链表记录前驱结点
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};


//递归
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
    ListNode* reverseList(ListNode* head) {
        //空链表无需进行翻转
        if (!head || !head->next) return head;
        ListNode *tail = reverseList(head->next);
        //翻转head->next为头结点的链表翻转，
        //原链表尾结点tail
        //此时head->next是新链表的尾结点
        //令其head->next->next指向head
        //head->next指针指向空
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*tail=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* prev=nullptr;
        ListNode* cur=head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
    }
};