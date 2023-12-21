#include <iostream>
#include "Graph.hpp"
#include "AStarSearch.hpp"

using namespace std;

int main()
{
    Graph<char> graph(25);
    graph.Push('A');
    graph.Push('B');
    graph.Push('C');
    graph.Push('D');
    graph.Push('E');
    graph.Push('F');
    graph.Push('G');
    graph.Push('H');
    graph.Push('I');
    graph.Push('J');
    graph.Push('K');
    graph.Push('L');
    graph.Push('M');
    graph.Push('N');
    graph.Push('O');
    graph.Push('P');
    graph.Push('Q');
    graph.Push('R');
    graph.Push('S');
    graph.Push('T');
    graph.Push('U');
    graph.Push('V');
    graph.Push('W');
    graph.Push('X');
    graph.Push('Y');

    // Conexiones
    graph.AttachEdge(0, 2); // A-C
    graph.AttachEdge(0, 3); // A-D
    graph.AttachEdge(0, 5); // A-F
    graph.AttachEdge(0, 7); // A-H
    graph.AttachEdge(1, 2); // B-C
    graph.AttachEdge(1, 6); // B-G
    graph.AttachEdge(2, 5); // C-F
    graph.AttachEdge(1, 3); // B-D
    graph.AttachEdge(2, 4); // C-E
    graph.AttachEdge(3, 6); // D-G
    graph.AttachEdge(4, 5); // E-F
    graph.AttachEdge(4, 7); // E-H
    graph.AttachEdge(5, 8); // F-I
    graph.AttachEdge(6, 9); // G-J
    graph.AttachEdge(7, 10); // H-K
    graph.AttachEdge(8, 11); // I-L
    graph.AttachEdge(9, 12); // J-M
    graph.AttachEdge(10, 13); // K-N
    graph.AttachEdge(11, 14); // L-O
    graph.AttachEdge(12, 15); // M-P
    graph.AttachEdge(13, 16); // N-Q
    graph.AttachEdge(14, 17); // O-R
    graph.AttachEdge(15, 18); // P-S
    graph.AttachEdge(16, 19); // Q-T
    graph.AttachEdge(17, 20); // R-U
    graph.AttachEdge(18, 21); // S-V
    graph.AttachEdge(19, 22); // T-W
    graph.AttachEdge(20, 23); // U-X
    graph.AttachEdge(21, 24); // V-Y
    graph.AttachEdge(22, 0); // W-A
    graph.AttachEdge(23, 1); // X-B
    graph.AttachEdge(24, 2); // Y-C

    // Conexiones extras para mejorar la conectividad indirecta
    graph.AttachEdge(3, 8); // D-I
    graph.AttachEdge(5, 10); // F-K
    graph.AttachEdge(7, 12); // H-M
    graph.AttachEdge(9, 14); // J-O
    graph.AttachEdge(11, 16); // L-Q
    graph.AttachEdge(13, 18); // N-S
    graph.AttachEdge(15, 20); // P-U
    graph.AttachEdge(17, 22); // R-W
    graph.AttachEdge(19, 24); // T-Y
    graph.AttachEdge(21, 1); // V-B
    graph.AttachEdge(23, 3); // X-D
    graph.AttachEdge(0, 6); // A-G
    graph.AttachEdge(2, 9); // C-J
    graph.AttachEdge(4, 11); // E-L
    graph.AttachEdge(6, 13); // G-N
    graph.AttachEdge(8, 15); // I-P
    graph.AttachEdge(10, 17); // K-R
    graph.AttachEdge(12, 19); // M-T
    graph.AttachEdge(14, 21); // O-V
    graph.AttachEdge(16, 23); // Q-X
    graph.AttachEdge(18, 0); // S-A
    graph.AttachEdge(20, 2); // U-C
    graph.AttachEdge(22, 4); // W-E

    /*int result = graph.DepthFirstSearch(0, 3);*/


    AStarSearch<char> astar(graph);

    // Definir puntos de inicio y fin
    int start = 0;  // Nodo A
    int end = 10;   // Nodo K

    // Realizar la búsqueda A*
    bool pathFound = astar.Search(start, end);

    if (pathFound) {
        cout << "Camino encontrado de " << static_cast<char>('A' + start)
            << " a " << static_cast<char>('A' + end) << endl;
    }
    else {
        cout << "Camino no encontrado de " << static_cast<char>('A' + start)
            << " a " << static_cast<char>('A' + end) << endl;
    }

    /*std::cout << "Minimum spanning tree:  \n";
    graph.DisplayMST();*/

    return 0;
}

