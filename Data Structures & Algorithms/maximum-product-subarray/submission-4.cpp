class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int size = nums.size();
        int maxending = nums[0];
        int minending = nums[0];
        int ans = nums[0];

        for(int i=1; i<size; i++)
        {
            int v1 = nums[i];
            int v2 = nums[i] * maxending;
            int v3 = nums[i] * minending;
            
            maxending = max(max(v1,v2),v3);
            minending = min(min(v2,v3),v1);
            ans = max(ans, max(maxending, minending));
        }
        return ans;
    }
};