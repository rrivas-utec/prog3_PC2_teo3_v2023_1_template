//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "parallel_product.h"
#include <forward_list>
using namespace std;

static void test_2_4() {
    int n = 0; cin >> n;
    forward_list<int> lst1(n);
    forward_list<int> lst2(n);
    for(auto& item: lst1) cin >> item;
    for(auto& item: lst2) cin >> item;
    auto result = parallel_product(begin(lst1), end(lst1), begin(lst2), end(lst2));
    for (const auto& item: result) cout << item << " ";
    cout << endl;
}

TEST_CASE("Question #2.4") {
    execute_test("test_2_4.in", test_2_4);
}