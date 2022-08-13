#include "StringBad.h"
#include <string>

//像这种类当中含有指针的，并且在构造函数当中new出堆空间的，最好自己定义拷贝构造函数以及重载赋值运算符，主要进行深拷贝

//初始化静态变量的值
int StringBad::num_string = 0;

StringBad::StringBad(const char * s)
{
	m_len = strlen(s);
	m_str = new char[m_len + 1];
	std::strcpy(m_str, s);
}	

//拷贝构造函数，对立面的指针进行深拷贝
StringBad::StringBad(const StringBad& stringbad)
{
	m_len = stringbad.m_len;
	m_str = new char[m_len + 1];
	std::strcpy(m_str,stringbad.m_str);
}

StringBad & StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;
	delete[] m_str; //释放已经存在的m_str
	m_len = st.m_len;
	m_str = new char[m_len + 1];
	std::strcpy(m_str,st.m_str);
	return *this;
}

StringBad::StringBad()
{

}

StringBad::~StringBad()
{
	delete [] m_str;
}

//静态函数不属于具体对象，因此他不能对具体对象的成员进行操作，因此它只能访问类里面的静态变量
int StringBad::HowMany()
{
	//return m_len;
	return num_string;
}