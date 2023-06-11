
class Solution {
public:
    int getlen(ListNode* head){
        int len  =0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tail =    new ListNode(-1); // dummy node
        ListNode*head = tail;
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry=0;
        int len1 = getlen(l1);
        int len2 = getlen(l2);
        ListNode*  traverse;
        if(len1 >= len2){
            traverse  = l2;
            
        }
        else{
            traverse = l1;
            
        }
        while(traverse!=NULL){
            ListNode* sum = new ListNode(-1) ;
            int val1 = temp1->val;
            int val2 = temp2->val;
            long long  add = val1 + val2 + carry;
            //cout << add << endl;
            if(add>=10){
                int f = add;
                f/=10;
                carry = f%10;
                add = add%10;
            }
            else{
                carry = 0;
            }
            sum->val = add;
            sum->next = NULL;
            tail->next = sum;
            tail = sum;
            temp1 = temp1->next;
            temp2 = temp2 ->next;
            traverse = traverse->next;
            
        }
        
        // if list1 is small
        
        while(temp1!=NULL){
            ListNode* sum = new ListNode(-1) ;
            long long  add = temp1->val + carry;
            
            if(add>=10){
                int f = add;
                f/=10;
                carry = f%10;
                add = add%10;
            }
            else{
                carry = 0;
            }
            sum->val = add;
            sum->next = NULL;
            tail->next = sum;
            tail = sum;
            temp1=  temp1->next;
            
            
        }

        // If list2 is small
        while(temp2 != NULL){
            ListNode* sum = new ListNode(-1) ;
            long long  add = temp2->val + carry;
            
            if(add>=10){
                int f = add;
                f/=10;
                carry = f%10;
                add = add%10;
            }
            else{
                carry = 0;
            }
            sum->val = add;
            sum->next = NULL;
            tail->next = sum;
            tail = sum;
            temp2 = temp2->next;
            
            
            
            
        }
        
        // if carry has some value , add it your list
        if(carry!=0){
            ListNode* sum = new ListNode(-1);
            sum->val = carry;
            sum->next = NULL;
            tail->next = sum;
            tail = sum;
            
        }
        
        ListNode* ans = head->next;
        head->next = NULL;
        return ans;
        
        
        
        
        
        
        
        
    }
};