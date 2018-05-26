#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void euklides(int e,int m, int *d)
{

	int n, z,
		x[100], y[100], r[100], q[100];

	z = 0;

	r[0] = e%m;
	q[0] = (e - r[0]) / m;

	x[0] = 1;
	y[0] = -q[0];

	//------------------------------//

	r[1] = m%r[0];
	q[1] = (m - r[1]) / r[0];

	x[1] = (-x[0])*q[1];
	y[1] = 1 - y[0] * q[1];

	//------------------------------//

	n = 2;

	while (r[n - 1] != 0)
	{
		r[n] = r[n - 2] % r[n - 1];
		q[n] = (r[n - 2] - r[n]) / r[n - 1];

		x[n] = x[n - 2] - (x[n - 1] * q[n]);
		y[n] = y[n - 2] - (y[n - 1] * q[n]);
		n++;
	}


	while (x[n - 2] < 0)
	{
		x[n - 2] = x[n - 2] + m;
	}
			
	*d = x[n - 2];
		
}

int main()
{
//---------------------------------------------------------------------------------------------------------//
												//SITO

	cout << endl << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SITO ERATOSTENESA" << endl<<endl;

	int i ,n , k, S[100000];
	double pierwiastek;

	n = 100000;

	pierwiastek = sqrt(n);

	for (i = 0; i < n; i++)
	{
		S[i] = i+2;
	}

	for (i = 0; i < n; i++)
	{
		if (((double)S[i] <= pierwiastek) && (S[i] != 0))
		{
			for (k = i+1; k < n; k++)
			{
				if (S[k] % S[i] == 0)
				{
					S[k] = 0;
				}
			}
		}
	}
	vector <int> do_rsa;
	k = 0;

	for (i = 0; i < n; i++)
	{
		if (S[i] != 0)
		{
			cout << S[i] << " ";
			do_rsa.push_back(S[i]);
			k++;
		}
	}

	cout << endl << endl << "----------------------------------------------------------------------------------------------------------------------"<<endl;

	



//---------------------------------------------------------------------------------------------------------//
											//EUKLIDES

	cout << "ROZSZERZONY ALGORYTM EUKLIDESA" << endl<<endl;

	int a, b, d,
		x[100], y[100], r[100], q[100];

	cout << endl << "Prosze podac a: ";
	cin >> a;
	cout << endl << "Prosze podac b: ";
	cin >> b;
	cout << endl;

//------------------------------//

	r[0] = a%b;
	q[0] = (a - r[0]) / b;

	x[0] = 1;
	y[0] = -q[0];

//------------------------------//

	r[1] = b%r[0];
	q[1] = (b - r[1]) / r[0];

	x[1] = (-x[0])*q[1];
	y[1] = 1 - y[0] * q[1];

//------------------------------//

	n = 2;

	while (r[n-1] != 0)
	{
		r[n] = r[n-2] % r[n-1];
		q[n] = (r[n-2] - r[n]) / r[n-1];

		x[n] = x[n - 2] - (x[n - 1] * q[n]);
		y[n] = y[n - 2] - (y[n - 1] * q[n]);
		n++;
	}

//------------------------------//



	cout << "NWD(d) to: " << r[n-2] << endl;
	cout << "Zas X i Y to: " << x[n - 2] << " i " << y[n - 2] << endl;

//---------------------------------------------------------------------------------------------------------//
												//RSA

	cout << endl << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SZYFR RSA" << endl << endl;

	int pe,qu,m,e,de;

	cout << "Podaj numer liczby p: ";
	cin >> pe;
	cout << endl << "Podaj numer liczby q: ";
	cin >> qu;
	cout << endl;

	pe = do_rsa[pe-1];
	qu = do_rsa[qu-1];

	n = pe*qu;
	m = (pe - 1)*(qu - 1);

	cout << "N to: " << n << endl;
	cout << "M to: " << m << endl;

	cout << "Podaj \"losowa\" liczbe e: ";
	cin >> e;
	cout << endl;

	euklides(e, m, &de);

	cout << "D to: " << de << endl << endl;

	cout << "Klucz prywatny to: (" << n << "," << e << "), a klucz prywatny to: (" << n << "," << de << ")";


	system("PAUSE");
	return 0;
}