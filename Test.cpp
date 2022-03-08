/**
 * AUTHORS: firas naamneh
 * 
 * Date: 2022-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;


string nospaces(string input) {
	 std::erase(input, ' ');
	 std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
// -std=c++2a

TEST_CASE("Good input") {

      	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	    CHECK(nospaces(mat(13, 7, '*', '-')) == nospaces("************\n"
													 "*-------*\n"
													 "*-*****-*\n"
													 "*-*---*-*\n"
													 "*-*****-*\n"
													 "*-------*\n"
													 "************"));



	    CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces("@@@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
													 "@@@"));

													 
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	//input is odd
    CHECK_THROWS(mat(10,12,'s','d'));
	CHECK_THROWS(mat(22,6,'s','d'));
	CHECK_THROWS(mat(16,2,'s','d'));
	CHECK_THROWS(mat(14,13,'s','d'));
	CHECK_THROWS(mat(10,17,'s','d'));

	//one or two of the first two inputs is not int or th two chars is the same	

	CHECK_THROWS(mat(9.0,7,'$', ')'));
	CHECK_THROWS(mat(13.0,7.0,')', '%'));
	CHECK_THROWS(mat(13,25.0,'$', '$'));
	CHECK_THROWS(mat(27,177.0,'%', '%'));
	CHECK_THROWS(mat(15,17,'^', '%'));
	CHECK_THROWS(mat('a',13,'^', '%'));
	CHECK_THROWS(mat('d','x','$', '%'));
	CHECK_THROWS(mat(3,'b','$', '$'));
	CHECK_THROWS(mat(7.0,'w','@', '$'));
	CHECK_THROWS(mat(11,17.0,'@', '%'));
	CHECK_THROWS(mat(3.0,2,'$', '%'));
	CHECK_THROWS(mat(11.0,5.0,'$', '%'));
	CHECK_THROWS(mat(25,25.0,'$', '%'));
	CHECK_THROWS(mat(27,27.0,'$', '%'));
	CHECK_THROWS(mat(119,17,'$', '%'));
	CHECK_THROWS(mat('a',17,'$', '%'));
	CHECK_THROWS(mat('d','x','$', '%'));
	CHECK_THROWS(mat(3,'b','$', '%'));
	CHECK_THROWS(mat(5.0,'w','$', '%'));
	CHECK_THROWS(mat(119,14.0,'$', '%'));



}


TEST_CASE("no negatives numbers"){
        CHECK_THROWS(mat(5,-2,'&','&'));
        CHECK_THROWS(mat(-5,9,'&','#'));
        CHECK_THROWS(mat(-7,3,'#','@'));
        CHECK_THROWS(mat(-3,1,'$','#'));
        CHECK_THROWS(mat(3,-5,'%','#'));
		CHECK_THROWS(mat(-9,17,'%','#'));
        CHECK_THROWS(mat(-5,3,'&','+'));
        CHECK_THROWS(mat(15,-23,'-','+'));
        CHECK_THROWS(mat(-5,-5,'(',')'));
        CHECK_THROWS(mat(-7,-7,'%','$'));
    }


TEST_CASE ("symbol can't be space") {
    CHECK_THROWS(mat(15, 13, '&', ' '));
    CHECK_THROWS(mat(9, 3, ' ', '@'));
    CHECK_THROWS(mat(3, 3, '^', ' '));
	CHECK_THROWS(mat(13, 15, ' ', ' '));
    CHECK_THROWS(mat(5, 5, ' ', '('));
    CHECK_THROWS(mat(9, 7, ' ', ' '));
	
}

TEST_CASE ("symbol can't be \n") {
    CHECK_THROWS(mat(11, 17, '\n', '-'));
    CHECK_THROWS(mat(7, 3, '@', '\n'));
    CHECK_THROWS(mat(5, 13, '\n', '\n'));
	CHECK_THROWS(mat(11, 17, '\n', '-'));
    CHECK_THROWS(mat(7, 3, '@', '\n'));
    CHECK_THROWS(mat(5, 13, '\n', '\n'));
}


TEST_CASE ("symbol can't be \r") {
    CHECK_THROWS(mat(23, 11, '+', '\r'));
    CHECK_THROWS(mat(15, 17, '\r', '-'));
    CHECK_THROWS(mat(3, 7, '$', '\r'));
	CHECK_THROWS(mat(9, 1, '\r', '*'));
    CHECK_THROWS(mat(9, 13, '\r', '$'));
    CHECK_THROWS(mat(27, 13, '\r', '\r'));
}

TEST_CASE(" one or two inputs is zero"){
        CHECK_THROWS(mat(0,-2,'&','&'));
        CHECK_THROWS(mat(0,9,'&','#'));
        CHECK_THROWS(mat(-7,0,'#','@'));
        CHECK_THROWS(mat(0,0,'$','#'));
        CHECK_THROWS(mat(0,0,'%','#'));
		CHECK_THROWS(mat(0,17,'%','#'));
        CHECK_THROWS(mat(-5,0,'&','+'));
        CHECK_THROWS(mat(0,0,'-','+'));
        CHECK_THROWS(mat(0,-5,'(',')'));
        CHECK_THROWS(mat(-7,0,'%','$'));
    }



