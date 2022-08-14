#include "StringBad.h"
#include <string>
#include <iostream>

//�������൱�к���ָ��ģ������ڹ��캯������new���ѿռ�ģ�����Լ����忽�����캯���Լ����ظ�ֵ���������Ҫ�������

//��ʼ����̬������ֵ
int StringBad::num_string = 0;

StringBad::StringBad(const char * s)
	:numTest(0)
{
	//const ��Ա�����ǳ������������õ��ںŸ�ֵ������Ҫ�ڹ������Ǳ߳�ʼ�� ++++++++++++++++++++++++++
	//numTest = 0;
	m_len = strlen(s);
	m_str = new char[m_len + 1];
	std::strcpy(m_str, s);
}	

//�������캯�����������ָ��������
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
	delete[] m_str; //�ͷ��Ѿ����ڵ�m_str
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

//��̬���������ھ��������������ܶԾ������ĳ�Ա���в����������ֻ�ܷ���������ľ�̬����
int StringBad::HowMany()
{
	//return m_len;
	return num_string;
}

