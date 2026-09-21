class Solution 
{
    public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int size = nums.size();

        int minend= nums[0];
        int minsum = nums[0];
        int totsum = nums[0];
        int maxend = nums[0];
        int maxsum =  nums[0];
        
        for(int i = 1; i < size; i++)
        {
            maxend = max(nums[i], maxend + nums[i]);
            maxsum = max(maxend, maxsum);

            minend = min(nums[i], minend + nums[i]);
            minsum = min(minend, minsum);

            totsum += nums[i];
        }

        if(maxsum<0)
            return maxsum;
        return max(maxsum,(totsum-minsum));
    }
};