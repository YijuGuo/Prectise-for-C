/*
为了方便处理边界情况，
我们定义一个虚拟元素 dummydummy 指向链表头节点。
然后从前往后扫描整个链表，
每次扫描元素相同的一段，
如果这段中的元素个数多于1个，则将整段元素直接删除。
时间复杂度
整个链表只扫描一遍，所以时间复杂度是 O(n)。
*/
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
    ListNode* deleteDuplication(ListNode* head) {
        //头节点可能被删掉，定义虚拟头节点，简化代码
        //在可能删除头节点的情况下常用
        auto dummy = new ListNode(-1);
        dummy->next = head;

        //p：上次保留的结点的最后一个位置
        //q：下一段的第一个结点
        auto p = dummy;
        while (p->next) {
            auto q = p->next;
            //如果q不为空，并且p->next->val == q->val，则一直遍历
            while (q && p->next->val == q->val) q = q->next;
            //如果p->next是q,无重复结点，不删
            if (p->next->next == q) p = p->next;
            //跨过中间的所有重复的结点
            else p->next = q;
        }
        //返回链表的头结点
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*p=dummy;
        while(p->next)
        {
            ListNode*q=p->next;
            while(q&&p->next->val==q->val)q=q->next;
            if(p->next->next==q)p=p->next;
            else p->next =q;
        }
        return dummy->next;
    }
};