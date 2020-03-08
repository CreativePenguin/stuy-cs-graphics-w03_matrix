#include <stdio.h>
#include <string.h>

#include "display.h"
#include "draw.h"
#include "ml6.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = 255;
  c.blue = 0;

  struct matrix *edges, *mult;

  clear_screen(s);

  edges = new_matrix(4, 4);
  mult = new_matrix(4, 4);
  mult->m[0][0] = 2;
  mult->m[1][1] = 2;
  mult->m[2][2] = 2;
  mult->m[3][3] = 2;
  double edges_x[4] = {120, 41, 9, 6};
  double edges_y[4] = {35, 21, 3, 9};
  // matrix_vals_row(edges, 0, edges_x, 4);
  // matrix_vals_row(edges, 1, edges_y, 4);
  // display(s);
  add_edge(edges, 150, 30, 30, 20, 30, 30);
  add_edge(edges, 20, 150, 30, 150, 150, 30);
  add_edge(edges, 150, 30, 30, 30, 30, 30);
  // printf("woah, expanding matrix?\n");
  // draw_line(0, 0, 500, 500, s, c);
  print_matrix(edges);
  draw_lines(edges, s, c);
  display(s);
  print_matrix(mult);
  matrix_mult(mult, edges);
  print_matrix(edges);
  draw_lines(edges, s, c);
  display(s);
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");
  save_extension(s, "img.png");
  /* matrix_vals(edges, 0, edges_m); */

  free_matrix(edges);
}
