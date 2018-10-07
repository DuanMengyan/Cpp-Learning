#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��26�� ������
> Last edited time: 2018��10��7�� ������
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

class Screen;

class Window_mgr
{
public:
	//������ÿ����Ļ�ı��
	using ScreenIndex = std::vector<Screen>::size_type;
	//���ձ�Ž�ָ����Screen����Ϊ�հ�
	void clear(ScreenIndex);
private:
	//std::vector<Screen> screens{ Screen(24, 80, ' ') };
	std::vector<Screen> screens;
};


class Screen
{	

public:
	//Window_mgr�ĳ�Ա���Է���Screen���˽�в���
	//friend class Window_mgr;
	//���Ա������Ϊ��Ԫ
	friend void Window_mgr::clear(ScreenIndex);
	
	void some_menber() const;
	typedef string::size_type pos;   //�����������͵ĳ�Ա�����ȶ����ʹ��
	//using pos = string::size_type;
	
	Screen &set(char);					//���õ�ǰ��괦����λ���ַ�	
	Screen &set(pos, pos, char);		//����ָ��λ���ַ�

	//���캯��
	Screen() = default;						//���߱������ϳ�Ĭ�ϵĹ��캯��
	Screen(pos ht, pos wd) :height(ht), width(wd),contents(ht*wd,'*') { };
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){ }   //Ĭ��inline
	
	char get() const						//��ȡ��괦���ַ�
	{
		return contents[cursor];			//��ʽ������Ĭ��inline
	}
	inline char get(pos ht, pos wd) const;	//��ʽ����
	
	Screen &move(pos r, pos c);				//����֮����Ϊ����
	
	const Screen &display(ostream &os) const
	{
		cout << "Const:" << endl;
		do_display(os);
		return *this;
	}

	Screen &dispaly(ostream &os) 
	{
		cout << "No const:" << endl;
		do_display(os);
		return *this;
	}

private:
	mutable size_t access_ctr;		//��ʹ��һ��const������Ҳ�ܱ��޸�+

	pos cursor = 0;		//���
	pos height = 2, width = 7;
	string contents = "ABCDEFGHIJKLMN";

	void do_display(ostream &os) const
	{
		//�������д�ӡ�ַ�������
		for (decltype(height) i = 0; i != height; ++i)
		{
			for (decltype(width) j = 0; j != width; ++j)
			{
				os << contents[i*width + j] << " ";
			}
			os << endl;
		}
		//os << contents << endl;
	}
};


void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}


inline 
Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline
Screen &Screen::set(pos row,pos col,char ch)
{
	if (row > 0 && col > 0)
	{
		contents[(row - 1)*width + (col - 1)] = ch;
		return *this;
	}
	else
	{
		cout << "Set error!" << endl;
		return *this;
	}

}

void Screen::some_menber() const
{
	++access_ctr;		//����һ������ֵ�����ڼ�¼��Ա���������õĴ���
}

inline 
Screen &Screen::move(pos r,pos c)
{
	if (r > 0 && c > 0)
	{
		pos row = (r - 1)*width;			//�����е�λ��
		cursor = row + (c - 1);			//�����ڽ�����ƶ���ָ������
		return *this;				//����ֵ����ʽ���ض���
	}
	else
	{
		cout << "Move error!" << endl;
		return *this;
	}
}

char Screen::get(pos r,pos c) const
{
	//r��c���ϵ��ַ�
	if (r > 0 && c > 0)
	{
		pos row = (r - 1)*width;
		return contents[row + (c - 1)];
	}
	else
	{
		cout << "Get error!" << endl;		
	}
}


//class Window_mgr
//{
//private:
//	//���window_mgr׷�ٵ�Screen
//	//Ĭ������£�һ��Window_mgr����һ����׼�ߴ�Ŀհ�Screen
//	//vector<Screen> screens{ Screen(24, 80, ' ') };  //�б��ʼ��
//};

//7.3.1 ���Ա��̽
void Fun_Class_Members_Revisited()
{
	//����һ�����ͳ�Ա
	
	//���Ա��Ϊ��������
	//���������ڲ��ĳ�Ա�������Զ�inline��
	//Ҳ����������ⲿ��inline�ؼ������κ����Ķ���
	//Screen myscreen;  //5��2��ȫ���ַ�D
	//myscreen.dispaly(cout);
	//char ch = myscreen.get();	 //��굱ǰλ�õ��ַ�(��1�е�1��)
	//cout << ch << endl;
	//ch = myscreen.get(1, 2);	 //��1�е�2�е��ַ�
	//cout << ch << endl;
	
	//�ɱ����ݳ�Ա��mutable data menber��
	//һ���ɱ����ݳ�Ա��Զ������const����ʹ����const����ĳ�Ա

	//�����ݳ�Ա�ĳ�ʼֵ
	//�������ṩһ�����ڳ�ʼֵ�ǣ������Է���=���߻����ű�ʾ

	//ex7.25
	//���ܣ���Ϊֻ���������ͺ�string���������ڿ����͸�ֵ������Ĭ�ϰ汾

	//ex7.26
	//�������ⶨ��ֱ�Ӽ�inline���ɣ���������ΪinlineҲ�ɣ���Ҫ����һ�¡�

}

//7.3.2 ����*this�ĳ�Ա����
void Fun_Functions_That_Return_this()
{
	//Screen myscreen1(5,5);
	//const Screen myscreen2(5,5,'&');
	////�����������������Ա���������ݵ��޶�����������һ�����´�һ�飬���ü��ݵ����غ���
	//myscreen2.display(cout);
	//cout << endl;
	//myscreen1.move(2,2).set('@');
	//myscreen1.dispaly(cout).set('$');
	//cout << endl;
	//myscreen1.set(1, 2, '#');
	//myscreen1.dispaly(cout);
	//cout << endl;

	//��const��Ա��������*this
	//����const������

	//ex7.27
	Screen myScreen(5, 5, 'X');
	//�ѹ���ƶ�����4�е�1�У���(4,2)λ���ַ���Ϊ#��Ȼ�����
	myScreen.move(4, 1).set('#').dispaly(cout); 
	cout << endl;
	myScreen.dispaly(cout);
	cout << endl;

	//ex7.28
	//�������������ͱ�ΪScreen���򷵻ص��Ƕ���ĸ�����
	//�����Ĳ���ֻ�������ڶ���ĸ����ϣ�����ı������ᷢ���ı�

	//ex7.30
	//�ŵ㣺
	//1.����Ҫһ��������Ϊ�������ö��������ö����һ����Աʱ��ʹ��this��
	//��ú������ضԵ��øú����Ķ�������á�
	//2.���Էǳ���ȷ��ָ�����ʵ��ǵ��øú����Ķ���ĳ�Ա��
	//�ҿ����ڳ�Ա������ʹ�������ݳ�Աͬ�����βΡ�
	//
}

//7.3.3 ������
void Fun_Class_Types()
{
	//�������
	//class Screen;   //��Screen����������������������

	//����ȫ����ʹ�ó�����
	//����ָ���������͵�ָ������ã�
	//���������ǲ��ܶ��壩�Բ���ȫ������Ϊ�������߷������͵ĺ���

	//�ڴ���һ����Ķ���֮ǰ��������뱻������������ܽ�����������

	//ex7.31
	//class Y;

	//class X
	//{
	//	Y *ptr_Y = nullptr;
	//};

	//class Y
	//{
	//	X x1;
	//};
}



struct X
{
	friend void f(){/*��Ԫ�������Զ���������ڲ�*/}
	//X(){ f(); }				//����f��δ������
	void g();
	void h();
};

//void X::g(){ return f(); }		//����f��δ������
void f();						//����������X�е���Ԫ����f
void X::h(){ return f(); }

//7.3.4 ��Ԫ��̽
void Fun_Friendship_Revisited()
{
	//��Ԫ�����ܶ���������ڲ��������ĺ�������ʽ������

	//��֮�����Ԫ��ϵ
	//Window_mgr��Screen����Ԫ�࣬��Ԫ��ĳ�Ա�������Է��ʴ�������ǹ��г�Ա���ڵ����г�Ա
	//��Ԫ��ϵ�����ڴ����ԣ�Window_mgr����Ԫ�����з���Screen����Ȩ
	//ÿ���ฺ������Լ�����Ԫ�����Ԫ����

	//���Ա������Ϊ��Ԫ
	//1.���ȶ���Window_mgr�࣬��������clear���������ǲ���������
	//	��clearʹ��Screen�ĳ�Ա����֮ǰ����������Screen��
	//2.����������Screen����������clear����Ԫ����
	//3.�����clear����ʱ���ſ���ʹ��Screen�ĳ�Ա��

	//�������غ���Ԫ
	//������һ�����غ���������������Ԫ����Ҫ�����麯���е�ÿһ���ֱ�����

	//��Ԫ������������




}



int main()
{
	//7.3.1 ���Ա��̽
	//Fun_Class_Members_Revisited();
	//7.3.2 ����*this�ĳ�Ա����
	//Fun_Functions_That_Return_this();
	//7.3.3 ������
	//Fun_Class_Types();
	//7.3.4 ��Ԫ��̽
	Fun_Friendship_Revisited();
	return 0;
}
