#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N, M;
    cin >> N >> M;
    int arr[N][M];
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        cin >> arr[i][j];
      }
    }
    int count = N * M;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        int p = 1;
        while ((i - p >= 0 && j + p < M) && (j - p >= 0 && i + p < N))
        {
          if ((arr[i + p][j] == arr[i - p][j]) && (arr[i][j + p] == arr[i][j - p]))
          {
            count++;
            p++;
          }
          else
            break;
        }
      }
    }
    cout << count << endl;
  }
}