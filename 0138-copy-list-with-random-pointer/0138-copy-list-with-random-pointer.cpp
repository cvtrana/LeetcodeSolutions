
class Solution {
public:
    void InsertAtTail(Node* &head,Node* &tail,int d){
        Node* newnode = new Node(d);
        if(head==NULL){
            head = newnode;
            tail =  newnode;
            return;
        }
        else{
            tail ->next = newnode;
            tail = newnode;
        }
        
        
        
    }
    Node* copyRandomList(Node* head) {
        // step1 = create a clone list using next pointer of orig list
        // step2 = create map of original nodes and clone nodes
        
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            InsertAtTail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }
        
        // creating a map
        unordered_map<Node*,Node*> oldtonew;
        
        Node* purana = head;
        Node* naya = clonehead;
        while(purana!=NULL){
            oldtonew[purana] = naya;
            purana = purana->next;
            naya = naya->next;
        }
        
        purana = head;
        naya = clonehead;
        while(purana!=NULL){
            
            naya->random = oldtonew[purana->random];   
            purana = purana->next;
            naya = naya->next;
            
        }
        return clonehead;
        
        
    }
};