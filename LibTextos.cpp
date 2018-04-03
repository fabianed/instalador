#pragma hdrstop
#include "LibTextos.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
AnsiString Texto(AnsiString fInd)
{
	AnsiString fCad;
	if (fInd == 100)
		fCad = ".exe";
	if (fInd == 101)
		fCad = ".txt";
	if (fInd == 102)
		fCad = ".fecx";
	if (fInd == 103)
		fCad = "Iniciar ";
	if (fInd == 104)
		fCad = "Cancela&r";
	if (fInd == 105)
		fCad = "&Instalar";
	if (fInd == 106)
		fCad = "S&iguiente";
	if (fInd == 107)
		fCad = "Instalando ";
	if (fInd == 108)
		fCad = "&Terminar";
	if (fInd == 109)
		fCad = "Servidor: ";
	if (fInd == 110)
		fCad = "User: ";
	if (fInd == 111)
		fCad = "Password: ";
	if (fInd == 112)
		fCad = "Registro: ";
	if (fInd == 113)
		fCad = "RutaP: ";
	if (fInd == 114)
		fCad = "RutaB: ";
	if (fInd == 115)
		fCad = "\\Backups";
	if (fInd == 116)
		fCad = "RutaO: ";
	if (fInd == 117)
		fCad = "\\Oficios";
	if (fInd == 118)
		fCad = "RutaR: ";
	if (fInd == 119)
		fCad = "\\Reportes";
	if (fInd == 120)
		fCad = "Nombre: ";
	if (fInd == 121)
		fCad = "Version: ";
	if (fInd == 122)
		fCad = "Time: 0";
	if (fInd == 123)
		fCad = "RutaC: ";
	if (fInd == 124)
		fCad = "Instalacion de ";
	if (fInd == 125)
		fCad = "Instalador ";
	if (fInd == 126)
		fCad = "Bienvenido a ";
	if (fInd == 127)
		fCad = "\\Certificaciones";
	if (fInd == 128)
		fCad = "Propietario de la licencia:";
	if (fInd == 129)
		fCad = "Nombre del servidor:";
	if (fInd == 130)
		fCad = "Copiando archivos .";
	if (fInd == 131)
		fCad = "Gracias por utilizar ";
	if (fInd == 132)
		fCad = "Instalación Finalizada.";
	if (fInd == 133)
		fCad = 	"Destino de la instalación...";
	if (fInd == 134)
		fCad = 	"Licencia de Contrato Final...";
	if (fInd == 135)
		fCad = "Información y clave del producto...";
	if (fInd == 136)
		fCad = "Contrato del usuario final (CLU)...";
	if (fInd == 137)
		fCad = "Administrador de listados censales";
	if (fInd == 138)
		fCad = "Licencia incorrecta. Por favor corrija...";
	if (fInd == 139)
		fCad = "Licencia mal digitada. Por favor corrija...";
	if (fInd == 140)
		fCad = "Se ha presentado un error. La instalación ha fallado..";
	if (fInd == 141)
		fCad = "Por favor digite el nombre de la empresa propietaria de la licencia";
	if (fInd == 142)
		fCad = "El asistente lo guiará durante la instalación. \n\n\n- "
		"Haga click en el botón siguiente para continuar.\n\n- Si no "
		"desea instalar la aplicación haga click en el botón Cancelar.";
	if (fInd == 143)
		fCad = "Lea el contrato del usuario final (CLU). Si está de "
		"acuerdo, haga click en la opción Acepto, de lo\ncontrario "
		"haga click en el botón No acepto ó en el botón Cancelar.";
	if (fInd == 144)
		fCad = "Ingrese el nombre de la Empresa y la clave del producto...";
	if (fInd == 145)
		fCad = "Ingrese el nombre de servidor de la base de datos...";
	return fCad;
}
//---------------------------------------------------------------------------
