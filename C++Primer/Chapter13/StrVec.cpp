#include "StrVec.h"

//构造函数，使用初始化参数列表进行构造
StrVec::StrVec(initializer_list<string> il)
{
	range_initialize(il.begin(), il.end());
}

//拷贝构造函数
StrVec::StrVec(const StrVec &s)
{
	//调用alloc_n_copy分配空间以容纳与s一样多的元素
	//auto newdata = alloc_n_copy(s.begin(), s.end());
	//elements = newdata.first;
	//first_free = newdata.second;
	range_initialize(s.begin(), s.end());
}

//拷贝赋值运算符
StrVec & StrVec::operator=(const StrVec &rhs)
{
	//调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

//析构函数
StrVec::~StrVec()
{
	free();
}

//拷贝元素
void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
//打印元素
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
	//预留空间
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
	{	//扩大size
		if(new_size>size()) reserve(new_size*2);
		for (size_t i = size(); i != new_size; ++i)
		{
			alloc.construct(first_free++, str);
		}
	}
	else
	{	//缩小size
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

//工具函数，被拷贝构造函数、拷贝赋值运算符和析构函数所使用
//alloc_n_copy成员会分配足够的内存来保存给定范围的元素，并将这些元素拷贝到新分配的内存中
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	//分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);
	//初始化并返回一个pair，该pair由data和uninitiallized_copy的返回值构成
	return{ data,uninitialized_copy(b,e,data) };
	//uninitialized_copy()返回值是一个指针，指向最后一个构造元素之后的位置
}

//销毁元素并释放内存
void StrVec::free()
{
	//注意检查elements是否为空
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

//获得更多内存并拷贝已有元素
void StrVec::reallocate()
{
	//在重新分配内存的过程中移动而不是拷贝元素
	//1.为一个新的、更大的string数组分配内存
	//2.在内存空间的前一部分构造对象，保存现有元素
	//3.销毁原内存空间中的元素，并释放这块内存

	//拷贝string中的数据是多余的，再重新分配内存空间时，如果我们能避免分配和释放string的额外开销，StrVec的性能会好得多

	//移动构造函数通常是将资源从给定对象“移动”而不是拷贝到正在创建的对象。
	//我们调用move来表示希望使用string的移动构造函数
	//使用move时，直接调用std::move而不是move

	//我们将分配当前大小两倍的内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_move_n(newcapacity);
}

void StrVec::alloc_move_n(size_t new_cap)
{
	//分配新内存
	auto newdata = alloc.allocate(new_cap);
	//将数据从旧内存移动到新内存
	auto dest = newdata;			//指向新数组中下一个空闲位置
	auto elem = elements;			//指向旧数组中下一个元素
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	//移动完元素就释放旧的内存空间
	free();
	//更新数据结构，执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}

//用一个范围内的元素进行初始化（拷贝）
void StrVec::range_initialize(const string *first, const string *second)
{
	auto newdata = alloc_n_copy(first, second);
	elements = newdata.first;
	first_free = cap = newdata.second;
}
