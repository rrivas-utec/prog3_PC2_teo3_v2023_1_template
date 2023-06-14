//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "split_range.h"
#include <deque>
using namespace std;

static void test_1_4() {
    int n = 0; cin >> n;
    deque<int> deq(n);
    for(auto& item: deq) cin >> item;
    auto res = split_range(deq, {0, 50, 0, 0});
    static_assert(is_same_v<decltype(res), vector<deque<int>>>, "Error in result type");
    for(const auto& row: res) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}