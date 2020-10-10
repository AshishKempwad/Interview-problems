/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B)
{
    if(!A && !B)
    {
        return NULL;
    }
    if(!A)
    {
        return B;
    }
    if(!B)
    {
        return A;
    }
    
    ListNode* head = NULL;
    
    if(A->val < B->val)
    {
        head = A;
        A = A->next;
    }
    else
    {
        head = B;
        B = B->next;
    }
    
    ListNode* temp = head;
    while(A && B)
    {
        if(A->val < B->val)
        {
            temp->next = A;
            A=A->next;
        }
        else
        {
            temp->next = B;
            B = B->next;
        }
        
        temp=temp->next;
    }
    
    if(A)    // If A is remaining then just join it 
    {
        temp->next = A;
    }
    if(B)  // If B is remaining then just join it
    {
        temp->next = B;
    }
    
    return head;
}
