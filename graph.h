/*                                                                                  *
 * File : graph.h                                                                   *
 * ================================================================================ *
 * This file is an abstraction interace for the graph type. It is a low level inter *
 * face in C++ based on structs.The interface has been slightly modified to include *
 * and model a circuit, wherein the nodes represent gates, and edges represent the  *
 * wires.                                                                           *
 * ================================================================================ *
 */

// Interface boiler plate
#ifndef _GRAPH_H
#define _GRAPH_H

//Including standard libraries
#include <string>
#include <map>
#include <set>

//Enum type for gates
enum GATE{
  AND,NOT,OR,START,END
};

//Forward references to structs
struct Node;
struct Arc;

//Core Graph Abstraction : A struct here
struct Graph{
  std::set<Node *> nodes;
  std::set<Arc *> arcs;
  std::map<std::string, Node *> nodeMap;
};

//Node abstraction. Arcs denotes set of arcs emanating from node
struct Node{
  int output;
  std::string name; 
  std::set<Arc *> arcsOut;
  std::set<Arc *> arcsIn;
  GATE gate; 
};

//Arc abstraction. Source Node and sink node
struct Arc{
  int signalValue;
  Node* source;
  Node* sink;
};

#endif
