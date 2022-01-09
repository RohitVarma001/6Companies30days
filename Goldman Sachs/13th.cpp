#include <bits/stdc++.h>
using namespace std;
string decodedString(string s)
{
    // code here
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ']')
        {
            string t = "";
            while (!st.empty() && st.top() != '[')
            {
                t = st.top() + t;
                st.pop();
            }
            st.pop();
            string num;
            // remove the digits from the stack
            while (!st.empty() && isdigit(st.top()))
            {
                num = st.top() + num;
                st.pop();
            }
            int number = stoi(num);
            string a = "";
            for (int j = 0; j < number; j++)
                a += t;
            for (auto x : a)
                st.push(x);
        }
        else
            st.push(s[i]);
    }
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}