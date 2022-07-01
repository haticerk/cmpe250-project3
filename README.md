## CMPE250 - Data Structures & Algorithms, Fall'20, 3rd Project

### From the project description:
A graph is called Eulerian if it contains a circuit that contains every edge exactly once. A
directed graph is Eulerian if and only if in-degree of a vertex v is equal to its out-degree, for
all v in the vertex set of G.

Hierholzer's algorithm ends an Eulerian circuit of an Eulerian graph by iteratively ending
and merging tours (a walk with no repeated edges). It picks a starting vertex for the circuit and
traverses the non-traversed edges arbitrarily, until it is stuck in a vertex,1 completing a tour.
When it is stuck, it merges the found tour with the known Eulerian circuit (initially empty)
and ends a vertex in the current circuit with non-traversed outgoing edges. It starts a new
tour from this vertex and merges the new tour with the known Eulerian circuit again. The
iterations continue until the Eulerian circuit is fully constructed. Note that it can always merge
the known Eulerian circuit with the found tour, since they share at least one common vertex
(starting vertex of the tour) and their edge sets are disjoint (we traverse only non-traversed
edges).

Depending on three parameters, Hierholzer's Algorithm can end dieerent Eulerian circuits.

## How to Run

Run the following commands.

``
g++ *.cpp -std=c++11 -o project3
``

``
./project3 inputFile outputFile
``
