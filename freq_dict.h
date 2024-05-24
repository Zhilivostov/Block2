#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <algorithm>	
#include <utility>

class dict_abstract {

public:

	virtual void add_dict(const std::string&) = 0;

	virtual std::pair<std::string, size_t> get_dict() = 0;
};

class dict_map final : public dict_abstract {
private:

	std::map<std::string, size_t> dict;

	std::map<std::string, size_t>::iterator it;   

	bool reload = true;

public:

	std::map<std::string, size_t>::iterator begin();

	std::map<std::string, size_t>::iterator end();
	
	virtual void add_dict(const std::string&) override;

	virtual std::pair<std::string, size_t> get_dict() override;
};

class dict_unordered_map final : public dict_abstract {
private:

	std::unordered_map<std::string, size_t> dict;

	std::unordered_map<std::string, size_t>::iterator it;

	bool reload = true;

public:

	std::unordered_map<std::string, size_t>::iterator begin();

	std::unordered_map<std::string, size_t>::iterator end();

	virtual void add_dict(const std::string&) override;

	virtual std::pair<std::string, size_t> get_dict() override;
};

class dict_vector final : public dict_abstract {
private:

	std::vector< std::pair<std::string, size_t> > dict;

	std::vector<std::pair<std::string, size_t> >::iterator it;

	bool reload = true;

public:

	std::vector<std::pair<std::string, size_t> >::iterator begin();

	std::vector<std::pair<std::string, size_t> >::iterator end();

	virtual void add_dict(const std::string&) override;

	virtual std::pair<std::string, size_t> get_dict() override;
};

class dict_list final : public dict_abstract {
private:

	std::list< std::pair<std::string, size_t> > dict;

	std::list<std::pair<std::string, size_t> >::iterator it;

	bool reload = true;

public:

	std::list<std::pair<std::string, size_t> >::iterator begin();

	std::list<std::pair<std::string, size_t> >::iterator end();

	virtual void add_dict(const std::string&) override;

	virtual std::pair<std::string, size_t> get_dict() override;
};

class dict_set final : public dict_abstract {
private:

	std::set< std::pair<std::string, size_t> > dict;

	std::set<std::pair<std::string, size_t> >::iterator it;

	bool reload = true;

public:

	std::set<std::pair<std::string, size_t> >::iterator begin();

	std::set<std::pair<std::string, size_t> >::iterator end();

	virtual void add_dict(const std::string&) override;

	virtual std::pair<std::string, size_t> get_dict() override;
};

class dict_unordered_set final : public dict_abstract {
private:

	typedef std::pair<std::string, int> Pair;

	struct pair_hash
	{
		size_t operator () (std::pair<std::string, size_t> const& pair) const
		{
			size_t h1 = std::hash<std::string>()(pair.first);
			size_t h2 = std::hash<size_t>()(pair.second);

			return h1 ^ h2;
		}
	};

	std::unordered_set< std::pair<std::string, size_t>, pair_hash > dict;

	std::unordered_set< std::pair<std::string, size_t>, pair_hash >::iterator it;

	bool reload = true;

public:

	std::unordered_set< std::pair<std::string, size_t>, pair_hash >::iterator begin();

	std::unordered_set< std::pair<std::string, size_t>, pair_hash >::iterator end();

	virtual void add_dict(const std::string&) override;

	virtual std::pair<std::string, size_t> get_dict() override;
};