

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
    ListNode* findKthToTail(ListNode* head, int k) {
        int n = 0;
        //求链表长度
        for (auto p = head; p; p = p->next) n ++ ;

        if (n < k) return nullptr;
        auto p = head;
        //从第一个点开始跳，最后返回当前点
        for (int i = 0; i < n - k; i ++ ) p = p->next;
        return p;
    }
};

ListNode* findKthToTail(ListNode* head, int k) {
        int n=0;
        for(au p=head;p;p=p->next)n++;
        if(n<k)return nullptr;
        auto p = head;
        for(itn i=0;i<n-k;i++)p=p->next;
        return p;
        
    }