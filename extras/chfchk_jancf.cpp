#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, maxJ = 2147483647;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
      if (arr[i] < maxJ)
        maxJ = arr[i];
    }
    cout << maxJ << endl;
  }
  return 0;
}
