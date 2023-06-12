
class Solution {
public:
    
    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        
        // now merge
        ListNode* sum = new ListNode(-1); // created the dummy node
        ListNode* head = sum;
        
        while(left != NULL && right!=NULL){
            if(left->val < right->val){
                head->next = left;
                head = left;
                left = left->next;
                
            }
            else{
                head->next = right;
                head = right;
                right = right->next;
                
            }
        }
        
        // agar left wali list khatam ho gayi toh
        
        while(left!=NULL){
            head->next = left;
            head = left;
            left = left->next;
        }
        
        while(right!=NULL){
            head->next = right;
            head = right;
            right  = right->next;
        }
        
        sum = sum->next;
        return sum;
        
    }
    
    ListNode* getmid(ListNode* &head){
        
        ListNode* slow = head;
        ListNode* fast  =  head->next;
        
        
        while(fast!=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
        
    }
    ListNode* sortList(ListNode* head) {
        //base case
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        // find mid to divide it into two lists
        
        ListNode* mid = getmid(head);
        
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL; // two separate lists created
        
        // sort both the lists
        
        left = sortList(head);
        right = sortList(right);
        
        ListNode* ans = new ListNode(-1);
        
        ans = merge(left,right); // merge both the list 
        return ans; // head 
        
        
    }
};