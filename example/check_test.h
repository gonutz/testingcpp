// check takes one argument which is converted to a bool and checked for being
// true.

TEST(checks_that_pass) {
	check(true);
	check(1);
	check(1 == 1);

	bool b = true;
	check(b);
}

TEST(checks_that_fail) {
	check(false);
	check(0);
	check(1 == 2);

	bool b = false;
	check(b);
}
