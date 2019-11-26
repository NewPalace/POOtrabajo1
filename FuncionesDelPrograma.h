#ifndef Funciones_para_el_main
#define Funciones_para_el_main
#include "classes.h"
Uint limite;

TipeInt Menu(){
	TipeInt numero;
	
	cout<<"|=============================================================================|\n";
	cout<<"Funcionalidades:::"<<endl;
	cout<<"Leer[0]\nGuardar[1]\njustificar[2]\nA la Izquierda[3]\nA la Derecha[4]\nAl Centro[5]\nBuscar[6]\nReemplazar[7]\nContar[8]\nEncriptar[9]\nDesencriptar[10]"<<endl;
	cout<<"|=============================================================================|"<<endl;
	
	cin>>numero;
	
	return numero;
}

Vid leer(CTexto &texto){
	texto.mostrar();
}

Vid guardar(CTexto &texto,string &nombreArchivo){
	texto.guardar(nombreArchivo);
	
	cout<<"\nProceso finalizado\n\n";
}

Vid just(CTexto &texto){
	cout<<"que tan grande le gustaria que fuera la linea\n";cin>>limite;
	
	texto.justificar(limite);
	texto.mostrar();
}

Vid izq(CTexto &texto){
	cout<<"que tan grande le gustaria que fuera la linea\n";cin>>limite;
	
	texto.izquierda(limite);
	texto.mostrar();
}

Vid der(CTexto &texto){
	cout<<"que tan grande le gustaria que fuera la linea\n";cin>>limite;
	
	texto.izquierda(limite);
	texto.derecha();
	texto.mostrar();
}

Vid cen(CTexto &texto){
	cout<<"que tan grande le gustaria que fuera la linea\n";cin>>limite;

	
	texto.izquierda(limite);
	texto.centrar();
	texto.mostrar();
}

Vid buscar(CTexto &texto){
    string palabra;
    cout<<"Â¿Que palabra desea buscar?\n";cin>>palabra;
    vector<Int> pos=texto.buscar(palabra);

    for(Int i=0;i<pos.size();i++){
        cout<<"la palabra aparece en la linea: "<<(int)(pos[i]/limite)<<" y empieza en el caracter "<<pos[i]%limite<<"\n";
    }

}

Vid reemplazar(CTexto &texto){
    string palabra1,palabra2;

    cout<<"Â¿Que palabra desea reemplazar?\n";cin>>palabra1;
    cout<<"Â¿por que palabra la desea reemplazar?\n";cin>>palabra2;
    texto.reemplazar(palabra1,palabra2);

    texto.justificar(limite);
    texto.mostrar();
}

Vid contar(CTexto &texto){
    string palabra;

    cout<<"Â¿Que palabra desea contar?\n";cin>>palabra;

    cout<<"la palabra "<<palabra<<"aparece "<<texto.contar(palabra)<<" 1veces\n";  
}

Vid ncrpt(CTexto &texto){
    Int llave;

    cout<<"Â¿Que llave le gustaria asignarle?\n";cin>>llave;

    texto.encriptar(llave);

    texto.mostrar();
}

Vid dncrpt(CTexto &texto){
    Int llave;

    cout<<"Ingrese la llave con la que quiere desencriptar\n";cin>>llave;

    texto.desencriptar(llave);

    texto.mostrar();
}

#endif
