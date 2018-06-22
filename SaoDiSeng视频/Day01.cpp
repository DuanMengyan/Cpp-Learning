
#include <iostream>



using namespace std;


//C++基础Day01
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


class MyCircle
{
public:
	MyCircle();
	~MyCircle();
public:
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

private:
	double m_r;
	double m_s;
};

MyCircle::MyCircle()
{
}

MyCircle::~MyCircle()
{
}

//面向对象的方法求圆的面积
//1.类的抽象 定义成员变量和成员函数
//2.实例化 用类定义变量(对象)
//3.面向过程加工的是一个一个函数；面向过程加工的是一个一个的类；

void S_Circle_02()
{
	MyCircle c1, c2;
	double r;
	std::cout << "请输入圆c1的半径：";
	std::cin >> r;
	c1.setR(r);
	std::cout << "圆c1的半径为：" << c1.getR() << std::endl;
	std::cout << "圆c1的面积为：" << c1.getS() << std::endl;
}




int main()
{


	S_Circle_02();
	return 0;

}
