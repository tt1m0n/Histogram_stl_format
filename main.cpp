#include "viewer.hpp"

int		main(int argc, char **argv)
{
	std::ifstream	file;
	double			cells[100];
	memset (cells, 0, sizeof(cells));
	if (argc == 2)
	{
		check_if_dir(argv[1]);
		file.open(argv[1], std::ios::in);
		if (file.is_open())
		{
			read_from_file(file, cells);
			write_to_file(cells);
		}
		else
			std::cout << "file [" << argv[1] << "] Does not exist"
					  << std::endl;
		file.close();
	}
	else
		std::cout << "Usage: ./viewer <filename>" << std::endl;
	return (0);
}

void	check_if_dir(const char *file)
{
	struct stat		inform;

	lstat(file, &inform);
	if (S_ISDIR(inform.st_mode))
	{
		std::cout << "error: [" << file << "] - " << "is a directory\n";
		exit (EXIT_FAILURE);
	}
}

void		read_from_file(std::ifstream &fd, double (&cells)[100])
{
	std::string line;

	getline(fd, line);
	parse_first_str(line);
	while (!fd.eof())
		read_one_facet(fd, cells);
}

void	parse_first_str(std::string &line)
{
	size_t found;

	found = line.find_first_not_of(" \t", 0);
	if (found != std::string::npos
		&& line.substr(found, 6) == "solid ")
		return ;
	else
	{
		std::cout << "It is no \"solid \" at start position in first line "
				  << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	write_to_file(double (&cells)[100])
{
	std::ofstream ready_file;

	ready_file.open("histogram", std::ios::out | std::ios::trunc);
	for(int i = 0; i < 100; i++)
	{
		ready_file << cells[i] << std::endl;
	}
	ready_file.close();
}