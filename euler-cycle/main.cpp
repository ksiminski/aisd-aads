

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <stack>
#include <numeric>
#include <type_traits>

class graph
{
public:
	struct edge 
	{
		std::size_t start;
		std::size_t end;
	};
	
protected:

	std::size_t number_of_vertices;
	std::vector<std::vector<bool>> adjacency_matrix;
	
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
		
		adjacency_matrix = std::vector<std::vector<bool>> (number_of_vertices, std::vector<bool> (number_of_vertices, false));
		
		std::vector<std::size_t> init (number_of_vertices);
		std::iota(init.begin(), init.end(), 0);
		
		
		for (const edge e : edges)
		{
			adjacency_matrix[e.start][e.end] = true;
			adjacency_matrix[e.end][e.start] = true;
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
	
public:
	std::size_t get_number_of_vertices() const 
	{
		return number_of_vertices;
	}
	
public:

	auto euler_cycle_iter()
	{
      std::vector<std::size_t> cycle;
      std::stack<std::size_t> stack; 

      // start from vertex 0
      std::size_t current_vertex = 0;
      cycle.push_back(current_vertex);

      do 
      {
         // take any neighbour of current_vertex
         bool has_neighbour = false;
         for (std::size_t neighbour = 0; neighbour < number_of_vertices; neighbour++) 
         {
            if (adjacency_matrix[current_vertex][neighbour]) 
            {
               // push current vertex to stack
               stack.push(current_vertex);

               // remove edge from graph
               adjacency_matrix[current_vertex][neighbour] = false;
               adjacency_matrix[neighbour][current_vertex] = false; 

               // move to neighbour
               current_vertex = neighbour;
               has_neighbour = true;
               break;
            }
         }
         if (not has_neighbour) 
         {
            // backtrack
            if (not stack.empty()) 
            {
               current_vertex = stack.top();
               stack.pop();
            }
            cycle.push_back(current_vertex);
         }
      } while (not stack.empty());

      return cycle;
   }


   auto visit(std::size_t v) -> std::vector<std::size_t>
   {
      std::vector<std::size_t> cycle;

      for (std::size_t neighbour = 0; neighbour < number_of_vertices; neighbour++) 
      {
         if (adjacency_matrix[v][neighbour]) 
         {
            // remove edge from graph
            adjacency_matrix[v][neighbour] = false;
            adjacency_matrix[neighbour][v] = false; 

            // recurse
            auto sub_cycle = visit(neighbour);
            cycle.insert(cycle.end(), sub_cycle.begin(), sub_cycle.end());
         }
      }
      cycle.push_back(v);
      return cycle;
   }

   auto euler_cycle_rec()
   {
      return visit(0);
   }

};


int main ()
{
	graph G;
	
	// [PL] Wierzchołki są numerowane zawsze od zera.
	// [EN] The vertices are always indexed from zero.
	G.add_edges(
		{
			{0, 3},
			{0, 5},
         {3, 1},
         {1, 5},
         {1, 4},
         {4, 2},
         {2, 6},
         {6, 1}
		}
	);
	
	std::cout << "GRAPH" << std::endl;
	std::cout << "adjacency matrix" << std::endl;

	std::cout << G.to_string_adjacency_matrix() << std::endl;
	std::cout << "Euler cycle" << std::endl;
	
   {
      std::cout << "iterative version:" << std::endl;
      auto g = G; 
      auto cycle = g.euler_cycle_iter();
      for (auto v : cycle)
      {
         std::cout << v << " ";
      }
      std::cout << std::endl;
   }
   {
      std::cout << "recursive version:" << std::endl;
      auto g = G; 
      auto cycle = g.euler_cycle_rec();
      for (auto v : cycle)
      {
         std::cout << v << " ";
      }
      std::cout << std::endl;
   }

	return 0; 
}




