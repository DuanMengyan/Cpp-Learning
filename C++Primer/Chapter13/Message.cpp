#include "Message.h"

//拷贝构造函数
Message::Message(const Message &m)
{
	save_to_Folders(m);			//将本消息添加到指向m的Folder中
}

//拷贝赋值运算符
Message & Message::operator=(const Message &rhs)
{
	//通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders();			//更新已有的Folder
	contents = rhs.contents;		//从rhs拷贝消息内容
	folders = rhs.folders;			//从rhs拷贝Folder指针
	save_to_Folders(rhs);			//将本Message添加到那些Folder中
	return *this;
}

//析构函数
Message::~Message()
{
	remove_from_Folders();
}

//把消息保存在指定的文件夹，
void Message::save_to_Folder(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove_from_Folder(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::print_message()
{
	cout << contents << endl;
}

void Message::print_folders()
{
	for (auto f : folders)
		cout << f->name << " ==== ";
	cout << endl;
}


//将本Message添加到指向参数的Folder中
void Message::save_to_Folders(const Message &m)
{
	for (auto f : m.folders)		//对每个包含m的Folder
	{								
		f->addMsg(this);			//向改Folder添加一个指向本Message的指针
	}
}

//从folders中的每个Folder中删除本Message
void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		f->remMsg(this);
	}
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;		
	//将每个消息的指针从它（原来）所在Folder中删除
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	
	//交换contents和Folder指针set
	swap(lhs.contents, rhs.contents);	
	swap(lhs.folders, rhs.folders);

	//将每个Message的指针添加到它的新Folders中
	lhs.save_to_Folders(lhs);
	rhs.save_to_Folders(rhs);
}
