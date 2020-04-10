#include <iostream>
using namespace std;
#define ll long long

int getIa(int a)
{
  if (a == 12)
    return 0;
  if (a == 3)
    return 1;
  if (a == 6)
    return 2;
  if (a == 9)
    return 3;
}

int getIb(char a)
{
  if (a == 'A')
    return 0;
  if (a == 'B')
    return 1;
  if (a == 'C')
    return 2;
  if (a == 'D')
    return 3;
}

void sort(int a[4])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = i + 1; j < 4; j++)
    {
      if (a[j] > a[i])
      {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

int main()
{
  int T;
  ll Tprofit = 0;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    int prevsum = -999999999;
    int ans[4];
    int temp[4];
    int sum;
    char *m = new char[N];
    int *t = new int[N];

    int mat[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    for (int i = 0; i < N; i++)
    {
      cin >> m[i];
      cin >> t[i];
      int j = getIb(m[i]);
      int k = getIa(t[i]);
      mat[j][k] += 1;
    }
    for (int i = 0; i < 4; i++)
    {
      ans[0] = mat[0][i];
      for (int j = 0; j < 4; j++)
      {
        if (i != j)
        {
          ans[1] = mat[1][j];
          for (int k = 0; k < 4; k++)
          {
            if (i != j && i != k && j != k)
            {
              ans[2] = mat[2][k];
              for (int l = 0; l < 4; l++)
              {
                if (i != j && j != k && k != l && i != k && i != l && j != l)
                {
                  sum = 0;
                  ans[3] = mat[3][l];
                  for (int s = 0; s < 4; s++)
                    temp[s] = ans[s];
                  sort(temp);
                  int T = 100;
                  for (int m = 0; m < 4; m++)
                  {
                    if (temp[m] == 0)
                    {
                      sum -= 100;
                    }
                    sum += temp[m] * T;
                    T -= 25;
                  }
                  if (sum > prevsum)
                  {
                    prevsum = sum;
                  }
                }
              }
            }
          }
        }
      }
    }
    cout << prevsum << endl;
    Tprofit += prevsum;
  }
  cout << Tprofit << "\n";
  cin >> Tprofit;
  return 0;
}