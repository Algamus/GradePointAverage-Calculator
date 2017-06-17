

void add(HWND hwnd){//Add Button ile calýsan fonksiyon
	
	LVITEM   lv ={ 0 };
	lv.mask=LVIF_TEXT;  
	lv.cchTextMax = 256;
	lv.iItem=SendMessage(hwnd,LVM_GETITEMCOUNT,0,0);
	
	ListView_InsertItem(hwnd, &lv);
	ListView_SetItemText(hwnd, 0, 0, TEXT(gstr1));
    ListView_SetItemText(hwnd, 0, 1, TEXT(creditstr(gcombo1)));
    ListView_SetItemText(hwnd, 0, 2, TEXT(gradestr(gcombo2)));
	
}
void detect(HWND hwnd){
	int ctr=ListView_GetSelectionMark(hwnd);
	int ctrcount=SendMessage(hwnd,LVM_GETITEMCOUNT,0,0);
	if(!(ctrcount<=ctr) && ctr>=0 ){ 
		//update
		gcombo1=-1;
		gcombo2=-1;
		ListView_GetItemText(hwnd,ctr,0,(LPTSTR)gstr1,26);
		ListView_GetItemText(hwnd,ctr,1,(LPTSTR)t1,2);
		if(t1[0]=='4'){
				gcombo1=0;
			}else if(t1[0]=='3'){
				gcombo1=1;
			}else if(t1[0]=='2'){
				gcombo1=2;
			}else{
				//send errror
				MessageBox(NULL, "get credits hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
			}
			ListView_GetItemText(hwnd,ctr,2,(LPTSTR)t1,3);
			if(t1[0]=='A'){
				gcombo2=0;
			}else if(t1[0]=='B' && t1[1]=='A'){
				gcombo2=1;
			}else if(t1[0]=='B' && t1[1]=='B'){
				gcombo2=2;
			}else if(t1[0]=='C' && t1[1]=='B'){
				gcombo2=3;
			}else if(t1[0]=='C' && t1[1]=='C'){
				gcombo2=4;
			}else if(t1[0]=='D' && t1[1]=='C'){
				gcombo2=5;
			}else if(t1[0]=='D' && t1[1]=='D'){
				gcombo2=6;
			}else if(t1[0]=='F'){
				gcombo2=7;
			}else{
				//send error
				MessageBox(NULL, "grades hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
			}
		test=ctr;
		ListView_SetSelectionMark(hwnd,-1);
	}else{

	}
}
void update(HWND hwnd){
	ListView_SetItemText(hwnd, test, 0, TEXT(gstr1));
    ListView_SetItemText(hwnd, test, 1, TEXT(creditstr(gcombo1)));
    ListView_SetItemText(hwnd, test, 2, TEXT(gradestr(gcombo2)));

}
void remove(HWND hwnd){


	int ctr=ListView_GetSelectionMark(hwnd);
	int ctrcount=SendMessage(hwnd,LVM_GETITEMCOUNT,0,0);
	if(!(ctrcount<=ctr) && ctr>=0 ){ 
		ListView_DeleteItem(hwnd,ctr);
		ListView_SetSelectionMark(hwnd,-1);
	}
	
}
char* creditstr(int t){
	if(t==0){
		return "4";
	}else if(t==1){
		return "3";
	}else if(t==2){
		return "2";
	}else{
		return NULL;
	}
}
char* gradestr(int t){
	if(t==0){
		return "AA";
	}else if(t==1){
		return "BA";
	}else if(t==2){
		return "BB";
	}else if(t==3){
		return "CB";
	}else if(t==4){
		return "CC";
	}else if(t==5){
		return "DC";
	}else if(t==6){
		return "DD";
	}else if(t==7){
		return "FF";
	}else{
		return NULL;
	}
}
char* gpacalculator(HWND hwnd){
	int listcount=SendMessage(hwnd,LVM_GETITEMCOUNT,0,0);
	if(listcount!=0){
		float gpa=0,credits=0,grades=0,totalcredits=0;

		for(int i=0;i<listcount;i++){
			t1[0]=NULL;
			t1[1]=NULL;
			ListView_GetItemText(hwnd,i,1,(LPTSTR)t1,2);
			
			if(t1[0]=='4'){
				credits=4.0;
			}else if(t1[0]=='3'){
				credits=3.0;
			}else if(t1[0]=='2'){
				credits=2.0;
			}else{
				//send errror
				MessageBox(NULL, "credits hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
			}
			ListView_GetItemText(hwnd,i,2,(LPTSTR)t1,3);
			if(t1[0]=='A'){
				grades=4.0;
			}else if(t1[0]=='B' && t1[1]=='A'){
				grades=3.5;
			}else if(t1[0]=='B' && t1[1]=='B'){
				grades=3.0;
			}else if(t1[0]=='C' && t1[1]=='B'){
				grades=2.5;
			}else if(t1[0]=='C' && t1[1]=='C'){
				grades=2.0;
			}else if(t1[0]=='D' && t1[1]=='C'){
				grades=1.5;
			}else if(t1[0]=='D' && t1[1]=='D'){
				grades=1.0;
			}else if(t1[0]=='F'){
				grades=0.0;
			}else{
				//send error
				MessageBox(NULL, "grades hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
			}

			totalcredits+=credits;
			gpa=gpa+(grades*credits);

		}
		gpa=gpa/totalcredits;
		sprintf(ggpa, "%f2.2",gpa);
		t1[0]=NULL;
		t1[1]=NULL;
		return ggpa;
	}else{
		return "NAN";
	}
}
BOOL checksaf(FILE *file){//SAF controlu
	char saf[]={'G','G','P','A'},x;
	int t=0,i;
	for(i=0;i<4;i++){
		fread(&x,sizeof(char),1,file);
		if(x==saf[i]){
			t++;
		}
	}
	if(t!=4){
		MessageBox(NULL, "ERROR:This type is not .ggpa", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}
	return TRUE;
}
BOOL LoadTextFileToEdit(HWND hwnd, LPCTSTR pszFileName)
{
	ListView_DeleteAllItems(hwnd);
	FILE *dosya;
	int olan,i;
	if((dosya=fopen(pszFileName,"rb"))==NULL){
		MessageBox(NULL, "diye bir dosya yok! ", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}
	if(!checksaf(dosya)){//SAF controlu
		fclose(dosya);
		return FALSE;
	}
	fread(&olan,sizeof(int),1,dosya);
	for(i=0;i<olan;i++){
		fread(gstr1,sizeof(char),25,dosya);
		fread(&gcombo1,sizeof(int),1,dosya);
		fread(&gcombo2,sizeof(int),1,dosya);
		add(hwnd);
	}
	fclose(dosya);
	return TRUE;
}
BOOL SaveTextFileFromEdit(HWND hwnd, LPCTSTR pszFileName)
{
	
	FILE *dosya;
	char saf[]={'G','G','P','A'};
	int k,okuncak=0;
	if((dosya=fopen(pszFileName,"wb"))==NULL){
		MessageBox(NULL, "dosya olusumunda hata", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}
	okuncak=SendMessage(hwnd,LVM_GETITEMCOUNT,0,0);
	fwrite(saf,sizeof(char),4,dosya);
	fwrite(&okuncak,sizeof(int),1,dosya);
	for(k=0;k<okuncak;k++){
		ListView_GetItemText(hwnd,k,0,(LPTSTR)gstr1,26);
		fwrite(gstr1,sizeof(char),25,dosya);
		ListView_GetItemText(hwnd,k,1,(LPTSTR)t1,2);
		if(t1[0]=='4'){
			gcombo1=0;
		}else if(t1[0]=='3'){
			gcombo1=1;
		}else if(t1[0]=='2'){
			gcombo1=2;
		}else{
			//send errror
			MessageBox(NULL, "get credits hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		}
		fwrite(&gcombo1,sizeof(int),1,dosya);
		ListView_GetItemText(hwnd,k,2,(LPTSTR)t1,3);
		if(t1[0]=='A'){
			gcombo2=0;
		}else if(t1[0]=='B' && t1[1]=='A'){
			gcombo2=1;
		}else if(t1[0]=='B' && t1[1]=='B'){
			gcombo2=2;
		}else if(t1[0]=='C' && t1[1]=='B'){
			gcombo2=3;
		}else if(t1[0]=='C' && t1[1]=='C'){
			gcombo2=4;
		}else if(t1[0]=='D' && t1[1]=='C'){
				gcombo2=5;
		}else if(t1[0]=='D' && t1[1]=='D'){
			gcombo2=6;
		}else if(t1[0]=='F'){
			gcombo2=7;
		}else{
			//send error
			MessageBox(NULL, "grades hata!", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		}
		fwrite(&gcombo2,sizeof(int),1,dosya);
		
	}
	//gpa eklenicek
	fclose(dosya);
	
	return TRUE;
}
void DoFileOpen(HWND hwnd,HWND main)
{
	
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = main;
	ofn.lpstrFilter = "Ggpa Files (*.Ggpa)\0*.Ggpa\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER  | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "Ggpa";

	if(GetOpenFileName(&ofn)){
		
		if(LoadTextFileToEdit(hwnd, szFileName)){

		}else{
			MessageBox(NULL, "Error on load", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		}
	}else{
		MessageBox(NULL, "Error", "Hata!",MB_ICONEXCLAMATION | MB_OK);
	}
}
void DoFileSave(HWND hwnd,HWND main)
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = main;
	ofn.lpstrFilter = "Ggpa Files (*.Ggpa)\0*.Ggpa\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrDefExt = "Ggpa";
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;

	if(GetSaveFileName(&ofn))
	{
	
		if(SaveTextFileFromEdit(hwnd, szFileName)){

		}else{
			MessageBox(NULL, "Error on save", "Hata!",MB_ICONEXCLAMATION | MB_OK);
		}
	}
}