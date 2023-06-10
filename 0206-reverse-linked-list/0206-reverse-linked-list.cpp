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
    void reverse(ListNode* &head,ListNode* &prev, ListNode* &curr){
        // base case 
        if(curr == NULL){
            head = prev;
            return;
        }
        ListNode* fwd = curr->next;
        reverse(head,curr,fwd);
        curr->next = prev;
        



    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        // solving it using recursion
        reverse(head,prev,curr);
        return head;
        
    }
};