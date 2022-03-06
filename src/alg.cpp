// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1;
  for (uint16_t i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
  if (count > 0){
    return calcItem(x, count) + expn(x, count-1);
  }
  return 1;
}

double sinn(double x, uint16_t count) {
  if(count > 0) {
    return calcItem(x, count * 2 + 1) * pown(-1, count) + sinn(x, count - 1);
  }
  return calcItem(x, count * 2 + 1) * pown(-1, count);
}

double cosn(double x, uint16_t count) {
  if (count > 0) {
    return calcItem(x, count * 2) * pown(-1, count) + cosn(x, count - 1);
  }
  return calcItem(x, count * 2) * pown(-1, count);
}
