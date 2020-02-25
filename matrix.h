#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
  double **m;
  int rows, cols;
  int lastcol;
};

// Basic matrix manipulation routines
struct matrix *new_matrix(int rows, int cols);
void free_matrix(struct matrix *m);
void grow_matrix(struct matrix *m, int newcols);
void copy_matrix(struct matrix *a, struct matrix *b);

// functions students need to complete
void print_matrix(struct matrix *m);
void ident(struct matrix *m);
void identn(struct matrix *m, int factor);
void matrix_mult(struct matrix *a, struct matrix *b);
void matrix_multr(struct matrix *a, struct matrix *b);
void matrix_multrh(struct matrix *a, struct matrix *b, int a_start, int b_start,
                   int a_end, int b_end);
int max(int a, int b);

#endif
