// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  int cot = 0;
  if (value == 1) return 0;
  for (int i = 1; i < (value / 2) + 1; i++)
    if (value%i == 0) cot++;
  if (cot > 1) return false;
  else
    return true;
}

uint64_t nPrime(uint64_t n) {
  int cot = 0;
  for (int i = 2; i < 100000; i++) {
    if (checkPrime(i)) {
      cot++;
    }
    if (cot == n) {
      return i;
    }
  }
}

uint64_t nextPrime(uint64_t value) {
  if (checkPrime(value)) return value;
  for (int i = value+1; i < value*value*value; i++)
    if (checkPrime(i)) return i;
}

uint64_t sumPrime(uint64_t hbound) {
  int sum = 0;
  for (int i = 2; i < hbound; i++)
    if (checkPrime(i)) sum += i;
  return sum;
}
