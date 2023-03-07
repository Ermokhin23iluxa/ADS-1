// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


bool checkPrime(uint64_t value) {
  int kol = 0;
  bool flag = true;
  for (int i = 2; i <= (value / 2) + 1; ++i) {
    if (value % i == 0) {
      kol++;
    }
    if (kol == 1) {
      flag = false;
      break;
    }
  }
  return flag;
}

uint64_t nPrime(uint64_t n) {
  int kol = 0;
  int temp = 2;
  while (1) {
    if (checkPrime(temp)) {
      kol++;
    }
    if (kol == n) {
      break;
    }
    ++temp;
  }
  return temp;
}

uint64_t nextPrime(uint64_t value) {
  while (1) {
    value++;
    if (checkPrime(value)) {
      break;
    }
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  uint64_t temp = 1;
  while (temp != hbound) {
    temp = nextPrime(temp);
    sum += temp;
  }
  sum -= temp;
  return sum;
}
