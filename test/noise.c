#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  srand(time(NULL));
  int row, col, i, j;
  scanf("%d\t%d", &row, &col);
  int* rgb = (int*) malloc(row * col * 3 * sizeof(int));

  for (i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      int idx = (i * col + j) * 3;
      scanf("%d\t%d\t%d", &rgb[idx], &rgb[idx + 1], &rgb[idx + 2]);
    }
  }

  printf("%d\t%d\n", row, col);

  for (i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      int idx = (i * col + j) * 3;
      double r = (double) (((double)rand())/((double)RAND_MAX));
      if (r < 0.1) {
        printf("%d\t%d\t%d\n", rand() % 256, rand() % 256, rand() % 256);
      }
      else {
        printf("%d\t%d\t%d\n", rgb[idx], rgb[idx + 1], rgb[idx + 2]);
      }
    }
  }

  return 0;
}
