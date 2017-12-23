#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#define NO_VERTEX -1
#define MAX_COST 0xfffffff

struct table_entry //�ҽ�˹���������·������Ҫ�ı���Ϣ
{
	int cost;
	int pre_node_num;
	bool visited;
};

struct edgeInfo
{
	int start;
	int end;
	int cost;
};

extern std::vector<edgeInfo*>edge;
void readFile(const char* file, int** graph, int graphSize);//��ȡͼ����Ϣ

void init_table_entry(int start, int vertex_num, table_entry* tables);

void output_min_tree( table_entry tables[], int size);

void Prim(int **graph,int vertex_num);

