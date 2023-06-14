//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "split_range.h"
#include <list>
using namespace std;

static void test_1_2() {
    int n = 0; cin >> n;
    list<int> lst(n);
    for(auto& item: lst) cin >> item;
    auto res = split_range(lst, {10, 10, 10, 10, 10});
    static_assert(is_same_v<decltype(res), vector<list<int>>>, "Error in result type");
    for(const auto& row: res) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}