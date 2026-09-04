class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int size = nums.size();
        int bestending = nums[0];
        int ans = nums[0];

        for(int i=1; i<size; i++)
        {
            int v1 = nums[i];
            int v2 = nums[i] + bestending;
            bestending = max(v1,v2);
            ans = max(ans, bestending);
        }
        return ans;
    }
};