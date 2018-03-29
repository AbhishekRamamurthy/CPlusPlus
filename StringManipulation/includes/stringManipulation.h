/*
 * stringMainpulation.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: abhishek
 */

#include<iostream>
#include <algorithm>
#include<map>

/*
 * sort the given string and check if
 * i and i+1 are not same for uniqueness
 */
bool Unique_Chars(std::string str) {

	std::sort(str.begin(),str.end());
	for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
		char ch = *it;
		++it;
		if(ch == *it) {
			return false;
		}
	}
	return true;
}

/*
 * Applicable only for ASCII
 * ASCII uses 7 bits for representation
 * by setting the index of the character and check if the bit is already
 * set we can justify if character was already present
 */
bool Unique_Chars_Bool(std::string str) {

	int index = 0;
	std::transform(str.begin(),str.end(),str.begin(),::tolower);
	for(std::string::iterator it = str.begin();it != str.end(); ++it) {

		int temp = *it - 'a';
		if(index & ( 1 << temp)) {
			return false;
		}
		index |= (1 << temp);
	}
	return true;
}

/*
 * Initial check if two strings of same length
 * if yes sort the strings and check if they are same
 * at each position.
 */
bool Permutation(std::string str1, std::string str2) {

	if(str1.length() != str2.length())
		return false;

	std::sort(str1.begin(),str1.end());
	std::sort(str2.begin(),str2.end());

	for(unsigned int i=0; i<str1.length(); i++) {

		if(str1[i] != str2[i])
			return false;
	}
	return true;
}

/*
 * similar to permuation2, using a separate hash structure
 * to keep track of character count if same return true
 */
bool Permutation2(std::string str1, std::string str2) {

	std::map<char,int> ch_count;

	if(str1.length() != str2.length())
		return false;

	for(std::string::iterator it = str1.begin(); it != str1.end(); ++it) {

		ch_count[*it]++;
	}

	for(std::string::iterator it = str2.begin(); it != str2.end(); ++it) {

		if(ch_count.count(*it) &&  ch_count[*it] > 0) {
			ch_count[*it]--;
		} else {
			return false;
		}
	}
	return true;
}

/*
 * URLify a given string
 * replace spaces with %20, when true length is known
 * break creation of new string at string length
 */

std::string String_Replace(std::string str, int len) {

	std::string result;
	int count =0;
	for(unsigned int i = 0; i < str.length(); i++) {

		if(str[i] == ' ') {
			result += "%20";
		} else {
			result += str[i];
		}
		if(count == len)
			break;
		count++;
	}
	str = result;
	return str;
}

/*
 * Check the character count, for strings
 * with odd length, there should be only one odd count
 * if we have even length string there should be no odd length
 */

bool Permutation_Palindrome(std::string str) {

	std::map<char,int> ch_count;
	unsigned int odd_count =0;
	for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
		ch_count[*it]++;
	}

	for(std::map<char,int>::iterator it = ch_count.begin(); it != ch_count.end(); ++it) {
		if(it->second == 1)
			odd_count++;
	}
	return odd_count <= 1;
}

/*
 * check if a given string is one edit away
 * i.e, one replace or one insert
 */

bool Edit(std::string big, std::string small) {
	unsigned int index1 =0, index2=0;
	bool edit;
	while((index1 < big.length()) && (index2 <small.length())) {

		if(big[index1] != small[index2]) {
			if(edit == true)
				return false;
			edit = true;
			if(big.length() == small.length())
				index1++;
		} else {
			index1++;
		}
		index2++;
	}
	return true;
}

bool One_Edit(std::string str1, std::string str2) {

	if(abs(str1.length() - str2.length()) > 1)
		return false;
	if(str1.length() > str2.length())
		return Edit(str1,str2);
	else
		return Edit(str2,str1);
}


/*
 * String compressiong
 * aaabbbbcccc
 * a3b4c3, if original string is less than compressed string
 */

std::string Compress_String(std::string str) {

	if(str.empty())
		return str;

	std::string temp;
	std::sort(str.begin(),str.end());
	unsigned int consecutive = 0;
	for(unsigned int i=1; i<str.length(); i++) {
		if(str[i] == str[i-1]) consecutive++;
		else {
			temp += str[i-1] + std::to_string(consecutive+1);
			consecutive =0;
		}
	}
	temp += str[str.length()-1] + std::to_string(consecutive+1);

	return str.length() > temp.length() ? str=temp : str;
}

/*
 * rotate a give string
 */

std::string Rotate_String(std::string str,int rotate) {

	std::rotate(str.begin(),str.begin()+rotate,str.end());
	return str;
}
