/*                                                                              *
 * File : circuitInitializer.cpp                                                *
 * ============================================================================ *
 * This is an implementation for the circuit Initializer code that initializes a*
 * given circuit.                                                               *
 * ============================================================================ *
 */


#include <string>
#include "graph.h"


/*                                                                              *
 * Function : initGraphCircuit(circuit)                                         *
 * ============================================================================ *
 * Function that initializes the circuit graph according to a predefined layout *
 * ============================================================================ *
 */ 
 
void initGraphCircuit(Graph &circuit){
  addGate(circuit,"A",START);
  addGate(circuit,"B",START);
  addGate(circuit,"C",START);
  addGate(circuit,"D",START);
  addGate(circuit,"E",START);
  addGate(circuit,"F",START);
  addGate(circuit,"G1",AND);
  addGate(circuit,"G2",AND);
  addGate(circuit,"G3",AND);
  addGate(circuit,"G4",OR);
  addGate(circuit,"G5",OR);
  addGate(circuit,"G6",NOT);
  addGate(circuit,"P",END);
  addGate(circuit,"M",END);
  addGate(circuit,"N",END);
  
  addWire(circuit,"A","G1"); 
  addWire(circuit,"B","G1"); 
  addWire(circuit,"C","G2"); 
  addWire(circuit,"D","G2"); 
  addWire(circuit,"E","G3"); 
  addWire(circuit,"F","G3");
  addWire(circuit,"G1","G4");
  addWire(circuit,"G2","G4");
  addWire(circuit,"G2","G5");
  addWire(circuit,"G3","G5");
  addWire(circuit,"G4","G6");
  addWire(circuit,"G6","P");
  addWire(circuit,"G4","M");
  addWire(circuit,"G5","N");
  
}

/*                                                                              *
 * Function : addGate(circuit,name,type)                                        *
 * ============================================================================ *
 * Analogous to adding a vertex(with associated data) in a graph                * 
 * ============================================================================ *
 */ 

void addGate(Graph &circuit,std::string name, GATE gate){
  Node* node = new Node;
  node->name = name;
  node->gate = gate;
  circuit.nodes.insert(node);
  circuit.nodeMap[name] = node;
}


/*                                                                              *
 * Function : addWire(circuit,src,sink)                                         *
 * ============================================================================ *
 * Analogous to adding an edge(with associated data) in a graph [Wrapper]       * 
 * ============================================================================ *
 */ 

void addWire(Graph &circuit,std::string source,std::string sink){
  Node* sourceNode = circuit.nodeMap[source];
  Node* sinkNode = circuit.nodeMap[sink];
  addArc(circuit,sourceNode,sinkNode);
}


/*                                                                              *
 * Function : addArc(circuit,srcNode,sinkNode)                                  *
 * ============================================================================ *
 * Analogous to adding a vertex(with associated data) in a graph [Core]         * 
 * ============================================================================ *
 */ 

void addArc(Graph &circuit,Node* source, Node* sink){
  Arc* arc = new Arc;
  arc->source = source;
  arc->sink = sink;
  circuit.arcs.insert(arc);
  source->arcsOut.insert(arc);
  sink->arcsIn.insert(arc);
}


