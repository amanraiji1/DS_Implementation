#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
Math Module

14)	Number of Divisors (HARD)
16)	Complex Numbers
17) Combination nCr


*/


//leap year must be divisible by 4 and if it is a century it must be divisible by 400.
bool isLeap(int year){
	if(year % 4 == 0){
		if(year % 100 == 0){
			return year % 400 == 0;
		}	
		else{
			return true;
		}
	}
	else{
		return false;
	}
}

//counts the number of set bits
int countSetBits(int n){
	int count = 0;

	while(n){
		count++;
		n = (n & (n-1));
	}

	return count;
}

//checks odd or even
int checkOdd(int num){
	return (num&1) != 0;
}

int checkEven(int num){
	return (num&1) == 0;
}

//covert a number to base like binary,octal,hexadecimal....
string convertToBase(int num,int base){
	string newNum = "";	
	
	while(num){
		int temp = num%base;
		if(base == 16){
			if(temp >= 10){
				int t = 'A' + (temp-10);
				newNum = (char)t + newNum;
			}
			else{
				newNum = to_string(temp) + newNum;	
			}
		}
		else{
			newNum = to_string(temp) + newNum;
		}
		num /= base;
	}

	return newNum;
}

bool isPrime(ll n){
	if(n <= 1)
		return false;
	if(n == 2 || n == 3)
		return true;
	if(n%2 == 0 || n%3 == 0)
		return false;
	if(n < 9)
		return true;

	for(int i=5;i*i <= n;i += 6)
		if(n%i == 0 || n%(i+2) == 0)
			return false;

	return true;
}

//returns a vector of prime numbers upto n
vector<int> allPrimeUptoN(int N){
	vector<bool> arr(N+1);
	for(int i=1;i<=N;i++){
		arr[i] = true;
	}

	arr[0] = arr[1] = 0;
	for(int i=2;i<=N;i++){
		if(arr[i] == true){
			for(int j=i+i;j<=N;j += i){
				arr[j] = false;
			}
		}
	}
	vector<int> ans;
	for(int i=1;i<=N;i++){
		if(arr[i] == true)
			ans.push_back(i);
	}

	return ans;
}


//calculates x to the power n
double power(ll x,ll n){
	if(n < 0)
		return 1.0/power(x,-n);
	if(n == 0)
		return 1;
	ll temp = power(x,n/2);
	ll ans = temp * temp;
	if(n%2 != 0){
		ans *= x;
	}
	return ans;
}

ll factorial(int n){
	ll res = 1;
	for(int i=2;i<=n;i++){
		res *= i;
	}

	return res;
}

//Fibonacci Series and nth term
vector<int> fibonacciUptoN(int n){
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp;
}

int Nthfibonacci(int n){
	vector<int> fib = fibonacciUptoN(n);
	return fib[n-1];
}

//HCF LCM
int gcd(int m,int n){
	if(n == 0)
		return m;
	return gcd(n,m%n);
}

int lcm(int m,int n){
	return (m*n)/gcd(m,n);
}

int lcm(vector<int> arr){
	int lcmAns = 1;
	for(int i=0;i<arr.size();i++)
		lcmAns = lcm(lcmAns,arr[i]);
	return lcmAns;
}

int gcd(vector<int> arr){
	int gcdAns = 0;
	for(int i=0;i<arr.size();i++)
		gcdAns = gcd(gcdAns,arr[i]);
	return gcdAns;
}

//string to int and vice versa
string intToString(ll n){
	string res = "";
	while(n){
		char c = (n%10 + '0');
		res = c + res;
		n /= 10;
	}
	return res;
}

int stringToInt(string n){
	int res = 0;
	int size = n.length();
	int maxPlace = power(10,(size-1));
	for(int i=0;i<size;i++){
		int c = n[i] - '0';
		res += c * maxPlace;
		maxPlace /= 10;
	}
	return res;
}
