//===============================================================
// Emma Steinman
// September 1, 2017
// set.h
// This is the header file for the set class. It declares methods
// to create and modify sets.
//===============================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//===============================================================

#ifndef SET_H
#define SET_H

template <class Element>
class Node
{
public:
	Element 		data;
	Node<Element> * next;


	Node (Element item)
	{
		data = item;
		next = NULL;
	}
};

template <class Element>
class Set
{
public:
				Set			(void);							//default constructor
				Set			(const Set<Element> & s);		//copy constructor
				~Set		(void);							//destructor

	void		insert		(const Element & x);
	void		remove		(const Element & x);
	int			cardinality	(void) const;
	bool		empty		(void) const;
	bool		contains	(const Element & x) const;	
	
	bool 		operator== 	(const Set<Element> & s) const;	//equality
	bool 		operator<= 	(const Set<Element> & s) const;	//subset
	Set<Element>& operator+ (const Set<Element> & s) const;	//union
	Set<Element>& operator& (const Set<Element> & s) const;	//intersection
	Set<Element>& operator- (const Set<Element> & s) const; //difference

	Set<Element>& operator= (const Set<Element> & s); 		//assignment

	string		toString	(void) const;

	friend ostream& operator<< (ostream & stream, const Set<Element> & s)
	{
		stream << s.toString();	
		return stream;
	}
	
private:
	Node<Element> * head;
	int				length;
	void		copy		(const Set<Element> & s);
	void		destroy		(void);
};


#include "set.cpp"
#endif
