#pragma once

class StringBad
{
public:
	StringBad(const char * s);
	StringBad(const StringBad&);
	StringBad();
	~StringBad();

	//����=
	StringBad & operator=(const StringBad&);
	static int HowMany();
private:
	char* m_str;
	int m_len;  //�ַ������ȣ���ȥβ0
	static int num_string;
};