#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "ml6.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);
  double edges_x[4] = {120, 41, 9, 6};
  matrix_vals_row(edges, 0, edges_x);
  print_matrix(edges);
  /* matrix_vals(edges, 0, edges_m); */

  free_matrix(edges);
}
