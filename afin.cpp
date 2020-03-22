//
//  afin.cpp
//  Cifrado_Afin
//
//  Created by Alexander Arturo Baylon Ibanez on 4/13/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "afin.h"


afin::afin()
{
    //cout << "Hola " << endl;
    tamAlfa = int(alfa.size());
    generarClaves();
    //a = 5;
    //b = 8;
    cout << a <<" " << b << endl;
}

afin::afin(string cif,int x,int y)
{
    tamAlfa = int(alfa.size());
    cifrado = cif;
    a = x;
    b = y;
}

void afin::generarClaves()
{
    do {
        a = randomKiss(getSemilla(),tamAlfa);
    } while ((mcd(a, tamAlfa)!=1));
    b = randomKiss(getSemilla(),tamAlfa);
}

string afin::cifrar()
{
    mensaje = getMsj();
    int tamMsj = int(mensaje.size());
    for (int i=0; i<tamMsj; i++) {
        cifrado += alfa[modulo((a*int(alfa.find(mensaje[i])))+b, tamAlfa)];
    }
    return cifrado;
}

string afin::decifrar()
{
    invA = euclides_ext(a, tamAlfa);
    cout << "invA: " << invA << endl;
    int tamMsj = int(cifrado.size());
    for (int i=0; i<tamMsj; i++) {
        decifrado += alfa[modulo(invA*(int(alfa.find(cifrado[i]))-b), tamAlfa)];
    }
    return decifrado;
}

unsigned int afin::getA(){
    return a;
}

unsigned int afin::getB(){
    return b;
}


int mcd(int a,int b)
{
    int c,d,r;
    if (a == 0)
        return b;
    c = a;
    d = b;
    while (d!=0)
    {
        r = modulo(c, d);
        c = d;
        d = r;
    }
    return c;
}


unsigned int randomKiss(unsigned int s,int m)
{
    // semillas
    //static unsigned int x = 123456789,y = 362436000, z = 521288629, c = 7654321;
    static unsigned int x = 123456789,y = 362436000, z = 521288629, c = s;
    unsigned long long t, a = 698769069ULL;
    x = 69069 * (x+12345);
    y ^= (y<<13);
    y ^= (y>>17);
    y ^= (y<<5);
    t = a*(z+c);
    c = (t>>32);
    return modulo(x + y + (z=t),m);
}

int modulo(int a,int b)
{
    if      (a==0) return 0;
    return  (a>0) ? a - ((a/b) * b) : abs(((a/b)-1) * b) + a;
}

string getMsj()
{
    string msj;
    cout << "Ingrese el mensaje: ";
    cin.ignore();
    getline(cin,msj);
    return msj;
}

unsigned int getSemilla()
{
    unsigned int a;
    cout << "Ingrese la semilla: "; cin >> a;
    return a;
}

unsigned int euclides_ext(int a,int b)
{
    int r,s,t,q,r1,r2,s1,s2,t1,t2;
    r1 = a; r2 = b;
    s1 = t2 = 1;
    t1 = s2 = 0;
    while (r2 > 0) {
        q = r1/r2;
        //actualizando r's
        r  = r1 - (q*r2);
        r1 = r2; r2 = r;
        //actualizando s's
        s  = s1 - (q*s2);
        s1 = s2; s2 = s;
        //actualizando t's
        t  = t1 - (q*t2);
        t1 = t2; t2 = t;
    }
    if(s1>0)
        return s1;
    else
        return modulo(s1, b);
}

