#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum < target)
        return 0;
    int l = 0, mn = INT_MAX;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        while (sum >= target)
        {
            mn = min(mn, i - l + 1);
            sum -= nums[l++];
        }
    }
    return mn;
}