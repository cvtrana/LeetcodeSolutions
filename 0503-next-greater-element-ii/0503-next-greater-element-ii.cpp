class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		stack<int> st;
		vector<int> ans;
		for(int i=nums.size()-1;i>=0;i--)
		{
			st.push(nums[i]);

		}

		for(int i=nums.size()-1;i>=0;i--)
		{
			while(!st.empty() && nums[i]>=st.top())
			{
				st.pop();
			}

			if(st.empty())
			{
				ans.push_back(-1);
			}
			else
			{
				ans.push_back(st.top());
			}
			st.push(nums[i]);
		}
		reverse(ans.begin(),ans.end());
		return ans;

	}
};