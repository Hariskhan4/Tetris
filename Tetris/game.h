#pragma once
#include "grid.h"
#include"blocks.h"

class Game {
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	Grid grid;
	void DrawGame();
	void PlayerInput();
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	bool IsBlockOutside();
	bool gameOver;
	int score;
private:
	std::vector<Block> AllBlocks;
	Block currentBlock;
	Block nextBlock;
	void RotateBlock();
	void LockBlock();
	bool Blockfits();
	void GameReset();
	void UpdateScore(int LinesCleared, int MoveDownPoints);
};