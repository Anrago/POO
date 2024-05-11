// Alumno: Antonio Ramos Gonzalez
// Matricula: 372576
// Practica 4: Composicion y agregacion
// Fecha: 04/05/2024 | 07/05/2024

#include "Banco.h"
#include "Menu.h"
using std::cin;
using std::getline;
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
    menu.Agregar({'2',
                  "No ingresar e irme "});
    menu.SetExitKey('2');
    menu.Ejecutar();

    return 0;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU DEL BANCO>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void EnElBanco()
{
    Banco BanCoppel;
    Menu menuBanco;
    BanCoppel.CrearCuentaHabiente("Ana Maria Garcia Lopez", "GALA940502MDFRPN07");
    BanCoppel.CrearCuentaHabiente("Javier Rodriguez Perez", "ROJP940704HDFXVR03");
    BanCoppel.CrearCuentaHabiente("Sofia Martinez Hernandez", " MAHS980301MDFRTS09");
    BanCoppel.CrearCuentaHabiente("Carlos Hernandez Gomez", "HEGC000630HDFLMZ01");
    BanCoppel.CrearCuentaDeCheques(30001, 1000);
    BanCoppel.CrearCuentaDeCheques(30001, 500);
    BanCoppel.CrearCuentaDeCheques(30002, 10000);
    BanCoppel.CrearCuentaDeCheques(30002, 6025);
    BanCoppel.CrearCuentaDeCheques(30003, 12.59);
    BanCoppel.CrearCuentaDeCheques(30004, 52600);
    system(CLEAR_SCREEN);
    cout << "Existen cuentas habientes de 30001 hasta 30004" << endl;
    cout << "Existen cuentas de cheques de 10001 hasta 10006" << endl;
    Pause();
    menuBanco.Agregar({'1', "CREAR CUENTA HABIENTE", [&BanCoppel]()
                       { CrearHabiente(&BanCoppel); }});
    menuBanco.Agregar({'2',
                       "CREAR CUENTA DE CHEQUES", [&BanCoppel]()
                       { CrearCheque(&BanCoppel); }});
    menuBanco.Agregar({'3',
                       "IMPRIMIR REPORTE", [&BanCoppel]()
                       {
                           ImprimirReporte(&BanCoppel);
                       }});
    menuBanco.Agregar({'4',
                       "DEPOSITAR", [&BanCoppel]()
                       {
                           Depositar(&BanCoppel);
                       }});
    menuBanco.Agregar({'5',
                       "RETIRAR", [&BanCoppel]()
                       {
                           Retirar(&BanCoppel);
                       }});
    menuBanco.Agregar({'6',
                       "TRANSFERIR", [&BanCoppel]()
                       {
                           Transferir(&BanCoppel);
                       }});
    menuBanco.Agregar({'7', "SALIR"});
    menuBanco.SetExitKey('7');
    menuBanco.Ejecutar();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,FUNCIONES PARA BANCO>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void CrearHabiente(Banco *BanCoppel)
{
    string nombre, curp;
    system(CLEAR_SCREEN);
    cout << "INGRESA NOMBRE: ";
    getline(cin, nombre);
    do
    {
        cout << "INGRESA CURP : ";
        getline(cin, curp);
    } while (curp.length() < 16);
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
    system(CLEAR_SCREEN);
    cout << "INGRESE NUMERO DE CUENTA ORIGEN: ";
    cin >> NcOrigen;
    cout << "INGRESE NUMERO DE CUENTA DESTINO: ";
    cin >> NcDestino;
    cout << "INGRESE MONTO A TRANSFERIR: ";
    cin >> Monto;
    Origen = BanCoppel->GetCheques(NcOrigen);
    Destino = BanCoppel->GetCheques(NcDestino);
    Pause();
    system(CLEAR_SCREEN);
    if (Origen != nullptr && Destino != nullptr)
    {
        BanCoppel->Transferir(Origen, Destino, Monto);
    }
    else
    {
        cout << "HUBO UN PROBLEMA DURANTE LA TRANSFERENCIA" << endl;
    }
    Pause();
}

void Pause()
{
    cout << "Presione Enter para continuar...";
    fflush(stdout); // Limpia el búfer de salida para asegurar que el mensaje se muestre antes de esperar la entrada
    while (getchar() != '\n')
        ; // Espera a que el usuario presione Enter
}