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
    bool hasCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL){
            return false;
        }
        // approach 2 : by creating slow and fast pointers
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(slow!=NULL && fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
            
            slow = slow->next;
            if(slow==fast){ // detect a loop 
                return true;
            }
            
        }
        return false;
        
    }
};