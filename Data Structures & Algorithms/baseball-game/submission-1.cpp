class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        int size = operations.size();
        stack<string> st;

        for(int i=0; i<size; i++)
        {
            if(operations[i] == "+")
            {
                int first = stoi(st.top());
                st.pop();
                int second = stoi(st.top());
                st.push(to_string(first));
                st.push(to_string(first+second));
            }
            else if(operations[i] == "D")
            {
                int top = stoi(st.top());
                st.push(to_string(top*2));
            }
            else if(operations[i] == "C")
            {
                st.pop();
            }
            else
            {
                st.push(operations[i]);
            }
        }

        int res = 0;
        while(!st.empty())
        {
                int top = stoi(st.top());
                res = res + top;
                st.pop();
        }

        return res;
    }
};