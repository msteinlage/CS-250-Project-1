#include <iostream>
#include <string>
using namespace::std;
#include "pythonListFA.h"
#include "PythonListTester.h"
const int NUMBER_NAMES = 25;

const string names[NUMBER_NAMES] = { "method append(string item)","method extend(const PythonList & listToAdd)","method insert(int index, string itemToInsert)","method remove(string itemToRemove)",
	"method pop(int positionToRemove)","method pop()","method index(string itemToFind)","method int  count(string itemToCount)","method sort()","method reverse()",
    "function int    len(const PythonList & parm)","function int    comp(const PythonList & left, const PythonList & right)","function string max(const PythonList & aList)",
	"function string min(const PythonList & aList)",
    "operator bool           operator == ( const PythonList & right)","operator string &       operator [] (int index)","operator const string & operator[](int index)",
	"operator PythonList     operator+(const PythonList & right)","operator PythonList     operator*(int times)",
    "operator bool inOperator(string lookFor, const PythonList & listToCheck)","operator  bool notInOperator(string lookFor, const PythonList & listToCheck)",
    "constructor PythonList()","constructor PythonList(const PythonList & listParm)","constructor PythonList( const string[], int num_cells)",
	"TEST ALL"}; 
/*
0 method append(string item)
1 method extend(const PythonList & listToAdd)
2 method insert(int index, string itemToInsert)
3 method remove(string itemToRemove)
4 method pop(int positionToRemove)
5 method pop()
6 method index(string itemToFind)
7 method int  count(string itemToCount)
8 method sort()
9 method reverse()
10 function int    len(const PythonList & parm)
11 function int    comp(const PythonList & left, const PythonList & right)
12 function string max(const PythonList & aList)
13 function string min(const PythonList & aList)
14 operator bool           operator == ( const PythonList & right)
15 operator string &       operator [] (int index)
16 operator const string & operator[](int index)
17 operator PythonList     operator+(const PythonList & right)
18 operator PythonList     operator*(int times)
19 operator bool inOperator(string lookFor, const PythonList & listToCheck)
20 operator  bool notInOperator(string lookFor, const PythonList & listToCheck)
21 constructor PythonList()
22 constructor PythonList(const PythonList & listParm)
23 constructor PythonList( const string[], int num_cells)
24 TEST ALL

*/
int menu();	
void visualTest();

void main()
{
	visualTest();                   // comment this line out when visual testing is not needed
	PythonListTester test;
	int choice = 0;
	while (choice != -1 )
	{
		choice = menu();
		switch(choice) {
		   case 0:  cout << "score for " << names[choice] << " is " << test.testAppend() << endl;
			        break;
		   case 1:  cout << "score for " << names[choice] << " is " << test.testExtend() << endl; 
			        break;
		   case 2:  cout << "score for " << names[choice] << " is " << test.testInsert() << endl;
			        break;
		   case 3:  cout << "score for " << names[choice] << " is " << test.testRemove() << endl; 
			        break;
		   case 4:  cout << "score for " << names[choice] << " is " << test.testPopWithArguments() << endl; 
			        break;
		   case 5:  cout << "score for " << names[choice] << " is " << test.testPopNoArguments() << endl;
			        break;
		   case 6:  cout << "score for " << names[choice] << " is " << test.testIndex() << endl;
			        break;
		   case 7:  cout << "score for " << names[choice] << " is " << test.testCount() << endl;
			        break;
		   case 8:  cout << "score for " << names[choice] << " is " << test.testSort() << endl;
			        break;
		   case 9:  cout << "score for " << names[choice] << " is " << test.testReverse() << endl;
			        break;
		   case 10: cout << "score for " << names[choice] << " is " << test.testLenFunction() << endl;
			        break;
		   case 11: cout << "score for " << names[choice] << " is " << test.testCompFunction() << endl;
			        break;
		   case 12: cout << "score for " << names[choice] << " is " << test.testMaxFunction() << endl;
			        break;
		   case 13: cout << "score for " << names[choice] << " is " << test.testMinFunction() << endl;
			        break;
		   case 14: cout << "score for " << names[choice] << " is " << test.testEqOperator() << endl;
			        break;
		   case 15: cout << "score for " << names[choice] << " is " << test.testIndexOperatorLvalue() << endl;
			        break;
		   case 16: cout << "score for " << names[choice] << " is " << test.testIndexOperatorRvalue() << endl;
			        break;
		   case 17: cout << "score for " << names[choice] << " is " << test.testPlusOperator() << endl;
			        break;
		   case 18: cout << "score for " << names[choice] << " is " << test.testTimesOperator() << endl;
			        break;
		   case 19: cout << "score for " << names[choice] << " is " << test.testInOperator() << endl;
			        break;
		   case 20: cout << "score for " << names[choice] << " is " << test.testNotInOperator() << endl;
			        break;
		   case 21: cout << "score for " << names[choice] << " is " << test.testDefaultConstructor() << endl;
			        break;
		   case 22: cout << "score for " << names[choice] << " is " << test.testCopyConstructor() << endl;
			        break;
		   case 23: cout << "score for " << names[choice] << " is " << test.testArrayArgumentConstructor() << endl;
			        break;
		   case 24: cout << "score for " << names[choice] << " is " << test.runAllTests() << endl; 
			        break;
		   default: break;
		};
	}
	
}    // end main

int menu()
{
	cout << endl << endl;
	cout << "Select for the following = use -1 to quit" << endl;
	for(int i = 0; i < NUMBER_NAMES; i++)
		cout << i <<  ' ' << names[i] << endl;
	int choice;
	cin >> choice;
	return choice;
}

void visualTest()
{
	cout << "Starting Visual Test" << endl;
	// for some of the following, show some visual testing that you used
	string d[4] = { "one","two","three","four" };
	PythonList a(d, 4);

	string d2[5] = { "for","int","if","while","bool" };
	PythonList keyWords(d2, 5);
	cout << "a is " << a << endl << endl;
	cout << "keyWords is " << keyWords << endl;

	//0 method append(string item)





	//1 method extend(const PythonList & listToAdd)
	cout << "Before extend a is " << endl;
	a.extend(keyWords);
	cout << "After extend a is " << a << endl << endl;



	//2 method insert(int index, string itemToInsert)
	cout << "Before insert a is " << endl;
	a.insert(1, "x");
	cout << "After insert a is " << a << endl;



	//3 method remove(string itemToRemove)





	//4 method pop(int positionToRemove)





	//5 method pop()
	PythonList t(d2, 5);
	cout << "Before pop t is " << t << endl;
	t.pop(2);
	cout << "After pop t is " << t << endl;



	//6 method index(string itemToFind)





	//7 method int  count(string itemToCount)





	//8 method sort()





	//9 method reverse()
	cout << "Before reverse a is " << a << endl;
	a.reverse();
	cout << "a after reverse is " << a << endl;



	//10 function int    len(const PythonList & parm)





	//11 function int    comp(const PythonList & left, const PythonList & right)

	// test cmp
	PythonList h(d2, 5), k(d2, 5);
	cout << comp(h, k) << endl;
	h.pop();
	cout << comp(h, k) << endl;
	cout << comp(k, h) << endl;



	//12 function string max(const PythonList & aList)





	//13 function string min(const PythonList & aList)





	//14 operator bool           operator == ( const PythonList & right)





	//15 operator string &       operator [] (int index)





	//16 operator const string & operator[](int index)


	


	//17 operator PythonList     operator+(const PythonList & right)





	//18 operator PythonList     operator*(int times)

	PythonList b(d, 4);
	PythonList c;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;
	c = b * 3;
	cout << "After * c is " << c << endl;



	//19 operator bool inOperator(string lookFor, const PythonList & listToCheck)





	//20 operator  bool notInOperator(string lookFor, const PythonList & listToCheck)





	//21 constructor PythonList()





	//22 constructor PythonList(const PythonList & listParm)





	//23 constructor PythonList( const string[], int num_cells)



	
	
	


	cout << "keyWords before removing index 2 is " << keyWords << endl;
	keyWords.pop(2);
	cout << "keyWords after removing index 2 is " << keyWords << endl;







	cout << "Ending Visual Test" << endl;
}