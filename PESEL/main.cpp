#include <iostream>
#include <cstring>

using namespace std;
int pesel[11];
bool poprawnyPesel = 0;

int pobierzRok()
{
    int rok;
    int miesiac;
    rok = 10 * pesel[0];
    rok += pesel[1];
    miesiac = 10 * pesel[2];
    miesiac += pesel[3];
    if (miesiac > 80 && miesiac < 93)
        {
            rok += 1800;
        }
    else if (miesiac > 0 && miesiac < 13)
        {
            rok += 1900;
        }
    else if (miesiac > 20 && miesiac < 33)
        {
            rok += 2000;
        }
    else if (miesiac > 40 && miesiac < 53)
        {
            rok += 2100;
        }
    else if (miesiac > 60 && miesiac < 73)
        {
            rok += 2200;
        }
    return rok;
}

int pobierzMiesiac()
{
    int miesiac;
    miesiac = 10 * pesel[2];
    miesiac += pesel[3];
    if (miesiac > 80 && miesiac < 93)
        {
            miesiac -= 80;
        }
    else if (miesiac > 20 && miesiac < 33)
        {
            miesiac -= 20;
        }
    else if (miesiac > 40 && miesiac < 53)
        {
            miesiac -= 40;
        }
    else if (miesiac > 60 && miesiac < 73)
        {
            miesiac -= 60;
        }
    return miesiac;
}

int pobierzDzien()
{
    int dzien;
    dzien = 10 * pesel[4];
    dzien += pesel[5];
    return dzien;
}



bool sprawdzSume()
{
    int suma = 1 * pesel[0] +
    3 * pesel[1] +
    7 * pesel[2] +
    9 * pesel[3] +
    1 * pesel[4] +
    3 * pesel[5] +
    7 * pesel[6] +
    9 * pesel[7] +
    1 * pesel[8] +
    3 * pesel[9];
    suma %= 10;
    suma = 10 - suma;
    suma %= 10;

    if (suma == pesel[10])
        {
            return true;
        }
    else
        {
            return false;
        }
}

bool sprawdzMiesiac()
{
    int miesiac = pobierzMiesiac();
    if (miesiac > 0 && miesiac < 13)
        {
            return true;
        }
    else
        {
            return false;
        }
}

bool rokPrzestepny(int rok)
{
    if (rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool sprawdzDzien()
{
    int rok = pobierzRok();
    int miesiac = pobierzMiesiac();
    int dzien = pobierzDzien();
    if ((dzien >0 && dzien < 32) &&
    (miesiac == 1 || miesiac == 3 || miesiac == 5 ||
    miesiac == 7 || miesiac == 8 || miesiac == 10 ||
    miesiac == 12))
        {
            return true;
        }
    else if ((dzien >0 && dzien < 31) &&
    (miesiac == 4 || miesiac == 6 || miesiac == 9 ||
    miesiac == 11))
        {
        return true;
        }
    else if ((dzien >0 && dzien < 30 && rokPrzestepny(rok)) ||
    (dzien >0 && dzien < 29 && !rokPrzestepny(rok)))
        {
            return true;
        }
    else
        {
            return false;
        }
}



void sprawdzPesel(char numerPesel[25])
{
    int i;

    if (strlen(numerPesel) != 11)
        {
            poprawnyPesel = false;
        }
    else
        {
            for (i = 0; i < 11; i++)
            {
                pesel[i] = numerPesel[i] - 48;
            }
    if (sprawdzSume() && sprawdzMiesiac() && sprawdzDzien())
        {
            poprawnyPesel = true;
        }
    else
        {
            poprawnyPesel = false;
        }
    }
}

string pobierzPlec()
{
    if (poprawnyPesel)
        {
            if (pesel[9] % 2 == 1)
                {
                    return "Mezczyzna";
                }
            else
                {
                    return "Kobieta";
                }
        }

}
int main()
{
    char numerPesel[25];

    cout<<"Podaj numer pesel"<<endl;
    cin>> numerPesel;

    sprawdzPesel(numerPesel);

    if (poprawnyPesel == true)
        {
            cout<<"Numer pesel jest prawidlowy"<<endl;
            cout<<"Rok urodzenia: "<< pobierzRok()<<endl;
            cout<<"Miesiac urodzenia: "<< pobierzMiesiac()<<endl;
            cout<<"Dzien urodzenia: "<< pobierzDzien()<<endl;
            cout<<"Plec: "<< pobierzPlec()<<endl;
        }
    else
        {
            cout<<"Numer pesel jest nieprawidlowy"<<endl;
        }

}
