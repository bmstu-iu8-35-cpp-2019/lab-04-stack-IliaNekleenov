// Copyright 2019 IliaNekleenov <neiluha@mail.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <cstddef>
#include <memory>

template <typename T>
class Stack {
  std::unique_ptr<T[]> _data;
  size_t _capacity;
  size_t _size;

 public:
  Stack() : _capacity(0), _size(0) {}
  Stack(const Stack<T>& object) = delete;
  Stack(Stack<T>&& object) noexcept {
    _data = std::move(object._data);
    object._data = nullptr;
    _capacity = object._capacity;
    _size = object._size;
  }
  void push(T&& value) {
    if (_size + 1 <= _capacity) {
      if (std::is_move_assignable<T>()) {
        _data[_size] = std::move(value);
      } else {
        _data[_size] = value;
      }
    } else {
      _capacity = (3 * _size) / 2 + 1;
      auto buf = std::make_unique<T[]>(_capacity);
      for (size_t i = 0; i < _size; i++) {
        buf[i] = _data[i];
      }
      if (std::is_move_assignable<T>()) {
        buf[_size] = std::move(value);
      } else {
        buf[_size] = value;
      }
      _data = std::move(buf);
    }
    _size++;
  }
  void push(const T& value) {
    if (_size + 1 <= _capacity) {
      _data[_size] = value;
    } else {
      _capacity = (3 * _size) / 2 + 1;
      auto buf = std::make_unique<T[]>(_capacity);
      for (size_t i = 0; i < _size; i++) {
        buf[i] = _data[i];
      }
      buf[_size] = value;
      _data = std::move(buf);
    }
    _size++;
  }
  void pop(int) {
    if (_size > 0)
      _size--;
    else
      throw std::logic_error("Pop from empty stack");
  }
  T pop() {
    if (_size > 0)
      _size--;
    else
      throw std::logic_error("Pop from empty stack");
    return _data[_size];
  }
  const T& head() const {
    if (_size > 0) {
      return _data[_size - 1];
    }
    throw std::logic_error("Get head from empty stack");
  }

  template <typename... Args>
  void push_emplace(Args&&... value) {
    if (_size + 1 <= _capacity) {
      _data[_size] = T(value...);
    } else {
      _capacity = (3 * _size) / 2 + 1;
      auto buf = std::make_unique<T[]>(_capacity);
      for (size_t i = 0; i < _size; i++) {
        buf[i] = _data[i];
      }
      _data = std::move(buf);
      _data[_size] = T(value...);
    }
    _size++;
  }

  ~Stack() {}
};

#endif  // INCLUDE_HEADER_HPP_
