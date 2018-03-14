#include "CommonGraphs.hpp"
#include "Probability.hpp"
#include <unordered_set>
#include <map>
#include "python3.5/Python.h"

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
		G.add_edge(0,1);

}
	if(nedges<500)
	{
		int mvertex=random_int(0,500-(500/3));//std::random_int(2,3)
		Graph G(mvertex);
		;

		for (int j = 0; j < G.num_vertices(); ++j)
		{	
			int listavertices[1000000];
			for(int i=0;i<G.num_vertices();++i)
				listavertices[i]=i;
			vertex_t V1= listavertices[j];vertex_t V2= listavertices[random_int(j+1,j+2)];
			G.add_edge(V1,V2);
		}
		
	}

	else
	{
		Py_Initialize();
		PyObject *FileScript;
	    FileScript = PyFile_FromString("script.py","r");
	    PyRun_SimpleFile(PyFile_AsFile(FileScript),"r");
	    PyObject *retorno, *modulo, *clase, *metodo, *argumentos, *objeto;
	    int resultado;
	    modulo = PyImport_ImportModule("script");
	    clase = PyObject_GetAttrString(modulo, "minimovertice");
	    argumentos = Py_BuildValue("ii",nedges);
	    objeto = PyEval_CallObject(clase, argumentos);
	    metodo = PyObject_GetAttrString(objeto, "minimovertices");
	    argumentos = Py_BuildValue("()");
	    retorno = PyEval_CallObject(metodo,argumentos);
	    PyArg_Parse(retorno, "i", &resultado);
		Py_Finalize();

		//Buscar el que mas se acerca a nedges en minimovertices
		//Completar sumando con las llaves de minimovertice
		//Hacer grafo completo del  valor seleccionado en minimovertice
		//Quitar aristas hasta tener nedges
		int retornO=retorno;
		Graph Complete(retornO);
		

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
int desordenarlista(int lista)
	{
		int listarevuelta[1000000];
		bool usado[1000000];

		for (int i=0; i < 1000000; i++)
		    usado[i]=false;

		int index=0;
		for (int i=0; i < 1000000; i++){
		    do{
		        index = (rand() % 1000000);
		    while (usado[index]);
		    listarevuelta[i] = lista[index];
		    usado[index]=true;
		return listarevuelta;
	}
}
}
}
