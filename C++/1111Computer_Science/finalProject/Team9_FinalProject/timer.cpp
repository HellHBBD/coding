#include <iostream>
#include <unistd.h>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	CONSOLE_FONT_INFOEX fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 0;
	fontex.dwFontSize.Y = 100;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 900, 250, 600, 400, TRUE);

	int time = 0;
	cout << "時間(秒)：" << endl;
	while (1) {
		cout << "\r     \r" << time;
		time += 1;
		sleep(1);
	}
	return 0;
}