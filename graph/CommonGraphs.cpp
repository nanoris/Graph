#include "CommonGraphs.hpp"
#include "Probability.hpp"
#include <unordered_set>
#include <map>

namespace graphs
{

using vertex_t = Graph::vertex_t;

Graph Petersen()
{
	Graph G(10);

	G.add_edges({{0, 1},
				 {0, 4},
				 {0, 5},
				 {1, 2},
				 {1, 6},
				 {2, 3},
				 {2, 7},
				 {3, 4},
				 {3, 8},
				 {4, 9},
				 {5, 7},
				 {5, 8},
				 {6, 8},
				 {6, 9},
				 {7, 9}});

	G.sort_neighbors();

	return G;
}

Graph Path(int n)
{
	Graph G(n + 1);
	for (vertex_t i = 0; i < n; ++i)
		G.add_edge(i, i + 1);
	return G;
}

Graph Cycle(int n)
{
	Graph G = Path(n - 1);
	if (n > 2)
	{
		G.add_edge(0, n - 1);
	}
	return G;
}

Graph Complete(int n)
{
	Graph G(n);

	for (vertex_t i = 0; i + 1 < n; ++i)
	{
		for (vertex_t j = i + 1; j < n; ++j)
		{
			G.add_edge(i, j);
		}
	}

	return G;
}

Graph Random(int n, double p)
{
	Graph G(n);

	for (auto i : G.vertices())
	{
		for (int j = i + 1; j < G.num_vertices(); ++j)
		{
			if (probability_of_true(p))
				G.add_edge(i, j);
		}
	}
	return G;
}

Graph RandomWeighted(int n, double p)
{
	Graph G(n);

	for (auto i : G.vertices())
	{
		for (int j = i + 1; j < G.num_vertices(); ++j)
		{
			if (probability_of_true(p))
			{
				G.add_edge(i, j, random_int(0, 100));
			}
		}
	}
	return G;
}

Graph Random(int num_verts, int num_edges)
{
	Graph G(num_verts);

	if (num_edges > num_verts * (num_verts - 1) / 2)
		return G; // error!!

	while (G.num_edges() < num_edges)
	{
		int u = random_int(0, num_verts);
		int v = random_int(0, num_verts);
		if (u == v)
			continue;

		using std::unordered_set;
		using Edge = Graph::Edge;
		// 		std::unordered_set<Graph::Edge> Usados;

		G.add_edge_no_repeat(u, v);
	}

	return G;
}

Graph Grid(int n, int m)
{
	Graph G((n + 1) * (m + 1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vertex_t v = i * (m + 1) + j;
			G.add_edge(v, v + 1, random_int(0, 1000));
			G.add_edge(v, v + m + 1, random_int(0, 1000));
		}
	}

	for (int j = 0; j < m; ++j)
	{
		vertex_t v = n * (m + 1) + j;
		G.add_edge(v, v + 1, random_int(0, 1000));
	}

	for (int i = 0; i < n; ++i)
	{
		vertex_t v = i * (m + 1) + m;
		G.add_edge(v, v + m + 1, random_int(0, 1000));
	}

	return G;
}
Graph RandomGraph(int nedges)
{
	if (nedges==0){
		Graph G(1);

}
if (nedges==1){
		Graph G(2);
		G.add_edge(0,1)

}
	if(nedges<50)
	{
		int mvertex=random_int(50/random_int(2,3));
		Graph G(mvertex);
		G.add_edge(random_int(0,mvertex),random_int(0,mvertex),nedges);
	}
	else
	{
		for(int i=2;i++; i<100){
			map<int i,int combinacion(i,2)> minimovertices;
		}
		//Buscar el que mas se acerca a nedges en minimovertices
		//Completar sumando con las llaves de minimovertice
		//Hacer grafo completo del valor seleccionado en minimovertice
		//Quitar aristas hasta tener nedges
		Graph Complete();
	}
	return G;
}
int factorial(int n)
{
    if(n<2)
        return 1;
    else
        return n * factorial(n-1);
}

int combinacion(int n, int r)
{
    if(r==1)
        return n;
    else
    {
        if(n==r)
            return 1;
        else
            return factorial(n) / (factorial(r) * factorial(n - r));
    }
}

// Fill here the cycle, path, complete and random graph.
} // namespace graphs

