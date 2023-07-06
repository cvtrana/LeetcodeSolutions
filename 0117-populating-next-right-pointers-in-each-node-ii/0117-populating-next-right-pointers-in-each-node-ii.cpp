/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // level order traversal
        if(root==NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n =  q.size();
            vector<Node*> v;
            while(n--){
                Node* front = q.front();
                v.push_back(front);
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                    
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                
                
            }
            for(int i=0;i<v.size()-1;i++){
                Node* first = v[i];
                Node* second = v[i+1];
                first->next = second;
            }
            Node* end = v[v.size()-1];
            end->next = NULL;
        }
        return root;
        
    }
};