//
// RegularExpressionTest.h
//
// $Id: //poco/1.4/Foundation/testsuite/src/RegularExpressionTest.h#1 $
//
// Definition of the RegularExpressionTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef RegularExpressionTest_INCLUDED
#define RegularExpressionTest_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/CppUnit/TestCase.h"


class RegularExpressionTest: public CppUnit::TestCase
{
public:
	RegularExpressionTest(const std::string& name);
	~RegularExpressionTest();

	void testIndex();
	void testMatch1();
	void testMatch2();
	void testMatch3();
	void testMatch4();
	void testMatch5();
	void testMatch6();
	void testMatchAll();
	void testMatchAllCapture();
	void testMatchAllUtf8();
	void testMatchAllPcreTest4();
	void testMatchAllPcreTest2();
	void testMatchAllPcreTest8();
	void testMatchAllPcreTest1();
	void testExtract();
	void testSplit1();
	void testSplit2();
	void testSubst1();
	void testSubst2();
	void testSubst3();
	void testSubst4();
	void testError();
	void testGroup();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // RegularExpressionTest_INCLUDED
