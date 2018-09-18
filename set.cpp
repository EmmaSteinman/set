//============================================================
// Emma Steinman
// September 1, 2017
// set.cpp
// This is the .cpp file for the Set class. It contains 
// methods for creating and modifying sets.
//============================================================

//============================================================
//default constructor
//============================================================
template <class Element>
		Set<Element>::Set		(void)
{
	head = NULL;
	length = 0;
}
//============================================================
//copy constructor
//copies a set from an existing set
//============================================================
template <class Element>
		Set<Element>::Set		(const Set<Element> & s)
{
	head = NULL;
	length = 0;
	copy(s);
		
}
//============================================================
//destructor
//============================================================
template <class Element>
		Set<Element>::~Set		(void)
{
	destroy();
}

//============================================================
//toString
//inserts items in a set into a printable string
//============================================================ 
template <class Element>
string	Set<Element>::toString	(void) const
{
	stringstream s;
	s << "{";
	Node<Element> * ptr = head;
	for (int i = 0; i < length; i++)
	{
		s << ptr->data;
		if (i+1 < length)
			s << ", ";
		ptr = ptr->next;
	}
	s << "}";
	return s.str();
}

//============================================================
//insert
//inserts an item into a set
//============================================================
template <class Element>
void	Set<Element>::insert	(const Element & x)
{

	if (!contains(x))
	{
		Node<Element> * ptr = new Node<Element>(x);

		if (head == NULL)				//if set is empty
			head = ptr;

		else
		{
			Node<Element> * qtr = head;	//nonempty set
			while (qtr->next!= NULL)
				qtr = qtr->next;
			qtr->next = ptr;
		}

		length += 1;					//increments length
	}
		
}

//============================================================
//remove
//removes an item from a set
//============================================================
template <class Element>
void	Set<Element>::remove	(const Element & x)
{	
		if (!contains(x))			//item already in set
		{
			cout << "Error: item not in set." << endl;
			return;
		}
	
		Node<Element> * ptr = head;
		Node<Element> * qtr = head;
		Node<Element> * rm;

		while (qtr->next->data != x)
		{
			qtr = qtr->next;		//finds node before one to 
		}							//be deleted

		ptr = qtr->next;			
		rm = qtr->next;				//node to be deleted
		ptr = ptr->next;			//next node
		qtr->next = ptr;			//skips node to be deleted
		delete rm;					
		length -= 1;				//decrements length
	
}

//============================================================
//cardinality
//returns the number of items in a set
//============================================================
template <class Element>
int		Set<Element>::cardinality (void) const
{
	return length;
}

//============================================================
//empty
//returns a boolean value indicating if the set is empty
//============================================================
template <class Element>
bool	Set<Element>::empty		(void) const
{
	return (length == 0);
}

//============================================================
//contains
//returns a boolean value indicating if a set contains an item
//============================================================
template <class Element>
bool	Set<Element>::contains	(const Element & x) const
{
	Node<Element> * ptr = head;

	while (ptr != NULL)
	{
		if (ptr-> data == x)
			return true;
		ptr = ptr->next;
	}	

	return false;
}

//============================================================
//operator == 
//returns a boolean value indicating if the two sets are equal
//============================================================
template <class Element>
bool	Set<Element>::operator==	(const Set<Element> & s) const
{
	if (length != s.length)
		return false;

	else
	{
		Node<Element> * ptr = head;

		while (ptr != NULL)		
		{
			if (!s.contains(ptr->data))
				return false;
			ptr = ptr->next;
		}

		return true;
	}
}

//============================================================
//operator <=
//returns a boolean value indicating if the set is a subset
//of another set
//============================================================
template <class Element>
bool	Set<Element>::operator<=	(const Set<Element> & s) const
{
	if (s.length == 0)
		return true;					//empty set is always 
										//a subset
	Node<Element> * ptr = head;			

	while (ptr != NULL)
	{
		if (!s.contains(ptr->data))
			return false;

		ptr = ptr->next;
	}

	return true;
}

//============================================================
//operator +
//returns the union of two sets
//============================================================
template <class Element>
Set<Element>&	Set<Element>::operator+	(const Set<Element> & s) const
{
	Set<Element> *s1 = new Set();
	Node<Element> * ptr = head;

	while (ptr != NULL)				//inserts elements from 
	{								//first set
		s1->insert(ptr->data);
		ptr = ptr->next;
	}

	Node<Element> * qtr = s.head;
	while (qtr != NULL)				//inserts elements from
	{								//second set
		s1->insert(qtr->data);
		qtr=qtr->next;
	}

	return *s1;

}

//============================================================
//operator &
//returns the intersection of two sets
//============================================================
template <class Element>
Set<Element>&	Set<Element>::operator&	(const Set<Element> & s) const
{
	Set<Element> *s1 = new Set();
	Node<Element> * ptr = head;

	while (ptr != NULL)
	{
		if (s.contains(ptr->data))		//inserts values in 
			s1->insert(ptr->data);		//both sets
		ptr = ptr->next;
	}
	
	return *s1;
}


//============================================================
//operator -
//returns the difference of two sets
//============================================================
template <class Element>
Set<Element>&	Set<Element>::operator-	(const Set<Element> & s) const
{
	Set<Element> *s1 = new Set();
	Node<Element> * ptr = head;

	while (ptr != NULL)
	{
		if (!s.contains(ptr->data))		//inserts values not in
			s1->insert(ptr->data);		//second set
		ptr = ptr->next;
	}
		
	return *s1;
}


//============================================================
//operator =
//sets a set equal to an existing set
//============================================================
template <class Element>
Set<Element>&	Set<Element>::operator=	(const Set<Element> & s)
{
	if (length > 0)						//clears nonempty set
	{									//before copying
		Node<Element> * ptr = head;
		Node<Element> * qtr = head;

		while (ptr != NULL)
		{
			qtr = ptr->next;
			delete ptr;
			ptr = qtr;
		}	

		head = NULL;
		length = 0;
	}

	this->copy(s);						//copies second set
	return *this;
}



//============================================================
//copy
//copies the set s to this set
//============================================================
template <class Element>
void			Set<Element>::copy		(const Set<Element> &s)
{
	Node<Element> *ptr1;
	ptr1 = s.head;

	while (ptr1 != NULL)
	{
		insert(ptr1->data);
		ptr1 = ptr1->next;
	}
}



//============================================================
//destroy
//deletes items from set and the memory
//============================================================

template <class Element>
void			Set<Element>::destroy	(void)
{
	Node<Element> * ptr, * qtr;
	ptr = head;
	qtr = head;

	while (ptr != NULL)
	{
		qtr = ptr -> next;		
		delete ptr;
		ptr = qtr;
		
	}
	delete ptr;
	length = 0;
}




