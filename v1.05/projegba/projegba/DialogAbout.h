BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)//dialog üzerindeki buttonu dinliyor
{
	switch(Message)
	{
		case WM_INITDIALOG:

		return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDOK:
					EndDialog(hwnd, IDOK);
					break;
			}
		break;
		case WM_CLOSE:
			EndDialog(hwnd, IDOK);
			break;
		default:
			return FALSE;
	}
	return TRUE;
}
BOOL CALLBACK AddDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)//add dialog üzerindeki buttonu dinliyor
{
	
	switch(Message)
	{
		case WM_INITDIALOG:

			SendDlgItemMessage(hwnd, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"4");
			SendDlgItemMessage(hwnd, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"3");
			SendDlgItemMessage(hwnd, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"2");


			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"AA");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"BA");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"BB");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"CB");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"CC");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"DC");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"DD");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"FF");

			
		return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDOK:
					GetWindowText(GetDlgItem(hwnd,IDC_ADD_TEXT1), gstr1, 25);
					
					gcombo1= SendMessage(GetDlgItem(hwnd,IDC_COMBO1), CB_GETCURSEL, 0, 0);
					gcombo2= SendMessage(GetDlgItem(hwnd,IDC_COMBO2), CB_GETCURSEL, 0, 0);
					if(gstr1=="" || gcombo1==-1 || gcombo2==-1){
						work=false;
						
						if(gstr1[0]==NULL && gcombo1==-1 && gcombo2==-1){
							MessageBox(NULL, "Enter A Course Name\nSelect Credits\nSelect Grades", "Hata!",MB_ICONEXCLAMATION | MB_OK);
						}else{
							if(gcombo1==-1 && gcombo2==-1){
								MessageBox(NULL, "Select Credits\nSelect Grades", "Hata!",MB_ICONEXCLAMATION | MB_OK);
							}else if(gstr1=="" && gcombo1==-1){
								MessageBox(NULL, "Enter A Course Name\nSelect Credits", "Hata!",MB_ICONEXCLAMATION | MB_OK);
							}else if(gstr1=="" && gcombo2==-1){
								MessageBox(NULL, "Enter A Course Name\nSelect Grades", "Hata!",MB_ICONEXCLAMATION | MB_OK);
							}else{
								if(gstr1==""){
									MessageBox(NULL, "Enter A Course Name", "Hata!",MB_ICONEXCLAMATION | MB_OK);
								}else if(gcombo1==-1){
									MessageBox(NULL, "Select Credits", "Hata!",MB_ICONEXCLAMATION | MB_OK);
								}else if(gcombo2==-1){
									MessageBox(NULL, "Select Grades", "Hata!",MB_ICONEXCLAMATION | MB_OK);
								}else{
									//buraya girerse hata
									MessageBox(NULL, "error kýsmý bulunamadý!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
								}
							}
						}
					}else{			
						work=true;
						EndDialog(hwnd, IDOK);
					}
					break;
				case IDCANCEL:
					work=false;
					EndDialog(hwnd, IDCANCEL);
					break;
			}
		break;
		case WM_CLOSE:
			EndDialog(hwnd, IDCANCEL);
			break;
		default:
			return FALSE;
	}
	return TRUE;
}
BOOL CALLBACK UpdateDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)//dialog update
{
	switch(Message)
	{
		case WM_INITDIALOG:

			SendDlgItemMessage(hwnd, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"4");
			SendDlgItemMessage(hwnd, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"3");
			SendDlgItemMessage(hwnd, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"2");


			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"AA");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"BA");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"BB");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"CB");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"CC");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"DC");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"DD");
			SendDlgItemMessage(hwnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"FF");

			SetWindowText(GetDlgItem(hwnd,IDC_ADD_TEXT1), gstr1);
			SendMessage(GetDlgItem(hwnd,IDC_COMBO1), CB_SETCURSEL, gcombo1, (LPARAM)NULL);
			SendMessage(GetDlgItem(hwnd,IDC_COMBO2), CB_SETCURSEL, gcombo2, (LPARAM)NULL);

		return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDOK:
					GetWindowText(GetDlgItem(hwnd,IDC_ADD_TEXT1), gstr1, 25);
					
					gcombo1= SendMessage(GetDlgItem(hwnd,IDC_COMBO1), CB_GETCURSEL, 0, 0);
					gcombo2= SendMessage(GetDlgItem(hwnd,IDC_COMBO2), CB_GETCURSEL, 0, 0);

					if(gstr1==""){
						work=false;
						MessageBox(NULL, "Enter A Course Name", "Hata!",MB_ICONEXCLAMATION | MB_OK);
					}else{
						work=true;
						EndDialog(hwnd, IDOK);
					}
					break;
				case IDCANCEL:
					work=false;
					EndDialog(hwnd, IDCANCEL);
					break;
			}
		break;
		case WM_CLOSE:
			EndDialog(hwnd, IDCANCEL);
			break;
		default:
			return FALSE;
	}
	return TRUE;
}