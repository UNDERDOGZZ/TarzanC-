#include "FrmJuego.h"
#include "FrmMenu.h"
#include "FrmBatalla.h"
#include "FrmOceano.h"
using namespace TF_Progra2_Guevara_Tairaku;

void main()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew FrmMenu());
}
