#include "Banco.h"
#include "Menu.h"
using std::cin;
void EnElBanco();
void CrearHabiente(Banco *BanCoppel);
void CrearCheque(Banco *BanCoppel);
void ImprimirReporte(Banco *BanCoppel);
void Depositar(Banco *BanCoppel);
void Retirar(Banco *BanCoppel);
void Transferir(Banco *BanCoppel);
void Pause();

int main()
{
    Menu menu;
    menu.Agregar({'1', "Ingresar al banco", EnElBanco});
    menu.Agregar({
        '2',
        "No ingresar e irme ",
    });
    do
    {
        menu.Ejecutar();
    } while (menu.Seleccionar() != '2');

    return 0;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU DEL BANCO>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void EnElBanco()
{
    Banco BanCoppel;
    Menu menuBanco;
    BanCoppel.CrearCuentaHabiente("Antonio", "RAGA031004RMN16");
    BanCoppel.CrearCuentaDeCheques(30001, 1000);
    BanCoppel.CrearCuentaHabiente("DIANA", "RAGD031004RMN16");
    BanCoppel.CrearCuentaDeCheques(30001, 500);
    menuBanco.Agregar({'1', "CREAR CUENTA HABIENTE", [&BanCoppel]()
                       { CrearHabiente(&BanCoppel); }});
    menuBanco.Agregar({'2',
                       "CREAR CUENTA DE CHEQUES", [&BanCoppel]()
                       { CrearCheque(&BanCoppel); }});
    menuBanco.Agregar({
        '3',
        "OBTENER CUENTA HABIENTE",
    });
    menuBanco.Agregar({
        '4',
        "OBTENER CUENTA DE CHEQUES",
    });
    menuBanco.Agregar({'5',
                       "IMPRIMIR REPORTE", [&BanCoppel]()
                       {
                           ImprimirReporte(&BanCoppel);
                       }});
    menuBanco.Agregar({'6',
                       "DEPOSITAR", [&BanCoppel]()
                       {
                           Depositar(&BanCoppel);
                       }});
    menuBanco.Agregar({'7',
                       "RETIRAR", [&BanCoppel]()
                       {
                           Retirar(&BanCoppel);
                       }});
    menuBanco.Agregar({'8',
                       "TRANSFERIR", [&BanCoppel]()
                       {
                           Transferir(&BanCoppel);
                       }});
    menuBanco.Agregar({'0', "SALIR"});
    do
    {
        menuBanco.Ejecutar();
    } while (menuBanco.Seleccionar() != 'x');
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,FUNCIONES PARA BANCO>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void CrearHabiente(Banco *BanCoppel)
{
    string nombre, curp;
    system(CLEAR_SCREEN);
    cout << "INGRESA NOMBRE: ";
    cin >> nombre;
    do
    {
        cout << "INGRESA CURP : ";
        cin >> curp;
    } while (curp.length() < 16);
    Pause();
    system(CLEAR_SCREEN);
    BanCoppel->CrearCuentaHabiente(nombre, curp);
    Pause();
}

void CrearCheque(Banco *BanCoppel)
{
    float saldo;
    int NumeorCh;
    system(CLEAR_SCREEN);
    cout << "INGRESA NUMERO DE CUENTA HABIENTE: ";
    cin >> NumeorCh;
    cout << "INGRESA SALDO: ";
    cin >> saldo;
    Pause();
    system(CLEAR_SCREEN);
    BanCoppel->CrearCuentaDeCheques(NumeorCh, saldo);
    Pause();
}

void ImprimirReporte(Banco *BanCoppel)
{
    int NumeroCh;
    system(CLEAR_SCREEN);
    cout << "INGRESE NUMERO DE CUENTA: ";
    cin >> NumeroCh;
    Pause();
    system(CLEAR_SCREEN);
    BanCoppel->ImprimirReporte(NumeroCh);
    Pause();
}

void Depositar(Banco *BanCoppel)
{
    int Deposito;
    int NumeroC;
    system(CLEAR_SCREEN);
    cout << "INGRESA EL NUMERO DE CUENTA DE CHEQUES AL QUE DESEA DEPOSITAR: ";
    cin >> NumeroC;
    cout << "INGRESA SALDO A DEPOSITAR: ";
    cin >> Deposito;
    Pause();
    system(CLEAR_SCREEN);
    BanCoppel->Depositar(NumeroC, Deposito);
    Pause();
}

void Retirar(Banco *BanCoppel)
{
    int Retiro;
    int NumeroC;
    system(CLEAR_SCREEN);
    cout << "INGRESA EL NUMERO DE CUENTA DE CHEQUES AL QUE DESEA RETIRAR: ";
    cin >> NumeroC;
    cout << "INGRESA SALDO A RETIRAR: ";
    cin >> Retiro;
    Pause();
    system(CLEAR_SCREEN);
    BanCoppel->Retirar(NumeroC, Retiro);
    Pause();
}

void Transferir(Banco *BanCoppel)
{
    int NcOrigen, NcDestino;
    float Monto;
    CuentaDeCheques *Origen, *Destino;
    cout << "INGRESE NUMERO DE CUENTA ORIGEN: ";
    cin >> NcOrigen;
    cout << "INGRESE NUMERO DE CUENTA DESTINO: ";
    cin >> NcDestino;
    cout << "INGRESE MONTO A TRANSFERIR: ";
    cin >> Monto;
    Origen = BanCoppel->GetCheques(NcOrigen);
    Destino = BanCoppel->GetCheques(NcDestino);
    if (Origen != nullptr && Destino != nullptr)
    {
        BanCoppel->Transferir(Origen, Destino, Monto);
    }
    else
        cout << "HUBO UN PROBLEMA DURANTE LA TRANSFERENCIA";

}

void Pause()
{
    cout << "Presione Enter para continuar...";
    fflush(stdout); // Limpia el búfer de salida para asegurar que el mensaje se muestre antes de esperar la entrada
    while (getchar() != '\n')
        ; // Espera a que el usuario presione Enter
}