#include "viewer.hpp"

void		add_area_to_cell(double (&cells)[100],
							 const triangle &triangle)
{
	double 	area;
	double 	angle;
	int 	index;

	area = сount_area_triangle(triangle);
	angle = count_angle(triangle.normalle);
	index = find_index_cell(angle);
	std::cout << index << std::endl;

}

double			сount_area_triangle (const triangle &triangle)
{
	return (form_gerona(triangle));
}

double 			form_gerona(const triangle &triangle)
{
	double len1;
	double len2;
	double len3;
	double semi_perim;
	double area;

	len1 = find_len_side(triangle.v1, triangle.v2);
	len2 = find_len_side(triangle.v1, triangle.v3);
	len3 = find_len_side(triangle.v2, triangle.v3);
	semi_perim = count_semi_perim(len1, len2, len3);
	area = sqrt (semi_perim * (semi_perim - len1)
							* (semi_perim - len2)
							* (semi_perim - len3));

	return (area);
}

double 			find_len_side(vertex v1, vertex v2)
{
	double	len;
	double	pow_diff_x;
	double 	pow_diff_y;
	double 	pow_diff_z;

	pow_diff_x = pow (v1.x - v2.x, 2);
	pow_diff_y = pow (v1.y - v2.y, 2);
	pow_diff_z = pow (v1.z - v2.z, 2);
	len = sqrt(pow_diff_x + pow_diff_y + pow_diff_z);

	return (len);
}

double			count_semi_perim(const double &s1,
								   const double &s2, const double &s3)
{
	return ((s1 + s2 + s3) / 2);
}

double			count_angle(const vertex &normal)
{
	double	cos;
	double	pow_norm_x;
	double 	pow_norm_y;
	double 	pow_norm_z;
	double	sqrt_norm;
	double 	angle;
	const double PI = 3.14159265;

	pow_norm_x = pow(normal.x, 2);
	pow_norm_y = pow(normal.y, 2);
	pow_norm_z = pow(normal.z, 2);
	sqrt_norm = sqrt(pow_norm_x + pow_norm_y + pow_norm_z);
	cos = normal.z /  (sqrt_norm * sqrt(1));
	angle = acos(cos) * 180.0 / PI;

	return (90.0 - angle);
}

int				find_index_cell (double angle)
{
	int index;

	index = int((angle + 90.0) / 1.8);
	return (index);
}