#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class s_string
{
	char* str;

public:

	s_string() : s_string(80){}

	s_string(int size) : str{new char[size]}
	{
		str[0] = '\0';
	}

	s_string(const char* s_str) : str{s_str ? new char[strlen(s_str)+1]:nullptr}
	{
		s_str ? strcpy_s(str, strlen(s_str) + 1, s_str) : 0;
	}

	~s_string()
	{
		delete[] str;
	}

	void set_str(const char* s_str)
	{
		delete[] str;
		str = s_str ? new char[strlen(s_str)+1]:nullptr;

		if(str)
		{
			strcpy_s(str, strlen(s_str) + 1, s_str);
		}
	}

	const char* get_str()const { return str; }

	void print()
	{
		cout << this->get_str() << endl;
	}
};

int main()
{
	s_string s;
	s.set_str("Hello!");
	cout << s.get_str() << endl;
	s_string s2("world");
	cout << s2.get_str() << endl;
	s.print();
}