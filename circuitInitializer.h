/*                                                                              *
 * File : circuitInitializer.h                                                  *
 * ============================================================================ *
 * This is an interface for the circuit Initializer code that initializes a     *
 * given circuit.                                                               *
 * ============================================================================ *
 */


#ifndef _circuitInitializer_h
#define _circuitInitializer_h

#include <string>
#include "graph.h"

void initGraphCircuit(Graph &circuit);
void addGate(Graph &circuit,std::string name,GATE gate);
void addWire(Graph &circuit,std::string source,std::string sink);
void addArc(Graph &circuit,Node* source,Node* sink);

#endif

