#include <vcl.h>
#pragma hdrstop
#include "DirectoryList.h"
#include "Principal.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TDirList *DirList;
//---------------------------------------------------------------------------
__fastcall TDirList::TDirList(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDirList::BAceptarClick(TObject *Sender)
{
	switch (fPrincipal->fInd)
	{
		case '2' :
			fPrincipal->EBackups->Text = Label1->Caption;
			break;
		case '3' :
			fPrincipal->ECertif->Text = Label1->Caption;
			break;
		case '4' :
			fPrincipal->EOficios->Text = Label1->Caption;
			break;
		case '5' :
			fPrincipal->EReport->Text = Label1->Caption;
			break;
		default:
			fPrincipal->EInstall->Text = Label1->Caption;
	}
	Close();
	caFree;
}
//---------------------------------------------------------------------------

