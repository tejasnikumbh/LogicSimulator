/*                                                                              *
 * File : circuitSimulator.cpp                                                  *
 * ============================================================================ *
 * This is an implementation for the circuit Simulator code that initializes a  *
 * given circuit.                                                               *
 * ============================================================================ *
 */
#include <string>
#include <vector>
#include <set>
#include "graph.h"

/*
 * Function : simulateCircuit(circuit,input)                                      *
 * ============================================================================== *
 *     The core Event Driven Circuit Simulator Logic. The logic takes a naive     *
 * approach to simulating the circuit in an event driven matter. The algorithm    *
 * used is as follows : -                                                         *
 *     The logic makes use of two functions, proccessEvents and processGates which*
 * recursively call each other until any one of the queue is empty. An empty queue*
 * implies there is no change beyond the previous queue layer and circuit need not*
 * be simulated further.                                                          *                     
 *                                                                                *
 * Reference for Algorithm : cs.baylor.edu/~maurer/aida/desauto/chapter3.pdfy     *
 *                                                                                *
 * ============================================================================== *
 */


void simulateCircuit(Graph &circuit,
                     std::vector<int>& prevInput,
                     std::vector<int>& curInput,
                     int& gatesSimulated,
                     int& eventsSimulated){

  std::string inputGates[] = {"A","B","C","D","E","F"};
  int inputLen = curInput.size();
  std::set<Arc*> eventQueue;

  if(prevInput.size() == 0)
  {
    for(int i=0;i<inputLen;i++){
      Node* n = circuit.nodeMap[inputGates[i]];
      n->output = curInput[i];  
      std::set<Arc*>::const_iterator itr;
      for(itr = n->arcsOut.begin();itr!=n->arcsOut.end();++itr){
        eventQueue.insert(*itr);
      }//end of inner for loop	
    }//end of outer for loop
  }//end of outer if block
  else
  {
    for(int i=0;i<curInput.size();i++){
      if(prevInput[i]!=curInput[i]){
        Node* n = circuit.nodeMap[inputGates[i]];
        n->output = curInput[i]; 
        std::set<Arc*>::const_iterator itr;
        for(itr = n->arcsOut.begin();itr!=n->arcsOut.end();++itr){
          eventQueue.insert(*itr);
        }//end of inner for loop	          
      }//end of inner if block
    }//end of outer for loop	
  }//end of outer else block    
  
  
  processEvents(circuit,eventQueue,gatesSimulated,eventsSimulated);
  
  prevInput = curInput;

} 

/*                                                                              *
 * Function : processEvents(circuit,eventQueue,gS,eS)                           *
 * ============================================================================ *
 * Processes the event queue and populates the gate queue as described above    * 
 * ============================================================================ *
 */ 

void processEvents(Graph& circuit,
                   std::set<Arc *>& eventQueue,
                   int& gatesSimulated,
                   int& eventsSimulated){

  if(eventQueue.size() == 0) return;
 
  std::set<Node *> gateQueue;
  std::set<Arc *>::iterator itr;
  for(itr = eventQueue.begin();itr!=eventQueue.end();++itr){
    (*itr)->signalValue = (*itr)->source->output;
    gateQueue.insert((*itr)->sink);
    eventsSimulated++;
  }

  processGates(circuit,gateQueue,gatesSimulated,eventsSimulated);

}


/*                                                                              *
 * Function : processGates(circuit,eventQueue,gS,eS)                            *
 * ============================================================================ *
 * Processes the gate queue and populates the event queue as described above    * 
 * ============================================================================ *
 */ 

void processGates(Graph& circuit,
                  std::set<Node *>& gateQueue, 
                  int& gatesSimulated,
                  int& eventsSimulated){

  if(gateQueue.size() == 0) return;

  std::set<Arc *> eventQueue;
  std::set<Node *>::iterator node;
  for(node = gateQueue.begin();node!=gateQueue.end();++node){

    // Old node output value
    int oldOutput = (*node)->output;

    //Gate processing
    GATE operation = (*node)->gate;
    std::set<Arc*>::iterator arcIn;
    int result;  
    switch(operation){

      case AND:
        result = 1;
        for(arcIn = (*node)->arcsIn.begin();arcIn!=(*node)->arcsIn.end();++arcIn){
          result = result && (*arcIn)->signalValue;
	}
        (*node)->output = result;
        gatesSimulated++;
        break;

      case OR:
        result  = 0;
        for(arcIn = (*node)->arcsIn.begin();arcIn!=(*node)->arcsIn.end();++arcIn){
          result = result||(*arcIn)->signalValue;
	}
        (*node)->output = result;
        gatesSimulated++;
        break;

      case NOT:
        arcIn = (*node)->arcsIn.begin();
        (*node)->output = !(*arcIn)->signalValue; 
        gatesSimulated++;
        break;

      case END:  
        arcIn = (*node)->arcsIn.begin();
        (*node)->output = (*arcIn)->signalValue;
        break;

      default:
        break;

    }//end of switch statement
  
    // New output of node
    int newOutput = (*node)->output;
    
    if(newOutput!=oldOutput){ 
      std::set<Arc*>::iterator arcOut;
      for(arcOut = (*node)->arcsOut.begin();arcOut!=(*node)->arcsOut.end();++arcOut){
        eventQueue.insert(*arcOut);
      }	    
    }
    
  }//End of gate processing

  processEvents(circuit, eventQueue,gatesSimulated,eventsSimulated);

}

