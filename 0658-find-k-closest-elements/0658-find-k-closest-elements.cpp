class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int L = 0, R = size(arr)-1;
        while (R - L >= k) 
            if (x - arr[L] <= arr[R] - x) R--;
            else L++;
        return vector<int>(begin(arr) + L, begin(arr) + R + 1);
    }
};