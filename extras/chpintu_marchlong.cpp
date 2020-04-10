#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll findmin(ll c[], ll chk[], ll M)
{
  ll min = 9999999999999;
  for (ll i = 0; i < M; i++)
  {
    if (c[i] < min && chk[i] == 1)
    {
      min = c[i];
    }
  }
  if (min == 9999999999999)
    return 0;
  return min;
}

int main()
{
  ll T;
  cin >> T;
  while (T--)
  {
    ll N, M;
    cin >> N >> M;
    ll a[N], b[N];
    ll c[M] = {0};
    ll chk[M] = {0};
    for (ll i = 0; i < N; i++)
    {
      cin >> a[i];
    }
    for (ll i = 0; i < N; i++)
    {
      cin >> b[i];
    }
    for (ll i = 0; i < N; i++)
    {
      c[a[i] - 1] = c[a[i] - 1] + b[i];
      chk[a[i] - 1] = 1;
    }
    ll min = findmin(c, chk, M);
    cout << min << endl;
  }
  return 0;
}
