#ifndef PYTHON_LIST
#define PYTHON_LIST
#include <string>
#include <iostream>
using namespace::std;

const int MAX_CELLS = 1000;      // Value for the size of the fixed array of data - can be changed by replacing the 1000 with any positive value
class PythonList 
{
	// functions with List arguments

	friend int    len(const PythonList & parm);
	friend int    comp(const PythonList & left, const PythonList & right); // -1, 0, or 1
	friend string max(const PythonList & aList);
	friend string min(const PythonList & aList);

	// operators that must be implemented as friends since the left operand is NOT a PythonList

	friend bool inOperator(string lookFor, const PythonList & listToCheck);
	                     //  Python syntax 
	                     //   horsemen = ["war", "famine", "pestilence", "death"]
                         //  "pestilence" in horsemen
	friend bool notInOperator(string lookFor, const PythonList & listToCheck);   //  use the inOperator and negate the return value 
	         

	//  useful operator for the C++ PythonList class, but not in Python
	friend ostream & operator<< ( ostream & out, const PythonList & parm);
	            //   output in the form:   [ "apple", "pear", "peach" ]
public:

	PythonList();     // default constructor
	PythonList(const PythonList & listParm);     // copy constructor
	PythonList( const string[], int num_cells);  // argument constructor, array of strings
	PythonList( string stringInListNotation);    // parameter of the form  ["apple","pear","peach"], 
	     // will need C++ string Class manipulation operators and methods

	// Python Methods
	void append(string item);
	void extend(const PythonList & listToAdd);
	void insert(int index, string itemToInsert);
	void remove(string itemToRemove); //Remove the first item from the list whose value is itemToRemove. 
	       // It is an error if there is no such item.
	string pop(int positionToRemove);    // return the value of the item removed at positionToRemove
	string pop();                      // remove the last item in the list, return the value of the item removed
	int  index(string itemToFind) const; // Return the index in the list of the first item whose value is xitemToFind. 
	    // It is an error if there is no such item.
	int  count(string itemToCount) const;
	void sort();                      //   sort the list in place, will not implement a 
	                                         // customized sort
	void reverse();                   //   reverse the elements in place

	// Python operators
	bool           operator == ( const PythonList & right) const;  //  test for equality operator
	                //if a is["bill", "sue", "sam", "ann"]
	                //	a[-1] is "ann", a[-2] is "sam", a[-3] is "sue" and a[-4] is "bill"
	string &       operator[](int index);                        //  index operator for l-value
	const string & operator[](int index) const;                  //  index operator for r-value
	PythonList     operator+(const PythonList & right) const;      //  will return by value a concateneated list
	PythonList     operator*(int times) const;                     //  see documentation for behavior of * operator

	const PythonList & operator=(const PythonList & right);  // this is NOT the python = operator, which creates an alias
	                                                         //  rather, this operator changes the object on the left side of the = operator



private:
    string data[MAX_CELLS];
	int itemCount;      // indicates the count of the number of items
	               //    in the list;
};


#endif