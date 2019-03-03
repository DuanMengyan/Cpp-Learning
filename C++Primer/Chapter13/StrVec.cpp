#include "StrVec.h"

//�������캯��
StrVec::StrVec(const StrVec &s)
{
	//����alloc_n_copy����ռ���������sһ�����Ԫ��
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
}

//������ֵ�����
StrVec & StrVec::operator=(const StrVec &rhs)
{
	//����alloc_n_copy�����ڴ棬��С��rhs��Ԫ��ռ�ÿռ�һ����
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
}

//��������
StrVec::~StrVec()
{
	free();
}

//����Ԫ��
void StrVec::push_pack(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

//���ߺ��������������캯����������ֵ�����������������ʹ��
//alloc_n_copy��Ա������㹻���ڴ������������Χ��Ԫ�أ�������ЩԪ�ؿ������·�����ڴ���
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return{ data,uninitialized_copy(b,e,data) };
	//uninitialized_copy()����ֵ��һ��ָ�룬ָ�����һ������Ԫ��֮���λ��
}

//����Ԫ�ز��ͷ��ڴ�
void StrVec::free()
{
	//ע����elements�Ƿ�Ϊ��
	if (elements) 
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

//��ø����ڴ沢��������Ԫ��
void StrVec::reallocate()
{
	//�����·����ڴ�Ĺ������ƶ������ǿ���Ԫ��
	//1.Ϊһ���µġ������string��������ڴ�
	//2.���ڴ�ռ��ǰһ���ֹ�����󣬱�������Ԫ��
	//3.����ԭ�ڴ�ռ��е�Ԫ�أ����ͷ�����ڴ�

	//����string�е������Ƕ���ģ������·����ڴ�ռ�ʱ����������ܱ��������ͷ�string�Ķ��⿪����StrVec�����ܻ�õö�

	//�ƶ����캯��ͨ���ǽ���Դ�Ӹ��������ƶ��������ǿ��������ڴ����Ķ���
	//���ǵ���move����ʾϣ��ʹ��string���ƶ����캯��
	//ʹ��moveʱ��ֱ�ӵ���std::move������move

	//���ǽ����䵱ǰ��С�������ڴ�ռ�
	auto newcapacity = size() ? 2 * size() : 1;
	//�������ڴ�
	auto newdata = alloc.allocate(newcapacity);
	//�����ݴӾ��ڴ��ƶ������ڴ�
	auto dest = newdata;			//ָ������������һ������λ��
	auto elem = elements;			//ָ�����������һ��Ԫ��
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	//�ƶ���Ԫ�ؾ��ͷžɵ��ڴ�ռ�
	free();
	//�������ݽṹ��ִ����Ԫ��
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
