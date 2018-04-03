#ifndef DirectoryListH
#define DirectoryListH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.FileCtrl.hpp>
//---------------------------------------------------------------------------
class TDirList : public TForm
{
__published:	// IDE-managed Components
	TDirectoryListBox *DirectoryListBox1;
	TButton *BAceptar;
	TDriveComboBox *DriveComboBox1;
	TLabel *Label1;
	void __fastcall BAceptarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDirList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDirList *DirList;
//---------------------------------------------------------------------------
#endif
