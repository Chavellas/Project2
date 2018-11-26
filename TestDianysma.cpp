/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestDianysma.cpp
 * Author: nikolaus
 * 
 * Created on November 17, 2018, 2:45 PM
 */

#include "TestDianysma.h"
#include "Dianisma.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestDianysma);

TestDianysma::TestDianysma() {
}

TestDianysma::~TestDianysma() {
}

void TestDianysma::setUp() {
    this->example = new int(1);
}

void TestDianysma::tearDown() {
    delete this->example;
}

void TestDianysma::testMethod() {
    CPPUNIT_ASSERT(*example == 1);
}

void TestDianysma::testFailedMethod() {
    CPPUNIT_ASSERT(++*example == 1);
}

void TestDianysma::testMikosDianysmatos() {
    Dianisma * d = new Dianisma();
    
    d->SetAndCheckDedomena(0,10);
    d->SetAndCheckDedomena(1,20);
    d->SetAndCheckDedomena(2,30);
    
    CPPUNIT_ASSERT(d->mikos() == 3);
    
    delete d;
}

void TestDianysma::testTost() {

}