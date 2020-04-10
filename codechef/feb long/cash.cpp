#include <iostream>
using namespace std;
#define ll long long

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    ll n, k, r, minr;
    r = minr = 999999999999;
    cin >> n >> k;
    ll a[n], maxrem[n], minrem[n], minadd[n] = {0};
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (i != 0)
      {
        minrem[i] = minrem[i - 1] + (a[i] % k);
        maxrem[i] = maxrem[i - 1] + a[i];
        for (int j = 0; j < i; j++)
        {
          if (a[i] % k)
          {
            minadd[j] = minadd[j] + (k - (a[i] % k));
          }
        }
      }
      else
      {
        minrem[i] = a[i] % k;
        maxrem[i] = a[i];
      }
    }
    for (int c = 0; c < n; c++)
    {
      if (maxrem[c] > minadd[c])
      {
        if (minrem[c] < minadd[c])
        {
          while (minadd[c] > minrem[c])
          {
            minrem[c] += k;
          }
          r = minrem[c] - minadd[c];
        }
        else if (minrem[c] > minadd[c])
        {
          r = (minrem[c] - minadd[c]) % k;
        }
        else if (minrem[c] == minadd[c])
        {
          r = 0;
        }
        if (minr > r)
        {
          minr = r;
        }
      }
    }
    cout << minr << endl;
  }
  return 0;
}
