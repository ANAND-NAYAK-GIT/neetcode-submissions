class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int size = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i=0; i<size; i++)
        {
            sum += nums[i];
            int remove = sum-k;
            count += mp[remove];
            mp[sum]++;
        }

        return count;
    }
};