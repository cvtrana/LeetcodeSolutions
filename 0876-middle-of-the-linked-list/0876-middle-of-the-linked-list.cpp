class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int N = 0;
        for(auto it = head; it; it = it -> next, N++); //len pf ll  
        for(int i = 0; i < N/2; i++)                             
            head = head -> next;
        return head;
    }
};