#include "ex12.32.h"

TextQuery::TextQuery(ifstream &infile)
{
	string text;
	while (getline(infile, text))
	{
		file.push_back(text);
		line_no n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			word = str_proc(word);
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string & sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

TextQuery::~TextQuery()
{
}

void TextQuery::print_file()
{
	if (!file.empty())
	{
		for (size_t i = 0; i < file.size(); ++i)
		{
			StrBlobPtr p(file, i);
			cout << "(Line " << i + 1 << ") " << p.deref() << endl;
		}
	}
	else
	{
		cout << "file is empty!";
	}
}


QueryResult::~QueryResult()
{
}

ostream & print_result(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << (qr.lines->size() > 1 ? " times: " : " time: ") << endl;
	for (auto line : *qr.lines)
	{
		StrBlobPtr p(qr.file, line);
		cout << "(Line " << line + 1 << ") " << p.deref() << endl;
	}	
	return os;
}
