#include <iostream>
using namespace std;
#define ll long long

bool sort(ll a[], int N)
{
  bool chek = true;
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (a[j] > a[i])
      {
        if (a[j] % a[i] != 0)
        {
          chek = false;
        }
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  if (chek == true)
  {
    return true;
  }
  return false;
}

int findmin(ll csum[], ll P, int N)
{
  ll min = 9999999999;
  int minI = -1;
  for (int i = 0; i < N; i++)
  {
    if (csum[i] - P < min && csum[i] != -1)
    {
      min = csum[i] - P;
      minI = i;
    }
  }
  return minI;
}

int getI(ll temp[], ll a[], int k, int N)
{
  int v = temp[k];
  for (int i = 0; i < N; i++)
  {
    if (a[i] == v)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    ll N, P;
    int flag = 1;
    cin >> N >> P;
    ll a[N], temp[N], csum[N];
    ll adders[N][N];
    ll cadders[N] = {0};
    ll ans[N];
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        adders[i][j] = 0;
      }
    }
    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
      temp[i] = a[i];
      if (P % a[i] != 0)
      {
        flag = 0;
      }
    }
    bool chk = sort(temp, N);
    if (flag == 1 && chk)
    {
      cout << "NO";
    }
    else
    {
      cout << "YES"
           << " ";
      ll S = 0;
      for (int j = 0; j < N; j++)
      {
        while (S + temp[j] < P)
        {
          S += temp[j];
          cadders[j]++;
        }
        if (S + temp[j] > P)
        {
          csum[j] = temp[j] + S;
          for (int k = 0; k < N; k++)
          {
            adders[j][k] = cadders[k];
            if (j == k)
            {
              adders[j][k]++;
            }
          }
        }
        else
        {
          csum[j] = -1;
        }
      }
      int I = findmin(csum, P, N);
      for (int k = 0; k < N; k++)
      {
        int j = getI(temp, a, k, N);
        ans[j] = adders[I][k];
      }
      for (int l = 0; l < N; l++)
      {
        cout << ans[l] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
