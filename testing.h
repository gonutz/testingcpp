#include <iostream>

#define TEST(name)                          \
struct name##_test__ : public test_case__ { \
    void run__();                           \
};                                          \
name##_test__ name##_test_instance__;       \
void name##_test__::run__()                 \

#define check(that)                                 \
{                                                   \
    if(!(that)) {                                   \
        std::cout << __FILE__ << ":" << __LINE__ << \
        ": " << #that << " is false" << std::endl;  \
        test_passed__ = false;                      \
    }                                               \
}                                                   \

#define check_equal(a, b)                           \
{                                                   \
    auto a_value = (a);                             \
    auto b_value = (b);                             \
    if(!(a_value == b_value)) {                     \
        std::cout << __FILE__ << ":" << __LINE__ << \
        ": " << #a << " != " << #b << ", " <<       \
        a_value << " != " << b_value << std::endl;  \
        test_passed__ = false;                      \
    }                                               \
}                                                   \

#define check_double_equal(a, b, epsilon)           \
{                                                   \
    double a_value = (a);                           \
    double b_value = (b);                           \
    double diff = a_value - b_value;                \
    if(!(-epsilon <= diff && diff <= epsilon)) {    \
        std::cout << __FILE__ << ":" << __LINE__ << \
        ": " << #a << " != " << #b << ", " <<       \
        a_value << " != " << b_value << std::endl;  \
        test_passed__ = false;                      \
    }                                               \
}                                                   \

#define fail(message)                           \
{                                               \
    std::cout << __FILE__ << ":" << __LINE__ << \
    ": " << message << std::endl;               \
    test_passed__ = false;                      \
}                                               \

struct test_case__;

test_case__* first_test_case__ = 0;

struct test_case__ {
    bool test_passed__;
    test_case__* next__;

    test_case__() {
        this->test_passed__ = true; // Until it fails.
        // Prepend ourselves at the start of the linked list of tests.
        this->next__ = first_test_case__;
        first_test_case__ = this;
    }

    virtual void run__() = 0;
};

int run_all_tests() {
    int test_count = 0;
    int fail_count = 0;

    for(test_case__* t = first_test_case__; t != 0; t = t->next__) {
        test_count++;
        t->run__();
        if(!t->test_passed__)
            fail_count++;
    }

    if(fail_count == 0)
        std::cout << "All " << test_count << " tests OK." << std::endl;
    else
        std::cout << fail_count << " of " << test_count << " tests fail." << std::endl;

    return fail_count;
}
