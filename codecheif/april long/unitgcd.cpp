#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++)

    // marking smallest prime factor for every
    // number to be itself.
    spf[i] = i;

  // separately marking spf for every even
  // number as 2
  for (int i = 4; i < MAXN; i += 2)
    spf[i] = 2;

  for (int i = 3; i * i < MAXN; i++)
  {
    // checking if i is prime
    if (spf[i] == i)
    {
      // marking SPF for all numbers divisible by i
      for (int j = i * i; j < MAXN; j += i)

        // marking spf[j] if it is not
        // previously marked
        if (spf[j] == j)
          spf[j] = i;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    int arr[N + 1][20];
    memset(arr, 0, sizeof(arr));
    int index[168];
    int check[N + 1];
    memset(check, 0, sizeof(check));
    vector<int> primes;
    primes.push_back(1);
    for (int i = 2; i <= N; i++)
    {
      arr[i][0] = i;
      int count = 1;
      int X = i;
      while (X != 1)
      {
        arr[i][count] = spf[X];
        count++;
        X = X / spf[X];
      }
      if (count == 2)
      {
        primes.push_back(i);
        int temp = 1;
        check[i] = temp;
      }
    }
    int sol[N / 2 + 1][200];
    memset(sol, 0, sizeof(sol));
    int jindex = 0;
    int iindex = 0;
    for (int p = 2; p <= N; p++)
    {
      if (check[p] == 0)
      {
        memset(index, 0, sizeof(index));
        for (int i = p; i <= N; i++)
        {
          if (check[i] == 0)
          {
            int flag = 0;
            for (int j = 0; j < 168 && index[j] != 0; j++)
            {
              for (int k = 1; k < 20 && arr[i][k] != 0; k++)
              {
                if (arr[i][k] == index[j])
                {
                  flag = 1;
                  break;
                }
              }
              if (flag == 1)
                break;
            }
            if (flag == 0)
            {
              check[i] = 1;
              sol[iindex][jindex] = arr[i][0];
              jindex++;
              for (int k = 1; k < 20 && arr[i][k] != 0; k++)
              {
                int flag2 = 0;
                int j;
                for (j = 0; j < 168 && index[j] != 0; j++)
                {
                  if (arr[i][k] == index[j])
                  {
                    flag2 = 1;
                    break;
                  }
                }
                if (flag2 == 0)
                {
                  index[j] = arr[i][k];
                }
              }
            }
          }
        }
        jindex = 0;
        iindex++;
      }
    }
    cout << iindex + 1 << endl;
    for (auto i = primes.begin(); i < primes.end(); i++)
      cout << *i << " ";
    cout << endl;
    for (int i = 0; i < 200 && sol[i][0] != 0; i++)
    {
      for (int j = 0; j < 200 && sol[i][j] != 0; j++)
      {
        cout << sol[i][j] << " ";
      }
      cout << endl;
    }
  }
}
