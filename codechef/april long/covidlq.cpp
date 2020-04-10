#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    int a[N];
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
      if (a[i] == 1)
      {
        int num = 0;
        while (i < N && num < 5)
        {
          i++;
          if (a[i] == 1)
          {
            flag = 1;
            break;
          }
          else
          {
            num++;
          }
        }
        if (flag == 1)
        {
          cout << "NO" << endl;
          break;
        }
      }
    }
    if (flag == 0)
    {
      cout << "YES" << endl;
    }
  }
  return 0;
}
