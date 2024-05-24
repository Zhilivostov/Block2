//#include "pch.h"
#include <gtest/gtest.h>
#include "parser.h"
#include <fstream>
#include <iostream>

//TEST(Test, test1) {
//	EXPECT_EQ(1, 1);
//}

std::istringstream ss("The Road Not Taken\n"
	"Two roads diverged in a yellow wood,\n"
	"And sorry I could not travel both\n"
	"And be one traveler, long I stood\n"
	"And looked down one as far as I could\n"
	"To where it bent in the undergrowth.\n"

	"Then took the other, as just as fair,\n"
	"And having perhaps the better claim,\n"
	"Because it was grassy and wanted wear;\n"
	"Though as for that the passing there\n"
	"Had worn them really about the same.\n"

	"And both that morning equally lay\n"
	"In leaves no step had trodden black.\n"
	"Oh, I kept the first for another day!\n"
	"Yet knowing how way leads on to way,\n"
	"I doubted if I should ever come back.\n"

	"I shall be telling this with a sigh\n"
	"Somewhere ages and ages hence :\n"
	"Two roads diverged in a wood, and I -\n"
	"I took the one less traveled by,\n"
	"And that has made all the difference.\n");

TEST(Test_work, Map)
{
	dict_map a;
	parser p;
	p.read_text(ss, a);
	p.write_result("result_map.txt", a);
	const std::string file = "result_map.txt";
	std::ifstream in(file);
	std::string first, second, third;
	in >> first >> second >> third;
	EXPECT_EQ(first, "a");
	EXPECT_EQ(third, "3");
}

TEST(Test_work, Unordered_map)
{
	dict_unordered_map a;
	parser p;
	p.read_text(ss, a);
	p.write_result("result_unordered_map.txt", a);
	const std::string file = "result_unordered_map.txt";
	std::ifstream in(file);
	std::string first, second, third;
	in >> first >> second >> third;
	EXPECT_EQ(first, "the");
	EXPECT_EQ(third, "9");
}

TEST(Test_work, Vector)
{
	dict_vector a;
	parser p;
	p.read_text(ss, a);
	p.write_result("result_vector.txt", a);
	const std::string file = "result_vector.txt";
	std::ifstream in(file);
	std::string first, second, third;
	in >> first >> second >> third;
	EXPECT_EQ(first, "the");
	EXPECT_EQ(third, "9");
}

TEST(Test_work, List)
{
	dict_list a;
	parser p;
	p.read_text(ss, a);
	p.write_result("result_list.txt", a);
	const std::string file = "result_list.txt";
	std::ifstream in(file);
	std::string first, second, third;
	in >> first >> second >> third;
	EXPECT_EQ(first, "the");
	EXPECT_EQ(third, "9");
}

TEST(Test_work, Set)
{
	dict_set a;
	parser p;
	p.read_text(ss, a);
	p.write_result("result_set.txt", a);
	const std::string file = "result_set.txt";
	std::ifstream in(file);
	std::string first, second, third;
	in >> first >> second >> third;
	EXPECT_EQ(first, "a");
	EXPECT_EQ(third, "3");
}

TEST(Test_work, Unordered_set)
{
	dict_unordered_set a;
	parser p;
	p.read_text(ss, a);
	p.write_result("result_unordered_set.txt", a);
	const std::string file = "result_unordered_set.txt";
	std::ifstream in(file);
	std::string first, second, third;
	in >> first >> second >> third;
	EXPECT_EQ(first, "in");
	EXPECT_EQ(third, "4");
}

TEST(Test_crush, Read_text)
{
	dict_map a;
	parser p;
	//EXPECT_ANY_THROW(p.read_text("",a));
	//EXPECT_ANY_THROW(p.read_text("task_empty.txt", a));
	EXPECT_ANY_THROW(a.add_dict(""));
	EXPECT_ANY_THROW(p.filter(""));

}

TEST(Test_crush, Write_result)
{
	dict_map a;
	parser p;
	EXPECT_ANY_THROW(a.get_dict());
	EXPECT_ANY_THROW(p.write_result("", a));
	EXPECT_ANY_THROW(p.write_result(" ", a));
}