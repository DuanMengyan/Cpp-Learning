
#include <iostream>



using namespace std;


//C++����Day01
//������̵ķ�����Բ�����
void S_Circle_01()
{
	double r = 0.0;
	double s = 0.0;
	std::cout << "������Բ�İ뾶: ";
	std::cin >> r;
	std::cout << "Բ�İ뾶rΪ��" << r << std::endl;
	s = 3.14 * r * r;
	std::cout << "Բ�����sΪ��" << s << std::endl;
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

//�������ķ�����Բ�����
//1.��ĳ��� �����Ա�����ͳ�Ա����
//2.ʵ���� ���ඨ�����(����)
//3.������̼ӹ�����һ��һ��������������̼ӹ�����һ��һ�����ࣻ

void S_Circle_02()
{
	MyCircle c1, c2;
	double r;
	std::cout << "������Բc1�İ뾶��";
	std::cin >> r;
	c1.setR(r);
	std::cout << "Բc1�İ뾶Ϊ��" << c1.getR() << std::endl;
	std::cout << "Բc1�����Ϊ��" << c1.getS() << std::endl;
}




int main01()
{


	S_Circle_02();
	return 0;

}