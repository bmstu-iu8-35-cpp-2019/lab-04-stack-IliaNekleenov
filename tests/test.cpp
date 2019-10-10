// Copyright 2019 IliaNekleenov <neiluha@mail.ru>

#include <gtest/gtest.h>

#include <header.hpp>

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
