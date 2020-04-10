#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    long long a[N], b[N];
    long long msum = 0;
    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
    }
    for (int j = 0; j < N; j++)
    {
      cin >> b[j];
    }
    sort(a, a + N);
    sort(b, b + N);
    for (int k = 0; k < N; k++)
    {
      if (a[k] < b[k])
      {
        msum += a[k];
      }
      else
      {
        msum += b[k];
      }
    }
    cout << msum << "\n";
  }
  return 0;
}
