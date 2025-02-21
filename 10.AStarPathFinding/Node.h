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

//��� Ŭ����.
class Node
{
public:
	Node(int x, int y, Node* parent = nullptr)
		: position(x, y), parent(parent)
	{
	}
	~Node() = default;

	//������ �����ε�.
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

	//���.
	//���� ��忡�� �̵� �������� ���.
	float gCost = 0;
	//�̵� ��忡�� ��ǥ �������� ���(�޸���ƽ, ����).
	float hCost = 0;
	//�� ����� ��ģ ���.
	float fCost = 0;

	//��ũ �ʵ�(�θ� ���).
	Node* parent = nullptr;

};