class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int low = 0;
        int high = 0;
        int size = nums.size();
        int result = INT_MAX;
        int sum = 0;

        while(high<size)
        {
            sum = sum + nums[high];
            while(sum >= target)
            {
                int length = high - low + 1;
                result = min(result, length);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if(result != INT_MAX)
            return result;
        else
            return 0;
    }
};