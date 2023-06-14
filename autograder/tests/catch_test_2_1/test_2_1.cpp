//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "parallel_product.h"
#include <list>
#include <deque>
using namespace std;

static void test_2_1() {
    int n = 0; cin >> n;
    list<int> lst(n);
    deque<int> deq(n);
    for(auto& item: lst) cin >> item;
    for(auto& item: deq) cin >> item;
    auto result = parallel_product(begin(lst), end(lst), begin(deq), end(deq));
    for (const auto& item: result) cout << item << " ";
    cout << endl;
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}