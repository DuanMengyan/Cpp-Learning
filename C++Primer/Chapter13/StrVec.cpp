#include "StrVec.h"

//���캯����ʹ�ó�ʼ�������б���й���
StrVec::StrVec(initializer_list<string> il)
{
	range_initialize(il.begin(), il.end());
}

//�������캯��
StrVec::StrVec(const StrVec &s)
{
	//����alloc_n_copy����ռ���������sһ�����Ԫ��
	//auto newdata = alloc_n_copy(s.begin(), s.end());
	//elements = newdata.first;
	//first_free = newdata.second;
	range_initialize(s.begin(), s.end());
}

//������ֵ�����
StrVec & StrVec::operator=(const StrVec &rhs)
{
	//����alloc_n_copy�����ڴ棬��С��rhs��Ԫ��ռ�ÿռ�һ����
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

//��������
StrVec::~StrVec()
{
	free();
}

//����Ԫ��
void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
//��ӡԪ��
void StrVec::print_str()
{
	for (auto str = elements; str != first_free; str++)
	{
		cout << *str << "   ";
	}
	cout << endl;
}

void StrVec::reserve(const size_t num)
{
	//Ԥ���ռ�
	if (num > capacity())
	{
		alloc_move_n(num);
	}
}

void StrVec::resize(const size_t new_size)
{
	resize(new_size, string());
}

void StrVec::resize(const size_t new_size, const string &str)
{
	if (new_size > size())
	{	//����size
		if(new_size>size()) reserve(new_size*2);
		for (size_t i = size(); i != new_size; ++i)
		{
			alloc.construct(first_free++, str);
		}
	}
	else
	{	//��Сsize
		for (size_t i = size(); i != new_size; --i)
		{
			alloc.destroy(--first_free);
		}
	}
}

bool StrVec::empty()
{
	if (elements == first_free)  return true;
	else return false;
}

//���ߺ��������������캯����������ֵ�����������������ʹ��
//alloc_n_copy��Ա������㹻���ڴ������������Χ��Ԫ�أ�������ЩԪ�ؿ������·�����ڴ���
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	//����ռ䱣�������Χ�е�Ԫ��
	auto data = alloc.allocate(e - b);
	//��ʼ��������һ��pair����pair��data��uninitiallized_copy�ķ���ֵ����
	return{ data,uninitialized_copy(b,e,data) };
	//uninitialized_copy()����ֵ��һ��ָ�룬ָ�����һ������Ԫ��֮���λ��
}

//����Ԫ�ز��ͷ��ڴ�
void StrVec::free()
{
	//ע����elements�Ƿ�Ϊ��
	if (elements) 
	{
		//for (auto p = first_free; p != elements;)
		//	alloc.destroy(--p);
		//alloc.deallocate(elements, cap - elements);

		//ex13.43
		for_each(elements, first_free, [this](string &str) {alloc.destroy(&str); });
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
	alloc_move_n(newcapacity);
}

void StrVec::alloc_move_n(size_t new_cap)
{
	//�������ڴ�
	auto newdata = alloc.allocate(new_cap);
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
	cap = elements + new_cap;
}

//��һ����Χ�ڵ�Ԫ�ؽ��г�ʼ����������
void StrVec::range_initialize(const string *first, const string *second)
{
	auto newdata = alloc_n_copy(first, second);
	elements = newdata.first;
	first_free = cap = newdata.second;
}
