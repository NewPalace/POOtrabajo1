#include "classes.h"
Vid encuadrarTexto(vector<string> &parrafo, const vector<string> &palabras,unsigned int tamanioLinea){
	unsigned int count=0;
	std::string linea="";
	
	for(int i=0;i<palabras.size();i++){//recorre el texto palabra por palabra
		for(int j=0;j<palabras[i].size();j++){//recorre cada palabara letra por letra
		
			if(count>=tamanioLinea){//cuando la contador llega al limite
			parrafo.push_back(linea);//agrega la linea al parrafo
			count=0;//resetea el contador
			linea="";//y la linea tambien
			}
			linea+=palabras[i][j];//ingresa cada letra a la linea
			count++;//aumenta el contador
			
		}//ya pusiste la palabra entera en la linea 
		if(i<palabras.size() && count>0){//si no llegas  a la ultima palabra y el contador es diferente de 0 
			linea+=' ';//aï¿½ade un espacio despues de la palabra
			count++;//y aumenta el contador
		}
	}
	parrafo.push_back(linea);//agrega la ultima linea
}
Vid splitString(vector<string> &palabras,const string &texto, character splitchar){
	std::string palabra="";
	int flag=0;

	for(int i=0;i<texto.size();i++){//recorre la cadena 
		if(texto[i]!=splitchar)//si no encuentras el caracter indicado
			palabra+=texto[i];//agrega la letra
		else{//si lo encuentras 
			if(palabra.size()!=0)//y la palabra no esta vacia
				palabras.push_back(palabra);//agrega lo que hallas encontrado hasta el momento 
				
			palabra="";//resetea la palabra
			flag=i;//y coloca la bandera en el lugar donde encontraste el caracter
		}
	}
	//como no se puede asegurar q el caracter buscado este al final de la cadena 
	palabra="";//resetea la palabra
	for(int i=flag+1;i<texto.size();i++)//y desde el ultimo caracter hasta el final de la cadena
		palabra+=texto[i];//crea la palabra
	palabras.push_back(palabra);//agrega la ultima palabra
} 

Vid CTexto::setContenido(string nombreArchivo){
		string lineasDeTexto;
		ifstream Iarchivo;
	
		Iarchivo.open(nombreArchivo.c_str(),ios::in);
		
		if(Iarchivo.fail()){
			cout<<"Archivo no encontrado";
		}
		else{
			while(!Iarchivo.eof()){
				getline(Iarchivo,lineasDeTexto);
				Vid splitString(Vtexto,lineasDeTexto,' ');
			}
		}
		Iarchivo.close();
		
		Vidd encuadrarTexto(VtextoFormateado,Vtexto,80);
}
	

Vid CTexto::mostrar(){
		for(int i=0;i<VtextoFormateado.size();i++){
			cout<<VtextoFormateado[i]<<'\n';
		}	
		cout<<endl;
}

Vid CTexto::guardar(string nombreArchivo){
	ofstream Oarchivo;
	
	Oarchivo.open(nombreArchivo.c_str(),ios::out);
	
	if(Oarchivo.fail()){
		cout<<"imposible guardar\n";
	}
	else{
	for(int i=0;i<VtextoFormateado.size();i++){
		if(i<Vtexto.size()-1)
			Oarchivo<<VtextoFormateado[i]<<"\n";
		else
			Oarchivo<<VtextoFormateado[i];
		}
	}
	Oarchivo.close();
}

Vid CTexto::justificar(unsigned int n){
	VtextoFormateado.clear();
	encuadrarTexto(VtextoFormateado,Vtexto,n);
}

Vid CTexto::izquierda(Uint limite){
	VtextoFormateado.clear();
	Uint count=0;
	string line="";
	
	for(int i=0;i<Vtexto.size();i++){//recorre todas las palabras
		if(count+Vtexto[i].size()<limite){//si con la palabra no te pasas del limite
			line+=Vtexto[i];//agrega la palabra a la linea
			count+=Vtexto[i].size();//agrega al contador el tamaï¿½o de la palabra
		
			if(i<Vtexto.size()){//si no llegas a la ultima palabra
			line+=' ';//agrega un espacio
			count++;//y aumenta el contador en uno
			}
		}else{
			VtextoFormateado.push_back(line);//agrega la linea al parrafo
			line="";//resetea la linea
			count=0;//resetea el contador
		}
	}
	VtextoFormateado.push_back(line);//agrega la ultima linea
}
	
Vid CTexto::derecha(){	
	string line="";
	int max=0;
	int temp;
	
	for(int i=0;i<VtextoFormateado.size();i++){//encontrar el maximo
		if(VtextoFormateado[i].size()>max)
			max=VtextoFormateado[i].size();
		}
	//////////////////////////////////////////////////////////////////////////////
	for(int l=0;l < VtextoFormateado.size();l++){//recorrer las lineas
		temp=max-VtextoFormateado[l].size();//cuantas veces se agregaran espacios?
		
		for(int j=0;j<temp;j++)//agrega espacios necesarios
			line+=' ';
		
		line+=VtextoFormateado[l];//crea la linea a la derecha 
		VtextoFormateado[l]=line;//la reeemplaza
		line="";//resetea la linea
	}
}

Vid CTexto::centrar(){
	string line="";
	int max=0;
	int temp;
	
	for(int l=0;l < VtextoFormateado.size();l++)//encontrar el maximo
		if(VtextoFormateado[l].size()>max)
			max=VtextoFormateado[l].size();
	//////////////////////////////////////////////////////////////////////////////
	for(int l=0;l < VtextoFormateado.size();l++){//recorrer las lineas
		temp=(max-VtextoFormateado[l].size())/2;//cuantas veces se agregaran espacios?
		/*                                    ï¿½
		            eso es lo unico q cambia con respecto a poner todo a la derecha*/
		
		for(int j=0;j<temp;j++)//agrega espacios necesarios
			line+=' ';
		
		line+=VtextoFormateado[l];//crea la linea a la derecha 
		VtextoFormateado[l]=line;//la reeemplaza
		line="";//resetea la linea
	}
}
