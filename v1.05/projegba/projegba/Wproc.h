LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){//frame ustundeki genel dinleme

	switch(msg){
		case WM_CREATE://Creation State
		{
			HWND list,text1,text2,text1a,text2a,add,remove,update,removeall;

			//Create Listbox listwiev
			LVCOLUMN lvc = { 0 };
			
			
			list=CreateWindowEx( WS_EX_CLIENTEDGE, WC_LISTVIEW, 0, LVS_REPORT | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |WS_VISIBLE | WS_CHILD | CBS_AUTOHSCROLL | LBS_MULTICOLUMN , 10, 10, 395, 300, hwnd, ( HMENU )IDC_LISTBOX, GetModuleHandle(NULL), NULL );
			if(list == NULL){
				MessageBox(NULL, "ListBox Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}

			lvc.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH  | LVCF_FMT;
			lvc.fmt  = LVCFMT_LEFT;
			SendMessage(list,LVM_SETEXTENDEDLISTVIEWSTYLE,0,LVS_EX_FULLROWSELECT); 
			/* Add four columns to the list-view (first column contains check box). */
			
 
			//lvc.iSubItem = 0;
			lvc.cx       = 270;
			lvc.pszText  = TEXT("Course");
			//ListView_InsertColumn(list, 0, &lvc);
			SendMessage(list,LVM_INSERTCOLUMN,0,(LPARAM)&lvc);
 
			//lvc.iSubItem = 1;
			lvc.cx       = 60;
			lvc.pszText  = TEXT("Credit");
			//ListView_InsertColumn(list, 1, &lvc);
			SendMessage(list,LVM_INSERTCOLUMN,1,(LPARAM)&lvc);

			//lvc.iSubItem = 2;
			lvc.cx       = 60;
			lvc.pszText  = TEXT("Grade");
			//ListView_InsertColumn(list, 2, &lvc);
            SendMessage(list,LVM_INSERTCOLUMN,2,(LPARAM)&lvc);

			
			//Creation Texts
			text1=CreateWindowEx(  NULL,"Static","Toplam Ders Sayýsý :", WS_CHILD | WS_VISIBLE, 420, 250, 170,30, hwnd,(HMENU)IDC_TEXT1,GetModuleHandle(NULL), NULL);
			if(text1 == NULL){
				MessageBox(NULL, "Text1 Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
			text1a=CreateWindowEx(  NULL,"Static","0", WS_CHILD | WS_VISIBLE, 590, 250, 30,30, hwnd,(HMENU)IDC_TEXT1A,GetModuleHandle(NULL), NULL);
			if(text1a == NULL){
				MessageBox(NULL, "Text1a Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
			text2=CreateWindowEx(  NULL,"Static","CGPA :", WS_CHILD | WS_VISIBLE, 420, 280, 170,30, hwnd,(HMENU)IDC_TEXT2,GetModuleHandle(NULL), NULL);
			if(text2 == NULL){
				MessageBox(NULL, "Text2 Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
			text2a=CreateWindowEx(  NULL,"Static","NAN", WS_CHILD | WS_VISIBLE, 590,280, 29 , 30, hwnd,(HMENU)IDC_TEXT2A,GetModuleHandle(NULL), NULL);
			if(text2a == NULL){
				MessageBox(NULL, "Text2a Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
			
			//BUTTONS
			add=CreateWindowEx(  NULL,"BUTTON","ADD", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 420, 20, 170,30, hwnd,(HMENU)IDC_BUTTON_ADD,GetModuleHandle(NULL), NULL);
			if(add == NULL){
				MessageBox(NULL, "Button Add Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
			update=CreateWindowEx(  NULL,"BUTTON","UPDATE", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 420, 50, 170,30, hwnd,(HMENU)IDC_BUTTON_UPDATE,GetModuleHandle(NULL), NULL);
			if(update == NULL){
				MessageBox(NULL, "Button Update Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
			remove=CreateWindowEx(  NULL,"BUTTON","REMOVE", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 420, 80, 170,30, hwnd,(HMENU)IDC_BUTTON_REMOVE,GetModuleHandle(NULL), NULL);
			if(remove == NULL){
				MessageBox(NULL, "Button Remove Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
			removeall=CreateWindowEx(  NULL,"BUTTON","REMOVE ALL", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 420, 110, 170,30, hwnd,(HMENU)IDC_BUTTON_REMOVE_ALL,GetModuleHandle(NULL), NULL);
			if(removeall == NULL){
				MessageBox(NULL, "Button Remove Olusumunda Hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
				return 0;
			}
		}
		break;


		case WM_COMMAND://Command State
			switch(LOWORD(wParam)){
				case ID_FILE_NEWX:{
					
					ListView_DeleteAllItems(GetDlgItem(hwnd,IDC_LISTBOX));
					SendMessage(GetDlgItem(hwnd,IDC_TEXT1A),WM_SETTEXT,NULL,(LPARAM)"0");
					SendMessage(GetDlgItem(hwnd,IDC_TEXT2A),WM_SETTEXT,NULL,(LPARAM)"NAN");
				}
					break;
				case ID_FILE_OPENX:{
					
					DoFileOpen(GetDlgItem(hwnd,IDC_LISTBOX),hwnd);
					char strcount[5];
					sprintf(strcount, "%d",SendMessage(GetDlgItem(hwnd,IDC_LISTBOX),LVM_GETITEMCOUNT,0,0));
					SendMessage(GetDlgItem(hwnd,IDC_TEXT1A),WM_SETTEXT,NULL,(LPARAM)strcount);
					char* gpastr=gpacalculator(GetDlgItem(hwnd,IDC_LISTBOX));
					SendMessage(GetDlgItem(hwnd,IDC_TEXT2A),WM_SETTEXT,NULL,(LPARAM)gpastr);
				
				}
					break;
				case ID_FILE_SAVEAS:{
					DoFileSave(GetDlgItem(hwnd,IDC_LISTBOX),hwnd);
				}
					break;
				case ID_FILE_EXIT:{
					PostMessage(hwnd, WM_CLOSE, 0, 0);
				}
					break;
				case ID_HELP_ABOUT:
				{
					int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
					if(ret == IDOK){
						//MessageBox(hwnd, "Dialog exited with IDOK.", "Notice",MB_OK | MB_ICONINFORMATION);
					}
					else if(ret == -1){
						//MessageBox(hwnd, "Dialog failed!", "Error",MB_OK | MB_ICONINFORMATION);
					}
				}
					break;
				case IDC_BUTTON_ADD:{
									//ADD
					DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ADD), hwnd, AddDlgProc);
					if(work){
						add(GetDlgItem(hwnd,IDC_LISTBOX));
						char strcount[5];
						sprintf(strcount, "%d",SendMessage(GetDlgItem(hwnd,IDC_LISTBOX),LVM_GETITEMCOUNT,0,0));
						SendMessage(GetDlgItem(hwnd,IDC_TEXT1A),WM_SETTEXT,NULL,(LPARAM)strcount);
						char* gpastr=gpacalculator(GetDlgItem(hwnd,IDC_LISTBOX));
						SendMessage(GetDlgItem(hwnd,IDC_TEXT2A),WM_SETTEXT,NULL,(LPARAM)gpastr);
						work=false;
					}
				}
					break;
				case IDC_BUTTON_UPDATE:{
									//Update
					if(gstr1[0]!=' '){
						for(int i=0;i<25;i++){
							gstr1[i]=' ';
						}
					}
					gcombo1=-1;
					gcombo2=-2;
					detect(GetDlgItem(hwnd,IDC_LISTBOX));
					DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_UPDATE), hwnd, UpdateDlgProc);
					update(GetDlgItem(hwnd,IDC_LISTBOX));
					char* gpastr=gpacalculator(GetDlgItem(hwnd,IDC_LISTBOX));
					SendMessage(GetDlgItem(hwnd,IDC_TEXT2A),WM_SETTEXT,NULL,(LPARAM)gpastr);
					work=false;
				}
					break;
				case IDC_BUTTON_REMOVE:{
					remove(GetDlgItem(hwnd,IDC_LISTBOX));
					char strcount[5];
					sprintf(strcount, "%d",SendMessage(GetDlgItem(hwnd,IDC_LISTBOX),LVM_GETITEMCOUNT,0,0));
					SendMessage(GetDlgItem(hwnd,IDC_TEXT1A),WM_SETTEXT,NULL,(LPARAM)strcount);
					char* gpastr=gpacalculator(GetDlgItem(hwnd,IDC_LISTBOX));
					SendMessage(GetDlgItem(hwnd,IDC_TEXT2A),WM_SETTEXT,NULL,(LPARAM)gpastr);
				}

					break;
				case IDC_BUTTON_REMOVE_ALL:{
					ListView_DeleteAllItems(GetDlgItem(hwnd,IDC_LISTBOX));
					SendMessage(GetDlgItem(hwnd,IDC_TEXT1A),WM_SETTEXT,NULL,(LPARAM)"0");
					SendMessage(GetDlgItem(hwnd,IDC_TEXT2A),WM_SETTEXT,NULL,(LPARAM)"NAN");
				}

					break;
		}
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}