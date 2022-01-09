// Problem Link : https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int cw(string s, int pos, int n)
{
    if (dp[pos] > -1)
        return dp[pos] % 1000000007;
    if (pos == n)
        return dp[pos] = 1;
    if (s[pos] == '0')
        return dp[pos] = 0;
    int l = cw(s, pos + 1, n) % 1000000007;
    if (pos < n - 1)
    {
        int x = s[pos] - '0';
        x = x * 10 + (s[pos + 1] - '0');
        // cout<<x<<endl;
        if (x >= 10 && x <= 26)
            l = (l % 1000000007 + cw(s, pos + 2, n) % 1000000007) % 1000000007;
    }
    return dp[pos] = l % 1000000007;
}
int CountWays(string str)
{
    // Code here
    int n = str.size();
    memset(dp, -1, sizeof(dp));
    return cw(str, 0, n) % 1000000007;
}

int countDecodingDP(char *digits, int n)
{
    // A table to store results of subproblems
    int count[n + 1];
    count[0] = 1;
    count[1] = 1;
    // for base condition "01123" should return 0
    if (digits[0] == '0')
        return 0;
    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;

        // If the last digit is not 0,
        // then last digit must add to the number of words
        if (digits[i - 1] > '0')
            count[i] = count[i - 1];

        // If second last digit is smaller
        // than 2 and last digit is smaller than 7,
        // then last two digits form a valid character
        if (digits[i - 2] == '1' ||
            (digits[i - 2] == '2' && digits[i - 1] < '7'))
            count[i] += count[i - 2];
    }
    return count[n];
}

int CountWays(string str)
{
    if (str[0] == '0')
        return 0;
    int n = str.size();
    long long int mod = 1e9 + 7;
    vector<long long int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (str[i] == '0' and str[i - 1] > '2')
            return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (str[i - 1] > '0')
            dp[i] = dp[i - 1];
        if (str[i - 2] == '1' or (str[i - 2] == '2' and str[i - 1] < '7'))
            dp[i] += dp[i - 2];
        dp[i] %= mod;
    }
    return (int)dp[n];
}