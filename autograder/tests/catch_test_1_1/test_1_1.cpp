//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "split_range.h"
#include <iterator>
#include <type_traits>
#include <vector>
using namespace std;

static void test_1_1() {
    int n = 0; cin >> n;
    vector<int> vec(n);
    for(auto& item: vec) cin >> item;
    auto res = split_range(vec, {n/2, n-n/2});
    static_assert(is_same_v<decltype(res), vector<vector<int>>>, "Error in result type");
    for(const auto& row: res) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

TEST_CASE("Question #1.1") {
    execute_test("test_1_1.in", test_1_1);
}