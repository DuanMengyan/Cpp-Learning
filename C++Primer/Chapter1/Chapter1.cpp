

#include <iostream>
#include "Sales_item.h"
#include "Version_test.h"

using namespace std;


int main()
{

	//1.20
	//Sales_item item;
	//while (std::cin >> item) std::cout << item << std::endl;
	//return 0;



	//1.21
	//Sales_item book1,book2;
	//std::cin >> book1 >> book2;
	//if (book1.isbn() == book2.isbn())
	//{
	//	std::cout << book1 + book2 << std::endl;
	//	return 0;
	//}
	//else
	//{
	//	std::cerr << "Data must refer to same ISBN" <<std::endl;
	//	return -1;
	//}



	//1.22

	//Sales_item itemsum, item;
	//std::cin >> itemsum;
	//while (std::cin >> item)
	//{
	//	if (itemsum.isbn()==item.isbn())
	//	{
	//		itemsum += item;
	//	}
	//}
	//std::cout << itemsum << std::endl;
	//return 0;


	//1.23
	//freopen("book_sales", "r", stdin);//输入文件重定向
	//freopen("data.out", "w", stdout);//输出文件重定向
	//int num = 1;
	//Sales_item curItem,nextItem;
	//std::cin >> curItem;
	//while (std::cin>>nextItem)
	//{
	//	if (curItem.isbn() == nextItem.isbn())
	//	{
	//		num++;
	//	}
	//	else
	//	{
	//		std::cout << curItem.isbn() <<"出现了"<<num<<"次"<< std::endl;
	//		curItem = nextItem;
	//		num = 1;
	//	}
	//}
	//std::cout << curItem.isbn() << "出现了" << num << "次" << std::endl;
	//return 0;

	//1.24同上

	//1.25
	freopen("book_sales", "r", stdin);
	Sales_item total;
	if (std::cin >> total)
	{
		Sales_item trans;
		while (std::cin >> trans)
		{
			if (trans.isbn() == total.isbn())
			{
				total += trans;
			}
			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else
	{
		std::cerr << "No Data" << std::endl;
		return -1;
	}

	return 0;


}