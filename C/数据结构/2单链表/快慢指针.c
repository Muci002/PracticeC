//力扣 141

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode List;
bool hasCycle(struct ListNode *head) 
{
    // 快慢指针
    List *cur1 = head, *cur2 = head;
    while(cur2 && cur2->next)
    {
         cur1 = cur1->next;
        cur2 = cur2->next->next;
        if(cur1 == cur2) return true;
       
    }
    return false;
}


// 如果我们把判断 cur1 == cur2 放在指针移动操作的前面，
// 那么在第一次循环的时候，由于 cur1 和 cur2 都指向头节点，这时候判断的结果就会是相等的。
// 但实际上，此时链表可能并没有环，这种情况下就会错误地返回 true，导致算法出现误判。