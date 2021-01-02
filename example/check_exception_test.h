struct UIException {};

void throw_ui_exception() {
	throw UIException{};
}

void throw_nothing() {}

TEST(expected_exception_is_thrown) {
	try {
		throw_ui_exception();
		fail("UIException expected");
	} catch(UIException e) {}
}

TEST(no_exception_is_thrown) {
	try {
		throw_nothing();
		fail("UIException expected");
	} catch(UIException e) {}
}

TEST(wrong_thing_is_thrown) {
	try {
		throw "this is a const char*";
		fail("UIException expected");
	} catch(UIException e) {
	} catch(...) {
		fail("UIException expected");
	}
}
