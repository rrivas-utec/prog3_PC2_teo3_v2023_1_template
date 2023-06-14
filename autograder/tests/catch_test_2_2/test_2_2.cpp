//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "parallel_product.h"
#include <deque>
using namespace std;

static void test_2_2() {
    int n = 0; cin >> n;
    deque<int> deq1(n);
    deque<int> deq2(n);
    for(auto& item: deq1) cin >> item;
    for(auto& item: deq2) cin >> item;
    auto result = parallel_product(begin(deq1), end(deq1), begin(deq2), end(deq2));
    for (const auto& item: result) cout << item << " ";
    cout << endl;
}

TEST_CASE("Question #2.2") {
    execute_test("test_2_2.in", test_2_2);
}