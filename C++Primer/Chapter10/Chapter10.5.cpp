#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��1�� ���ڶ�
> Last edited time: 2019��1��1�� ���ڶ�
> Topic:C++Primer Chapter10.5 �����㷨�ṹ
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
//#include "Sales_item.h"


using namespace std;

//Chapter10.5 �����㷨�ṹ
//


//10.5.1 5�������
void Fun_The_Five_Iterator_Categories()
{
	//ex10.38
	//(1)���������(==,!=,++,*,->)
	//���бȽϵ���ȺͲ����������==,!=��
	//֧��ǰ�úͺ��õĵ����������++��
	//֧�ֶ�ȡԪ�صĽ������������*���������ڸ�ֵ��������Ҳ�
	//��ͷ�������->��,�����õ���������ȡ����ĳ�Ա
	//(2)���������(++,*)
	//�����ƽ���������ǰֵ�ͺ��õ����������++��
	//�������������ֻ�����ڸ�ֵ����������
	//(3)ǰ�������(++,==,!=,*,->)
	//���Զ�дԪ�أ�ֻ����һ�������ƶ�
	//֧���������������������в���
	//ʹ��ǰ����������Զ����н��ж��ɨ��
	//(4)˫�������(++,--,==,!=,*,->)
	//����/�����ȡ�����е�Ԫ��
	//֧��ǰ�úͺ��õݼ��������--��
	//(5)������ʵ�����(++,--,==,!=,*,->,>,<,>=,<=,+,-,+=,-=��-(two iterators),iter[n]==*(iter+n))
	//�ṩ�������з�������Ԫ�ص�����
	//֧�ֵ�����������Ƚϴ�С��ǰ��

	//ex10.39
	//list�ϵĵ���������˫�������
	//vector�ϵĵ���������������ʵ�����

	//ex10.40
	//copyҪ��ǰ��������������Ҫ����������������һ��Ҫ�����������
	//reverse˫�������
	//uniqueҪ��ǰ�������
}



//10.5.2 �㷨�β�ģʽ
void Fun_Algorithm_Parameter_Patterns()
{
	//���յ���Ŀ����������㷨
	//�ٶ�Ŀ��ռ��㹻����д�������

	//���ܵڶ����������е��㷨

}




//10.5.3 �㷨�����淶
void Fun_Algorithm_Naming_Conventions()
{
	//vector<int> vec = { 0,1,2,3,4,5,6,5,6,7,8,9 };
	//һЩ�㷨ʹ��������ʽ����һ��ν��
	//sort(vec.begin(), vec.end());
	//auto iter1 = unique(vec.begin(), vec.end());
	//vec.erase(iter1, vec.end());
	//printitem(vec);
	//auto iter2 = unique(vec.begin(), vec.end(), [](int num1, int num2) {return num1 == num2; });
	//vec.erase(iter2, vec.end());
	//printitem(vec);


	//_if�汾���㷨
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//auto iter1 = find(vec.begin(), vec.end(), 5);
	//auto iter2 = find_if(vec.begin(), vec.end(), [](int val) {return val == 5; });
	//cout << *iter1 << "   " << *iter2 << endl;
	
	//���ֿ���Ԫ�صİ汾�Ͳ������İ汾
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//reverse(vec.begin(), vec.end());
	//printitem(vec);
	//vector<int> vec2(vec.size());
	//reverse_copy(vec.begin(), vec.end(),vec2.begin());
	//printitem(vec2);

	//һЩ�㷨ͬʱ�ṩ_copy��_if�汾����Щ�汾����һ��Ŀ��Ϊֹ��������һ��ν�ʣ�
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//printitem(vec);
	////�Ƴ�����Ԫ�أ�����һ��������ָ��ż��Ԫ�غ�һ��Ԫ�ص�λ��
	//auto iter = remove_if(vec.begin(), vec.end(), [](int i){return i % 2 == 1; });  
	//vec.erase(iter, vec.end());
	//printitem(vec);
	//vector<int> vec3;
	////����ż��Ԫ�ص�vec3,vec���ֲ���
	//remove_copy_if(vec.begin(), vec.end(), back_inserter(vec3), [](int i) {return i % 2 == 1; }); 
	//printitem(vec);
	//printitem(vec3);

	//ex10.41
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//vector<int> vec2;
	////��1����������������5�滻��6
	//replace(vec.begin(), vec.end(), 5, 6);
	//printitem(vec)
	////��2������pred��Ԫ�أ��滻��6
	//replace_if(vec.begin(), vec.end(), [](int i) {return i <= 5; }, 6);//����pred��Ԫ�أ��滻��6
	//printitem(vec)
	////��3��vec�е�5�滻��6��Ȼ�󿽱���vec2��
	//replace_copy(vec.begin(), vec.end(), back_inserter(vec2), 5, 6);
	//printitem(vec2);
	////��4������pred��Ԫ�أ��滻��6,Ȼ�󿽱���vec2��
	//replace_copy_if(vec.begin(), vec.end(), back_inserter(vec2), [](int i) {return i <= 5; }, 6);
	//printitem(vec2);

}







int main()
{
	//10.5.1 5�������
	//Fun_The_Five_Iterator_Categories();
	//10.5.2 �㷨�β�ģʽ
	//Fun_Algorithm_Parameter_Patterns();
	//10.5.3 �㷨�����淶
	Fun_Algorithm_Naming_Conventions();
	return 0;
}

