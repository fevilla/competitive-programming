#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main()
{
  int n, m;
  while (cin >> n >> m, n, m)
  {
    int ans, maxi, mini;

    if (n < m)
    {
      mini = n;
      maxi = m;
    }
    else
    {
      mini = m;
      maxi = n;
    }

    if (mini == 1)
      ans = maxi;
    else if (mini == 2)
      ans = (maxi / 4) * 4 + ((maxi % 4 >= 2) ? 4 : ((maxi % 4) * 2));
    else
      ans = (n * m + 1) / 2;

    cout << ans << " knights may be placed on a " << n << " row " << m << " column board.\n";
  }
  return 0;
}
