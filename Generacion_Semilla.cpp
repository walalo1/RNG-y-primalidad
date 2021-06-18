#include <NTL/ZZ.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <Windows.h>
#include <string>
#include <sstream>

NTL_CLIENT
using namespace std;

bool PRIMECHECK(ZZ numero)
{
  // Casos especiales
  if (numero == 0 || numero == 1 || numero == 4)
  {
      cout<<"FALSE";return false;
  }


  for (ZZ x (2); x < numero / 2; x++)
  {
    if (numero % x == 0)
    {
        cout<<"FALSE";return false;
    }
  }

  cout<<"TRUE";return true;
}

string conv_String(ZZ valor)
{
	stringstream palabra;
	palabra << valor;
	return palabra.str();
}


long long conv_ll(ZZ valor)
{
	string aux = conv_String(valor);
	return stoll(aux);
}


ZZ modulo(ZZ a, ZZ n)
{
	if (n <= 0)
		return ZZ(0);
	if (a < n && a >= 0)
		return a;
	ZZ q = a / n;
	if (a < 0)
		q -= 1;
	return  a - (q * n);
}
void swap_(ZZ & a, ZZ & b)
{
	ZZ aux;
	aux = a;
	a = b;
	b = aux;
}

void print(vector<ZZ> S)
{
	for (long long i = 0; i < S.size(); i++)
		cout << S[i] << endl;
	cout << endl;
}



vector<string> Memoria()
{
	vector<string>datos;
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);

	DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

	string VMU = to_string(virtualMemUsed);
	string PMU = to_string(physMemUsed);

	datos.push_back(VMU);
	datos.push_back(PMU);

	return datos;
}

vector<ZZ> semilla(ZZ bits)
{
	vector<string>mem = Memoria();
	vector<ZZ> k;
	//inicializamos K (semilla)

	int j = 0;

	for (ZZ i(0); i < bits; i++)
	{
		ZZ tiempo(time(NULL));
		string otr = mem[j];
		ZZ valor(INIT_VAL, otr.c_str());

		if (modulo(modulo(valor, i), ZZ(2)) == ZZ(0)) 
        {
            valor *= tiempo+i ;
        }

		else
        {
            valor *= tiempo-i;
        }

		k.push_back(valor);

		if (j + 1 == mem.size()) 
        {
            j = -1;
        }

		j++;
		// Sleep(20);
	}

	


	return k;
}


ZZ RANDBIGINTEGER(ZZ bits)
{
	vector<ZZ> k=semilla(bits),r;
	ZZ num(0),val(1),t(0);

	//agregamos a S los numeros de 0 al valor de los bits
	for (ZZ i(0); i < bits; i++)
    {
        r.push_back(i);
    }


	for (long long i = 0, j = 0; i < bits; i++, j++)
	{
		t = modulo((t + r[i] + k[j]), bits);
		long long aux = conv_ll(t);
		swap_(r[i], r[aux]);

		if (j + 1 == k.size())
        {
            j = -1;
        }
	}
    

	for (long long i = r.size() - 1, j = 0; i >= 0; i--, j++)
	{
		if (modulo(r[i], ZZ(2)) == ZZ(1))
        {
            num += val;
        }

		val *= 2;
	}
	return num;
}


int main()
{
	ZZ bits,n;

	cout << "Ingrese la cantidad de valores : "; cin >> bits;
	

    n=RANDBIGINTEGER(bits);

    cout<<n<<endl;
    PRIMECHECK(n);

}
