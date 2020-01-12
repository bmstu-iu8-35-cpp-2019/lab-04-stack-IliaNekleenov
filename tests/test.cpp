// Copyright 2019 IliaNekleenov <neiluha@mail.ru>

#include <gtest/gtest.h>

#include <header.hpp>
#include <string>
#include <vector>
//#include <type_traits>

TEST(STACK, push) {
  Stack<int> st;
  st.push(1);
  EXPECT_EQ(st.head(), 1);
  st.push(2);
  EXPECT_EQ(st.head(), 2);
  st.push(3);
  EXPECT_EQ(st.head(), 3);
}

TEST(STACK, copy) {
  Stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  Stack<int> copy(std::move(st));
  EXPECT_EQ(copy.head(), 3);
}

TEST(STACK, pop) {
  Stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(st.pop(), 3);
  EXPECT_EQ(st.head(), 2);
  EXPECT_EQ(st.pop(), 2);
  EXPECT_EQ(st.head(), 1);
}

TEST(STACK, push_emplace) {
  Stack<std::vector<std::string>> s;
  s.push_emplace(5, "aaa");
  s.push_emplace(10, "bbb");
  auto v_b = s.pop();
  auto v_a = s.pop();
  EXPECT_EQ(v_b.size(), 10);
  EXPECT_EQ(v_b[0], std::string("bbb"));
  EXPECT_EQ(v_a.size(), 5);
  EXPECT_EQ(v_a[4], std::string("aaa"));
}
