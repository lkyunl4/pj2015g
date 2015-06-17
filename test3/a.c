#include <stdio.h>
#include <srp_vector.h>

int main() {
  int4 a = (int4) (1, 2, 3, 4);
  int4 one = (int4) (1, 1, 1, 1);
  a = a + one;
  printf("%d\n", ((int*)(&a))[1]);

}
