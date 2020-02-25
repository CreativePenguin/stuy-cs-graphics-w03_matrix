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
  print_matrix(edges);

  free_matrix(edges);
}
