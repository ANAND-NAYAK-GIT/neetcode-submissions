class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else 
            {
                if (st.empty())
                    return false;
                else 
                {
                    char opn = st.top();
                    char cls = s[i];
                    if (opn == '(' && cls == ')' || opn == '{' && cls == '}' ||
                        opn == '[' && cls == ']')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        if(st.empty())
            return true;
        else 
            return false;
    }
};