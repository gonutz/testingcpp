#include <string>
#include <string.h>

// check_equal compares two values with the == operator.

TEST(check_equal_successes) {
	check_equal(123, 123);
	check_equal(true, true);

	// Remember that char* strings cannot be compared with the == operator. You
	// can do one of these instead:
	char str[4] = {'a', 'b', 'c', 0};
	check_equal(std::string(str), "abc"); // Convert to std::string.
	check_equal(strcmp(str, "abc"), 0); // Check strcmp for being 0.
	check(strcmp(str, "abc") == 0); // Use check and compare it yourself.
}

TEST(check_equal_failures) {
	check_equal(123, 666);
	check_equal(true, false);

	char str[4] = {'a', 'b', 'c', 0};
	check_equal(str, "abc"); // Fails because raw pointers are compared.
}
