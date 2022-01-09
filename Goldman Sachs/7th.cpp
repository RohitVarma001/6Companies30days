// Problem Link : https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/

#include <bits/stdc++.h>
using namespace std;

int distributeCircle(int m, int n, int k)
{
    int x = (m + k - 1) % n;
    if (x == 0)
        return n;
    return x;
}

int lastPosition(int n, int m, int k)
{
    // n - k + 1 is number of positions
    // before we reach beginning of circle
    // If m is less than this value, then
    // we can simply return (m-1)th position
    if (m <= n - k + 1)
        return m + k - 1;

    // Let us compute remaining items before
    // we reach beginning.
    m = m - (n - k + 1);

    // We compute m % n to skip all complete
    // rounds. If we reach end, we return n
    // else we return m % n
    return (m % n == 0) ? n : (m % n);
}

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    if (m > n)
        m = m % n;
    if (m + k > n)
        cout << m + k - n << endl;
    else
        cout << m + k - 1 << endl;

    return 0;
}