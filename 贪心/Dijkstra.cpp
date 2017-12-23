#include "Dijkstra.h"

void Dijkstra(int start, int end, int ** graph, int vertex_num)
{
	table_entry* tables = new table_entry[vertex_num];
	init_table_entry(start, vertex_num, tables);
	int vertex = start;
	while (vertex != NO_VERTEX)
	{
		tables[vertex].visited = true;
		for (int i = 0; i < vertex_num; i++)
		{
			if (tables[i].cost > graph[vertex][i]+tables[vertex].cost)
			{
				tables[i].cost = graph[vertex][i] + tables[vertex].cost;
				tables[i].pre_node_num = vertex;
			}
		}
		int temp_v = -1;
		for (int i = 0; i < vertex_num; i++)
		{
			if (!tables[i].visited)
			{
				if (temp_v == -1)
					temp_v = i;
				else
					if (tables[temp_v].cost > tables[i].cost)
						temp_v = i;
			}
		}
		vertex = temp_v;
	}
	output_shortest_path(start, end, tables);
	delete[] tables;
	tables = 0;
}


void output_shortest_path(int start, int end, table_entry tables[])
{
	if (tables[end].pre_node_num != NO_VERTEX)
	{
		output_shortest_path(start, tables[end].pre_node_num, tables);
	}
	std::cout <<end << "  ";
}