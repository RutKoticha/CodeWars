/**
 * @file B_Optimal_Shifts.cpp
 * @author Rut Koticha
 * @date 2026-01-08
 */

#include <iostream>
#include <string>

int IntValue(char integer)
{
  return integer - '0';
}

void Solve()
{
  int n, operations = 0;
  std::cin >> n;

  std::string number;
  std::cin >> number;

  if (n == 1)
  {
    std::cout << 0 << std::endl;
    return;
  }

  int i = 0;

  // Count leading 0s
  while (i < n && !IntValue(number[i]))
  {
    operations++;
    i++;
  }

  // Count trailing 0s
  int j = n - 1;
  while (j > i && !IntValue(number[j]))
  {
    operations++;
    j--;
  }
  // Count max consicutive 0s
  int currentCount = 0, maxCount = 0;
  while (i <= j)
  {
    if (IntValue(number[i]))
      currentCount = 0;
    else
      currentCount++;

    maxCount = std::max(currentCount, maxCount);
    i++;
  }

  operations = std::max(maxCount, operations);

  std::cout << operations << std::endl;
}

int main(int argc, char* argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tests{};
  std::cin >> tests;

  while (tests--)
    Solve();
  return 0;
}
