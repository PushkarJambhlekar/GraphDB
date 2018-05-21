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

Graph_Template
vector<Key> Graph_Schema :: traverse_dfs(Key startNode)
{
	vector<Key> out;
	for(auto it = _graph.begin(); it!=_graph.end();it++)
	{
		for(auto p = (it->second).begin(); p != (it->second).end(); p++)
		{
			cout<<it->first<<"\t=>\t"<< p->first<<"\t\tWeight : "<<(p->second)<<endl;
		}	
	}

	return out;
}

/*----------------------- Function exports -----------------------------------*/
template vector<int>  Graph<int,int,int> :: traverse_dfs (int startNode);
/*----------------------- End-------------------------------------------------*/
