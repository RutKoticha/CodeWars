/**
 * @file B_Hourglass.cpp
 * @author Rut Koticha
 * @date 2026-01-14
 */

#include <iostream>
#include <print>

void Solve()
{
  int hourGlassTime, flipMinutes, leaveIn;
  std::cin >> hourGlassTime >> flipMinutes >> leaveIn;

  int totalFlips = leaveIn / flipMinutes;
  int lastFlipToLeaving = leaveIn - (totalFlips * flipMinutes);

  int remainingTime;

  if (totalFlips & 1)
    remainingTime = std::min(hourGlassTime, flipMinutes) - lastFlipToLeaving;
  else
    remainingTime = hourGlassTime - lastFlipToLeaving;

  std::cout << std::max(remainingTime, 0) << std::endl;
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
