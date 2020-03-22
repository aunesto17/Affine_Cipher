//
//  main.cpp
//  Cifrado_Afin
//
//  Created by Alexander Arturo Baylon Ibanez on 4/13/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "afin.h"

int main(int argc, const char * argv[]) {
    
    afin prueba;
    string pru = prueba.cifrar();
    cout << pru << endl;
    unsigned int a = prueba.getA(),b=prueba.getB();
    
    
    //string pru = "cabxydbrsmvnvmdjyrdfbmryrdoirdwmvrwbr";
    //string pru = " hts";
    afin prueba1(pru,a,b);
    string de = prueba1.decifrar();
    cout << de << endl;
    

    return 0;
}
