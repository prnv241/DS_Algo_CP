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
    ll X, K, count;
    count = 0;
    cin >> X >> K;
    for (ll i = 2; i <= sqrt(X); i++)
    {
      if (X % i == 0)
      {
        while (X % i == 0)
        {
          count++;
          X = X / i;
        }
      }
    }
    if (X != 1)
      count++;
    if (K <= count)
    {
      cout << "1" << endl;
    }
    else
    {
      cout << "0" << endl;
    }
  }
  return 0;
}