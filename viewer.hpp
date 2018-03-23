#ifndef VIEWER_H
# define VIEWER_H

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <cctype>


struct vertex
{
	double x;
	double y;
	double z;
};

struct triangle
{
	vertex normalle;
	vertex v1;
	vertex v2;
	vertex v3;
};

void			read_from_file(std::ifstream &fd, double *cell);
void			parse_first_str(std::string &line);
void			read_one_facet(std::ifstream &fd, double *cell);
void			read_facet_line (std::string &line,
								 int number, triangle &triangle);
void			initialize_triangle(triangle &triangle);
void			initialize_vertex(vertex &vertex);
void			read_normalle (std::string &line, vertex &normal);
void			print_error_facet(void);
void			string_to_double(std::string &line, vertex &vertex);
double			extract_one_double(std::string line,
									 std::string::size_type &sz);
void			read_outer_loop (std::string &line);
void			check_end_of_line(std::string &line);
void			read_vertex (std::string &line, vertex &vertex);
void			read_endloop (std::string &line);
void			read_endfacet (std::string &line);

void			add_area_to_cell(double *cell, triangle &triangle);
double 			find_len_side(vertex v1, vertex v2);
double			count_semi_perimetr(const double &s1,
							  const double &s2, const double &s3);
double			count_angle(triangle const &triangle);
void			check_if_dir(const char *file);
double			сount_area_triangle (triangle const &triangle);
int				find_index_cell (triangle const &triangle);

#endif

