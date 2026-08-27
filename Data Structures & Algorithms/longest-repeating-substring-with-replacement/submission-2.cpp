class Solution {
public:

    int maxfrequency(unordered_map<char, int>& freq)
    {
        int maxFreq = 0;
        for(auto it : freq)
        {
            maxFreq = max(maxFreq, it.second);
        }
        return maxFreq;
    }

    int characterReplacement(string s, int k) 
    {
        int size = s.length();
        int low = 0;
        int high = 0;
        int result = 0;
        int maxi = 0;
        unordered_map<char,int> freq;


        while(high < size)
        {
            freq[s[high]-'A']++;
            maxi = maxfrequency(freq);

            int length = high - low + 1;
            if((length - maxi) <=k)
            {
                result = max(result, length);
            }
            else
            {
                freq[s[low]-'A']--;
                if(freq[s[low]-'A'] == 0)
                    freq.erase(s[low]-'A');
                low++;
            }
            high++;
        }
        return result;
    }
};