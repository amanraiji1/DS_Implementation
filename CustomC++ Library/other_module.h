#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
1)	Number format  to String format (I --> one)
2)	String to number
3)	Day of Week

*/


string to_lowercase(string s){
	//given a string this function returns a modified string having all lowercase letters
	for(int i=0;s[i]!='\0';i++){
		char c = s[i];
		if(c >= 'A' && c <= 'Z')
			s[i] = s[i] + 32;
	}

	return s;
}

string to_uppercase(string s){
	//given a string this function returns a modified string having all uppercase letters
	for(int i=0;s[i]!='\0';i++){
		char c = s[i];
		if(c >= 'a' && c <= 'z')
			s[i] = s[i] - 32;
	}

	return s;
}


//methods to reverse a number and string

int getReverse(int number){
	int revNum = 0;
	while(number){
		revNum = revNum * 10 + number % 10;
		number /= 10;
	}
	return revNum;
}

string getReverse(string s){
	int i=0,j = s.length()-1;
	while(i<j){
		swap(s[i++],s[j--]);
	}

	return s;
}

//To check Palindrome for both number and strings

bool checkPalindrome(int num){
	int revNum = getReverse(num);
	return revNum == num;
}

bool checkPalindrome(string s){
	s = to_lowercase(s);
	int i=0,j=s.length()-1;
	while(i<j){
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}	
	return true;
}
