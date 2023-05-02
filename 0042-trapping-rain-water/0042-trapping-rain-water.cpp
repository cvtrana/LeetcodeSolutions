class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftgreat;
        int left = height[0];
        for(int j=0; j<n; j++){
            if(left <height[j]){
                  left = height[j];
            }
            leftgreat.push_back(left);
        }
        int right = height[n-1];
        vector<int>rightgreat;
        for(int j = n-1 ; j>=0; j--){
                if(right<height[j])
                    right = height[j];
             rightgreat.push_back(right);
            }
        reverse(rightgreat.begin() , rightgreat.end());
        cout << "leftgreat" << endl;
        for(int i=0;i<n;i++){
            cout << leftgreat[i] <<" ";
        }
        cout << endl;
        cout << "rightgreat" << endl;
        for(int i=0;i<n;i++){
            cout << rightgreat[i] <<" ";
        }
        cout << endl;
        int sum = 0;
        for(int i = 0 ; i<n;i++){
            sum = sum + (min(leftgreat[i] , rightgreat[i]) - height[i]);
        }
        return sum;
        
    }
};