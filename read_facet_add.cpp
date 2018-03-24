#include "viewer.hpp"

void	read_normalle (std::string &line, vertex &normalle)
{
	size_t		first_elem;
	const int	LEN_PRE_STR = 13;

	first_elem = line.find_first_not_of(" \t", 0);
	if (first_elem != std::string::npos
		&& line.substr(first_elem, LEN_PRE_STR) == "facet normal ")
	{
		line.erase(0, first_elem + LEN_PRE_STR);
		string_to_double(line, normalle);
	}
	else
		print_error_facet();
}

void	read_outer_loop (std::string &line)
{
	size_t		first_elem;
	const int	LEN_PRE_STR = 10;

	first_elem = line.find_first_not_of(" \t", 0);
	if (first_elem != std::string::npos
		&& line.substr(first_elem, LEN_PRE_STR) == "outer loop")
	{
		line.erase(0, first_elem + LEN_PRE_STR);
		check_end_of_line(line);
	}
	else
		print_error_facet();
}

void	read_vertex (std::string &line, vertex &vertex)
{
	size_t 		first_elem;
	const int 	LEN_PRE_STR = 7;

	first_elem = line.find_first_not_of(" \t", 0);
	if (first_elem != std::string::npos
		&& line.substr(first_elem, LEN_PRE_STR) == "vertex ")
	{
		line.erase(0, first_elem + LEN_PRE_STR);
		string_to_double(line, vertex);
	}
	else
		print_error_facet();
}

void	read_endloop (std::string &line)
{
	size_t		first_elem;
	const int	LEN_PRE_STR = 7;

	first_elem = line.find_first_not_of(" \t", 0);
	if (first_elem != std::string::npos
		&& line.substr(first_elem, LEN_PRE_STR) == "endloop")
	{
		line.erase(0, first_elem + LEN_PRE_STR);
		check_end_of_line(line);
	}
	else
		print_error_facet();
}

void	read_endfacet (std::string &line)
{
	size_t		first_elem;
	const int	LEN_PRE_STR = 8;

	first_elem = line.find_first_not_of(" \t", 0);
	if (first_elem != std::string::npos
		&& line.substr(first_elem, LEN_PRE_STR) == "endfacet")
	{
		line.erase(0, first_elem + LEN_PRE_STR);
		check_end_of_line(line);
	}
	else
		print_error_facet();
}
