#include "StringBad.h"
#include <string>
#include <iostream>

//像这种类当中含有指针的，并且在构造函数当中new出堆空间的，最好自己定义拷贝构造函数以及重载赋值运算符，主要进行深拷贝

//初始化静态变量的值
int StringBad::num_string = 0;

StringBad::StringBad(const char * s)
	:numTest(0)
{
	//const 成员变量是常量，不可以用等于号赋值，所以要在构造器那边初始化 ++++++++++++++++++++++++++
	//numTest = 0;
	m_len = strlen(s);
	m_str = new char[m_len + 1];
	std::strcpy(m_str, s);
}	

//拷贝构造函数，对立面的指针进行深拷贝
StringBad::StringBad(const StringBad& stringbad)
	:numTest(0)
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
	:numTest(0)
{
	std::cout << "enter StringBad" << std::endl;
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

