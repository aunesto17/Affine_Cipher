//
//  afin.h
//  Cifrado_Afin
//
//  Created by Alexander Arturo Baylon Ibanez on 4/13/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#ifndef __Cifrado_Afin__afin__
#define __Cifrado_Afin__afin__

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <math.h>

using namespace std;

class afin
{
private:
    unsigned int a,b,invA;
    int tamAlfa;
    string cifrado,decifrado;
public:
    string mensaje;
    afin();
    afin(string,int,int);
    string alfa = "abcdefghijklmnopqrstuvwxyz ";
    string cifrar();
    string decifrar();
    void generarClaves();
    unsigned int getA();
    unsigned int getB();
};

unsigned int randomKiss(unsigned int,int);
int mcd(int,int);
int modulo(int,int);
string getMsj();
unsigned int getSemilla();
unsigned int euclides_ext(int,int);

#endif /* defined(__Cifrado_Afin__afin__) */
