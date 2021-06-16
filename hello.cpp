#include <cstdio>

int twoSum(int a, int b) { return a + b; }
int fourSum(int a, int b, int c, int d) { return twoSum(a, b) + twoSum(c, d); }

int main() { printf("Addition = %d\n", fourSum(1, 2, 3, 4)); }
