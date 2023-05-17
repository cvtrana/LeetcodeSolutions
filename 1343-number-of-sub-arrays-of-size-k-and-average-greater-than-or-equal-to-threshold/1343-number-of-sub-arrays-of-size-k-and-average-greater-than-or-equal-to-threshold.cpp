class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //brute force - -- using two for loops and checking every subarray
        
        
        // optimal :  we can use prefix sum to calculate avg in o(1);
        int n =  arr.size();
        
        vector<int> pref(n);
        pref[0]  =  arr[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + arr[i]; 
        }
        
        for(int i =0;i<n;i++){
            cout << pref[i] <<" ";
        }
        int i =0;
        int j = k-1;
        int cnt =0;
        while(i< n-k+1){ // this will cover all the windows of size "k";
            
            if(i==0){
                int temp = pref[j];
                temp = (temp/k);
                cout << temp << endl;
                if(temp >= threshold){
                    cnt++;
                    
                }
                i++;
                j++; // shift the window
                
            }
            else{
                int temp  =  pref[j] - pref[i-1]; // this will give the sum of the current window
                temp = (temp/k);
                cout << temp << endl;
                if(temp >= threshold){
                    cnt++;
                    
                }
                i++;
                j++; // shift the window 
                
            }  
            
            
            
        }
        return cnt;
        
    }
};