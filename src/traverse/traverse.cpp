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
#include <queue>

using namespace::std;
/*----------------------- Application includes -------------------------------*/
/*----------------------- Macros ---------------------------------------------*/
/*----------------------- Prototypes -----------------------------------------*/
/*----------------------- Global Variables -----------------------------------*/
/*----------------------- Function definations -------------------------------*/

Graph_Template
void Graph_Schema :: _dfs(Key k, vector<Key> &out, unordered_map<Key, bool> &visited, U_Int &count)
{
	if(visited[k] == true) return;

	visited[k] = true;
	out.push_back(k);
	count++;

	cout<<"Visiting "<<k<<" Count = "<<count<<endl;

	auto p = _graph.find(k);
	if (p == _graph.end())
		return;
	
	for(auto it = (p->second).begin(); it != (p->second).end(); it++)
	{
		_dfs(it->first, out, visited,count); 
	}
}

Graph_Template
vector<Key> Graph_Schema :: traverse_dfs(Key startNode)
{
	vector<Key> out;
	unordered_map<Key, bool> v;
	bool bDone = false;
	U_Int count = 0;
	auto it = _graph.find(startNode);

	if (it == _graph.end()) it = _graph.begin();

	while(!bDone)
	{
		cout<<"Traversing Graph: "<<it->first<<endl;	
		cout<<" Node count is  "<<_node_count<<endl;
		_dfs((it->first), out, v, count);
		it++;
		if(it == _graph.end())
			it = _graph.begin();
		bDone = count == _node_count;
	}

	return out;
}

Graph_Template
vector<Key> Graph_Schema :: traverse_bfs(Key startNode)
{
	queue<Key> q;
	unordered_map<Key, bool> visited;
	vector<Key> out;
	bool bDone = false;
	U_Int count = 0;
	auto it = _graph.find(startNode);
	if(it == _graph.end()) it = _graph.begin();

	while(!bDone)
	{
		if(visited[it->first] == false)
		{
		cout<<"PRocessing "<<it->first<<endl;
			q.push(it->first);
			cout<<"Pushing : "<<it->first<<endl;
		}
		while(!q.empty())
		{
			auto p = q.front();
			q.pop(); 
	
			out.push_back(p);
			count++;
			visited[p] = true;
			auto i = _graph.find(p);
			if(i == _graph.end()) continue;

			for(auto neighbour = (i->second).begin(); neighbour != (i->second).end(); neighbour++)
			{
				if(visited[neighbour->first] == false)
				{
					q.push(neighbour->first);
					cout<<" ** Pushing : "<<neighbour->first<<endl;
				}
			}
		}
		it++;
		if(it == _graph.end()) it = _graph.begin();
		bDone = count == _node_count;
	}

	return out;
}

Graph_Template
vector<Key> Graph_Schema :: serialize()
{
	vector<Key> out;
	/*for(auto it = _graph.begin(); it!=_graph.end();it++)
	{
		for(auto p = (it->second).begin(); p != (it->second).end(); p++)
		{
			cout<<it->first<<"\t=>\t"<< p->first<<"\t\tWeight : "<<(p->second)<<endl;
		}	
	}*/

	for(auto it = _graph.begin(); it!=_graph.end();it++)
	{
		cout<<it->first<<" : \t";
		for(auto p = (it->second).begin(); p != (it->second).end(); p++)
		{
			cout<< p->first<<"\t";	//"\t\tWeight : "<<(p->second)<<endl;
		}
		cout<<endl;
	}

	return out;
}

/*----------------------- Function exports -----------------------------------*/
template vector<int>  Graph<int,int,int> :: serialize();
template vector<int>  Graph<int,int,int> :: traverse_dfs (int startNode);
template vector<int>  Graph<int,int,int> :: traverse_bfs (int startNode);
/*----------------------- End-------------------------------------------------*/
