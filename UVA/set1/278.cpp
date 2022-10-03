#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int cases, r, c;
  char op;

  cin >> cases;
  while (cases--)
  {
    cin >> op >> r >> c;
    switch (op)
    {
    case 'k':
      cout << ((r * c + 1) / 2) << "\n";
      break;
    case 'K':
      cout << (((r + 1) / 2) * ((c + 1) / 2)) << "\n";
      break;
    default:
      cout << min(r, c) << "\n";
      break;
    }
  }
  return 0;
}