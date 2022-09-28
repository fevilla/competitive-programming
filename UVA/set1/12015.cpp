#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int prior[10];

  string urls[10];

  int cases, ans;

  cin >> cases;
  f(j, 0, cases)
  {
    ans = 0;
    f(i, 0, 10)
    {
      cin >> urls[i] >> prior[i];
      ans = max(ans, prior[i]);
    }

    cout << "Case #" << j + 1 << ":\n";
    f(i, 0, 10)
    {
      if (prior[i] == ans)
        cout << urls[i] << "\n";
    }
  }

  return 0;
}