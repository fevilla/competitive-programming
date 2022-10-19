#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int order[101];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  while (cin >> n, n)
  {
    int a;

    f(i, 0, 101)
    {
      order[i] = 0;
    }
    int maxi = 0;
    f(i, 0, n)
    {
      cin >> a;
      order[a]++;
      maxi = max(maxi, a);
    }

    string es = "";
    f(i, 0, maxi + 1)
    {
      while (order[i])
      {
        cout << es << i;
        order[i]--;
        es = " ";
      }
    }
    cout << "\n";
  }
  return 0;
}