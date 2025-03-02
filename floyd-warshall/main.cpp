

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>

class graph
{
public:
	struct edge 
	{
		std::size_t start;
		std::size_t end;
		double weight;
	};
	
protected:

	std::size_t number_of_vertices;
	std::vector<std::vector<double>> adjacency_matrix;
	
	std::vector<std::vector<std::size_t>> predecessor_matrix;
	
public:
	void add_edges (const std::vector<edge> & edges)
	{
		std::size_t max_index {0};
		for (const edge e : edges)
		{
			if (e.start > max_index)
				max_index = e.start;
			if (e.end > max_index)
				max_index = e.end;
		}
		number_of_vertices = max_index + 1;
		
		adjacency_matrix = std::vector<std::vector<double>> (number_of_vertices, std::vector<double> (number_of_vertices, std::numeric_limits<double>::infinity()));
		
		std::vector<std::size_t> init (number_of_vertices);
		std::iota(init.begin(), init.end(), 0);
		
		predecessor_matrix = std::vector<std::vector<std::size_t>> (number_of_vertices, std::vector<std::size_t>(number_of_vertices, std::numeric_limits<std::size_t>::max()));
		
		for (std::size_t i = 0; i < number_of_vertices; i++)
		{
			adjacency_matrix[i][i] = 0;
			predecessor_matrix[i][i] = i;
		}	
		for (const edge e : edges)
		{
			adjacency_matrix[e.start][e.end] = e.weight;
			predecessor_matrix[e.start][e.end] = e.end;
		}
	}
	
public:
	template <class T>
	static 
    std::string to_string(const std::vector<std::vector<T>> & matrix) 
    {
		std::stringstream ss; 
		
		// column numbers
		auto size = matrix.size();
		
		ss << '\t';
		for (std::size_t i = 0; i < size; i++)
			ss << i << '\t';
		ss << std::endl;
		
		// body of the matrix
		for (std::size_t i = 0; i < size; i++)
		{
			// row number 
			ss << i << '\t';
			for (std::size_t j = 0; j < size; j++)
			{
				if (std::is_same<T, std::size_t>::value)
				{
					if (matrix[i][j] == std::numeric_limits<T>::max())
						ss << "inf\t";
					else
						ss << matrix[i][j] << '\t';
				}
				else
					ss << matrix[i][j] << '\t';
			}
			ss << std::endl;
		}
		
		return ss.str();
	}
	
public:
	std::string to_string_adjacency_matrix() const 
	{
		return to_string(adjacency_matrix);
	}
	std::string to_string_predecessor_matrix() const 
	{
		return to_string(predecessor_matrix);
	}
	
public:
	std::size_t get_number_of_vertices() const 
	{
		return number_of_vertices;
	}
	
public:
	std::size_t get_predecessor(const std::size_t i, const std::size_t j)
	{
		return predecessor_matrix[i][j];
	}
	double get_distance(const std::size_t i, const std::size_t j)
	{
		return adjacency_matrix[i][j];
	}
public:
	auto floyd_warshall()
	{
	 std::vector<std::pair<std::vector<std::vector<double>>, std::vector<std::vector<std::size_t>> >> results;
		
		for (std::size_t k = 0; k < number_of_vertices; k++)
		{
			for (std::size_t i = 0; i < number_of_vertices; i++)
			{
				if (adjacency_matrix[i][k] != std::numeric_limits<double>::infinity())
				{
					for (std::size_t j = 0; j < number_of_vertices; j++)
					{
						if (adjacency_matrix[i][k] + adjacency_matrix[k][j] < adjacency_matrix[i][j])
						{
							adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];
							predecessor_matrix[i][j] = predecessor_matrix[i][k];
						}
					}
				}
			}
			results.push_back({adjacency_matrix, predecessor_matrix});
		}
		return results;
	}
};


int main ()
{
	graph g;
	
	// [PL] Wierzchołki są numerowane zawsze od zera.
	// [EN] The vertices are always indexed from zero.
/*
   g.add_edges(
		{
			{0, 1, 2},
			{0, 3, 8},

			{1, 0, 5},
			{1, 2, 6},
			{1, 3, 3},

			{2, 1, 1},
			{2, 3, 5},

			{3, 0, 1},
			{3, 1, 1},
			{3, 2, 2},
		}
	);
*/	
   g.add_edges(
		{
			{0, 1, 2},
			{0, 4, 2},

			{1, 0, 2},
			{1, 2, 3},
			{1, 3, 4},

			{2, 3, -1},

			{3, 0, 7},
			{3, 4, 2},

			{4, 0, 5},
			{4, 1, 1},
			{4, 2, 1},
		}
	);
	std::cout << "GRAPH" << std::endl;
	std::cout << "adjacency matrix" << std::endl;
	std::cout << g.to_string_adjacency_matrix() << std::endl;
	
	std::cout << "predecessor matrix" << std::endl;
	std::cout << g.to_string_predecessor_matrix() << std::endl;
	
	std::cout << std::endl;
	std::cout << "FLOYD-WARSHALL algorithm" << std::endl;
	
	
	auto matrices = g.floyd_warshall();
	
	std::size_t k = 0;
	for (auto [d, p] : matrices)
	{
		std::cout << "X --> " << k << " --> Y" << std::endl;
		std::cout << "adjacency matrix d" << k << std::endl;
		std::cout << graph::to_string(d) << std::endl;
		
		std::cout << "predecessor matrix p" << k << std::endl;
		std::cout << graph::to_string(p) << std::endl;
		
		k++;
	}
	 
	std::cout << std::endl;
	std::cout << "PATHS" << std::endl;
	
	auto nVertices = g.get_number_of_vertices();
	for (std::size_t i = 0; i < nVertices; i++)
	{
		for (std::size_t j = 0; j < nVertices; j++)
		{
			if (i != j)
			{
				double dist = g.get_distance(i,j);
				std::cout << "d(" << i << ", " << j << ") == " << dist; 
				
				if (dist != std::numeric_limits<double>::infinity())
				{
			std::cout << ": " << i;
			auto predecessor = g.get_predecessor(i, j);
 			while (predecessor != j and predecessor != std::numeric_limits<std::size_t>::max())
 			{
 				std::cout << " --> " << predecessor;
 				predecessor = g.get_predecessor(predecessor, j);
 			}
			std::cout << " --> " << j;
			}
			std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
	 
	return 0; 
}




