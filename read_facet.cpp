#include "viewer.hpp"

void	read_one_facet(std::ifstream &fd, double (&cells)[100])
{
	std::string line;
	triangle 	triangle;
	const int	FACET_LINES = 7;
	const int	LEN_ENDSOLID = 8;

	initialize_triangle(triangle);
	for (int i = 1; i <= FACET_LINES; i++)
	{
		getline(fd, line);
		if (line.substr(0, LEN_ENDSOLID) == "endsolid")
		{
			getline(fd, line);
			return;
		}
		read_facet_line (line, i, triangle);
	}
	add_area_to_cell(cells, triangle);
}

void	read_facet_line (std::string &line, int number, triangle &triangle)
{
	if (number == 1)
		read_normalle (line, triangle.normalle);
	else if (number == 2)
		read_outer_loop(line);
	else if (number == 3)
		read_vertex (line, triangle.v1);
	else if (number == 4)
		read_vertex (line, triangle.v2);
	else if (number == 5)
		read_vertex (line, triangle.v3);
	else if (number == 6)
		read_endloop (line);
	else if (number == 7)
		read_endfacet (line);
}
