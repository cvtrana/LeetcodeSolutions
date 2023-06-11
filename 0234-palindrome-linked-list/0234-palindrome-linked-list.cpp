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
    ListNode* reversed(ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // idhr head node hogi
        
        
        
        
        
    }
    
    ListNode* getmid(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        
        // step 1 : getMiddle
        ListNode* middle = getmid(head);
        ListNode* temp = middle->next;
        
        
        // reverse the second half
        middle->next = reversed(temp);
        
        
        // compare both the half
        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        while(head2!=NULL){
            
            if(head1->val != head2->val){
                return false;
                 
            }
            head2 = head2->next;
            head1 = head1->next;
        }
        return true;
        
        
        
    }
};