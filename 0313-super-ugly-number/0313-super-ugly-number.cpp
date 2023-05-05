class Solution {
public:
int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>arri(primes.size());
  vector<long>arrn(primes.size());
    vector<long>dp(n+1);
    dp[0]=1;
    for(int j=0;j<n;j++){
        long  mini=INT_MAX;
        for(int i=0;i<arri.size();i++){
            arrn[i]=dp[arri[i]]*primes[i];
            mini=min(mini,arrn[i]);
        }
      for(int i=0;i<arri.size();i++){
          if(mini==arrn[i]){
              dp[j+1]=arrn[i];
              arri[i]++;
          }
      }
  
    }

  return dp[n-1]; 
}
};
