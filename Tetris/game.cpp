#include "game.h"
#include "blocks.h"
#include <random>
#include <iostream>


Game::Game()
{
	grid = Grid();
	AllBlocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;
}

Block Game::GetRandomBlock()
{
	if (AllBlocks.empty())
	{
		AllBlocks = GetAllBlocks();
	}
	int RandIndex = rand() % AllBlocks.size();
	Block RandBlock = AllBlocks[RandIndex];
	AllBlocks.erase(AllBlocks.begin()+RandIndex);
	return RandBlock;
}

std::vector<Block> Game::GetAllBlocks()
{
	return {IBlock(), JBlock(), OBlock(), SBlock(), LBlock(), TBlock(), ZBlock()};
}

void Game::DrawGame()
{
	grid.DrawGrid();
	currentBlock.DrawBlock(0,0);
	nextBlock.DrawBlock(280, 270);
}

void Game::PlayerInput()
{
	int KeyPressed = GetKeyPressed();
	if (gameOver && KeyPressed == KEY_ENTER)
	{
		gameOver = false;
		GameReset();
	}
	switch (KeyPressed)
	{
	case KEY_LEFT:
		MoveLeft();
		break;
	case KEY_RIGHT:
		MoveRight();
		break;
	case KEY_DOWN:
		MoveDown();
		UpdateScore(0, 1);
		break;
	case KEY_R:
		RotateBlock();

	}
}

void Game::MoveLeft()
{
	if (!gameOver)
	{
		currentBlock.Move(0, -1);
		if (IsBlockOutside() || Blockfits() == false)
		{
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveRight()
{
	if (!gameOver)
	{
		currentBlock.Move(0, 1);
		if (IsBlockOutside() || Blockfits() == false)
		{
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveDown()
{
	if (!gameOver)
	{
		currentBlock.Move(1, 0);
		score += 1;
		if (IsBlockOutside() || Blockfits() == false)
		{
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position> parts = currentBlock.GetCellPosition();
	for (Position current : parts)
	{
		if (grid.IsCellOutside(current.row,current.column))
		{
			return true;
		}
		
	}
		return false;
}

void Game::RotateBlock()
{
	if (!gameOver)
	{
		currentBlock.Rotate();
		if (IsBlockOutside() || Blockfits() == false)
		{
			currentBlock.UndoRotation();
		}
	}
}

void Game::LockBlock()
{
	std::vector<Position> parts = currentBlock.GetCellPosition();
	for (Position current : parts)
	{
		grid.grid[current.row][current.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	nextBlock = GetRandomBlock();
	if (Blockfits() == false)
	{
		gameOver = true;
	}
	int RowsCleared=grid.ClearFullRow();
	UpdateScore(RowsCleared, 0);
}

bool Game::Blockfits()
{
	std::vector<Position> parts = currentBlock.GetCellPosition();
	for (Position current : parts)
	{
		if (grid.IsCellEmpty(current.row,current.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::GameReset()
{
	grid.Initialize();
	AllBlocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::UpdateScore(int LinesCleared, int MoveDownPoints)
{
	switch (LinesCleared)
	{
	case 1: score += 100;
		break;
	case 2: score += 200;
		break;
	case 3:score += 300;
		break;
	default:
		break;
	}
}
