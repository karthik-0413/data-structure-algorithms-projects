#ifndef _BINARY_SEARCH_HPP
#define _BINARY_SEARCH_HPP

#include <vector>

// BINARY SEARCH LOOKS FOR A TARGET IN A SORTED (ASCENDING) VECTOR.
// PRECONDITION: THE VECTOR MUST ALREADY BE SORTED. RESULTS ON UNSORTED INPUT ARE UNSPECIFIED.
// STEPS:
// 1. LOOK AT THE MIDDLE ELEMENT OF THE CURRENT RANGE
// 2. IF IT EQUALS THE TARGET, RETURN ITS INDEX
// 3. IF THE TARGET IS SMALLER, SEARCH THE LEFT HALF; OTHERWISE SEARCH THE RIGHT HALF
// 4. IF THE RANGE BECOMES EMPTY, THE TARGET IS NOT PRESENT, SO RETURN -1

template<typename T> int binarySearch(const std::vector<T>& sortedValues, const T& target)
{
	int low = 0;
	int high = static_cast<int>(sortedValues.size()) - 1;

	while (low <= high)
	{
		// Computed this way to avoid overflow of (low + high)
		int mid = low + (high - low) / 2;

		if (sortedValues[mid] == target)
		{
			return mid;
		}
		else if (target < sortedValues[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	// Range is empty, so the target is not in the vector
	return -1;
}

#endif
