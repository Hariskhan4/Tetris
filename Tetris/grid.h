#pragma once
#include <vector>
#include "raylib.h"
class Grid {
public:
	Grid();
	int grid[20][10];
	void Initialize();
	void Print();
	void DrawGrid();
	bool IsCellOutside(int row,int column);
	bool IsCellEmpty(int row,int column);
	int ClearFullRow();
private:
	int numRows;
	int numCols;
	int cellSize;
	std::vector<Color> colors;
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
	
};