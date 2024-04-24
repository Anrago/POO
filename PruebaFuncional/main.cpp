#include <iostream>
#include <functional>
#include <vector>

using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::ostream;

void salud();
void saludar(function<void(void)> fs);
void saludo2();
vector<int> ExtraerPares(vector<int> V,function<bool(int)>p);
int contar(vector<int> V,function<bool(int)>p);
bool esPar(int x);
bool esPrimo(int x);


ostream &operator<<(ostream &out, vector<int> V);
/*  */
int main()
{

    //salud();
    // Las funciones pueden ser manejadas como objetos.
    // Hay una clase llamada fuction, es una plantilla para crear objetos
    // de tipo puncion. Estos objetos siempren tienen una funcion asociada
    // La plantilla de function recibe como parametros el tipo de retorno y
    // tipos para los parametros
    function<void(void)> f = salud;
    // para invocar la funcion se utiliza el operador ()
    //f();
    function<void(void)> f2 = saludo2; 

    vector<int> numeros={1,2,3,4,5,6,7};

    vector<int> n2=ExtraerPares(numeros,esPar);
    cout<<"Hay: "<<n2<<endl;
    n2=ExtraerPares(numeros,esPrimo);
    cout<<endl;
    cout<<"Hay: "<<n2<<endl;
    // saludar(f);
    // cout<<endl;
    // saludar(f2);
    return 0;
}

void salud()
{
    cout << "holaMundo" << endl;
}

void saludar(function<void(void)> fs)
{
    cout<<"Te voy a saludar..."<<endl;
    cout<<"....preparate...."<<endl;
    fs();
    cout<<"...Listo"<<endl;
}

void saludo2()
{
    srand(time(NULL));
    if ((rand()%100)<50)
        cout << "Que transa..." << endl;
    else
        cout << "Buenas tardes mi estimado..." <<endl;
    
}

vector<int> ExtraerPares(vector<int> V,function<bool(int)>p)
{
    vector<int> element;

    for (int n:V)
        if (p(n)==0)
            element.push_back(n);
    
    return element;
    
    
}

int contar(vector<int> V,function<bool(int)>p)
{
    int conteo;

    for (int n:V)
        if (p(n)==0)
            conteo++;
    
    return conteo;
    
    
}

bool esPar(int x)
{
    return(x%2)==0;
}

bool esPrimo(int x)
{
    if (x==2||x==3)return true;
    if (x==1||(x%2)==0||(x%3)==0)return false;
    for (int d=5;d<=x/2;d+=2)
    {
        if (x%d==0)
            return false;
        
    }
    return true;
    
    
}


ostream &operator<<(ostream &out,vector <int > V)
{
    out<< "[";
    for ( int n:V)
        cout<<n<<"";
    out << "]";
    return out;
    
}