#include "funcioncitas.h"
#include "iostream"

int main(){
	TipeInt continuar = 1;
	CTexto texto;
	string nombreArchivo;
	
	cout<<"ingrese el nombre del archivo que desea trabajar: ";cin>>nombreArchivo;
	texto.setContenido(nombreArchivo);
	//texto a trabajar cargado
	
	
	while(continuar){
	switch(Menu()){
		case 0:
			leer(texto);break;
		case 1:
			guardar(texto,nombreArchivo);break;
		case 2:
			just(texto);break;
		case 3:
			izq(texto);break;
		case 4:
			der(texto);break;
		case 5:
			cen(texto);break;
		case 6:
			buscar(texto);break;
		case 7:
			reemplazar(texto);break;
		case 8:
			contar(texto);break;
		case 9:
			ncrpt(texto);break;
		case 10:
			dncrpt(texto);break;
		default:
			cout<<"funcionalidad no existente"<<endl;
	}
		
		cout<<"Â¿deseas continuar?\nSi[1]\nNo[0]"<<endl;cin>>continuar;cout<<"\n\n";
	
}
	return 0;
}
