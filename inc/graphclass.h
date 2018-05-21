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

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "graphtypes.h"
using namespace::std;

#ifndef __GRAPHCLASS_H_
#define __GRAPHCLASS_H_



Graph_Template
class Graph
{
private:
	unordered_set<Key>				_nodes;
	unordered_map<Key, Value> 			_db;
	unordered_map<Key, unordered_map<Key,Weight>> 	_graph;
	Graph_Type 					_graph_type;
	U_Int 						_edge_count;
	U_Int 						_node_count;

	void _dfs(Key, vector<Key>&, unordered_map<Key,bool>&, U_Int&); 
public:
	Graph(u_int type=GRAPH_TYPE_UNDIRECTED)
	{
		_graph_type = type;
		_node_count = 0;
		_edge_count = 0;
	}

	GRAPH_STATUS insert_edge  (Key from, Key to, Weight weight=Weight());
	vector<Key>  traverse_dfs (Key startNode);
	vector<Key>  serialize    ();
        GRAPH_STATUS insertKey    (Key k, Value v);
	GRAPH_STATUS removeKey	  (Key k);
};

//Graph_Template void insert(Graph<T,V>, T,T,V);
#endif // __GRAPHCLASS_H_
