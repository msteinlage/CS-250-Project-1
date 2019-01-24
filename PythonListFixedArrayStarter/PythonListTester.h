#ifndef PYTHON_LIST_TESTER
#define PYTHON_LIST_TESTER

#include "pythonListFA.h"
#include <string>
using namespace::std;


class PythonListTester
{
public:
  PythonListTester(void);
// 0 method append(string item)
  int testAppend();
// 1 method extend(const PythonList & listToAdd)
  int testExtend();
// 2 method insert(int index, string itemToInsert)
 int testInsert();
// 3 method remove(string itemToRemove)
  int testRemove();
// 4 method pop(int positionToRemove)
  int testPopWithArguments();
// 5 method pop()
  int testPopNoArguments();
// 6 method index(string itemToFind)
  int testIndex();
// 7 method int  count(string itemToCount)
  int testCount();
// 8 method sort()
  int testSort();
// 9 method reverse()
  int testReverse();
// 10 function int    len(const PythonList & parm)
  int testLenFunction();
// 11 function int    comp(const PythonList & left, const PythonList & right)
  int testCompFunction();
// 12 function string max(const PythonList & aList)
     int testMaxFunction();
// 13 function string min(const PythonList & aList)
	 int testMinFunction();
// 14 operator bool           operator == ( const PythonList & right)
	 int testEqOperator();
// 15 operator string &       operator [] (int index)
     int testIndexOperatorLvalue();
// 16 operator const string & operator[](int index)
	 int testIndexOperatorRvalue();
// 17 operator PythonList     operator+(const PythonList & right)
	 int testPlusOperator();
// 18 operator PythonList     operator*(int times)
	 int testTimesOperator();
// 19 operator bool inOperator(string lookFor, const PythonList & listToCheck)
	 int testInOperator();
// 20 operator  bool notInOperator(string lookFor, const PythonList & listToCheck)
	 int testNotInOperator();
// 21 constructor PythonList()
     int testDefaultConstructor();
// 22 constructor PythonList(const PythonList & listParm)
	 int testCopyConstructor();
// 23 constructor PythonList( const string[], int num_cells)
	 int testArrayArgumentConstructor();
// 24 TEST ALL
     int runAllTests(); 


private:
	static const int VALUE_OF_TEST = 5;      // can be changed to any value by replacing the 5 with any positive integer

};

#endif