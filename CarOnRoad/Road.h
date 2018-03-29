#pragma once
class Road
{
	int xLeftSolidLine;
	int xRightSolidLine;
	int xCenterDottedLine;
	int y1Gap1;
	int y2Gap1;
	int y1Gap2;
	int y2Gap2;
public:
	Road();
	~Road();
	void Draw();
	int GetXLeftSolidLine();
	int GetXRightSolidLine();
};

