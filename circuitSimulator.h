/*                                                                              *
 * File : circuitSimulator.h                                                    *
 * ============================================================================ *
 * This is an interface for the circuit Simulator code that initializes a       *
 * given circuit.                                                               *
 * ============================================================================ *
 */


#ifndef _circuitSimulator_h
#define _circuitSimulator_h

#include <string>
#include <vector>
#include <set>
#include "graph.h"

void simulateCircuit(Graph &circuit,
                     std::vector<int>& prevInput,
                     std::vector<int>& curInput,
                     int& gatesSimulated,
                     int& eventsSimulated);

void processGates(Graph& circuit,
                  std::set<Node *>& gateQueue,
                  int& gatesSimulated,
                  int& eventsSimulated);

void processEvents(Graph& circuit,
                   std::set<Arc *>& eventQueue,
                   int& gatesSimulated,
                   int& eventsSimulated);

#endif

