#include <stdio.h>
#include "a.h"
//#include <stdlib.h>

extern short rgb[];
// Median filter
int main() {
  int row = 690, col = 690, i, j;

  //int* rgb = (int*) malloc(row * col * 3 * sizeof(int));

  printf("%d\t%d\n", row, col);

  for (i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      int  idx = (i * col + j) * 3;
      short* surround_pixel[8];
      int  surrounding_size = 0;
      if (i == 0) {
        if (j == 0) {
          surround_pixel[0] = (&rgb[idx]) +  3;
          surround_pixel[1] = (&rgb[idx]) + (3 *  row);
          surround_pixel[2] = (&rgb[idx]) + (3 * (row + 1)); 
          surrounding_size = 3;
        }
        else if (j == col - 1) {
          surround_pixel[0] = (&rgb[idx]) -  3;
          surround_pixel[1] = (&rgb[idx]) + (3 * (row - 1));
          surround_pixel[2] = (&rgb[idx]) + (3 *  row);
          surrounding_size = 3;
        }
        else {
          surround_pixel[0] = (&rgb[idx]) -  3;
          surround_pixel[1] = (&rgb[idx]) +  3;
          surround_pixel[2] = (&rgb[idx]) + (3 * (row - 1));
          surround_pixel[3] = (&rgb[idx]) + (3 *  row);
          surround_pixel[4] = (&rgb[idx]) + (3 * (row + 1)); 
          surrounding_size = 5;
        }
      }
      else if (i == row - 1) {
          if (j == 0) {
          surround_pixel[0] = (&rgb[idx]) - (3 *  row);
          surround_pixel[1] = (&rgb[idx]) - (3 * (row - 1));
          surround_pixel[2] = (&rgb[idx]) +  3;
          surrounding_size = 3;
        }
        else if (j == col - 1) {
          surround_pixel[0] = (&rgb[idx]) - (3 * (row + 1));
          surround_pixel[1] = (&rgb[idx]) - (3 *  row);
          surround_pixel[2] = (&rgb[idx]) -  3;
          surrounding_size = 3;
        }
        else {
          surround_pixel[0] = (&rgb[idx]) - (3 * (row + 1));
          surround_pixel[1] = (&rgb[idx]) - (3 *  row);
          surround_pixel[2] = (&rgb[idx]) - (3 * (row - 1));
          surround_pixel[3] = (&rgb[idx]) -  3;
          surround_pixel[4] = (&rgb[idx]) +  3;
          surrounding_size = 5;
        }
      }
      else {
        if (j == 0) {
          surround_pixel[0] = (&rgb[idx]) - (3 *  row);
          surround_pixel[1] = (&rgb[idx]) - (3 * (row - 1));
          surround_pixel[2] = (&rgb[idx]) +  3;
          surround_pixel[3] = (&rgb[idx]) + (3 *  row);
          surround_pixel[4] = (&rgb[idx]) + (3 * (row + 1)); 
          surrounding_size = 5;
        }
        else if (j == col - 1) {
          surround_pixel[0] = (&rgb[idx]) - (3 * (row + 1));
          surround_pixel[1] = (&rgb[idx]) - (3 *  row);
          surround_pixel[2] = (&rgb[idx]) -  3;
          surround_pixel[3] = (&rgb[idx]) + (3 * (row - 1));
          surround_pixel[4] = (&rgb[idx]) + (3 *  row);
          surrounding_size = 5;
        }
        else {
          surround_pixel[0] = (&rgb[idx]) - (3 * (row + 1));
          surround_pixel[1] = (&rgb[idx]) - (3 *  row);
          surround_pixel[2] = (&rgb[idx]) - (3 * (row - 1));
          surround_pixel[3] = (&rgb[idx]) -  3;
          surround_pixel[4] = (&rgb[idx]) +  3;
          surround_pixel[5] = (&rgb[idx]) + (3 * (row - 1));
          surround_pixel[6] = (&rgb[idx]) + (3 *  row);
          surround_pixel[7] = (&rgb[idx]) + (3 * (row + 1)); 
          surrounding_size = 8;
        }
      }

      short mean[3];
      mean[0] = 2*rgb[idx];
      mean[1] = 2*rgb[idx+1];
      mean[2] = 2*rgb[idx+2];

      int k;
      for (k = 0; k < surrounding_size; k++) {
        //printf("(%d, %d, %d)\n", *(surround_pixel[k]), *(surround_pixel[k]+1), *(surround_pixel[k]+2));
        mean[0] += *(surround_pixel[k]);
        mean[1] += *(surround_pixel[k] + 1);
        mean[2] += *(surround_pixel[k] + 2);
      }

      mean[0] /= (surrounding_size + 2);
      mean[1] /= (surrounding_size + 2);
      mean[2] /= (surrounding_size + 2);      
      //printf("%d\t%d\t%d\n", rgb[idx], rgb[idx + 1], rgb[idx + 2]);
      
      printf("%d\t%d\t%d\n", mean[0], mean[1], mean[2]);
    }
  }

  return 0;
}
