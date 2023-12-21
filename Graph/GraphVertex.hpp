#pragma once

template<typename T>
class GraphVertex 
{
private:
	T _node;

public:
	GraphVertex(T node) : _node(node)
	{

	}

	T GetNode()
	{
		return _node;
	}
};