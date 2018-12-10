#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��8�� ������
> Last edited time: 2018��12��8�� ������
> Topic:C++Primer Chapter9.5 �����string����
************************************************************************/

#include "header_include.h"

using namespace std;

//9.5.1 ����string����������
void Fun_Other_Ways_to_Construct_strings()
{
	//const char *cp = "Hello World!!!";			//���ַ���\0������������
	//char noNull[] = { 'H','i' };				//�����Կ��ַ�����
	//string s1(cp);								//����cp��ֱ���������ַ�
	//string s2(noNull, 2);						//����noNull�е�ǰ�����ַ�
	//string s3(noNull);							//noNull�����Կ��ַ���������Ϊδ����
	//string s4(cp + 6, 5);						//��cp[6]��ʼ����5���ַ�
	//string s5(s1, 6, 5);						//��s1[6]��ʼ����5���ַ�
	//string s6(s1, 6);							//��s1[6]��ʼ������ֱ��s1ĩβ
	//string s7(s1, 6, 20);						//��s1[6]��ʼ������ֻ������s1ĩβ
	//string s8(s1, 16);						//�׳��쳣

	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;
	//cout << s6 << endl;
	//cout << s7 << endl;

	//sunstr����
	//string s("hello world");					 
	//string s2 = s.substr(0, 5);					 //��s[0]��ʼ����5���ַ�
	//string s3 = s.substr(6);					 //��s[6]��ʼ����������
	//string s4 = s.substr(6, 11);				 //��s[6]��ʼ����11���ַ�������ֻ�ܵ���β
	////string s5 = s.substr(12);					 //������Χ���׳��쳣
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;

	//ex9.41
	//vector<char>  cvec{ 'h','e','l','l','o',' ','w','o','r','l','d' };
	//string s(cvec.begin(),cvec.end());
	//cout << s << endl;

	//ex9.42
	//reverse()Ԥ�����㹻���ڴ�
}


 //9.5.2 �ı�sreing����������
void Fun_Other_Ways_to_Change_a_string()
{
	//const char *cp = "Stately, plump Buck";
	//string s = "hello world";
	//s.assign(cp, 7);					//��s�е��ַ��滻��cp��ǰ7���ַ�
	//cout << s << endl;
	//s.insert(s.size(), cp + 7, 6);		//��sĩβ����cp[7]��ʼ6���ַ�
	//cout << s << endl;

	//string s1 = "some string", s2 = "some other string";
	//s1.insert(0, s2);					//��s1[0]֮ǰ����s2�Ŀ���
	//cout << s1 << endl;
	//s1.insert(0, s2, 0, s2.size());		//��s1[0]֮ǰ����s2[0]��ʼ��s2.size()���ַ�
	//cout << s1 << endl;

	//append��replace����
	//string s("C++ Primer"), s2 = s;
	//s.insert(s.size(), " 4th Ed.");
	//cout << s << endl;
	//s2.append(" 4th Ed.");
	//cout << s2 << endl;

	//s.erase(11, 3);				//��s[11]��ʼɾ��3���ַ�
	//s.insert(11, "5th");			
	//cout << s << endl;
	//s2.replace(11, 3, "5th");	//��s2[11]��ʼ��3���ַ��滻�ɡ�5th��
	//cout << s2 << endl;

	//�ı�string�Ķ������غ���

	//ex9.43

	//ex9.44
	
	//ex9.45
	
	//ex9.46


}
 //9.5.3
 
 //9.5.4
 
 //9.5.5
 






int main()
{
	//9.5.1 ����string����������
	//Fun_Other_Ways_to_Construct_strings();
	//9.5.2 �ı�sreing����������
	Fun_Other_Ways_to_Change_a_string();

	return 0;

}