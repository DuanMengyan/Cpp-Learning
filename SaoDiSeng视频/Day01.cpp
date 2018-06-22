/*************************************************************************
> File Name: C++基础Day01.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年06月22日 星期五
> Topic:面向对象基础及易犯错误
************************************************************************/


#include <iostream>
using namespace std;


//面向过程的方法求圆的面积
void S_Circle_01()
{
	double r = 0.0;
	double s = 0.0;
	std::cout << "请输入圆的半径: ";
	std::cin >> r;
	std::cout << "圆的半径r为：" << r << std::endl;
	s = 3.14 * r * r;
	std::cout << "圆的面积s为：" << s << std::endl;
}


//面向对象的方法求圆的面积
//1.类的抽象 定义成员变量和成员函数
//2.实例化 用类定义变量(对象)
//3.面向过程加工的是一个一个函数；面向过程加工的是一个一个的类；

class MyCircle1
{
public:
	double m_r;
	double m_s;

	void setR(double r)
	{
		m_r = r;
	}
	double getR()
	{
		return m_r;
	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}
};


//面向对象求解圆的面积
void S_Circle_02()
{
	MyCircle1 c1;
	double r;
	std::cout << "请输入圆c1的半径：";
	std::cin >> r;
	c1.setR(r);
	std::cout << "圆c1的半径为：" << c1.getR() << std::endl;
	std::cout << "圆c1的面积为：" << c1.getS() << std::endl;
}


//类中不定义成员函数易犯错误
class MyCircle2
{
public:
	double m_r;
	double m_s = 3.14*m_r*m_r;

	void setR(double r)
	{
		m_r = r;
	}
	double getR()
	{
		return m_r;
	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}
};


//类中定义成员函数的重要性，因为成员变量的值计算过程只在初始化的时候执行
void S_Circle_03()
{
	MyCircle2 c2;
	double r;
	std::cout << "请输入圆c2的半径：";
	std::cin >> r;
	std::cout << "圆c1的半径为：" << c2.getR() << std::endl;//此时c2的半径m_r为实例化对象c1时的随机值（乱码）；
	c2.setR(r);
	std::cout << "圆c1的半径为：" << c2.getR() << std::endl;//此时c2的半径m_r为用户输入的值；
	std::cout << "圆c1的面积m_s为：" << c2.m_s << std::endl;//此时c2的面积m_s为实例化对象c1时的随机值（乱码）；
	std::cout << "圆c1的面积m_s为：" << c2.getS() << std::endl;//此时c2的面积m_s为计算得到的面积；
	std::cout << "圆c1的面积m_s为：" << c2.m_s << std::endl;//此时c2的面积m_s为计算得到的面积；
}



int main()
{
	//S_Circle_01();
	//S_Circle_02();
	S_Circle_03();
	return 0;
}
