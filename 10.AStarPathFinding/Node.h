#pragma once

#include <iostream>

struct Position
{
	Position(int x = 0, int y = 0)
		:x(x), y(y)
	{
	}

	int x, y;
};

//노드 클래스.
class Node
{
public:
	Node(int x, int y, Node* parent = nullptr)
		: position(x, y), parent(parent)
	{
	}
	~Node() = default;

	//연산자 오버로딩.
	Position operator-(const Node& other)
	{
		return Position(position.x - other.position.x, position.y - other.position.y);
	}

	bool operator==(const Node& other) const
	{
		return position.x == other.position.x && position.y == other.position.y;
	}

public:
	Position position;

	//비용.
	//현재 노드에서 이동 노드까지의 비용.
	float gCost = 0;
	//이동 노드에서 목표 노드까지의 비용(휴리스틱, 추정).
	float hCost = 0;
	//두 비용을 합친 비용.
	float fCost = 0;

	//링크 필드(부모 노드).
	Node* parent = nullptr;

};