#define ll long long
vector<ll> pr(5000006, 1);
class Solution {
public:
    vector<ll> primes;

    void sieve(ll n)
    {
        pr[1] = 0;
        for(ll i=4; i<=n; i+=2) pr[i] = 0;
        for(ll i=3; i*i<=n; i+=2) {
            if(pr[i]) {
                for(ll j=i*i; j<=n; j+=i) pr[j]=0;
            }
        }
        for(ll i=1; i<=n; i++) if(pr[i]) primes.push_back(i);
    }
    
    int countPrimes(int n) {
        sieve(n-1);
        cout<<primes.size()<<"\n";
        int ans = primes.size();
        return ans;
        
    }
};