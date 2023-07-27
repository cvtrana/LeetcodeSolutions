
#define ll long long
class Solution
{
    public:

        bool check(ll x, int n, vector<int> &bat)
        {

            ll sum = 0, last = 0;

            for (int i = 0; i < bat.size(); i++)
            {

                if (bat[i] >= x)
                {
                    sum += x;
                }
                else
                {
                    sum += bat[i];
                }
            }

            return (sum / (n)) >= x;
        }
    long long maxRunTime(int n, vector<int> &batteries)
    {
        ll ans = -1, l = 1, r = 1e14;
        sort(batteries.begin(), batteries.end(), greater<int> ());
        while (l <= r)
        {
            ll mid = r + (l - r) / 2;

            if (check(mid, n, batteries))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};