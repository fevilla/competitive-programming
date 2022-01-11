#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;
string signs[12] = {"Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};

int vals[12] = {21, 20, 21, 21, 22, 22, 23, 22, 24, 14, 13, 23};

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sumDays[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, day, month, year;
  cin >> n;
  string s;
  while (n--)
  {
    cin >> s;
    day = (s[0] - '0') * 10 + (s[1] - '0');
    month = (s[2] - '0') * 10 + (s[3] - '0');
    year = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
    ;

    int tot = (days[month - 1] - day) + ((days[month + 8] - days[month - 1]));

    cout << tot << "\n";
  }
  return 0;
}