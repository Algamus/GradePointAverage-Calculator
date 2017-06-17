/*
 =================================================================================================================
 Name        : GPA Calculator Yeditepe
 Author      : Gokhan Gobus
 Version     : 01.05
 Copyright   : Gokhan Gobus
 Description : 
 =================================================================================================================
 */
//Inludes
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "Maps.h"



#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "comctl32.lib")


//Defines
	//Pencere Ayarlar
	#define SCREEN_WIDTH 650
	#define SCREEN_HEIGHT 400
	#define WINDOWS_TITLE "CGpa Calculator"
	#define WINDOWS_CLASS_NAME "Window"

	
	





//Main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	//Standart Pencere Kaydý
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;                  
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_WINDOWS_ICON));      
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);            
	wc.lpszClassName = WINDOWS_CLASS_NAME;
	wc.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_WINDOWS_ICON), IMAGE_ICON, 16, 16, 0);
	if(!RegisterClassEx(&wc)){
		MessageBox(NULL, "Pencere Kaydýnda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	//Creating the Window
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,WINDOWS_CLASS_NAME,WINDOWS_TITLE,(WS_OVERLAPPED   | WS_CAPTION  | WS_SYSMENU | WS_MINIMIZEBOX ),CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT,NULL, NULL, hInstance, NULL);
	if(hwnd == NULL){
		MessageBox(NULL, "Pencere Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	//The Message Loop
	while(GetMessage(&Msg, NULL, 0, 0) > 0){
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}