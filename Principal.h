#ifndef PrincipalH
#define PrincipalH
#include "ShortCuts.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
//---------------------------------------------------------------------------
class TfPrincipal : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TImage *Image1;
	TLabel *Label16;
	TImage *Image2;
	TButton *BSiga;
	TButton *BAtras;
	TButton *BCancela;
	TButton *BInstall;
	TTimer *Timer1;
	TTimer *Timer2;
	TAccesDir *AccesDir;
	TPanel *Panel9;
	TLabel *Label1;
	TMemo *Memo2;
	TPanel *PanSix;
	TLabel *Label14;
	TLabel *Label15;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox1;
	TPanel *PanFiv;
	TLabel *Label20;
	TLabel *Label13;
	TProgressBar *ProgressBar1;
	TPanel *PanFou;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *EInstall;
	TEdit *EBackups;
	TEdit *ECertif;
	TEdit *EOficios;
	TEdit *EReport;
	TButton *DirInstall;
	TButton *DirBackups;
	TButton *DirCertif;
	TButton *DirOficios;
	TButton *DirReport;
	TPanel *PanTre;
	TLabel *Label18;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TPanel *PServer;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label19;
	TLabel *Label21;
	TLabel *Label4;
	TLabel *Label17;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TPanel *PanTwo;
	TLabel *Label3;
	TMemo *Memo1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TPanel *PanOne;
	TLabel *Label2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BCancelaClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Edit6KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit4Change(TObject *Sender);
private:	// User declarations

	AnsiString fFullName, fName, fVersion, fRuta, kRuta, pfArch;
	bool pSeg, sSeg, tSeg, cSeg, fFin, fServer;
	int ptBoton, i, fSizex;
	float fDato;

	AnsiString FileSize(AnsiString fFich);
	AnsiString NombrePC();
	void AdvanBotton();
	void RetroBotton();
	void VerPanel(TPanel *pPanel, TPanel *sPanel);
	void Errors(AnsiString fMsg, TEdit *fVacio, TEdit *fFoco);
	void Directorios(bool fServ);
	void BuscarDir();
	void MkDir(AnsiString fPRuta, AnsiString fSRuta,
												AnsiString fMRuta, AnsiString fWRuta, int fFx);
	void Copiar(bool fServ);
	void CopyDir(String Origen, String Destino);
	void ListFiles(AnsiString Dir, TMemo *Memo, char fInd);
	void ListDir(String Dir, TMemo *Memo);
	void SaveFile();
	void InfProd();
	void Cambio(bool fFlag);

public:		// User declarations
	__fastcall TfPrincipal(TComponent* Owner);
  int fInd;
};
//---------------------------------------------------------------------------
extern PACKAGE TfPrincipal *fPrincipal;
//---------------------------------------------------------------------------
#endif
