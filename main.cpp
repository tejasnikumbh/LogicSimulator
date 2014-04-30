/*                                                                              *
 * File : main.cpp                                                              *
 * ============================================================================ *
 * This is a program to initialize and simulate event driven logic  on a defined*
 * circuit.                                                                     *
 * ============================================================================ *
 */

// Including standard libraries
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include "graph.h"
#include "circuitInitializer.h"
#include "circuitInitializer.cpp"
#include "circuitSimulator.h"
#include "circuitSimulator.cpp"
using namespace std;

// Function prototypes
void printGraphCircuit(Graph &circuit);

// Main program
int main(){
  //Initializing the graph circuit and showing it
  Graph circuit;
  initGraphCircuit(circuit);
  
  cout<<"====== Program to simulate Logic circuit in an event driven manner ======"<<endl;

  cout<<"============================= Simulation 1 =============================="<<endl;
  int gatesSimulated = 0;
  int eventsSimulated = 0;

  // Simulating with a 0 vector. Simulation #1. So all 6 gates should be simulated
  vector<int> prevInput;
  vector<int> curInput(6,1);
  simulateCircuit(circuit,prevInput,curInput,gatesSimulated,eventsSimulated);
  printGraphCircuit(circuit);
  cout<<"Total Processing Gates : "<<gatesSimulated<<endl;

  cout<<"============================= Simulation 2 =============================="<<endl;
  gatesSimulated = 0;
  eventsSimulated = 0;
  
  //Simulating with a different vector. This is Simulation #2.
  curInput[0] = 0;
  simulateCircuit(circuit,prevInput,curInput,gatesSimulated,eventsSimulated);
  printGraphCircuit(circuit);
  cout<<"Total Processing Gates : "<<gatesSimulated<<endl;

  cout<<"============================= Simulation 3 =============================="<<endl;
  gatesSimulated = 0;
  eventsSimulated = 0;
  
  //Simulating with a different vector. This is Simulation #3.
  curInput[2] = 0;
  simulateCircuit(circuit,prevInput,curInput,gatesSimulated,eventsSimulated);
  printGraphCircuit(circuit);
  cout<<"Total Processing Gates : "<<gatesSimulated<<endl;

  cout<<"========================================================================="<<endl;

  return 0;
}



/* 
 * Function : printGraphCircuit(circuit)                                        *
 * ============================================================================ *
 * Function that prints the graph circuit.                                      *
 * ============================================================================ *
 */

void printGraphCircuit(Graph &circuit){
  std::set<Node *>::const_iterator pos;
  for(pos = circuit.nodes.begin();pos!=circuit.nodes.end();++pos){
    std::string n = (*pos)->name;
    if((*pos)->gate == END) continue;
    cout<<n<<" -";
    bool first = true;
    std::set<Arc *>::const_iterator pos2;
    for(pos2 = (*pos)->arcsOut.begin();pos2!=(*pos)->arcsOut.end();++pos2){
      if(first) cout<<(*pos2)->signalValue<<"->";
      if(!first) cout<<" , ";
      cout<<(*pos2)->sink->name;
      first = false;
    }
    cout<<endl;	
  }
  
}


