int dp[1 << 16][64];
bool choice[1 << 16][64];
class Solution {
public:
int req_mask, m;
vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>&
people_skills) {
    int n = req_skills.size();
    m = people_skills.size();
    unordered_map<string, int> skills;
    for (int i = 0; i < n; ++i)
    skills[req_skills[i]] = i;
    vector<int> people;
    for (auto &v: people_skills) {
    int h = 0;
    for (string &skill: v)
    h |= 1 << skills[skill];
    people.push_back(h);
    }
    req_mask = (1 << n) - 1;
    memset(dp, -1, 1 << n + 8);
    memset(choice, 0, 1 << n + 6);
    solve(people, 0, 0);
// build the answer through the choice matrix (see the solve function first)
    vector<int> ans;
    for (int i = 0, mask = 0; i < m; ++i) {
    // did we include the i'th person?
    if (choice[mask][i]) {
    ans.push_back(i);
    mask |= people[i];
    }
    if (mask == req_mask)
    break;
    }
    return ans;
}
int solve(vector<int> &people, int i, int mask) {
    if (mask == req_mask)
    return 0;
    if (i == m)
    return 10000;
    int &ans = dp[mask][i];
    if (ans != -1)
    return ans;
    int ans1 = solve(people, i+1, mask | people[i]) + 1;
    int ans2 = solve(people, i+1, mask);
    if (ans1 < ans2)
    choice[mask][i] = 1;
    return ans = min(ans1, ans2);
}
};