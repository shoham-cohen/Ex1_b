#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	
	CHECK(nospaces(mat(1, 11, '|', '#')) == nospaces("|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|"));
		
	CHECK(nospaces(mat(3, 5, '1', 'x')) == nospaces("111\n1x1\n1x1\n1x1\n111\n"));

	CHECK(nospaces(mat(11, 71, '~', '?')) == nospaces("~~~~~~~~~~~\n"
													  "~?????????~\n"
													  "~?~~~~~~~?~\n"
													  "~?~?????~?~\n"
													  "~?~?~~~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~?~?~?~\n"
														"~?~?~~~?~?~\n"
														"~?~?????~?~\n"
														"~?~~~~~~~?~\n"
														"~?????????~\n"
														"~~~~~~~~~~~"));

CHECK(nospaces(mat(91, 13, '#', 'Z')) == nospaces("###########################################################################################\n"
													"#ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ#\n"
													"#Z#######################################################################################Z#\n"
													"#Z#ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ#Z#\n"
													"#Z#Z###################################################################################Z#Z#\n"
													"#Z#Z#ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ#Z#Z#\n"
													"#Z#Z#Z###############################################################################Z#Z#Z#\n"
													"#Z#Z#ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ#Z#Z#\n"
													"#Z#Z###################################################################################Z#Z#\n"
													"#Z#ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ#Z#\n"
													"#Z#######################################################################################Z#\n"
													"#ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ#\n"
													"###########################################################################################"));
}

TEST_CASE("even input"){
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(2, 11, '.', '-'));
	CHECK_THROWS(mat(257, 322, 'c', '~'));
	CHECK_THROWS(mat(121, 410, '-', 'N'));
	CHECK_THROWS(mat(98, 3142, '^', '&'));
	//all of those needs to throw run time error "Mat size is always odd"
}

TEST_CASE("zero or negative input"){
	CHECK_THROWS(mat(0, 5, '$', '%'));
	CHECK_THROWS(mat(15, -5, 'P', '%'));
	CHECK_THROWS(mat(-13, 0, '>', '<'));
	CHECK_THROWS(mat(0, 0, '=', '+'));
	CHECK_THROWS(mat(-11, -1, 'V', '?'));

	//all of those needs to throw run time error "rows/coloms need to be a positive integer");
}

TEST_CASE("invallid char"){
	CHECK_THROWS(mat(77, 5, 0, '%'));//null
	CHECK_THROWS(mat(3, 5, '$', 0)); //null
	CHECK_THROWS(mat(11, 81, 127, '{')); //del
	CHECK_THROWS(mat(11, 81, ']', 127)); //del
	CHECK_THROWS(mat(111, 1, 's', '\n')); //\n is illegal
	CHECK_THROWS(mat(3, 3, ' ', 'P'));// nospaces will delete it so ' ' is iillegal

}
