class Solution {
public:
    ListNode* _reverseKGroup(ListNode* head, int size, int k){
        if(head==NULL || size<k) 
            return head;
        
        ListNode* prev=NULL, *cur=head, *next=NULL;
        int count=0;
        
        while(cur!=NULL && count<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        head->next=_reverseKGroup(next, size-k, k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head, *root;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        return _reverseKGroup(head, size, k);
    }
};