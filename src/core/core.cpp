/* __COPYRIGHT_BEGIN_
 *
 * Copyright 2018 by Pushkar Jambhlekar. This program is free software.
 * You can use, redistribute and/or modify it under the terms of GPL 
 * published by the Free softwre.
 * This sofware come with no warrenty and authors are not liable for any
 * damage cause
 *
 * @Author: Pushkar Jambhlekar
 *
 * __COPYRIGHT_END
*/

/*------------------------ System includes -----------------------------------*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include "graph.h"
#include <typeinfo>

using namespace::std;
/*----------------------- Application includes -------------------------------*/
/*----------------------- Macros ---------------------------------------------*/
/*----------------------- Prototypes -----------------------------------------*/
/*----------------------- Global Variables -----------------------------------*/
/*----------------------- Function definations -------------------------------*/

/*
 * @brief: insert_edge
 *      Inserts an edge in graph 'from'->'to' with weight. if weight no present 
 *      it takes default value of type V()
 *
 * @return: GRAPH_OK on success
 */
Graph_Template
GRAPH_STATUS Graph_Schema ::  insert_edge(Key from, Key to, Weight weight)
{
	int updateCount = 1;
	int nc          = 0;
	if(_db.find(to) == _db.end() || _db.find(from) == _db.end())
		return GRAPH_ERR_KEY_NOT_PRESENT;

	if (_graph.find(from) != _graph.end())
	{
		unordered_map<Key,Weight> p = (_graph.find(from))->second;
		if(p.find(to) != p.end())
		{
			updateCount = 0;
		}
	}

	if(_nodes.find(from) == _nodes.end())
	{
		nc++;
		_nodes.insert(from);
	}
	if (_nodes.find(to)  == _nodes.end())
	{
		_nodes.insert(to);
		nc++;
	}

	cout<<"Updating Node: "<<from<<" to "<<to<<endl;
	_graph[from][to] =weight;
	if(_graph_type & GRAPH_TYPE_UNDIRECTED)
		_graph[to][from] = weight;

	_edge_count     += updateCount;
	_node_count     += nc;
	cout <<" Node count is "<<_node_count<<endl;
	return GRAPH_OK;
}


/*----------------------- Function exports -----------------------------------*/
template GRAPH_STATUS Graph<int,int,int> :: insert_edge  (int from, int to, int weight);
/*----------------------- End-------------------------------------------------*/
