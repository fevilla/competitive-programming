#include <iostream>
using namespace std;
int main()
{

  bool A[10000];

  int t, n, temp, a1, a2, rest;
  bool ok;

  while (cin >> n)
  {

    cin >> a1;
    for (int i = 0; i < n + 1; i++)
      A[i] = 0;

    temp = n - 1, ok = 1;

    while (temp--)
    {
      cin >> a2;
      rest = abs(a2 - a1);
      if (!ok)
        continue;

      if (rest > 0 && rest < n && !A[rest])
        A[rest] = 1;
      else
        ok = 0;
      a1 = a2;
    }

    if (ok)
      cout << "Jolly\n";
    else
      cout << "Not jolly\n";
  }

  return 0;
}
