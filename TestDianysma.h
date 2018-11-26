/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestDianysma.h
 * Author: nikolaus
 *
 * Created on November 17, 2018, 2:45 PM
 */

#ifndef TESTDIANYSMA_H
#define TESTDIANYSMA_H

#include <cppunit/extensions/HelperMacros.h>

class TestDianysma : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestDianysma);
    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);
    CPPUNIT_TEST_SUITE_END();

public:
    TestDianysma();
    virtual ~TestDianysma();
    void setUp();
    void tearDown();

private:
    int *example;
    void testMethod();
    void testFailedMethod();
    
    void testMikosDianysmatos();
    void testTost();
};

#endif /* TESTDIANYSMA_H */

