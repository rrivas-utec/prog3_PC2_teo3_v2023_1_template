//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "split_range.h"
#include <forward_list>
using namespace std;

static void test_1_3() {
    int n = 0; cin >> n;
    forward_list<int> lst(n);
    for(auto& item: lst) cin >> item;
    auto res = split_range(lst, {20, 20, 10});
    static_assert(is_same_v<decltype(res), vector<forward_list<int>>>, "Error in result type");
    for(const auto& row: res) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}