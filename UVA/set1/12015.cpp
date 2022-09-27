#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int main()
{
  int cases, a, b;

  scanf("%d", &cases);

  f(i, 0, cases)
  {
    scanf("%d %d", &a, &b);
    if (a < b)
      cout << "<\n";
    else if (a > b)
      cout << ">\n";
    else
      cout << "=\n";
  }

  return 0;
}