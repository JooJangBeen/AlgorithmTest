#pragma once

//�簢�� ������ ǥ���ϴ� Ŭ����.
class Bounds
{
public:
	Bounds(int x, int y, int width = 1, int height = 1)
		:x(x), y(y), width(width), height(height)
	{
	}

	int X() const { return x; }
	int Y() const { return y; }
	int Width() const { return width; }
	int Height() const { return height; }

	int MaxX() const { return x + width; }
	int MaxY() const { return y + height; }

	//��ħ ���� �Լ�.
	bool Intersects(const Bounds& other) const;
private:
	//���ʻ�� ����.
	int x = 0;
	int y = 0;
	int width = 1;
	int height = 1;
};