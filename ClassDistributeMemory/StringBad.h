#pragma once

class StringBad
{
public:
	explicit StringBad(const char * s);
	StringBad(const StringBad&);
	StringBad();
	~StringBad();

	//����=
	StringBad & operator=(const StringBad&);

private:
	char* m_str;
	int m_len;  //�ַ������ȣ���ȥβ0
};