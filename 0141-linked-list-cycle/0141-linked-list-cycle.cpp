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
        map<ListNode*,bool> m;
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            if(m[temp]==1){
                return true;
            }
            m[temp]=1;
            temp = temp->next;
        }
        return false;
        
    }
};