#ifndef VIEWER_H
# define VIEWER_H

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

double find_len_side(vertex v1, vertex v2);
double	count_semi_perimetr(const double &s1,
							  const double &s2, const double &s3);
double	count_angle(triangle const &triangle);
double	сount_area_triangle (triangle const &triangle);
int		find_index_cell (triangle const &triangle);

#endif

