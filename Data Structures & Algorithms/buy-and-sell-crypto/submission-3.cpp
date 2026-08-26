class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        int profit = 0;
        int mini = prices[0];

        for(int i=1; i<size; i++)
        {
            profit = max(profit, (prices[i] - mini));
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};