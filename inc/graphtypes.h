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

#ifndef __GRAPHTYPES_H_
#define __GRAPHTYPES_H_

/*--------------------------- Type defines -----------------------------------*/
typedef unsigned int U_Int;
typedef unsigned int Graph_Type;

/*---------------------------- Macro defines ---------------------------------*/
#define Graph_Template 		template<class Key, class Value, class Weight>
#define Graph_Schema 		Graph<Key,Value,Weight>

#define GRAPH_TYPE_DIRECTED     (1<<1)
#define GRAPH_TYPE_UNDIRECTED   (1<<2)
#define GRAPH_TYPE_WEIGHTED     (1<<3)
#define GRAPH_TYPE_UNWEIGHTED   (1<<4)

/*---------------------------- Enums------------------------------------------*/
typedef enum 
{
	GRAPH_OK = 0,
	GRAPH_ERR_GENERIC,
	GRAPH_ERR_KEY_NOT_PRESENT,
} GRAPH_STATUS;

/*----------------------------------------------------------------------------*/

#endif // __GRAPHCLASS_H_
