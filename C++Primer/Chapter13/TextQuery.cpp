#include "TextQuery.h"



TextQuery::TextQuery(ifstream & is) :file(new StrVec)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;			//当前行号
		istringstream line(text);
		string word;
		while (line >> word)				//对行中的每个单词
		{
			//如果单词不再wm中，以之为下标在wm中添加一项
			word = Str_proc(word);			//对单词进行格式化（全部小写，去掉之后的标点）
			auto &lines = wm[word];			//lines是shared_ptr<set<vector<string>::size_type>>
			if (!lines)						//第一次遇到这个单词时，指针为空
			{
				lines.reset(new set<line_no>);			//分配一个新的set
			}
			lines->insert(n);							//将行号插入到set中
		}
	}
}

QueryResult TextQuery::query(const string & sought) const
{
	//如果未找到sought，我们将返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//使用fine而不是使用下标运算符来查找单词，避免将单词填加到wm中！
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}



TextQuery::~TextQuery()
{
}

//打印文本内容
void TextQuery::print()
{
	if (!file->empty())
	{
		line_no row = 0;
		for (auto str : *file)
		{
			cout << "(Line " << ++row << ") " << str << endl;
		}
	}
	else
	{
		cout << "file is empty!";
	}
	
}

string & TextQuery::Str_proc(string & word)
{
	for (auto iter = word.begin(); iter != word.end();)
	{
		//全部变成小写，并删除最后的标点符号
		*iter = tolower(*iter);
		if (ispunct(*iter) && (iter + 1 == word.end()))
			iter = word.erase(iter);
		else ++iter;
	}
	return word;
}
