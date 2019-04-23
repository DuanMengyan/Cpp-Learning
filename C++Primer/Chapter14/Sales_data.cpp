#include "Sales_data.h"

//��Ԫ����
istream& operator >> (istream &is, Sales_data& s)
{
	double price;
	is >> s.bookNo >> s.units_sold >> price;
	// check that the inputs succeeded
	if (is)
		s.revenue = s.units_sold * price;
	else
		s = Sales_data();  // input failed: reset object to default state
	return is;
}

ostream& operator<<(ostream &os, const Sales_data& s)
{
	os << s.isbn() << " " << s.units_sold << " "
		<< s.revenue << " " << s.avg_price();
	return cout;
}


//��ֵ���أ���Ҫ���ؾֲ����������
//������ִ����ϣ������ͷŷ�����ֲ�����Ĵ洢�ռ䡣��ʱ���Ծֲ���������þͻ�ָ��ȷ�����ڴ档
//ͬ��ָ��Ҳ������������ָ���ʱ�򣬲���ָ��ֲ���ʱ����������ָ�뽫��ΪҰָ�룻

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum(lhs);  
	sum += rhs;            
	return sum;            
}


//�������캯��
Sales_data::Sales_data(const Sales_data &lhs)
{
	bookNo = lhs.bookNo;
	revenue = lhs.revenue;
	units_sold = lhs.units_sold;
}

//������ֵ�����
Sales_data& Sales_data::operator=(const Sales_data &lhs)
{
	bookNo = lhs.bookNo;
	revenue = lhs.revenue;
	units_sold = lhs.units_sold;
	return *this;
}

bool Sales_data::operator==(const Sales_data &lhs)
{
	return lhs.isbn()==isbn();
}



// assumes that both objects refer to the same ISBN
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}



//���ߺ���
double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;		//��rhs�ĳ�Ա�ӵ�this����ĳ�Ա��
	revenue += rhs.revenue;
	return *this;						//���ص��øú����Ķ���
}
ostream& Sales_data::output(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price() << endl;
	return os;
}

istream& Sales_data::input(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}