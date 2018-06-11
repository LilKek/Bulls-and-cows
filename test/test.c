#define CTEST_MAIN

#include <ctest.h>
#include <stdio.h>
#include <ctest.h>
#include <func.h>


CTEST(bulls_and_cows, input_correct)
{
	int really;
	int exp1 = 0, exp2 = 0, exp3 = 20, exp4 = 0, exp5 = 20;
	int num1[] = {5, 3, 2, 4};
	int num2[] = {4, 2, 9, 0};
	int num3[] = {8, 4, 8, 0};
	int num4[] = {5, 0, 7, 1};
	int num5[] = {3, 8, 5, 3};

	really = input_correct(num1);
	ASSERT_EQUAL(exp1, really);

	really = input_correct(num2);
	ASSERT_EQUAL(exp2, really);

	really = input_correct(num3);
	ASSERT_EQUAL(exp3, really);

	really = input_correct(num4);
	ASSERT_EQUAL(exp4, really);

	really = input_correct(num5);
	ASSERT_EQUAL(exp5, really);
}

CTEST(bulls_and_cows, count_bulls)
{
	int really;
	int exp1 = 2, exp2 = 0, exp3 = 1, exp4 = 3, exp5 = 4;
	int number[] = {6, 0, 3, 7};
	int num1[] = {4, 0, 5, 7};
	int num2[] = {3, 6, 7, 0};
	int num3[] = {6, 9, 2, 0};
	int num4[] = {6, 5, 3, 7};
	int num5[] = {6, 0, 3, 7};

	really = count_bulls(number, num1);
	ASSERT_EQUAL(exp1, really);

	really = count_bulls(number, num2);
	ASSERT_EQUAL(exp2, really);

	really = count_bulls(number, num3);
	ASSERT_EQUAL(exp3, really);

	really = count_bulls(number, num4);
	ASSERT_EQUAL(exp4, really);

	really = count_bulls(number, num5);
	ASSERT_EQUAL(exp5, really);
}

CTEST(bulls_and_cows, count_cows)
{
	int really;
	int exp1 = 1, exp2 = 3, exp3 = 0, exp4 = 4, exp5 = 2;
	int number[] = {4, 1, 8, 9};
	int num1[] = {2, 1, 7, 8};
	int num2[] = {9, 7, 4, 1};
	int num3[] = {4, 1, 7, 0};
	int num4[] = {8, 4, 9, 1};
	int num5[] = {9, 1, 8, 4};

	really = count_cows(number, num1);
	ASSERT_EQUAL(exp1, really);

	really = count_cows(number, num2);
	ASSERT_EQUAL(exp2, really);

	really = count_cows(number, num3);
	ASSERT_EQUAL(exp3, really);

	really = count_cows(number, num4);
	ASSERT_EQUAL(exp4, really);

	really = count_cows(number, num5);
	ASSERT_EQUAL(exp5, really);
}

int main(int argc, const char** argv)
{
	return ctest_main(argc, argv);
}
