class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int size = temperatures.size();
        vector<int> ans(size);
        ans[size-1] = 0;

        stack<int> st;
        st.push(size-1);
    
        for(int i=size-2; i>=0; i--)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();
    
            if(st.empty())
            {
               ans[i] = 0;
               st.push(i);
            }
            else
            {
               ans[i] = st.top()-i;
               st.push(i);
            }
        }
        return ans;
    }
};