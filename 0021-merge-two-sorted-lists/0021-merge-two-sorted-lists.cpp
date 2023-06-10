
class Solution {
public:
    ListNode*  solve(ListNode* &first,ListNode* &second){
        if(first->next==NULL){
            first->next = second;
            return first;
        }
    
        ListNode* curr1 = first;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = second;
        ListNode* next2 = curr2->next;

        while(next1 !=NULL && curr2 !=NULL){

            if(curr2->val >= curr1->val !=NULL && (curr2->val <= next1->val)){
                // add node in between 
                curr1 ->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;

                // update pointers
                curr1 = curr2;
                curr2 = next2;

            }
            else{
                curr1 = next1;
                next1 = next1->next;

                if(next1==NULL){
                    curr1->next = curr2;
                    return first;
                }

            }

        }
        return first;
        
        
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL){
            return list2;
        }
        
        if(list2==NULL){
            return list1;
        }
        
        if(list1->val <= list2->val){
            
            return solve(list1,list2);
        }
        
        else{
            return solve(list2,list1);
        }
    }
};