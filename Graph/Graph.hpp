#pragma once
#include <vector> 
#include <iostream>
#include <assert.h>
#include <stack>
#include "GraphVertex.hpp"

using namespace std;

template<typename T>
class Graph
{
private:
	vector<GraphVertex<T>> vertices;
	int maxVerts;

	char** adjMatrix;
	char* vertVisits;
public:
	Graph(int numVerts) : maxVerts(numVerts), adjMatrix(NULL)
	{
		vertices.reserve(maxVerts);
		adjMatrix = new char* [maxVerts];
		vertVisits = new char[maxVerts];
		memset(vertVisits, 0, maxVerts);
		for (int i = 0; i < maxVerts; i++)
		{
			adjMatrix[i] = new char[maxVerts];
			memset(adjMatrix[i], 0, maxVerts);
		}
	}

	~Graph() 
	{
		if (adjMatrix != NULL) 
		{
			for (int i = 0; i < maxVerts; i++)
			{
				if (adjMatrix[i] != NULL)
				{
					delete[] adjMatrix[i];
					adjMatrix[i] = NULL;
				}
			}
			delete[]adjMatrix;
			adjMatrix = NULL;
		}
		if (vertVisits != NULL)
		{
			delete[] vertVisits;
			vertVisits = NULL;
		}
	}

	bool Push(T node)
	{
		if ((int)vertices.size() >= maxVerts)
			return false;

		vertices.push_back(GraphVertex<T>(node));
		return true;
	}

	void AttachEdge(int index1, int index2)
	{
		assert(adjMatrix != NULL);
		adjMatrix[index1][index2] = 1;
		adjMatrix[index2][index1] = 1;
	}

	void AttachDirectEdge(int index1, int index2)
	{
		assert(adjMatrix != NULL);
		adjMatrix[index1][index2] = 1;
	}

	int MaxVertices() const 
	{
		return maxVerts;
	}

	int GetNextUnvisitedVertex(int index)
	{
		for (int i = 0; i < (int)vertices.size(); i++)
		{
			if (adjMatrix[index][i] == 1 && vertVisits[i] == 0)
				return i;
		}
		return -1;
	}

	bool DepthFirstSearch(int startIndex, int endIndex)
	{
		vertVisits[startIndex] = 1;
		stack<int> searchStack;
		int vert = 0;
		searchStack.push(startIndex);

		while (searchStack.empty() != true)
		{
			vert = GetNextUnvisitedVertex(searchStack.top());
			if (vert == -1)
				searchStack.pop();
			else
			{
				vertVisits[vert] = 1;
				searchStack.push(vert);
			}

			if (vert == endIndex)
			{
				memset(vertVisits, 0, maxVerts);
				return true;
			}
			
		}
		return false;
	}

	void DisplayMST()
	{
		int startIndex = 0;
		vertVisits[startIndex] = 1;
		stack<int>searchStack;
		int vert = 0, currentVert = 0;
		searchStack.push(startIndex);

		while (searchStack.empty() != true)
		{
			currentVert = searchStack.top();
			vert = GetNextUnvisitedVertex(currentVert);

			if (vert == -1)
			{
				searchStack.pop();
			}
			else 
			{
				vertVisits[vert] = 1;
				searchStack.push(vert);

				cout << vertices[currentVert].GetNode() << ":" << vertices[vert].GetNode() << endl;
			}
		}
	}

	std::vector<int> GetNeighbors(int nodeIndex) {
		std::vector<int> neighbors;

		for (int i = 0; i < maxVerts; i++) {
			if (adjMatrix[nodeIndex][i] == 1) { // Si hay una conexión
				neighbors.push_back(i);
			}
		}
		return neighbors;
	}
};