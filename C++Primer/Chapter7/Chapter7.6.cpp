#pragma once
#pragma execution_character_set("utf-8")
/*************************************************************************
> File Name: Chapter7.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��24�� ������
> Last edited time: 2018��10��25�� ������
> Topic:C++Primer Chapter7.6 ��ľ�̬��Ա
************************************************************************/

#include "header_include.h"

using namespace std;

class Account
{
public:
	//��Ա��������ͨ�����������������ʹ�þ�̬��Ա
	void claculate(){ amount += amount*interestRate; }
	static double rate(){ return interestRate; }
	static void rate(double);		//��̬��Ա����������thisָ��
									//static�ؼ���ֻ���������ڲ������������

private:
	string owner;
	double amount;
	static constexpr double todayRate = 42.42;	//const�����ṩ�����������ڳ�ʼֵ����������ֵ������constexpr
	static double interestRate;		//�þ�̬��Ա������Account������
	static double initRate(){ return todayRate; };
	
	//static constexpr int period = 30;		//period�ǳ������ʽ
	//double daily_tbl[period];
};

Account::Account()
{
}

Account:: ~Account()
{
}

//������ⲿ���徲̬��Ա����
void Account::rate(double newRate)
{
	interestRate = newRate;
}

//���岢��ʼ����̬���ݳ�Ա����������ʼ�������ʣ�ಿ�־Ͷ�λ���������������
//ȷ������ֻ����һ�Σ��Ѿ�̬���ݳ�Ա�Ķ�������������������Ķ������ͬһ���ļ���
double Account::interestRate = initRate();
//��̬��Ա���ڳ�ʼ����ͨ�������ҲӦ���ⲿ����һ�¸ó�Ա
//constexpr int Account::period;


//ex7.58
class Example
{
public:
	static constexpr double rate = 6.5;
	static const int vecSize = 20;
	//���ڳ�ʼ��������������ֵ��̬������vector string����������ֵ��̬����
	static vector<double> vec;
};

//���ڳ�ʼ��������ⲿ����
constexpr double Example::rate;

vector<double> Example::vec(Example::vecSize);



//7.6 ��ľ�̬��Ա
void Fun_static_Class_Members()
{
	//ʹ����ľ�̬��Ա
	double r = Account::rate();		//ʹ�������������ֱ�ӷ��ʾ�̬��Ա
	//Account ac1;
	//Account *ac2 = &ac1;
	//r = ac1.rate();					
	//r = ac2->rate();

	//���徲̬��Ա
	//һ����˵�����ǲ���������ڲ���ʼ����̬��Ա
	//�෴������������ⲿ����ͳ�ʼ��ÿ����̬��Ա��һ����̬���ݳ�Աֻ�ܶ���һ�Ρ�

	//��̬��Ա�����ڳ�ʼ��
	//Ҫ�����������ֵ�������������ڳ�ʼ��



	//��̬��Ա������ĳЩ����������ͨ��Ա����
	//1.��̬���ݳ�Ա�����ǲ���ȫ���ͣ����ݳ�Ա��������ȫ����
	//2.���ǿ���ʹ�þ�̬��Ա��ΪĬ��ʵ�Σ��Ǿ�̬���ݳ�Ա������ΪĬ��ʵ��

	//ex7.56
	//��̬���ݳ�Ա��������������Ա���������κ�һ�������
	
	//ÿ���������Ҫ�洢һ����ȫ��ͬ�Ĺ������ݣ�
	//����þ�̬���ݳ�Ա�����˱仯��ÿ���඼����ʹ����ֵ

	//����
	//1.��̬���ݳ�Ա����ʹ�ù��캯�����г�ʼ��
	//2.��̬���ݳ�Ա�����ǲ���ȫ���ͣ���ͨ���ݳ�Ա���У�
	//3.��̬���ݳ�Ա������ΪĬ��ʵ�Σ���ͨ���ݳ�Ա���У�

	//ex7.57
	
	//ex7.58	
}

int main()
{

	return 0;
}