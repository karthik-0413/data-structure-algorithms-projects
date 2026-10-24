#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <vector>

#include "binary_search.hpp"

TEST_CASE("Target in the middle", "binary_search")
{
	std::vector<int> v = {1, 3, 5, 7, 9};
	REQUIRE(binarySearch(v, 5) == 2);
}

TEST_CASE("First and last elements", "binary_search")
{
	std::vector<int> v = {1, 3, 5, 7, 9};
	REQUIRE(binarySearch(v, 1) == 0);
	REQUIRE(binarySearch(v, 9) == 4);
}

TEST_CASE("Missing targets return -1", "binary_search")
{
	std::vector<int> v = {1, 3, 5, 7, 9};
	REQUIRE(binarySearch(v, 0) == -1);
	REQUIRE(binarySearch(v, 10) == -1);
	REQUIRE(binarySearch(v, 4) == -1);
}

TEST_CASE("Empty vector", "binary_search")
{
	std::vector<int> v;
	REQUIRE(binarySearch(v, 1) == -1);
}

TEST_CASE("One-element vector", "binary_search")
{
	std::vector<int> v = {42};
	REQUIRE(binarySearch(v, 42) == 0);
	REQUIRE(binarySearch(v, 7) == -1);
}

TEST_CASE("Negative numbers", "binary_search")
{
	std::vector<int> v = {-10, -3, 0, 4};
	REQUIRE(binarySearch(v, -3) == 1);
	REQUIRE(binarySearch(v, -4) == -1);
}

TEST_CASE("Duplicates return a matching index", "binary_search")
{
	std::vector<int> v = {1, 2, 2, 2, 3};
	int index = binarySearch(v, 2);
	REQUIRE(index >= 1);
	REQUIRE(index <= 3);
	REQUIRE(v[index] == 2);
}

TEST_CASE("Doubles", "binary_search")
{
	std::vector<double> v = {1.5, 2.5, 3.5};
	REQUIRE(binarySearch(v, 2.5) == 1);
	REQUIRE(binarySearch(v, 2.0) == -1);
}

TEST_CASE("Chars", "binary_search")
{
	std::vector<char> v = {'a', 'c', 'e'};
	REQUIRE(binarySearch(v, 'c') == 1);
	REQUIRE(binarySearch(v, 'd') == -1);
}

TEST_CASE("Strings", "binary_search")
{
	std::vector<std::string> v = {"apple", "banana", "cherry"};
	REQUIRE(binarySearch(v, std::string("banana")) == 1);
	REQUIRE(binarySearch(v, std::string("grape")) == -1);
}
