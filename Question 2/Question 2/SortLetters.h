//
// SortLetters.h
//
//
// This file declares SortLetters Function.
//

#pragma once
#include <iostream>
#include <map>
using std::map;

//	2. Write a function that modifies an input string, sorting the letters according 
//		to a sort order defined by a second string.You may assume that every character in the 
//		input string also appears somewhere in the sort order string.Make your function as 
//		fast as possible for long input strings.
// 
//		void SortLetters(char* input, char* sortOrder)
//	Example:
//		char* inputStr = strdup(“trion world network”);
//		SortLetters(inputStr, “ oinewkrtdl”);
//
//	would modify the input string to “  oooinnewwkrrrttdl”.


namespace GameCompanyProjectName {
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// SortLetters Function Declaration
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


	// function gets error copied below when using SortLetters(inputStr, “ oinewkrtdl”); call because " onewkrtdl" is considered
	// to be a const.
	// error C2664: 'void GameCompanyProjectName::SortLetters(char *,char *)': cannot convert argument 2 from 'const char [12]' to 'char *'
	// To fix error the compiler gets stuck on, added const to defenition. 

	void SortLetters(char* input, const char* sortOrder);

} // End of GameCompanyProjectName
