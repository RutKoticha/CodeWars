/**
 * @file C_Isamatdin_and_His_Magic_Wand.cpp
 * @author Rut Koticha
 * @date 2026-01-10
 */

#include <iostream>
#include <vector>

void Solve()
{
  int n;
  std::cin >> n;

  std::vector<int> numbers(n, 0);
  for (int& number : numbers)
    std::cin >> number;

  // Check for different parity
  bool differentParity = false;
  for (int i = 1; i < n; i++)
  {
    if ((numbers.at(0) & 1) != (numbers.at(i) & 1))
      differentParity = true;
  }

  if (differentParity)
    std::sort(numbers.begin(), numbers.end());

  for (int number : numbers)
    std::cout << number << " ";

  std::cout << std::endl;
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
