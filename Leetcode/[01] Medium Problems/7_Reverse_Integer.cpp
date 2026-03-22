/**
 * @file 7_Reverse_Integer.cpp
 * @author Rut Koticha
 * @date 2026-02-02
 */

#include <cstdint>
#include <climits>
#include <cmath>

class Solution {
public:
	int reverse(int number)
	{
		const int MAX_REVERSED = INT_MAX / 10;
		const int MIN_REVERSED = INT_MIN / 10;
		const int MAX_REMAINDER = INT_MAX % 10;
		const int MIN_REMAINDER = INT_MIN % 10;

		int reversed = 0;

		while (number)
		{
			int remainder = number % 10;
			number /= 10;

			bool isReversedAtMin = reversed == MIN_REVERSED;
			bool isReversedAtMax = reversed == MAX_REVERSED;
			bool isReversedGreater = reversed > MAX_REVERSED;
			bool isReversedSmaller = reversed < MIN_REVERSED;
			bool isRemainderGreater = remainder >= MAX_REMAINDER;
			bool isRemainderSmaller = remainder <= MIN_REMAINDER;

			// If adding 0 would make them out of range
			if (isReversedGreater || isReversedSmaller)
				return 0;

			// If adding the remainder make it go positively out
			if (isReversedAtMax && isRemainderGreater)
				return 0;

			// If adding the remainder make it go negatively out
			if (isReversedAtMin && isRemainderSmaller)
				return 0;

			reversed = (reversed * 10) + remainder;
		}

		return reversed;
	}
};
