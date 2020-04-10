#include <iostream>
#include <cmath>
using namespace std;

unsigned long long POW(int a, int b)
{
  unsigned long long A = 1;
  while (b--)
  {
    A = A * a;
  }
  return A;
}

int main()
{
  int T;
  cin >> T;
  int V, N;
  long long A, B, C, D, E;
  unsigned long long S, P;
  while (T--)
  {
    cin >> N;
    cin >> A;
    P = POW(10, N);
    S = (2 * P) + A;
    cout << S << endl;
    cin >> B;
    C = P - B;
    cout << C << endl;
    cin >> D;
    E = P - D;
    cout << E << endl;
    cin >> V;
    if (V == -1)
      break;
  }
}