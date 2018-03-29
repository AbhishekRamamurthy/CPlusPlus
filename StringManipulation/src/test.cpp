/*
 * test.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: abhishek
 */

#include <iostream>
#include "../includes/stringManipulation.h"
using namespace std;


int main() {

	string str = "abca";
	bool result = Unique_Chars(str);
	cout << "Result From Unique_Chars = " << result << endl;
	result = Unique_Chars_Bool(str);
	cout << "Result From Unique_Chars_Bool = " << result << endl;
	string str2 = "bcaa";
	result = Permutation(str,str2);
	cout << "Result From Permutation = " << result << endl;
	string str3 = "bcaz";
	result = Permutation2(str,str3);
	cout << "Result From Permutation2 = " << result << endl;
	std::string str4 = "Mr John Smith    ";
	std::string replaced_string = String_Replace(str4,13);
	cout << "Result From String_Replace = " << replaced_string << endl;
	std::string str5 = "malayalam";
	result = Permutation_Palindrome(str5);
	cout << "Result From Permutation_Palindrome = " << result << endl;
	std::string str6 = "pale";
	std::string str7 = "bale";//try "bake"
	result = One_Edit(str6,str7);
	cout << "Result From One_Edit = " << result << endl;
	std::string str8 = "aaabbbbcccddd"; //try aa
	std::string result_string = Compress_String(str8);
	cout << "Result From Compress_String = " << result_string << endl;
	cout << "Result From Rotate_String = " << Rotate_String(str8,4) << endl; // to rotate right , pass str.length()-4
	return 0;
}
