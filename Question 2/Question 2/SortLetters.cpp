//
// SortLetters.cpp
//
//
// This file is the implementation of SortLetters Function.
//

#include "SortLetters.h"

namespace GameCompanyProjectName {


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// SortLetters Function Implementation
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	void SortLetters(char* input, const char* sortOrder)
	{
		// Create a map that will hold our letter (char) as the key, and how many
		// times (int) it appears.
		// Example: 
		//  input = "ABCBB"
		//  lettersCount : {{ 'C', 1 }, { 'B', 3 }, { 'A', 1 }}

		map<char, int> lettersCount;

		// Start Loop for input string
		for (char* iChr = input; *iChr; iChr++) {

			// Search for Current Char in arrary.
			// returns an pointer to a map<char, int>
			auto itResult = lettersCount.find(*iChr);

			// If Char isn't in map,
			if (itResult == lettersCount.end()) {
				// Add Char into map, with starting count of 1
				lettersCount.emplace(*iChr, 1);
			}
			else {
				// Char exists, increase count by 1
				lettersCount[*iChr] = itResult->second + 1;
			}
		}

		// Pointer for start of input string
		char* ptrInputPos = input;

		// Begin loop to rearrange input string
		// sortOrder = "ABC"
		// lettersCount = {{ 'C', 1 }, { 'B', 3 }, { 'A', 1 }}
		// Loop: A x 1, B x 3, C x 1
		// input: ABBBC
		for (const char* currentSortChar = sortOrder; *currentSortChar; currentSortChar++) {

			// Change Letter to current sortOrder letter by
			// how many times it was counted in string.
			for (int i = lettersCount[*currentSortChar]; i > 0; i--) {
				// Move current sortOrder letter into current input position
				*ptrInputPos = *currentSortChar;
				// Move to next character position for input
				ptrInputPos++;
			}

		}

	} // End of SortLetters

} // End of GameCompanyProjectName