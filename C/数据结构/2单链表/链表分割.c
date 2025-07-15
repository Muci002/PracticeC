/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition 
{
public:
    ListNode* partition(ListNode* pHead, int x) 
    {
        // write code here
        ListNode* LessHead = (ListNode*)malloc(sizeof(ListNode));  // 储存小于x的节点
        ListNode* LessTail = LessHead;
        ListNode* GreaterHead = (ListNode*)malloc(sizeof(ListNode));  // 储存大于x的节点
        ListNode* GreaterTail = GreaterTail;
        ListNode* tail = pHead;

        while(tail)
        {
            if(tail->val < x)
            {
                LessTail->next = tail;
                LessTail = LessTail->next;
            }
            else 
            {
                GreaterTail->next = tail;
                GreaterTail = GreaterTail->next;
            }
            tail = tail->next;
        }
        GreaterTail->next = NULL;
        LessTail->next = GreaterHead->next;
        free(GreaterHead);
        GreaterHead = NULL;
        pHead = LessHead->next;
        free(LessHead);
        LessHead = NULL;
        return pHead;
    }
};

//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking