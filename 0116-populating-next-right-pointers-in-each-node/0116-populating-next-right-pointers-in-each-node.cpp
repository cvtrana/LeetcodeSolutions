
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        // level order traversal would be a good start
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            
            int sz = q.size();
            vector<Node*> nodes;
            while(sz--){
                
                Node* front = q.front();
                q.pop();
                nodes.push_back(front);
                if(front->left!=NULL){
                     q.push(front->left);
                    
                }
                if(front->right !=NULL){
                    q.push(front->right);
                }
                
            }
            // ab next pointer ko jod do 
            for(int i=0;i<nodes.size()-1;i++){
                Node* pichla  =  nodes[i];
                Node* agla    = nodes[i+1];
                pichla->next  =agla; 
                
            }
            Node* last = nodes[nodes.size()-1];
            last->next = NULL;
        }
        
        return root;
        
        
    }
};