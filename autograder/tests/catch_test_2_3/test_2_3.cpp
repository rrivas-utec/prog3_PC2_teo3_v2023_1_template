//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "parallel_product.h"
#include <vector>
using namespace std;

static void test_2_3() {
    int n = 0; cin >> n;
    vector<int> vec1(n);
    vector<int> vec2(n);
    for(auto& item: vec1) cin >> item;
    for(auto& item: vec2) cin >> item;
    static_assert(is_same_v<decltype(vec1), vector<int>>, "Error in result type");
    auto result = parallel_product(begin(vec1), end(vec1), begin(vec2), end(vec2));
    for (const auto& item: result) cout << item << " ";
    cout << endl;
}

TEST_CASE("Question #2.3") {
    execute_test("test_2_3.in", test_2_3);
}