#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��26�� ������
> Last edited time: 2018��9��24�� ������
> Topic:C++Primer Chapter7.3 �����������
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using namespace std;

class Screen
{
public:
	void some_menber() const;
	typedef string::size_type pos;   //�����������͵ĳ�Ա�����ȶ����ʹ��
	//using pos = string::size_type;
	Screen() = default;						//���߱������ϳ�Ĭ�ϵĹ��캯��
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}   //Ĭ��inline
	char get() const						//��ȡ��괦���ַ�
	{
		return contents[cursor];			//��ʽ������Ĭ��inline
	}
	inline char get(pos ht, pos wd) const;	//��ʽ����
	Screen &move(pos r, pos c);				//����֮����Ϊ����
	void get_string()
	{
		//�������д�ӡ�ַ�������
		for (decltype(height) i = 0; i != height; ++i)
		{
			for (decltype(width) j = 0; j != width; ++j)
			{
				cout << contents[i*width+j] <<" ";
			}
			cout << endl;
		}	
	}
private:
	mutable size_t access_ctr;		//��ʹ��һ��const������Ҳ�ܱ��޸�+

	pos cursor = 0;		//���
	pos height = 2, width = 7;
	string contents = "ABCDEFGHIJKLMN";
};

void Screen::some_menber() const
{
	++access_ctr;		//����һ������ֵ�����ڼ�¼��Ա���������õĴ���
}

inline 
Screen &Screen::move(pos r,pos c)
{
	pos row = (r-1)*width;			//�����е�λ��
	cursor = row + (c-1);			//�����ڽ�����ƶ���ָ������
	return *this;				//����ֵ����ʽ���ض���
}

char Screen::get(pos r,pos c) const
{
	//r��c���ϵ��ַ�
	pos row = (r-1)*width;
	return contents[row+(c-1)];
}

class Window_mgr
{
private:
	//���window_mgr׷�ٵ�Screen
	//Ĭ������£�һ��Window_mgr����һ����׼�ߴ�Ŀհ�Screen
	vector<Screen> screens{ Screen(24, 80, '  ') };  //�б��ʼ��
};
//7.3.1 ���Ա��̽
void Fun_Class_Members_Revisited()
{
	//����һ�����ͳ�Ա
	
	//���Ա��Ϊ��������
	//���������ڲ��ĳ�Ա�������Զ�inline��
	//Ҳ����������ⲿ��inline�ؼ������κ����Ķ���
	Screen myscreen;  //5��2��ȫ���ַ�D
	myscreen.get_string();
	char ch = myscreen.get();	 //��굱ǰλ�õ��ַ�(��1�е�1��)
	cout << ch << endl;
	ch = myscreen.get(1, 2);	 //��1�е�2�е��ַ�
	cout << ch << endl;
	

	//�ɱ����ݳ�Ա��mutable data menber��
	//һ���ɱ����ݳ�Ա��Զ������const����ʹ����const����ĳ�Ա

	//�����ݳ�Ա�ĳ�ʼֵ
	//�������ṩһ�����ڳ�ʼֵ�ǣ������Է���=���߻����ű�ʾ


}


int main()
{
	//7.3.1 ���Ա��̽
	Fun_Class_Members_Revisited();
	return 0;
}
