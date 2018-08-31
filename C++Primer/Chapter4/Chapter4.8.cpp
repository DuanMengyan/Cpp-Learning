#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter4.8.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��08��30�� ������
> Last edited time: 2018��8��31�� ������
> Topic:C++Primer Chapter4.8 λ�����
************************************************************************/

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

//λ�����
void Fun_The_Bitwise_Operators()
{
	//����ֵ���������ǿ��Խ���������ֵд��ʮ���������˽�������ʮ������������ʽ��
	//��0��ͷ��֤�����˽�����
	//��0x��0X��ͷ�Ĵ���ʮ��������

	//��λ�����
	//unsigned char bits = 030;				//�˽���0030��������Ϊ��00011000	
	//cout << (bits << 3) << endl;			//����3λ��11000000��ʮ����Ϊ��192

	//unsigned char bits = 30;				//ʮ����30��������Ϊ��11110
	//cout << (bits << 3) << endl;			//����3λ��11110000��ʮ����Ϊ��240
	////ʮ������������nλ������2^n��
	//unsigned result = bits << 5;
	//cout << result << endl;

	//λ�������
	//unsigned char bits = 0001;		//�˽��ƣ�10010111
	//cout << ~bits << endl;

	//λ�룬λ��λ��������
	//unsigned char b1 = 0145;
	//unsigned char b2 = 0257;
	//int result1 = b1 & b2;
	//int result2 = b1 | b2;
	//int result3 = b1 ^ b2;
	//cout << result1 << endl;
	//cout << result2 << endl;
	//cout << result3 << endl;

	//00000000 00000000 00000000 00000000				// quizl = 0	
	//00001000 00000000 00000000 00000000				// (1UL << 27) 134217728   
	//00001000 00000000 00000000 00000000				// quizl | 1UL << 27;  134217728   ѧ��27ͨ���˲���
	//11110111 11111111 11111111 11111111				// ~(1UL << 27) 4160749567
	//00000000 00000000 00000000 00000000				// quizl & ~(1UL << 27);  0    ѧ��27û��ͨ������

	//ʹ��λ�����
	//unsigned long quizl = 0;				//�����ƣ�00000000 00000000 00000000 00000000��ʮ����0
	////quizl |= 1UL << 27;
	//quizl = quizl | 1UL << 27;				//ѧ��27ͨ���˲���
	//cout << (1UL << 27) << endl;			//134217728
	//cout << quizl << endl;					//134217728
	//bool status = quizl & (1UL << 27);		//1
	//cout << status << endl;
	
	
	
	//quizl = 0;
	//quizl = quizl & ~(1UL << 27);			//ѧ��27û��ͨ������
	//cout << ~(1UL << 27) << endl;			//4160749567	
	//cout << quizl << endl;				//0
	//bool status = quizl & (1UL << 27);
	//cout << status << endl;				//


	//��λ�����(IO�����)����������
	//��������������ȼ��ף��ȹ�ϵ��������ȼ���
	//cout << 10 + 42 << endl;
	//cout << (10 < 42) << endl;

	//ex4.25
	//'q':		00000000 00000000 00000000 01110001
	//char���͵������������������int���ͣ���λ���0
	//~'q':		11111111 11111111 11111111 10001110
	//~'q'<< 6:	11111111 11111111 11100011 10000000		-7296
	
	//ex4.26
	//������Ҫ32λ��ĳЩ������ unsigned int ���ܲ���32λ

	//ex4.27
	//ul1: 00000000 00000000 00000000 00000011			3
	//ul2: 00000000 00000000 00000000 00000111			7	
	//(a): 00000000 00000000 00000000 00000011			3
	//(b): 00000000 00000000 00000000 00000111			7
	unsigned long ul1 = 3, ul2 = 7;
	cout << (ul1 & ul2) << endl;					//3
	cout << (ul1 | ul2) << endl;					//7
	cout << (ul1 && ul2) << endl;					//1
	cout << (ul1 || ul2) << endl;					//1

}

int main()
{

	Fun_The_Bitwise_Operators();
	return 0;
}


