#include "baseblock.h"
#include "position.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColor();
}

void Block::DrawBlock(int offsetx,int offsetY)
{
	std::vector<Position> parts = GetCellPosition();
	for (Position item : parts)
	{
		DrawRectangle(item.column * cellSize+offsetx, item.row * cellSize+offsetY, cellSize - 1, cellSize - 1, colors[id]);
	}
};

void Block::Move(int row,int column)
{
	rowOffset += row;
	columnOffset += column;
}

std::vector<Position> Block::GetCellPosition()
{
	std::vector<Position> parts = cells[rotationState];
	std::vector<Position> movedParts;
	for (Position initial : parts)
	{
		Position newPos = Position(initial.row + rowOffset, initial.column + columnOffset);
		movedParts.push_back(newPos);
	}
	return movedParts;
	
}

void Block::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size())
	{
		rotationState = 0;
	}
}

void Block::UndoRotation()
{
	rotationState--;
	if (rotationState == -1)
	{
		rotationState = 0;
	}
}
