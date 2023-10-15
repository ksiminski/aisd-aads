

#include <iostream>
#include <array>
#include <utility>
#include <iterator>
#include <algorithm>
#include <vector>


#include <boost/format.hpp>
#include <boost/array.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/directed_graph.hpp>
#include <boost/graph/exterior_property.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/graphviz.hpp>
 
auto create_graph ()
{
	std::vector<std::pair<int, int>> edges
	{
		{0,3},
		{1,2},
		{2,3},
		{3,4},
		{1,5},
		{5,6},
	};
	
	
	typedef boost::adjacency_list<boost::setS, boost::vecS,	boost::undirectedS, boost::property<boost::vertex_color_t, boost::default_color_type>> graph;
	
// 	typedef boost::adjacency_list<boost::setS, boost::vecS,	boost::directedS, boost::property<boost::vertex_color_t, boost::default_color_type>> graph;
	
	graph g{edges.begin(), edges.end(), 7};
	
	return g;
}

void print_graph (auto & graph, std::ostream & file)
{
	boost::write_graphviz(file, graph);
}

void breadth_first_search (auto & g)
{
	std::cout << "[PL] przeszukiwanie wszerz" << std::endl;
	std::cout << "[EN] breadth first search" << std::endl;
 
	using vertices_size_type = boost::graph_traits<boost::adjacency_list<>>::vertices_size_type;
	
	std::vector<vertices_size_type> distances(boost::num_vertices(g));
	std::vector<vertices_size_type> predecessors(boost::num_vertices(g));
	
	auto dist_pmap = boost::make_iterator_property_map(distances.begin(),    get(boost::vertex_index, g));
	auto pred_pmap = boost::make_iterator_property_map(predecessors.begin(), get(boost::vertex_index, g));
	
	
	int nr_starting = 0;
	boost::breadth_first_search(g, nr_starting,
								boost::visitor(
									boost::make_bfs_visitor(
										std::make_pair(
										boost::record_distances(
											dist_pmap, boost::on_tree_edge{}),
										boost::record_predecessors(
											pred_pmap, boost::on_tree_edge{})
								))));
	 
	std::cout << "starting: " << nr_starting << std::endl;
	for (std::size_t i = 0; i < distances.size(); ++i)
	{	
		std::cout << "v: " << i << ", d(" << nr_starting << ", " << i << ") == " << distances[i] << ", ";
	    int p = i;
		while (p != nr_starting)
		{
			std::cout << p << " <-- ";
			p = predecessors[p];
		}
	    std::cout << nr_starting << std::endl;
	}
	
	return; 
}

struct MyVisitorDiscover : public boost::null_visitor
{ 
	using event_filter = boost::on_discover_vertex;

	template <typename Vertex, typename Graph>
	void operator()(Vertex v, Graph &g) 
	{
		std::cout << " ( " << v << " ";
	}
};

struct MyVisitorFinish : public boost::null_visitor 
{
	using event_filter = boost::on_finish_vertex;

	template <typename Vertex, typename Graph>
	void operator()(Vertex v, Graph &g) 
	{
		std::cout << " " << v << " ) ";
	}
};



void depth_first_search (auto & g)
{
	std::cout << "[PL] przeszukiwanie w glab" << std::endl;
	std::cout << "[EN] depth first search" << std::endl;
	
	using vertices_size_type = boost::graph_traits<boost::adjacency_list<>>::vertices_size_type;
	
	std::vector<vertices_size_type> distances(boost::num_vertices(g));
	std::vector<vertices_size_type> predecessors(boost::num_vertices(g));
	
	
	auto dist_pmap = boost::make_iterator_property_map(distances.begin(),    get(boost::vertex_index, g));
	auto color_map = boost::get(boost::vertex_color, g);
		
	int nr_startowego = 0;
	auto startowy = boost::vertex(nr_startowego, g);
	
	boost::depth_first_search(
		g, boost::make_dfs_visitor(
			std::make_pair(
				MyVisitorDiscover(),
				MyVisitorFinish()
			)), color_map, startowy);
	
	std::cout << std::endl;
	
	return; 
}

int main ()
{
	auto graph = create_graph();
	std::cout << "------------------" << std::endl;
	print_graph(graph, std::cout );
	std::cout << "------------------" << std::endl;
	breadth_first_search(graph);
	std::cout << "------------------" << std::endl;
	depth_first_search(graph);
	std::cout << "------------------" << std::endl;
	
	
	return 0;
}




