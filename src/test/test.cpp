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
	Graph<int,int,int> p;

	p.insertKey(1,2);
	p.insertKey(2,2);
	p.insertKey(3,2);
	p.insertKey(4,2);
	p.insertKey(5,2);
	p.insertKey(6,2);
	p.insert_edge(2,1,4);
	p.insert_edge(4,1,4);
	p.insert_edge(2,4,4);
	p.insert_edge(3,4,4);
	p.insert_edge(5,6,4);
	p.insert_edge(5,1,4);
	vector<int> out = p.traverse_dfs(0);

	for(auto i : out)
	{
		printf("%d\t",i);
	}
	printf("\n");

	p.serialize();
	return 0;
}
