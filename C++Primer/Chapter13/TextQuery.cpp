#include "TextQuery.h"



TextQuery::TextQuery(ifstream & is) :file(new StrVec)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;			//��ǰ�к�
		istringstream line(text);
		string word;
		while (line >> word)				//�����е�ÿ������
		{
			//������ʲ���wm�У���֮Ϊ�±���wm�����һ��
			word = Str_proc(word);			//�Ե��ʽ��и�ʽ����ȫ��Сд��ȥ��֮��ı�㣩
			auto &lines = wm[word];			//lines��shared_ptr<set<vector<string>::size_type>>
			if (!lines)						//��һ�������������ʱ��ָ��Ϊ��
			{
				lines.reset(new set<line_no>);			//����һ���µ�set
			}
			lines->insert(n);							//���кŲ��뵽set��
		}
	}
}

QueryResult TextQuery::query(const string & sought) const
{
	//���δ�ҵ�sought�����ǽ�����һ��ָ���set��ָ��
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//ʹ��fine������ʹ���±�����������ҵ��ʣ����⽫������ӵ�wm�У�
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}



TextQuery::~TextQuery()
{
}

//��ӡ�ı�����
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
		//ȫ�����Сд����ɾ�����ı�����
		*iter = tolower(*iter);
		if (ispunct(*iter) && (iter + 1 == word.end()))
			iter = word.erase(iter);
		else ++iter;
	}
	return word;
}
