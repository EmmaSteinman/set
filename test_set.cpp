//============================================================
//Emma Steinman
//September 2, 2017
//test_set.cpp
//This file contains non-terminal testing for the set class
//============================================================

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>
#include "set.h"
using namespace std;

//============================================================
// tests default constructor
//============================================================

void test1 (void)
{
	Set<int> s1;
	string str = s1.toString();
	assert(str=="{}");
	
}

//============================================================
// tests insert
//============================================================

void test2 (void)
{
	Set<int> s1;
	s1.insert(1);
	s1.insert(4);
	s1.insert(89);
	s1.insert(3);
	string str = s1.toString();
	assert(str=="{1, 4, 89, 3}");
}

//============================================================
// tests copy constructor
//============================================================

void test3 (void)
{
	Set<int> s1;
	s1.insert(4);
	s1.insert(44);
	s1.insert(55);
	Set<int> s2(s1);
	string str = s2.toString();

	assert(str == "{4, 44, 55}");
}

//============================================================
// tests remove
//============================================================

void test4 (void)
{
	Set<char> s1;
	s1.insert('s');
	s1.insert('e');
	s1.insert('a');
	s1.insert('g');
	s1.insert('z');

	s1.remove('a');

	string str = s1.toString();
	assert(str == "{s, e, g, z}");
}

//============================================================
// tests cardinality
//============================================================

void test5 (void)
{
	Set<int> s1;
	s1.insert(4);
	s1.insert(8);
	s1.insert(12);
	s1.insert(16);
	int length = s1.cardinality();
	assert (length == 4);
}

//============================================================
// tests ==
//============================================================
void test6 (void)
{
	Set<char> s1;
	Set<char> s2;
	for (char letter = 'a';letter<='z';letter++)
	{
		s1.insert(letter);
		s2.insert(letter);
	}

	if (s1==s2)
		return;
	
	else
		cout << "Test 6 failed." << endl;
}
//============================================================
// tests contains
//============================================================

void test7 (void)
{
	Set<int> s1;
	for (int i = 0; i < 8; i++)
		s1.insert(i);
	if (s1.contains(3))
		return;
	else
		cout << "Test 7 failed" << endl;
}


//============================================================
// tests union
//============================================================

void test8 (void)
{
	Set<int> s1;
	for (int i = 0; i<6; i++)
		s1.insert(i);
	Set<int> s2;
	for (int i = 6; i<11; i++)
		s2.insert(i);
	Set<int> s3;
	s3.insert(5);
	s3.insert(3);
	s3.insert(6);
	s3 = s1+s2;
	string str = s3.toString();
	assert(str == "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");
}

//============================================================
//tests copy to an empty list
//============================================================

void test9 (void)
{
	Set<int> s1;
	for (int i = 0; i < 6; i++)
		s1.insert(i);
	Set<int> s2(s1);
	string str = s2.toString();
	assert(str == "{0, 1, 2, 3, 4, 5}");
}

//============================================================
//tests operator =
//============================================================

void test10	(void)
{
	Set<char> s1;
	for (char a = 'a'; a<='z'; a++)
		s1.insert(a);
	Set<char> s2;
	s2 = s1;
	string str = s2.toString();
	assert(str == "{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}");
}


//============================================================
//tests operator &
//============================================================

void test11	(void)
{
	Set<char> s1;
	for (char a = 'a'; a<='e'; a++)
		s1.insert(a);
	Set<char> s2;
	for (char f = 'c'; f<= 'j'; f++)
		s2.insert(f);
	Set<char> s3;	
	s3 = s1 & s2;
	string str = s3.toString();
	assert(str == "{c, d, e}");
}

//============================================================
//tests remove with item not in list
// TERMINAL
//============================================================

void test12	(void)
{
	Set<char> s1;
	for (char a = 'a'; a < 'r'; a++)
		s1.insert(a);
	s1.remove('z');

	
}


//============================================================
//tests operator -
//============================================================

void test13	(void)
{
	Set<int> s1;
	Set<int> s2;
	for (int i = 0; i <= 10; i++)
		s1.insert(i);
	for (int i = 0; i <=10; i+=2)
		s2.insert(i);
	Set<int> s3;	
	s3 = s1-s2;
	string str = s3.toString();
	assert(str == "{1, 3, 5, 7, 9}");
}

//============================================================
//tests operator = with items in set previously
//============================================================

void test14	(void)
{
	Set<int> s1;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	Set<int> s2;
	for (int j = 0; j < 3; j++)
		s2.insert(j);
	s2 = s1;
	string str = s2.toString();
	assert(str=="{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}");
}

//============================================================
//tests operator<=
//============================================================
void test15	(void)
{
	Set<int> s1;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	Set<int> s2;
	for (int j = 0; j < 3; j++)
		s2.insert(j);
	if (s2 <= s1)
		return;
	else
		cout << "test 15 failed" << endl;
}

//============================================================
//tests insert with existing item
//TERMINAL
//============================================================

void test16	(void)
{
	Set<int> s1;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	for (int j = 5; j < 15; j++)
		s1.insert(j);
	string str = s1.toString();
	assert(str=="{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}");
}

//============================================================
//tests <= with empty set
//============================================================

void test17	(void)
{
	Set<int> s1;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	Set<int> s2;
	if (s1 <= s2)
		return;
	else
		cout << "test 17 failed" << endl;
}

//============================================================
//tests intersection between two different sets
//============================================================

void test18()
{
	Set<int> s1;
	for (int i = 0; i<6; i++)
		s1.insert(i);
	Set<int> s2;
	for (int i = 6; i<11; i++)
		s2.insert(i);
	Set<int> s3;
	s3 = s1&s2;
	string str = s3.toString();
	assert(str == "{}");
}

//============================================================
//tests difference between two different sets
//============================================================

void test19()
{
	Set<int> s1;
	for (int i = 0; i<6; i++)
		s1.insert(i);
	Set<int> s2;
	for (int i = 6; i<11; i++)
		s2.insert(i);
	Set<int> s3;
	s3 = s1-s2;
	string str = s3.toString();
	assert(str == "{0, 1, 2, 3, 4, 5}");
}

//============================================================
//tests cardinality of empty set
//============================================================

void test20	(void)
{
	Set<char> s1;
	assert(s1.cardinality() == 0);
}

//============================================================
//tests difference operator with a bigger second set
//============================================================

void test21	(void)
{
	Set<int> s1;
	for (int i = 0; i<6; i++)
		s1.insert(i);
	Set<int> s2;
	for (int i = 0; i<11; i++)
		s2.insert(i);
	Set<int> s3 = s1 - s2;
	string str = s3.toString();
	assert(str == "{}");
}

//============================================================
//tests == with non equal sets
//============================================================

void test22	(void)
{
	Set<int> s1;
	for (int i = 0; i<6; i++)
		s1.insert(i);
	Set<int> s2;
	for (int i = 6; i<11; i++)
		s2.insert(i);
	if (s1 == s2)
		cout << "Test 22 failed" << endl;

}

//============================================================
//tests string set
//============================================================

void test23 (void)
{
	Set<string> s1;
	s1.insert("Emma");
	s1.insert("Eliza");
	s1.insert("Evelyn");
	assert(s1.toString()=="{Emma, Eliza, Evelyn}");
}

//============================================================
// tests contains when item not in set
//============================================================

void test24 (void)
{
	Set<int> s1;
	for (int i = 0; i<6; i++)
		s1.insert(i);
	bool cont = s1.contains(6);
	assert(cont==0);
}


int main (void)
{
	
	test1();
	test2();
	test3();
	test4();
	test5();
	test2();
	test6();
	test7();
	
	test8();
	test9();

	test10();
	test11();
	//test12();
	test13();
	test14();
	test15();
	test16();
	test17();
	test18();
	test19();
	test20();
	test21();
	test22();
	test23();
	test24();
	return 0;
}








