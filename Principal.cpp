#include <vcl.h>
#include "DirectoryList.h"
#pragma hdrstop
#include "Principal.h"
#include "LibTextos.h"
#pragma package(smart_init)
#pragma link "ShortCuts"
#pragma resource "*.dfm"
#define NAME "MaxCenso"
#define VERSION " v.6.1.5"
#define pRuta "C:\\Archivos de programa\\"
#define sRuta "C:\\Program Files\\"
#define bRuta "D:\\MaxCenso\\"
TfPrincipal *fPrincipal;
//---------------------------------------------------------------------------
__fastcall TfPrincipal::TfPrincipal(TComponent* Owner)
	: TForm(Owner)
{
	fName = NAME;
	fVersion = VERSION;
	fFullName = fName + fVersion;
	fRuta = sRuta;
	pSeg = sSeg = tSeg = cSeg = fFin = fServer = false;
	ptBoton = 1;
	i = fSizex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfPrincipal::FormCreate(TObject *Sender)
{
	Caption = Texto(125) + fFullName;
	Label2->Caption = Texto(126) + fFullName + "\n\n\n\n" + Texto(142);
	BAtras->Enabled = false;
	Label16->Caption = Texto(124) + fFullName;
/*	AnsiString ffName = Application->ExeName;
	AnsiString ffPath = ExtractFilePath(ffName);
*/}
//---------------------------------------------------------------------------
void __fastcall TfPrincipal::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfPrincipal::BCancelaClick(TObject *Sender)
{
	if (Sender == BCancela || Sender == RadioButton2)
	{
		if (Sender == BCancela && fFin)
		{
			SaveFile();
			if (CheckBox1->Checked)
				AccesDir->AddShortcut(kRuta + "\\" + fName + Texto(100), fFullName, Texto(137));
			if (CheckBox2->Checked){
				AnsiString x, HightPath;
				HightPath = kRuta + "\\" + fName + Texto(100);
				ShellExecuteA(0, static_cast<const char*>(x.data()), HightPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
			}
		}
		Application->Terminate();
	}

	if (Sender == BSiga)
	{
		ptBoton ++;
		AdvanBotton();
		if (BSiga->Caption == Texto(104))
			Application->Terminate();
	}

	if (Sender == BAtras)
	{
		ptBoton --;
		RetroBotton();
	}

	if (Sender == BInstall)
	{
		try{
			BInstall->Visible = false;
			Directorios(fServer);
			if (BInstall->Caption == Texto(105))
				Copiar(fServer);
			fFin = true;
			if (BInstall->Caption == Texto(106)){
				ptBoton ++;
				AdvanBotton();
				BInstall->Visible = false;
			}
		}
		catch (...){
			ShowMessage(Texto(140));
			BCancela->Enabled = true;
		}
	}

	if (Sender == RadioButton1)
	{
		BSiga->Enabled = true;
		BSiga->SetFocus();
	}

	if (Sender == RadioButton3)
	{
		if (!fServer)
			fServer = true;
		PServer->Visible = true;
		InfProd();
	}

	if (Sender == RadioButton4)
	{
		if (fServer)
			fServer = false;
		PServer->Visible = true;
		InfProd();
	}
}
//---------------------------------------------------------------------------
void __fastcall TfPrincipal::Timer1Timer(TObject *Sender)
{
	if (Sender == Timer1) {
		ProgressBar1->StepIt();
		if (ProgressBar1->Position == ProgressBar1->Max){
			Timer1->Enabled = false;
			Timer2->Enabled = false;
			BInstall->Visible = true;
			BInstall->SetFocus();
			BInstall->Caption = Texto(106);
		}
	}

	if (Sender == Timer1) {
		Label13->Caption = Label13->Caption + " .";
		i++;
		if (i == 5){
			i = 0;
			Label13->Caption = Texto(130);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfPrincipal::Edit6KeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN)
		keybd_event(VK_TAB, 0, 0, 0);
}
//---------------------------------------------------------------------------
void TfPrincipal::AdvanBotton()
{
	if (ptBoton == 1)
	{
		VerPanel(PanTwo, PanOne);
		if (BAtras->Enabled)
			BAtras->Enabled = false;
		BSiga->Caption =  Texto(106);
	}
	if (ptBoton == 2)
	{
		VerPanel(PanOne, PanTwo);
		RadioButton1->Checked = false;
		BAtras->Enabled = true;
		BSiga->Enabled = false;
		Label16->Caption = Texto(136);
		Label3->Caption = Texto(143);
		Label16->Caption = Texto(134);
		AnsiString Lemae = ExtractFilePath(Application->ExeName) + fFullName + Texto(101);
		Memo1->Lines->LoadFromFile(ExtractFilePath(Application->ExeName) + fFullName + Texto(101));
		ListFiles(ExtractFilePath(Application->ExeName), Memo2, 'l');
		Label20->Caption = (Memo2->Lines->Count - 3) * 100;
	}
	if (ptBoton == 3)
	{
		VerPanel(PanTwo, PanTre);
		BSiga->Enabled = false;
		Label16->Caption = Texto(135);
	}
	if (ptBoton == 4)
	{
		VerPanel(PanTre, PanFou);
		Label16->Caption = Texto(133);
		EInstall->Text = pRuta;
		EBackups->Text = bRuta;
		ECertif->Text = bRuta;
		EOficios->Text = bRuta;
		EReport->Text = bRuta;
	}
	if (ptBoton == 5)
	{
		VerPanel(PanFou, PanFiv);
		BAtras->Visible = false;
		BSiga->Visible = false;
		BInstall->Visible = true;
		BInstall->SetFocus();
		BCancela->Enabled = false;
		Label16->Caption =  Texto(107) + fFullName + "...";
	}
	if (ptBoton == 6)
	{
		VerPanel(PanFiv, PanSix);
		BCancela->Enabled = true;
		BCancela->SetFocus();
		BCancela->Caption = Texto(108);
		Label15->Caption = Texto(131) + fFullName;
		CheckBox2->Caption = Texto(103) + fFullName;
		Label16->Caption = Texto(132);
	}
}
//---------------------------------------------------------------------------
void TfPrincipal::RetroBotton()
{
	if (ptBoton == 4)
	{
		VerPanel(PanFiv, PanFou);
	}
	if (ptBoton == 3)
	{
		VerPanel(PanFou, PanTre);
		BSiga->Enabled = false;
		Edit1->Text = "";
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
		Edit5->Text = "";
		Label16->Caption = Texto(135);
	}
	if (ptBoton == 2)
	{
		VerPanel(PanTre, PanTwo);
		BSiga->Enabled = false;
		RadioButton1->Checked = false;
		if (RadioButton3->Checked)
			RadioButton3->Checked = false;
		if (RadioButton4->Checked)
			RadioButton4->Checked = false;
		PServer->Visible = false;
		Label16->Caption =  Texto(134);
	}
	if (ptBoton == 1)
	{
		VerPanel(PanTwo, PanOne);
		BAtras->Enabled = false;
		BSiga->Enabled = true;
		Label16->Caption = Texto(124) + fFullName;
	}
}
//---------------------------------------------------------------------------
void TfPrincipal::BuscarDir()
{
	DirList = new TDirList(Application);
	DirList->ShowModal();
	delete DirList;
	DirList = NULL;
 }
//---------------------------------------------------------------------------
void TfPrincipal::VerPanel(TPanel *pPanel, TPanel *sPanel)
{
	pPanel->Visible = false;
	sPanel->Visible = true;
}
//---------------------------------------------------------------------------
void TfPrincipal::Errors(AnsiString fMsg, TEdit *fVacio, TEdit *fFoco)
{
	if(fVacio->Text != "")
	{
		MessageDlg(fMsg, mtError, TMsgDlgButtons() << mbOK, 0);
		fVacio->Text = "";
		fFoco->SetFocus();
	}
}
//---------------------------------------------------------------------------
void TfPrincipal::Directorios(bool fServ)
{
	if (fServ) //Servidor
	{
		MkDir(pRuta, EInstall->Text, fName, fRuta, 0);
		MkDir(bRuta, EBackups->Text, Texto(115), fRuta, 1);
		MkDir(bRuta, ECertif->Text, Texto(127), fRuta, 1);
		MkDir(bRuta, EOficios->Text, Texto(117), fRuta, 1);
		MkDir(bRuta, EReport->Text, Texto(119), fRuta, 1);
	}
	else  //Terminal
		MkDir(pRuta, EInstall->Text, fName, fRuta, 0);
}
//---------------------------------------------------------------------------
void TfPrincipal::MkDir(AnsiString fPRuta, AnsiString fSRuta,
									AnsiString fMRuta, AnsiString fWRuta, int fFx)
{
	if (fSRuta == fPRuta) {
		if (fFx == 0)
		{
			if (DirectoryExists(fSRuta + "\\"))
			{
				if (!DirectoryExists(fSRuta + "\\" + fMRuta + "\\"))
					CreateDir(fSRuta + "\\" +  fMRuta + "\\");
			}
			else
				CreateDir(fWRuta + "\\" +  fMRuta + "\\");
			if (fFx == 0)
				kRuta = fWRuta +  fMRuta;
		}
		else
		{
			if (DirectoryExists(fSRuta + "\\"))
			{
				if (!DirectoryExists(fSRuta + "\\" + fMRuta + "\\"))
					CreateDir(fSRuta + "\\" +  fMRuta + "\\");
			}
			else
			{
				CreateDir(fSRuta + "\\");
				CreateDir(fSRuta + "\\" +  fMRuta + "\\");
			}
			if (fFx == 0)
				kRuta = fSRuta +  fMRuta;
		}
	}
	else
	{
		if (DirectoryExists(fSRuta + "\\"))
		{
			if (!DirectoryExists(fSRuta + "\\" + fMRuta + "\\"))
				CreateDir(fSRuta + "\\" +  fMRuta + "\\");
		}
		else
		{
			CreateDir(fSRuta + "\\");
			CreateDir(fSRuta + "\\" +  fMRuta + "\\");
		}
		if (fFx == 0)
			kRuta = fSRuta +  fMRuta;
	}
}
//---------------------------------------------------------------------------*/
void TfPrincipal::Copiar(bool fServ)
{
	ProgressBar1->Min = 0;
	ProgressBar1->Position = 0;
	ProgressBar1->Max = StrToInt(Label20->Caption);
	Timer1->Enabled = true;
	Timer1->Interval = 50;
	Timer2->Enabled = true;
	if (fServ) //Servidor
	{
		UnicodeString fFileCopy = ExtractFilePath(Application->ExeName) + "*.*";
		CopyDir(fFileCopy, kRuta + "\\");
	}
	else  //Terminal
	{

	}
}
//---------------------------------------------------------------------------
void TfPrincipal::ListFiles(AnsiString Dir, TMemo *Memo, char fInd)
{
	TSearchRec sr;
	if (FindFirst("*.*", faDirectory, sr) == 0){
		do{
			if(((sr.Attr & faDirectory) > 0) & (sr.Name != ".") & (sr.Name != "..")){
				ListDir(Dir + "\\" + sr.Name, Memo);
				if (fInd == 'c')
				{}
				else
					Memo->Lines->Insert(0, "\\" + sr.Name);
			}
			else
				if (fInd == 'c')
				{}
				else
					Memo->Lines->Add(sr.Name);
		}
		while (FindNext(sr) == 0);
		FindClose(sr);
	}
}
//---------------------------------------------------------------------------
void TfPrincipal::ListDir(String Dir, TMemo *Memo)
{
	TSearchRec sr;
	if(FindFirst(Dir + "*.*", faAnyFile, sr) == 0){
		do{
			if(((sr.Attr & faDirectory) > 0) & (sr.Name != ".") & (sr.Name != ".."))
				Memo->Lines->Add(sr.Name);
		}
		while(FindNext(sr) == 0);
		FindClose(sr);
	}
}
//---------------------------------------------------------------------------
void TfPrincipal::CopyDir(String Origen, String Destino)
{
	SHFILEOPSTRUCT sfos = {0,};
	ZeroMemory(&sfos, sizeof(sfos));
//	sfos.hwnd = NULL;
	sfos.wFunc = FO_COPY;  //FO_COPY, FO_DELETE,  FO_MOVE,  FO_RENAME.
	// Añadimos estas dos líneas
	Origen.SetLength(Origen.Length() + 1);
	Origen[Origen.Length()] = '\0';
	sfos.pFrom = Origen.c_str();
	sfos.pTo = Destino.c_str();
//	sfos.fFlags = FOF_NOCONFIRMMKDIR | FOF_NOCONFIRMATION;
	SHFileOperation(&sfos);
}
//---------------------------------------------------------------------------
AnsiString TfPrincipal::FileSize(AnsiString fFich)
{
	//Creación de un tipo de datos donde se contendrán los atributos de un fichero
	WIN32_FIND_DATA* dat = new WIN32_FIND_DATA();
	//Busco el fichero en concreto.
	HANDLE buscar = FindFirstFile(WideString(fFich).c_bstr(), dat);
	//Si existe el fichero.
	if (buscar != INVALID_HANDLE_VALUE)
		fDato = dat->nFileSizeLow;
	else
		fDato = 0;
	return FloatToStr(fDato);
}
//---------------------------------------------------------------------------
//CopyFile("C:\\archivo.fec", "D:\\archivo.fec", false);
//CopyFile(Pchar(origen), Pchar(destino), false);
//---------------------------------------------------------------------------
void TfPrincipal::SaveFile()
{
	Memo2->Lines->Clear();
	if (fServer)
		Memo2->Lines->Add(Texto(109) + NombrePC());
	else
		Memo2->Lines->Add(Texto(109) + Edit2->Text);
	Memo2->Lines->Add(Texto(110) + Edit6->Text);
	Memo2->Lines->Add(Texto(111) + Edit5->Text);
	Memo2->Lines->Add(Texto(112) + Edit1->Text);
	Memo2->Lines->Add(Texto(113) + kRuta);
	Memo2->Lines->Add(Texto(114) + EBackups->Text + Texto(115));
	Memo2->Lines->Add(Texto(123) + ECertif->Text + Texto(127));
	Memo2->Lines->Add(Texto(116) + EOficios->Text + Texto(117));
	Memo2->Lines->Add(Texto(118) + EReport->Text + Texto(119));
	Memo2->Lines->Add(Texto(120) + fName);
	Memo2->Lines->Add(Texto(121) + fVersion);
	Memo2->Lines->Add(Texto(122));
	pfArch = kRuta + "\\" + fName + Texto(102);
	Memo2->Lines->SaveToFile(pfArch);
}
//---------------------------------------------------------------------------
AnsiString TfPrincipal::NombrePC()
{
	AnsiString fNombrePC;
	DWORD dwSize = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t szBuf[MAX_COMPUTERNAME_LENGTH + 1];
	szBuf[0] = '\0';
	GetComputerName(szBuf, &dwSize);
	fNombrePC = szBuf;
	return fNombrePC;
}
// ---------------------------------------------------------------------------
void TfPrincipal::InfProd()
{
	if (fServer)
		Cambio(true);
	else
		Cambio(false);
}
// ---------------------------------------------------------------------------
void __fastcall TfPrincipal::Edit4Change(TObject *Sender)
{
	if (Sender == Edit2)
	{
		if (Edit2->Text.Length() == 3)
			Edit3->SetFocus();
	}

	if (Sender == Edit3)
	{
		if (Edit3->Text.Length() == 11)
			Edit4->SetFocus();
	}

	if (Sender == Edit4)
	{
		if (Edit1->Text != "")
		{
			if (Edit2->Text != "" && Edit3->Text != "")
			{
				if (Edit2->Text == Label17->Caption.SubString(4,3))
					pSeg = true;
				if (Edit3->Text.SubString(7,5) == Label17->Caption.SubString(7,5))
					sSeg = true;
				if (Edit3->Text.SubString(1,6) == Label17->Caption.SubString(12,6))
					tSeg = true;
				if (Edit4->Text.Length() == 3)
				{
					if (Edit4->Text == Label17->Caption.SubString(1,3))
						cSeg = true;
					if (pSeg && sSeg && tSeg && cSeg)
					{
						BSiga->Enabled = true;
						BSiga->SetFocus();
					}
					else
					{
						Errors(Texto(138), Edit4, Edit2);
						cSeg = false;
					}
				}
			}
			else
				Errors(Texto(139), Edit4, Edit2);
		}
		else
			Errors(Texto(141), Edit4, Edit1);
	}
}
//---------------------------------------------------------------------------
void TfPrincipal::Cambio(bool fFlag)
{
	if (fFlag) {
		Label4->Caption = Texto(144);
		Label5->Caption = Texto(128);
		Label6->Visible = true;
		Edit2->Visible = true;
		Edit3->Visible = true;
		Edit4->Visible = true;
	}
	else {
		Label4->Caption = Texto(145);
		Label5->Caption = Texto(129);
		Label6->Visible = false;
		Edit2->Visible = false;
		Edit3->Visible = false;
		Edit4->Visible = false;
	}
}
//---------------------------------------------------------------------------

