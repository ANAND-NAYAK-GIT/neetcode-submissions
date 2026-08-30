class Solution {
public:

    bool fun(vector<int> &have, vector<int> &need)
    {
        for(int i=0;i<256;i++)
        {
            if(have[i]<need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) 
    {
        int size = s.length();
    
        vector<int> needed(256,0);
        for(int i=0; i<t.length(); i++)
        {
            needed[t[i]]++;
        }

        vector<int> have(256,0);
        string result = "";
        int low = 0;
        int ans = INT_MAX;
        int start = -1;

        for(int high=0; high<size; high++)
        {
            have[s[high]]++;
            while(fun(have,needed))
            {
                int len = high-low+1;
                if(ans > len)
                {
                    ans = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(ans == INT_MAX)
            return "";

        return s.substr(start, ans);
    }
};