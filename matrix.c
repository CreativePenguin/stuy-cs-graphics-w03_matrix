/*==========================================
  A matrix will be a 4xN array of doubles
  Each column will represent an [x, y, z, 1] point.
  For multiplication purposes, consider the rows like so:
  x0  x1      xn
  y0  y1      yn
  z0  z1  ... zn
  1  1        1
  ==========================================*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m

print the matrix such that it looks like
the template in the top comment
*/
void print_matrix(struct matrix *m) {
  int i, j;
  printf("[\n");
  for (i = 0; i < m->rows; i++) {
    printf("\t[ ");
    for (j = 0; j < m->cols; j++) {
      printf("%f ", m->m[i][j]);
    }
    printf("]\n");
  }
  printf("]\n");
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix

turns m in to an identity matrix
*/
void ident(struct matrix *m) { identn(m, 1); }

void identn(struct matrix *m, int factor) {
  int i, j;
  m = new_matrix(4, 3);
  for (i = 0; i < m->rows; i++)
    for (j = 0; j < m->lastcol; j++)
      m->m[i][j] = 0;
  m->m[0][0] = factor;
  m->m[1][1] = factor;
  m->m[2][2] = factor;
}

/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b

multiply a by b, modifying b to be the product
a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
	int i, j, k, max_col;
	/* max_col = max(a->lastcol, b->lastcol); */
	struct matrix *tmp = new_matrix(4, a->lastcol);
	for(i = 0; i < tmp->rows; i++) {
		for(j = 0; j < tmp->lastcol; j++) {
			tmp->m[i][j] = 0;
			for(k = 0; k < sizeof(a->m) / sizeof(a->m[0]); k++) {
				tmp->m[i][j] += a->m[k][j] * b->m[i][k];
			}
		}
	}
	copy_matrix(tmp, b);
	free_matrix(tmp);
}

void matrix_multr(struct matrix *a, struct matrix *b) {
	matrix_multrh(a, b, 0, 0, a->lastcol, b->lastcol);
}

void matrix_multrh(struct matrix *a, struct matrix *b, int a_start, int b_start,
                   int a_end, int b_end) {
	if(a_start + 2 >= a_end && b_start + 2 >= b_end) {
		matrix_multrh(a, b, 0, 0, a_end / 2, b_end / 2);
		matrix_multrh(a, b, a_end / 2 + 1, b_end / 2 + 1, a_end, b_end);
	}
}

int max(int a, int b) { return a >= b ? a : b; }

/*===============================================
  These Functions do not need to be modified
  ===============================================*/

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols

Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)...
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i = 0; i < rows; i++) {
    tmp[i] = (double *)malloc(cols * sizeof(double));
  }

  m = (struct matrix *)malloc(sizeof(struct matrix));
  m->m = tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}

/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m
Returns:

1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i = 0; i < m->rows; i++) {
    free(m->m[i]);
  }
  free(m->m);
  free(m);
}

/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols
Returns:

Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {

  int i;
  for (i = 0; i < m->rows; i++) {
    m->m[i] = realloc(m->m[i], newcols * sizeof(double));
  }
  m->cols = newcols;
}

/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b
Returns:

copy matrix a to matrix b
 */
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

<<<<<<< HEAD
  if(b->lastcol < a->lastcol) grow_matrix(b, a->lastcol);

	for (r=0; r < a->rows; r++)
		for (c=0; c < a->cols; c++)
			b->m[r][c] = a->m[r][c];
=======
  for (r = 0; r < a->rows; r++)
    for (c = 0; c < a->cols; c++)
      b->m[r][c] = a->m[r][c];
>>>>>>> ee5357d8c4f26d8e58beb9b7f1ab572c967e8f89
}
