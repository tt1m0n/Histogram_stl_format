#include "viewer.hpp"

void	string_to_double(std::string &line,
						 vertex &vertex)
{
	std::string::size_type sz;

	vertex.x = extract_one_double(line, sz);
	line.erase(0, sz);
	vertex.y = extract_one_double(line, sz);
	line.erase(0, sz);
	vertex.z = extract_one_double(line, sz);
	line.erase(0, sz);
	check_end_of_line(line);
}

double	extract_one_double(std::string line,
							 std::string::size_type &sz)
{
	double number;
	size_t first_elem;

	first_elem = line.find_first_not_of(" \t", 0);
	if (line[first_elem] != '-' && isdigit(line[first_elem]) == 0)
		print_error_facet();
	number = (double)std::stof (line, &sz);

	return (number);
}

void	check_end_of_line(std::string &line)
{
	size_t	last_elem;

	last_elem = line.find_first_not_of(" \t", 0);
	if (last_elem != std::string::npos)
		print_error_facet();
}