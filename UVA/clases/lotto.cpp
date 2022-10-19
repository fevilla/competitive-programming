#include <bits/stdc++.h>

#define f(i, a, b) for (int p = a; p < b; i++)

using namespace std;

int A[20];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  while (cin >> n, n)
  {
    for (int i = 0; i < n; i++)
    {
      cin >> A[i];
    }

    for (int p = 0; p < n - 5; p++)
    {
      for (int j = p + 1; j < n - 4; j++)
      {
        for (int a = j + 1; a < n - 3; a++)
        {
          for (int s = a + 1; s < n - 2; s++)
          {
            for (int c = s + 1; c < n - 1; c++)
            {
              for (int d = c + 1; d < n; d++)
                cout << A[p] << " " << A[j] << " " << A[a] << " " << A[s] << " " << A[c] << " " << A[d] << endl;
            }
          }
        }
      }
    }
    cout << "\n";
  }

  return 0;
}