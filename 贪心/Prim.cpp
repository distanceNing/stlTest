#include "Prim.h"
std::vector<edgeInfo*>edge;
void readFile(const char* file,int** graph,int graphSize)//读取图的信息
{
	for (int i = 0; i < graphSize; i++)
	{
		for (int j = 0; j < graphSize; j++)
			*(*(graph + i) + j) = MAX_COST;
	}

	char a[15];  //从文件中读取数据信息
	char *temp;  //临时变量
	int start, end, cost;
	int i;
	std::ifstream in;
	edgeInfo* tempEdge;
	in.open(file, std::ios::in);
	if (in)         
	{
		while (in.getline(a, 15))
		{
			temp = strtok(a, ","); 
			i = 1;
			while (temp) 
			{
				switch (i)  
				{
				case 1:
				{
					start = atoi(temp);  
					break;
				}
				case 2:
				{
					end = atoi(temp);
					break;
				}
				case 3:
				{
					cost = atoi(temp);
					break;
				}
				default:
					break;
				}
				i++;
				temp = strtok(NULL, ",");
			}
			graph[start][end] = cost;  
			graph[end][start] = cost;
			tempEdge = new edgeInfo;
			tempEdge->cost = cost;
			tempEdge->start = start;
			tempEdge->end = end;
			edge.push_back(tempEdge);
		}

	}
}

void init_table_entry(int start, int vertex_num, table_entry* tables)
{
	for (int i = 0; i < vertex_num; i++)
	{
		(tables + i)->visited = false;
		(tables + i)->cost = MAX_COST;
		(tables + i)->pre_node_num = NO_VERTEX;
	}
	(tables + start)->cost = 0;
}

void output_min_tree( table_entry tables[],int size)
{

	for (int i = 1; i < size; i++)
	{
		std::cout <<"Edge: "<< tables[i].pre_node_num << "--"<<i<<"  cost: "<<tables[i].cost<<std::endl;
	}
}

void Prim(int ** graph, int vertex_num)
{
	table_entry* tables = new table_entry[vertex_num];
	init_table_entry(0, vertex_num, tables);
	int vertex = 0;
	while (vertex!=NO_VERTEX)
	{
		tables[vertex].visited = true;
		for (int i = 0; i < vertex_num; i++)
		{
			if (tables[i].cost > graph[vertex][i])
			{
				tables[i].cost = graph[vertex][i];
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
	
	
	output_min_tree( tables,vertex_num);

	delete[] tables;
	tables = 0;
}
