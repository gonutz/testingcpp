// check_double_equal takes two floating point values to compare and an epsilon
// value which is the allowed range in which the two values are still considered
// equal.

TEST(check_double_equal_cases) {
	check_double_equal(10, 10, 0);
	check_double_equal(10, 10.5, 0.5);
	check_double_equal(10, 9.5, 0.5);

	int i1 = 100;
	int i2 = 100;
	check_double_equal(i1, i2, 0);

	float f1 = 100.5;
	float f2 = 100.5;
	check_double_equal(f1, f2, 0);

	double d1 = 100.5;
	double d2 = 100.5;
	check_double_equal(d1, d2, 0);
}

TEST(check_double_unequal_cases) {
	check_double_equal(10, 10.50001, 0.5);
	check_double_equal(10, 9.49999, 0.5);

	int i1 = 100;
	int i2 = 666;
	check_double_equal(i1, i2, 0);

	float f1 = 100.5;
	float f2 = 666.5;
	check_double_equal(f1, f2, 0);

	double d1 = 100.5;
	double d2 = 666.5;
	check_double_equal(d1, d2, 0);
}
