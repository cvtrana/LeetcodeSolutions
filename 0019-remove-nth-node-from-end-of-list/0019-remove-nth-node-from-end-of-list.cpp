/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int  getlen(ListNode* &head){
        int len = 0;
        ListNode* temp  = head;
        while(temp !=  NULL){
            len++;
            temp = temp->next;
        }
        return len;
        
        
        
        
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        int len  = getlen(head);
        int cnt =  len - n  +1;
        
        int pos =  1;
        while(pos!=cnt){
            prev  = curr;
            if(curr->next !=NULL){
                curr = curr->next;
                
            }
            pos++;
        }
        
        if(prev==NULL){
            // head node to be deleted
            ListNode* temp  = head->next;
            head->next =NULL;
            return temp;
        }
        if(curr->next==NULL){
            // tail to be deleted
            prev->next = NULL;
            return head;
        }
        
        prev ->next = curr->next;
        curr->next = NULL;
        return head;
        
        
        
        
        
        
        
    }
};