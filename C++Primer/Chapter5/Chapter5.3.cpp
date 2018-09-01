#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter5.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月01日 星期六
> Last edited time: 2018年9月01日 星期六
> Topic:C++Primer Chapter5.3 条件语句
************************************************************************/

#include <iostream>
#include <cstddef>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using namespace std;


//条件语句
void Fun_Conditional_Statements()
{
	//5.3.1 if语句
	//ex5.5    嵌套if  
	//const vector<string> scores = { "E", "D", "C", "B", "A", "A++" };
	//const vector<int> grades = { 100, 89, 75, 62, 59, 55, 90 ,99};
	//string lettergrade;
	//for (int g : grades)
	//{
	//	if (g < 60)
	//	{
	//		lettergrade = scores[0];
	//	}
	//	else
	//	{ 
	//		lettergrade = scores[(g - 50) / 10];
	//		if (g != 100)			//只要不是A++，就考虑加‘+’或‘-’；
	//			if (g % 10 > 7)
	//			{
	//				lettergrade += '+';
	//			}
	//			else if (g % 10 < 3)
	//			{
	//				lettergrade += '-';
	//			}
	//	}
	//	cout << lettergrade << endl;
	//}
	
	//ex5.6
	//for (int g : grades)
	//{
	//	(g < 60) ? lettergrade = scores[0] : (lettergrade = scores[(g - 50) / 10],
	//		(g != 100) ? ((g % 10 > 7) ? (lettergrade += '+') : (lettergrade += '-')) : "" );
	//	cout << lettergrade << endl;
	//}

	//ex5.7

	//ex5.8


	//ex5.3.2  switch语句
	//ex5.9
	//char ch;
	//int a = 0, e = 0, i = 0, o = 0, u = 0;
	//while (cin >> ch)
	//{
	//	if (ch == 'a')++a;		
	//	else if (ch == 'e') ++e;
	//	else if (ch == 'i') ++i;	
	//	else if (ch == 'o') ++o;
	//	else if (ch == 'u') ++u;
	//}
	//cout << a << "  " << e << "  " << i << "  " << o << "  " << u << endl;

	//ex5.10
	//char ch;
	//int a = 0, e = 0, i = 0, o = 0, u = 0, s = 0, t = 0, n = 0;
	////std::noskipws 读取空白字符，默认是std::skipws,忽略空白字符
	//while (cin >> std::noskipws >> ch)
	//{
	//	//if (ch == 'a' || ch == 'A')++a;
	//	//else if (ch == 'e' || ch == 'E') ++e;
	//	//else if (ch == 'i' || ch == 'I') ++i;
	//	//else if (ch == 'o' || ch == 'O') ++o;
	//	//else if (ch == 'u' || ch == 'U') ++u;

	//	switch (ch)
	//	{
	//	case 'a':
	//	case 'A':++a; break;
	//	case 'e':
	//	case 'E':++e; break;
	//	case 'i':
	//	case 'I':++i; break;
	//	case 'o':
	//	case 'O':++o; break;
	//	case 'u':
	//	case 'U':++u; break;
	//	case ' ':++s; break;
	//	case '\t':++t; break;
	//	case '\n':++n; break;
	//	}
	//}
	//cout << a << "  " << e << "  " << i << "  " << o << "  " << u << "  " << s << "  " << t << "  " << n << "  " << endl;


	//ex5.12
	//unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
	//char ch, prech = '\0';
	//while (cin >> std::noskipws >> ch)
	//{
	//	switch (ch)
	//	{
	//	case 'a':
	//	case 'A':
	//		++aCnt;
	//		break;
	//	case 'e':
	//	case 'E':
	//		++eCnt;
	//		break;
	//	case 'i':
	//		if (prech == 'f') ++fiCnt;
	//	case 'I':
	//		++iCnt;
	//		break;
	//	case 'o':
	//	case 'O':
	//		++oCnt;
	//		break;
	//	case 'u':
	//	case 'U':
	//		++uCnt;
	//		break;
	//	case ' ':
	//		++spaceCnt;
	//		break;
	//	case '\t':
	//		++tabCnt;
	//		break;
	//	case '\n':
	//		++newLineCnt;
	//		break;
	//	case 'f':
	//		if (prech == 'f') ++ffCnt;
	//		break;
	//	case 'l':
	//		if (prech == 'f') ++flCnt;
	//		break;
	//	}
	//	prech = ch;
	//}

	//cout << "Number of vowel a(A): \t" << aCnt << '\n'
	//	<< "Number of vowel e(E): \t" << eCnt << '\n'
	//	<< "Number of vowel i(I): \t" << iCnt << '\n'
	//	<< "Number of vowel o(O): \t" << oCnt << '\n'
	//	<< "Number of vowel u(U): \t" << uCnt << '\n'
	//	<< "Number of space: \t" << spaceCnt << '\n'
	//	<< "Number of tab char: \t" << tabCnt << '\n'
	//	<< "Number of new line: \t" << newLineCnt << '\n'
	//	<< "Number of ff: \t" << ffCnt << '\n'
	//	<< "Number of fl: \t" << flCnt << '\n'
	//	<< "Number of fi: \t" << fiCnt << endl;
	
}



int main()
{
	Fun_Conditional_Statements();
	return 0;
}
