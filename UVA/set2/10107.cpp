#include <bits/stdc++.h>

using namespace std;

multiset<int> arr;

int main()
{
  int x, ident = 0, N = 0;
  cin >> x;
  arr.insert(x);
  auto it = arr.begin();
  cout << *it << "\n";
  ident = 1;

  N++;
  while (cin >> x)
  {
    arr.insert(x);
    cout << *it << "\n";
    N++;

    if (x < *it)
      ++ident;

    // 1 3(it) 4
    int parse = (N + 1) / 2;
    while (ident > parse)
    {
      ident--;
      it--;
    }
    while (ident < parse)
    {
      ident++;
      it++;
    }

    if (!N % 2)
    {
      auto aux = it;
      cout << (*(++aux) + *it) / 2 << "\n";
    }
    else
    {
      cout << *it << "\n";
    }
  }
  return 0;
}

// 1(it) 3

// 1 3
// 1 3