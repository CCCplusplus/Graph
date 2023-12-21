#pragma once
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <limits>
#include <functional>
#include "Graph.hpp"  // Asegúrate de que este es el archivo correcto para tu clase Graph

// Definición de la clase AStarSearch
template<typename T>
class AStarSearch {
public:
    AStarSearch(Graph<T>& graph) : graph(graph) {}

    bool Search(int start, int goal) {
        // Estructuras de datos para A*.
        std::unordered_map<int, int> cameFrom;
        std::unordered_map<int, int> gScore;
        std::unordered_map<int, int> fScore;
        std::unordered_set<int> openSetContents;  // Conjunto para rastrear los elementos en openSet

        for (int i = 0; i < graph.MaxVertices(); ++i) {
            gScore[i] = std::numeric_limits<int>::max();
            fScore[i] = std::numeric_limits<int>::max();
        }

        gScore[start] = 0;
        fScore[start] = Heuristic(start, goal);

        auto compare = [&fScore](int lhs, int rhs) {
            return fScore[lhs] > fScore[rhs];
            };

        std::priority_queue<int, std::vector<int>, decltype(compare)> openSet(compare);
        openSet.push(start);
        openSetContents.insert(start);

        while (!openSet.empty()) {
            int current = openSet.top();
            openSet.pop();
            openSetContents.erase(current);  // Eliminar el elemento actual de openSetContents

            if (current == goal) {
                // Llegamos al objetivo.
                return true;
            }

            for (auto neighbor : graph.GetNeighbors(current)) {
                int tentative_gScore = gScore[current] + 1;  // Coste uniforme
                if (tentative_gScore < gScore[neighbor]) {
                    cameFrom[neighbor] = current;
                    gScore[neighbor] = tentative_gScore;
                    fScore[neighbor] = gScore[neighbor] + Heuristic(neighbor, goal);

                    if (openSetContents.find(neighbor) == openSetContents.end()) {
                        openSet.push(neighbor);
                        openSetContents.insert(neighbor);  // Añadir el vecino a openSetContents
                    }
                }
            }
        }

        return false;  // No se encontró un camino.
    }

private:
    Graph<T>& graph;

    int Heuristic(int node, int goal) const {
        // Implementación simple de la heurística
        // Aquí puedes añadir una heurística más sofisticada si es necesario.
        return std::abs(node - goal);
    }
};