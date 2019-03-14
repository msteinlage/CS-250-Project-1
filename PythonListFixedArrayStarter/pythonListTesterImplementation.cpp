#include "PythonListTester.h"

//  A number of methods uses the 3 contructor methods, len function and the 2 [] operators, which are assumed to be correct
//   Hence the starting score is 6 * 5 ==> 30

//  Some of the methods use other methods, such as append.  The other methods must test correct
//        before testing the method at hand


PythonListTester::PythonListTester(void)
{

}


// 0 method append(string item)
int PythonListTester::testAppend()   //    uses append
{
	PythonList a;
	string work = "x";
	for (int i = 0; i < 100; i++)
	{
		work = work + "x";
		a.append(work);
		if (len(a) != (i + 1)) return 0;
		if (a[i] != work) return 0;
	}
	return VALUE_OF_TEST;
}
// 1 method extend(const PythonList & listToAdd)
int PythonListTester::testExtend()   // uses append
{
	PythonList a;
	string work = "x";
	for (int i = 0; i < 100; i++)
	{
		work = work + "x";
		a.append(work);
	}
	PythonList b;
	string work2 = "y";
	for (int i = 0; i < 75; i++)
	{
		work2 = work2 + "y";
		b.append(work);
	}
	a.extend(b);
	if (len(a) != 175) return 0;
	for (int i = 0; i < 75; i++)
		if (b[i] != a[i + 100]) return 0;

	return VALUE_OF_TEST;

}
// 2 method insert(int index, string itemToInsert)
int PythonListTester::testInsert()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };
	PythonList a(d, 10);
	string work = "x";
	for (int i = 0; i< 12; i++)
	{
		work = work + "x";
		a.insert(i, work);
		if (a[i] != work) return 0;
	}

	return VALUE_OF_TEST;
}
// 3 method remove(string itemToRemove)
int PythonListTester::testRemove()                
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };
	string orderToRemove[10] = { "ten","one","two","six","three","nine", "four","seven","five","eight" };

	PythonList a(d, 10);
	if (len(a) != 10) return 0;
	for (int i = 0; i < 10; i++)
	{
		a.remove(orderToRemove[i]);
		if (len(a) != (9 - i)) return 0;
	}
	return VALUE_OF_TEST;
}
// 4 method pop(int positionToRemove)
int PythonListTester::testPopWithArguments()             // uses index
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };
	//	string orderToRemove[10] = { "ten","one","two","six","three","nine", "four","seven","five","eight"};
	int orderToRemove[10] = { 9,0,1,5,2,8,3,6,4,7 };
	PythonList a(d, 10);
	if (len(a) != 10) return 0;
	for (int i = 0; i < 10; i++)
	{
		a.pop(a.index(d[orderToRemove[i]]));    
		if (len(a) != (9 - i)) return 0;
	}
	return VALUE_OF_TEST;
}
// 5 method pop()
int PythonListTester::testPopNoArguments()
{
	string d[4] = { "one","two","three","four" };
	PythonList a(d, 4);
	for (int i = 0; i < 4; i++)
	{
		a.pop();
		if (len(a) != (3 - i)) return 0;
	}
	return VALUE_OF_TEST;
}
// 6 method index(string itemToFind)
int PythonListTester::testIndex()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);
	if (len(a) != 10) return 0;
	for (int i = 0; i < len(a); i++)
	{
		if (a.index(d[i]) != i) return 0;
	}
	return VALUE_OF_TEST;
}
// 7 method int  count(string itemToCount)
int PythonListTester::testCount()     // uses append
{
	PythonList q;
	if (q.count("x") != 0) return 0;
	for (int i = 1; i <= 100; i++)
	{
		q.append("x");
		if (q.count("x") != i) return 0;
	}

	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);
	if (a.count("x") != 0) return 0;
	return VALUE_OF_TEST;
}
// 8 method sort()
int PythonListTester::testSort()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);
	a.sort();
	int lim = len(a);
	for (int i = 0; i < lim - 1; i++)
		if (a[i] > a[i + 1]) return 0;

	return VALUE_OF_TEST;
}
// 9 method reverse()
int PythonListTester::testReverse()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);
	PythonList b(a);
	a.reverse();

	if (len(a) != len(b)) return 0;

	int lim = len(a);
	for (int i = 0; i < lim; i++)
		if (a[i] != b[lim - 1 - i]) return 0;

	return VALUE_OF_TEST;
}
// 10 function int    len(const PythonList & parm)
int PythonListTester::testLenFunction()    
{
	string d[MAX_CELLS];
	for (int i = 0; i < MAX_CELLS; i++)
		d[i] = "x";
	for( int i = 1;i <= MAX_CELLS; i++)
	{ 
	   PythonList work(d,i);
	   if (len(work) != i) return 0;
	}
	return VALUE_OF_TEST;
}
// 11 function int    comp(const PythonList & left, const PythonList & right)
int PythonListTester::testCompFunction()                       //   uses pop()
{
	int temp = 7;
	string d[7] = { "one","two","three","four", "six", "five","nine" };
	PythonList a(d, 7);
	PythonList b(d, 7);
	temp = comp(a, b);
	if (comp(a, b) != 0) return 0;
	b[6] = "xxx";
	if (comp(a, b) != -1) return 0;
	if (comp(b, a) != 1) return 0;
	PythonList c(a);
	c.pop();
	if (comp(c, a) != -1) return 0;

if (comp(a, c) != 1) return 0;
	return VALUE_OF_TEST;

}
// 12 function string max(const PythonList & aList)        // uses insert and pop
int PythonListTester::testMaxFunction()
{
	string d[7] = { "one","two","three","four", "six", "five","nine" };
	PythonList a(d, 7);
	int times = len(a);

	for (int i = 0; i < times; i++)
	{
		a.insert(i, "xxx");
		if (max(a) != "xxx") return 0;
		a.pop(i);
	}
	return VALUE_OF_TEST;
}
// 13 function string min(const PythonList & aList)
int PythonListTester::testMinFunction()           // uses insert and pop
{
	string d[7] = { "one","two","three","four", "six", "five","nine" };
	PythonList a(d, 7);
	int times = len(a);

	for (int i = 0; i < times; i++)
	{
		a.insert(i, "aaa");
		if (min(a) != "aaa") return 0;
		a.pop(i);
	}
	return VALUE_OF_TEST;
}
// 14 operator bool           operator == ( const PythonList & right)
int PythonListTester::testEqOperator()
{
	string d1[2] = { "one","two" };
	string d2[2] = { "one","two" };
	string d3[2] = { "one","Two" };
	string d4[3] = { "one","two","three" };
	PythonList a1(d1, 2);
	PythonList a2(d2, 2);
	PythonList a3(d3, 2);
	PythonList a4(d4, 3);

	if ((a1 == a2) && !(a1 == a3) && !(a1 == a4)) {
		
		return VALUE_OF_TEST;
	}
	cout << "TEST SCORE: " << VALUE_OF_TEST << endl;
	return 0;
}
// 15 operator string &       operator [] (int index)
int PythonListTester::testIndexOperatorLvalue()
{
	string d[4] = { "one","two","three","four" };

	PythonList a(d, 4);
	int sum = 0;
	if (a[3] != string("four")) return 0;
	a[3] = string("five");
	if (a[3] != string("five")) return 0;
	// test negative indexes
	int length = len(a);
	for (int i = 1; i <= length; i++)
		if (a[-i] != a[length - i]) return 0;
	return VALUE_OF_TEST;
}
// 16 operator const string & operator[](int index)
int PythonListTester::testIndexOperatorRvalue()
{
	string d[4] = { "one","two","three","four" };
	PythonList a(d, 4);
	for (int i = 0; i < 3; i++)
	{
		a[i] = a[3];
		if (a[i] != a[3]) return 0;
	}
	int length = len(a);
	for (int i = 1; i <= length; i++)
		if (a[-i] != a[length - i]) return 0;

	return VALUE_OF_TEST;
}
// 17 operator PythonList     operator+(const PythonList & right)
int PythonListTester::testPlusOperator()
{
	string d[4] = { "one","two","three","four" };
	PythonList a(d, 4);

	string d2[5] = { "for","int","if","while","bool" };
	PythonList b(d2, 5);

	PythonList c;
	c = a + b;
	int lenA = len(a);
	int lenB = len(b);
	cout << " result::: " << c << endl;
	if (len(c) != (lenA + lenB)) return 0;
	for (int i = 0; i < lenA; i++)
		if (c[i] != a[i]) return 0;

	for (int i = 0; i < lenB; i++)
		if (b[i] != c[i + lenA]) return 0;

	return VALUE_OF_TEST;
}
// 18 operator PythonList     operator*(int times)
int PythonListTester::testTimesOperator()    // uses append
{
	PythonList q;
	if (len(q * 4) != 0) return 0;
	q.append("x");
	if (len(q * 7) != 7) return 0;

	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);
	PythonList b;
	const int TIMES_VALUE = 4;
	b = a * TIMES_VALUE;

	if (len(b) != (len(a) * TIMES_VALUE)) return 0;

	int lim = len(a);
	int lim2 = len(b);
	for (int i = 0; i < lim; i++)
		for (int j = 0; j < TIMES_VALUE; j++)
			if (a[i] != b[i + j * lim]) return 0;

	return VALUE_OF_TEST;
}
// 19 operator bool inOperator(string lookFor, const PythonList & listToCheck)
int PythonListTester::testInOperator()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);

	for (int i = 0; i < len(a); i++)
	{
		if (inOperator(d[i], a) != true) return 0;
	}
	string d2[4] = { "abc","hello","goodbye","code" };
	for (int i = 0; i < 4; i++)
		if (inOperator(d2[i], a) == true) return 0;

	return VALUE_OF_TEST;
}
// 20 operator  bool notInOperator(string lookFor, const PythonList & listToCheck)
int PythonListTester::testNotInOperator()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);

	for (int i = 0; i < len(a); i++)
	{
		if (notInOperator(d[i], a) == true) return 0;
	}

	string d2[4] = { "abc","hello","goodbye","code" };
	for (int i = 0; i < 4; i++)
		if (notInOperator(d2[i], a) == false) return 0;
	return VALUE_OF_TEST;
}
// 21 constructor PythonList()
int PythonListTester::testDefaultConstructor()
{
	PythonList info;
	if (len(info) == 0) return VALUE_OF_TEST;
	return 0;
}
// 22 constructor PythonList(const PythonList & listParm)
int PythonListTester::testCopyConstructor()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList b(d, 10);
	PythonList a(b);
	if (len(a) != 10) return 0;
	for (int i = 0; i < len(a); i++)
	{
		if (a[i] != d[i]) return 0;  // a[i] is list indexing, d[i] is array subscripting
	}
	return VALUE_OF_TEST;
}
// 23 constructor PythonList( const string[], int num_cells)
int PythonListTester::testArrayArgumentConstructor()
{
	string d[10] = { "one","two","three","four","five","six","seven","eight","nine","ten" };

	PythonList a(d, 10);
	if (len(a) != 10) return 0;
	for (int i = 0; i < len(a); i++)
	{
		if (a[i] != d[i]) return 0;  // a[i] is list indexing, d[i] is array subscripting
	}
	return VALUE_OF_TEST;
}
// 24 TEST ALL
int PythonListTester::runAllTests()
{
	PythonListTester test;
	int total = 0;
	for (int choice = 0; choice <= 23; choice++)
	{
		int oldTotal = total;
		switch (choice) {
		case 0:  total += test.testAppend();
			break;
		case 1:  total += test.testExtend();
			break;
		case 2:  total += test.testInsert();
			break;
		case 3:  total += test.testRemove();
			break;
		case 4:  total += test.testPopWithArguments();
			break;
		case 5:  total += test.testPopNoArguments();
			break;
		case 6:  total += test.testIndex();
			break;
		case 7:  total += test.testCount();
			break;
		case 8:  total += test.testSort();
			break;
		case 9:  total += test.testReverse();
			break;
		case 10: total += test.testLenFunction();
			break;
		case 11: total += test.testCompFunction();
			break;
		case 12: total += test.testMaxFunction();
			break;
		case 13: total += test.testMinFunction();
			break;
		case 14: total += test.testEqOperator();
			break;
		case 15: total += test.testIndexOperatorLvalue();
			break;
		case 16: total += test.testIndexOperatorRvalue();
			break;
		case 17: total += test.testPlusOperator();
			break;
		case 18: total += test.testTimesOperator();
			break;
		case 19: total += test.testInOperator();
			break;
		case 20: total += test.testNotInOperator();
			break;
		case 21: total += test.testDefaultConstructor();
			break;
		case 22: total += test.testCopyConstructor();
			break;
		case 23: total += test.testArrayArgumentConstructor();
			break;
		}   // end switch
		if (oldTotal == total)
			cout << "Test Failed " << choice << endl;
	} // end while
	return total;
}










