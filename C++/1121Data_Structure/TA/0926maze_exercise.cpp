//
//  main.cpp
//  stack
//

#include <iostream>
#include <stack>

using namespace std;

struct Position {
	int xPos;
	int yPos;

	Position(int x, int y) : xPos(x), yPos(y) {}
};


int main()
{
	//wall=1
	//road=0
	int maze[8][12] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1,
		1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

	int startX = 1;
	int startY = 1;
	int endX = 3;
	int endY = 8;

	stack<Position> mouse;
	Position start(startX,startY);
	mouse.push(start);

	Position nowPos(0,0);
	Position nextPos (0,0);

	while(1)
	{
		//set start point as current position
		nowPos.xPos = mouse.top().xPos;
		nowPos.yPos = mouse.top().yPos;

		if (nowPos.xPos == endX && nowPos.yPos == endY)
			break;
		else if(maze[nowPos.xPos-1][nowPos.yPos] == 0) //up
		{
			nextPos.xPos = nowPos.xPos-1;
			nextPos.yPos = nowPos.yPos;
			mouse.push(nextPos);
			maze[nowPos.xPos-1][nowPos.yPos] = 2; //mark the route passed by as 2
		}
		else if(maze[nowPos.xPos][nowPos.yPos+1] == 0) //right
		{
			nextPos.xPos = nowPos.xPos;
			nextPos.yPos = nowPos.yPos+1;
			mouse.push(nextPos);
			maze[nowPos.xPos][nowPos.yPos+1] = 2; //mark the route passed by as 2
		}
		else if(maze[nowPos.xPos+1][nowPos.yPos] == 0) //down
		{
			nextPos.xPos = nowPos.xPos+1;
			nextPos.yPos = nowPos.yPos;
			mouse.push(nextPos);
			maze[nowPos.xPos+1][nowPos.yPos] = 2; //mark the route passed by as 2
		}
		else if(maze[nowPos.xPos][nowPos.yPos-1] == 0) //left
		{
			nextPos.xPos = nowPos.xPos;
			nextPos.yPos = nowPos.yPos-1;
			mouse.push(nextPos);
			maze[nowPos.xPos][nowPos.yPos-1] = 2; //mark the route passed by as 2
		}
		else //dead end
		{
			mouse.pop();
		}
	};


	//mark the correct route which is saved in the stack as 3
	int x,y;
	while(!mouse.empty())
	{
		x = mouse.top().xPos;
		y = mouse.top().yPos;
		maze[x][y] = 3;
		mouse.pop();
	}

	//print
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<12; j++)
		{
			if (i == endX && j == endY)
				cout << "E "; 
			else {
				switch(maze[i][j]) {
					case 0: cout << "  "; break; // never passed by
					case 1: cout << "# "; break; // wall
					case 2: cout << ". "; break; // passed by
					case 3: cout << "o ";         //correct route
				}
			}
		}
		cout << "\n";
	}
	cout << "\n\n";


	system("pause");

	return 0;

}



