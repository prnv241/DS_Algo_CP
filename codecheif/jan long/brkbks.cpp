#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int S, a[3], b[3] = {0};
    cin >> S >> a[0] >> a[1] >> a[2];
    int curS = 0, cnt = 0;
    int k = 0;
    while (b[2] == 0)
    {
      curS = 0;
      if (b[0] == 0)
      {
        if (a[2] < a[0])
        {
          swap(a[0], a[2]);
        }
      }
      else if (b[0] != 0 && b[1] == 0)
      {
        if (a[2] < a[1])
        {
          swap(a[1], a[2]);
        }
      }
      while (b[k] == 0 && k < 3)
      {
        if (S >= curS + a[k])
        {
          b[k] = 1;
          curS += a[k];
          k++;
        }
        else
          break;
      }
      cnt++;
    }
    cout << cnt << endl;
  }
}