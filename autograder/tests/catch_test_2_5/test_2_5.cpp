//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "parallel_product.h"
#include <vector>
#include <list>
#include <exception>
using namespace std;

static void test_2_5() {
    list lst {1, 2, 3, 4, 5, 6};
    vector vec {10, 20, 30, 40};
    try {
        auto result = parallel_product(begin(lst), end(lst), begin(vec), end(vec));
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

TEST_CASE("Question #2.5") {
    execute_test("test_2_5.in", test_2_5);
}