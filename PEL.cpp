//Project Euler Library
//Author: Arne

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

template <typename T>
bool isPalindrome (T n)
{
	stringstream ss;
	ss << n;
	string str = ss.str ();
	
	string str2 (str);
	reverse (str2.begin(), str2.end());
	
	return (str == str2);
}

template <typename T>
bool isPrime (T n)
{
	bool factorFound = false;
	
	for (int i=2; i<=ceil(sqrt(n)+1); i++) 
	{
		if (n%i == 0) 
		{
			factorFound = true;
			break;
		}
	}
	
	if ((!factorFound && n != 1) || n == 2 || n == 3)
		return true;
	else 
		return false;
}

template <typename T>
T factorial (T n)
{
	T product = 1;
	
	for (T j=1; j<= n; j += 1)
		product *= j;
		
	return product; 	   	       
}

template <typename T>
T fibI (T n)
{
	T i = 1; 
	T j = 0;
	
	for (T k=1; k<=n; k += 1)
	{
		j = i + j;
		i = j - i;
	}
	
	return j;	      
}

template <typename T>
T power (T base, int n)
{	 
	T product = base;
	
	for (int i=0; i<n-1; i++)
		product *= base;
		
	return (n == 0) ? 1 : product;
}

template <typename T>
T getSumDigits (T n)
{
	T sum = 0;
	
	while (n > 0)
	{
		sum += n % 10;
		n /= 10; 
	}
	
	return sum;
}

template <typename T>
string getBinary (T n)
{
	stringstream ss;
	
	while (n > 0)
	{
		ss << n % 2;
		n /= 2;
	}	 
	
	string str = ss.str();
	string str2 (str);
	reverse (str2.begin(), str2.end());
	
	return str2;
}

int main ()
{
	//Palindrome test
	int noToTest[3] = {1221, 121, 123};
	
	for (int i=0; i<3; i++)
	{
		if (isPalindrome (noToTest[i]))
			cout << noToTest[i] << " is Palindrome!" << endl;
		else
			cout << noToTest[i] << " is not Palindrome!" << endl;
	}
	
	cout << "----------------------------------------------------------------------------" << endl;
	
	//Prime test
	int noToTest2[5] = {1, 2, 3, 11, 12};
	
	for (int i=0; i<5; i++)
	{
		if (isPrime (noToTest2[i]))
			cout << noToTest2[i] << " is Prime!" << endl;
		else
			cout << noToTest2[i] << " is not Prime!" << endl;
	}
	
	cout << "----------------------------------------------------------------------------" << endl;
	
	//Factorial test
	int noToTest3[3] = {0, 1, 5};
	
	for (int i=0; i<3; i++)
		cout << noToTest3[i] << "! is " << factorial (noToTest3[i]) << endl;
	
	cout << "----------------------------------------------------------------------------" << endl;
	
	//Fibonacci  test
	int noToTest4[5] = {1, 2, 3, 4, 5};
	
	for (int i=0; i<5; i++)
		cout << "fib(" << noToTest4[i] << ") is " << fibI (noToTest4[i]) << endl;
	
	cout << "----------------------------------------------------------------------------" << endl;
	
	//Power  test
	pair <int, int> p[3];
	p[0] = make_pair (2, 0);
	p[1] = make_pair (1, 1);
	p[2] = make_pair (3, 3);
	
	for (int i=0; i<3; i++)
		cout << p[i].first << "^" << p[i].second << " = " << power (p[i].first, p[i].second) << endl;
	
	cout << "----------------------------------------------------------------------------" << endl;
	
	//Sum of digits test
	int noToTest5[3] = {123, 12345, 3330};
	
	for (int i=0; i<3; i++)
		cout << "Sum of digits of " << noToTest5[i] << " is " << getSumDigits (noToTest5[i]) << endl;
	
	cout << "----------------------------------------------------------------------------" << endl;
	
	//Get Binary test
	int noToTest6[3] = {12, 15, 20};
	
	for (int i=0; i<3; i++)
	{
		cout << "Binary representation of " << noToTest6[i] << " is " 
			 << getBinary (noToTest6[i]) << endl;
	}
	
	cout << "----------------------------------------------------------------------------" << endl;
}
