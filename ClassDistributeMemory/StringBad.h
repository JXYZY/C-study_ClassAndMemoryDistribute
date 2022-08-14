#pragma once

class StringBad
{
public:
	StringBad(const char * s);
	StringBad(const StringBad&);
	StringBad();
	~StringBad();


	//重载=
	StringBad & operator=(const StringBad&);
	static int HowMany();
private:
	const int numTest;
	char* m_str;
	int m_len;  //字符串长度，出去尾0
	static int num_string;
};