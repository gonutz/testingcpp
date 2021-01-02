Minimal C++ Header-Only Unit Testing
------------------------------------

Copy the file testing.h into your project.
Create a main code file like this:

    #include "testing.h"
    #include "calculator_test.h"
    #include "ui_test.h"
    #include "bowling_game_test.h"

    int main() {
        return run_all_tests();
    }


where the example test files calculator_test.h, ui_test.h and
bowling_game_test.h look like this:

    #include "calculator.h"

    TEST(calculator_adds_numbers) {
        calculator c;
        c.add(123, 456);
        check_equal(c.result, 579);
    }

    TEST(activating_hidden_ui_throws_exception) {
        ui.hide();
        try {
            ui.activate();
            fail("UIException expected");
        } catch(UIException e) {}
    }


Do not #include testing.h in your test files.
Only #include testing.h once, in your main file, before all the test files.

You can now compile your test code into an executable, for example:

    g++ test_main.cpp calculator.cpp ui.cpp -o test.exe

Run the resulting executable. It returns the number of failed tests, so it
returns 0 on success (all tests pass). All failures are printed to stdout.
