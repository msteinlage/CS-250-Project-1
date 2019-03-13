#include "pythonListFA.h"
#include <algorithm>
#include <string.h>
#include <iostream>

// TODO DELETE
#include <string>


// Constructors
PythonList::PythonList(void)   // this method is correct
{
	itemCount = 0;            
}

PythonList::PythonList(const PythonList & listParm)    // copy constructor, this method is correct
{
    itemCount = listParm.itemCount;
	for ( int i = 0; i < itemCount; i++)
		data[i] = listParm.data[i];
}

PythonList::PythonList( const string info[], int num_cells)   // this method is correct
{
    itemCount = num_cells;
	for ( int i=  0; i < itemCount; i++)
		data[i] = info[i];
}




// Python Methods
void PythonList::append(string item)
{
	data[itemCount] = item;
	itemCount++;

}
void PythonList::extend(const PythonList & listToAdd)
{
	for (int i = 0; i < listToAdd.itemCount; i++)
		append(listToAdd.data[i]);

}
void PythonList::insert(int index, string itemToInsert)
{
	for (int i = itemCount; i > index; i--)
		data[i] = data[i - 1];
	data[index] = itemToInsert;
	itemCount++;

}
void PythonList::remove(string itemToRemove) //Remove the first item from the list whose value is itemToRemove. 
	       // It is an error if there is no such item.
{
	for (int i = 0; i < itemCount; i++)
		if (data[i] == itemToRemove)
		{
			for (int j = i; j < itemCount - 1; j++)
				data[j] = data[j + 1];
			itemCount--;
		}
}
string PythonList::pop(int positionToRemove)
{

	string popped = data[positionToRemove];
	itemCount--;
	return popped;

	/*
	if (positionToRemove >= 0 && positionToRemove <= itemCount)
	{
		popped = data[positionToRemove];

		for (int i = positionToRemove; i < itemCount - 1; i++)
		{
			data[i] = data[i + 1];

		}
		itemCount--;
	}
	
	return popped; // Dummy Statement to get to compile
	)*/
}

string PythonList::pop()                      // remove the last item in the list
{
	string popped = data[itemCount];
	itemCount--;
	return popped; // Dummy Statement to get to compile
}

int  PythonList::index(string itemToFind) const // Return the index in the list of the first item whose value is xitemToFind. 
	    // It is an error if there is no such item.
{
	//int index;
	for (int i = 0; i < itemCount; i++) 
	{
		//item = data[i];
		if (data[i] == itemToFind)
		{
			return i;
		}
	}
	
	
	
}

int  PythonList::count(string itemToCount) const
{
	int count = 0;
	for (int i = 0; i < itemCount; i++) 
	{
		if (data[i] == itemToCount) 
		{
			count++;
		}
	}
	return count;    
}

void PythonList::sort()                     //   sort the list in place, will not implement a 
{
	
	std::sort(data, data + itemCount);
	
}

	                                         
void PythonList::reverse()                 //   reverse the elements in place
{
	
	string temp = "";
	if (itemCount %2 != 0) 
	{
		itemCount++;
	}
	
	for(int i = 0; i < itemCount/2; i++)
	{
		temp = data[itemCount - i - 1];
		data[itemCount - i - 1] = data[i];
		data[i] = temp;


		cout << "********** TEMP: " << data[i] << endl;
	}
}

// functions with List arguments

int len(const PythonList & parm)      // Correct Code
{
	return parm.itemCount;
}





int    comp(const PythonList & left, const PythonList & right) // -1, 0, or 1
{
	auto GetWeight = [&](const PythonList& a, const PythonList& b) {
		int sumA = 0;
		int sumB = 0;
		for (string s : a.data) {
			for (char c : s) sumA += c;
		}

		for (string s : b.data) {
			for (char c : s) sumB += c;
		}

		cout << "SUM_A : " << sumA << endl;
		cout << "SUM_B : " << sumB << endl;
	};

	//GetWeight(left, right);

	if (left.itemCount > right.itemCount)
		return 1;
	if (left.itemCount < right.itemCount)
		return -1; 
	/*
	Left [0] = "ZZZ"
	Left [1] = "ZZZ"

	Right [0] = "A"
	Right [1] = "A"
	Right [2] = "A"
		*/


	for (int i = 0; i < left.itemCount; i++) {
		if (left.data[i] < right.data[i]) {

			cout << "lEFT"  << left.data[i] << "right" << right.data[i] << endl;
			return -1;
		}
		//cout << "Left: " << left.data[i] << "     Right: " << right.data[i] << endl;
		else if (left.data[i] > right.data[i]) {
			cout << "LEFT" << endl;
			return 1;
		}
		else
		
			cout << "SAME" << endl;
	}

	return 0;
	/*
	if (left.data == right.data)
		return 0;
	else if (left.data < right.data)
		return -1;
	else
		return 1;
		*/

	
	//int itemCount = left.count;
	/*
	int tester = 0;
	char selectL[100], selectR[100];
	if (left.itemCount < right.itemCount)
		return 1;
	else if (left.itemCount > right.itemCount)
		return -1;
	for (int i = 0; i < left.itemCount; i++)
		if (left[i] != right[i])
			return -1;

	return tester;
	*/
	
	//while (left[i] != left[left.itemCount])
	

}





string max(const PythonList & aList)
{
	string tempM;
	for (int i = 0; i < aList.itemCount - 1; i++) {

		if (aList[i] > aList[i+1])
			tempM = aList[i];

	}
	return tempM;
}

string min(const PythonList & aList)
{
	return " ";    // Dummy Statement to get to compile

}

// Python operators

bool PythonList::operator == ( const PythonList & right) const
{
   
	return true;      // Dummy Statement to get to compile
}

//  if a is["bill", "sue", "sam", "ann"]
//  a[-1] is "ann", a[-2] is "sam", a[-3] is "sue" and a[-4] is "bill"
string &   PythonList::operator [] (int index)                        //  index operator for l-value
{
    if ( index >= 0 ) return data[index];                         // CORRECT CODE
	return data[itemCount + index];                // for negative values of index
}

const string & PythonList::operator[](int index) const               //  index operator for r-value
{
	if ( index >= 0 ) return data[index];                        // CORRECT CODE
	return data[itemCount + index];                // for negative values of index
}

PythonList PythonList::operator+(const PythonList & right) const    //  will return by value a concateneated list
{
	PythonList ans;    // Dummy Code to get to compile


	return ans;
}

PythonList PythonList::operator*(int times) const                    //  see documentation for behavior of * operator
{
	PythonList ans;    // Dummy Code to get to compile
	

	return ans;
}


// operators that must be implemented as friends since the left operand is NOT a PythonList

bool inOperator(string lookFor, const PythonList & listToCheck)
	                     //  Python syntax 
	                     //   horsemen = ["war", "famine", "pestilence", "death"]
                         //  "pestilence" in horsemen
{

	return true;    // Dummy Statement to get to compile
}

bool notInOperator(string lookFor, const PythonList & listToCheck)   //  use the inOperator and negate the return value 
{

	return true;    // Dummy Statement to get to compile
}





//  useful operator for the C++ PythonList class, but not in Python

	            //   output in the form:   ["apple","pear","peach"]
ostream & operator << ( ostream & out, const PythonList & parm)                  // this operator is correct
{
	out << '[';
	for ( int i = 0; i < parm.itemCount; i++)
	{
		out << '"' << parm.data[i] << '"';
		if ( i != (parm.itemCount - 1) ) out << ',';
	}
	out << ']';
	return out;
}

// the = operator is correct
const PythonList & PythonList::operator=(const PythonList & right)  // this is NOT the python = operator, which creates an alias
{	                                                         //  rather, this operator changes the object on the left side of the = operator
    if ( this == & right ) return *this;
    itemCount = right.itemCount;
    for ( int i = 0; i < itemCount; i++)
	    data[i] = right.data[i];

    return *this;

}