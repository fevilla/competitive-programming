#include <bits/stdc++.h>

#define MAX(a, b) ((a > b) ? return a : return b)

using namespace std;

int main()
{
  map<vector<int>, int> courses;
  vector<int> temp(5);
  int t, ans, maxi;

  string frosh;

  cin >> t;

  for (int p = 0; p < t; p++)
  {
    for (int i = 0; i < 5; i++)
      cin >> temp[i];
    sort(temp.begin(), temp.end());
    courses[temp]++;
  }

  maxi = 0, ans = 0;

  for (auto x : courses)
    maxi = max(maxi, x.second);

  for (auto x : courses)
    if (x.second == maxi)
      ans++;

  cout << ans * maxi << "\n";
  courses.clear();

  return 0;
}
