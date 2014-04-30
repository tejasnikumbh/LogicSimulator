Logic-Simulator
===============

Event Driven Logic Simulator for Foundation of Project Course. This simulator is written in c++ and makes use of the naive Twin Queue (Event Processor and Gate Processor) Algorithm to simulate the evaluation of a circuit with logic gates.

Currently the circuit is hardcoded into the code. The contents of this repository are described below.

* Sample Circuit
     Image of circuit which is simulated in the simulator.

* main.cpp
     Main program that simulates the circuit.

* graph.h
     Graph Abstraction that is leveraged for modelling of circuit as a graph. Note that this has minor modifications to the definition of a node and an arc to accomodate the concepts of gate and wires respectively.

* circuitInitializer.h and circuitInitializer.cpp
     Interface and implementation of circuit initializer code. The code is sufficiently modularised such that the definition of the ckt can be changed easily. Further revisions would include taking in ckt input from a text file.

* circuitSimulator.h and circuitSimulator.cpp
     Interface and implementation for the circuit simulator. Here is where the core recursive algorithm lies. The algorithm consists of two functions, processEvents and processGates, which recurseively call each other until the queue size becomes 0, indicating that there is no need to simulate the ckt further as there is no change in inputs to the next layer.


     


