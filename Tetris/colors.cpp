#include "colors.h"


	const Color darkgrey = { 26, 31, 40, 255 };
	const Color orange = { 255, 161, 0, 255 };
	const Color red = { 230, 41, 55, 255 };
	const Color yellow = { 253, 249, 0, 255 };
	const Color purple = { 200, 122, 255, 255 };
	const Color blue = { 0, 121, 241, 255 };
	const Color cyan = { 21,204,209,255 };
	const Color green = { 0, 228, 48, 255 };
	const Color lightBlue = { 59, 85, 162, 255 };
	const Color darkBlue = { 44, 44, 127, 255 };

	std::vector<Color> GetCellColor()
	{
		return { darkgrey,orange,red,yellow,purple,blue,cyan,green };

	}