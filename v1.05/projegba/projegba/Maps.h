/*	Harita Header butun prototip ve includes larý içerir
	   Developer:     Gökhan göbüs        
	   
*/
//General font
HFONT defaultfont=CreateFont(16/*height*/, 10/*Width*/, 0/*Escapement*/, 100/*Orientation*/,FW_MEDIUM/*Weight*/, FALSE/*italic*/, FALSE/*underline*/, FALSE/*strikeout*/,ANSI_CHARSET/*charset*/, OUT_DEFAULT_PRECIS/*OutputPrecision*/, CLIP_DEFAULT_PRECIS/*ClipPrecision*/, DEFAULT_QUALITY/*Quality*/,DEFAULT_PITCH | FF_ROMAN/*PitchAndFamily*/,"MS Sans Serif");
//Super Includes Lists

//Prototype Lists
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AddDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK UpdateDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
void add(HWND hwnd);
void detect(HWND hwnd);
void update(HWND hwnd);
void remove(HWND hwnd);
char* creditstr(int t);
char* gradestr(int t);
char* gpacalculator(HWND hwnd);
BOOL checksaf(FILE *file);
BOOL LoadTextFileToEdit(HWND hwnd, LPCTSTR pszFileName);
BOOL SaveTextFileFromEdit(HWND hwnd, LPCTSTR pszFileName);
void DoFileOpen(HWND hwnd,HWND main);
void DoFileSave(HWND hwnd,HWND main);


//Includes Lists
#include "resource.h"
#include "Wproc.h"
#include "DialogAbout.h"
#include "ArkaPlanF.h"




