//
// AllDigitsUnique.cpp
//
//
// This file is the implementation of AllDigitsUnique Function.
//

#include "AllDigitsUnique.h"

namespace GameCompanyProjectName {

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// AllDigitsUnique Function Implementation
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	bool AllDigitsUnique(unsigned int value) {

		// Create an Array to remember for each digit for 0-9 and set it to false
		// Array Address:	[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 6 ][ 7 ][ 8 ][ 9 ]
		// Default Value:	[ F ][ F ][ F ][ F ][ F ][ F ][ F ][ F ][ F ][ F ]
		bool seenDigits[10] = { false };

		// Start a loop to extract each digit and then shift decmal place by 1 digit
		// Since value is an int, decmal place will be dropped.
		// Example:  Loop 1 ( 564 ) Loop 2 ( 56.4 -> Int(56) ) Loop 3 ( 5.64 Int(5) ) End Loop ( 0.564 -> Int(0) )
		while (value > 0) {

			// Use Mod 10 to find last digit in number Ex: 564 mod 10 = 4, 56 mod 10 = 6, 5 mod 10 = 5
			int lastDigit = value % 10;

			// Look at array of digits and see if last digit has been seen
			// If true, then exit function because digit repeats in number and makes number not unique
			// if false, then set that digit as seen by setting value to true
			// example:
			// Last digit is 4:	[   ][   ][   ][   ][ 4 ][   ][   ][   ][   ][   ]
			// Array Address:	[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 6 ][ 7 ][ 8 ][ 9 ]
			// Current Value:	[ F ][ F ][ F ][ F ][ F ][ F ][ F ][ F ][ F ][ F ]

			if (seenDigits[lastDigit]) {
				// if value is true, that means digit has been seen already, so exit function with false value. All Digits are not Unique.
				return false;
			}
			else {
				// If value is still default value of false, then toggle it to true and as being seen.
				seenDigits[lastDigit] = true;
			}

			// Divide value by 10 to decrease value and shift one decmal place.
			value /= 10;
		}

		// Loop has finished without seeing same number twice, so exit function as true, it is a unique number
		return true;

	} // End of AllDigitsUnique

} // End of GameCompanyProjectName