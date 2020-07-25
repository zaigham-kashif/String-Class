#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class MyString
{
	private:
		char* pr_CharArray;
		int pr_Array_Length;
	public:

		//constructors

		MyString();
		MyString(int, char*);
		MyString(char*);
		MyString(MyString&);

		//operators
		friend void operator >>(istream&, MyString&);
		friend void operator <<(ostream&, MyString&);
		char& operator[](int const);
		MyString& operator =(const MyString&);
		MyString operator +(const MyString&);
		MyString operator -(const MyString&);

		bool operator ==(const MyString&);
		bool operator >(const MyString&);
		bool operator <(const MyString&);
		bool operator !=(const MyString&);

		friend void operator >>(ifstream&, MyString&);
		friend void operator <<(ofstream&, MyString&);

		//Functions
		void Clear();

		//Destructor
		~MyString();
};

