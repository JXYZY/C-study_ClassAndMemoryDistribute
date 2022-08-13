#include "StringBad.h"
#include <string>

//�������൱�к���ָ��ģ������ڹ��캯������new���ѿռ�ģ�����Լ����忽�����캯���Լ����ظ�ֵ���������Ҫ�������

//��ʼ����̬������ֵ
int StringBad::num_string = 0;

StringBad::StringBad(const char * s)
{
	m_len = strlen(s);
	m_str = new char[m_len + 1];
	std::strcpy(m_str, s);
}	

//�������캯�����������ָ��������
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
	delete[] m_str; //�ͷ��Ѿ����ڵ�m_str
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

//��̬���������ھ��������������ܶԾ������ĳ�Ա���в����������ֻ�ܷ���������ľ�̬����
int StringBad::HowMany()
{
	//return m_len;
	return num_string;
}