#pragma once
#include <vector>
#include <map>
#include "colors.h"

class Position;
class Block {

public:
	Block();
	void DrawBlock(int offsetX,int offsetY);
	void Move(int row,int column);
	std::vector<Position> GetCellPosition();
	int id;
	std::map<int, std::vector<Position>> cells;
	void Rotate();
	void UndoRotation();
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset=0;
	int columnOffset=0;
};