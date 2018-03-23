#include "viewer.hpp"

void			initialize_triangle(triangle &triangle)
{
	initialize_vertex(triangle.normalle);
	initialize_vertex(triangle.v1);
	initialize_vertex(triangle.v2);
	initialize_vertex(triangle.v3);
}

void			initialize_vertex(vertex &vertex)
{
	vertex.x = 0;
	vertex.y = 0;
	vertex.z = 0;
}
