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

#include <iostream>
#include "graph.h"
#include <dlfcn.h>

int main()
{
	Graph<int,int,int> p(GRAPH_TYPE_DIRECTED);

	p.insertKey(1,2);
	p.insertKey(2,2);
	p.insertKey(3,2);
	p.insertKey(4,2);
	p.insertKey(5,2);
	p.insertKey(6,2);
	p.insertKey(7,2);
	p.insertKey(8,2);
	p.insert_edge(2,1,4);
	p.insert_edge(4,1,4);
	p.insert_edge(2,4,4);
	p.insert_edge(3,4,4);
	p.insert_edge(5,6,4);
	p.insert_edge(5,1,4);
	p.insert_edge(1,8,4);
	p.insert_edge(6,4);
	p.insert_edge(7,7);
	p.insert_edge(8,7);
	vector<int> out = p.traverse_dfs(0);
	p.serialize();

	for(auto i : out)
	{
		printf("%d\t",i);
	}
	printf("\n\nBFS\n");

	vector<int> ou = p.traverse_bfs(0);

	for(auto i : ou)
	{
		printf("%d\t",i);
	}
	printf("\n");
	p.serialize();
	return 0;
}
