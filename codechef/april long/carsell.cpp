#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    ll a[N];
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
    }
    sort(a, a + N, greater<int>());
    for (int j = 0; j < N; j++)
    {
      if ((a[j] - j) > 0)
      {
        sum += a[j] - j;
      }
    }
    int res = sum % 1000000007;
    cout << res << endl;
  }
  return 0;
}
