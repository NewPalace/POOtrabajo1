#ifndef CLASES_PARA_EL_PROYECTO
#define CLASES_PARA_EL_PROYECTO

#include "Types.h"


class CTexto{
	private:
		vector<string> Vtexto, VtextoFormateado;

	public:
		CTexto(){}
		~CTexto(){}
		
		Vid setContenido(string);
		
		Vid mostrar();
		
		Vid guardar(string);
		
		Vid justificar(Unsint);
		
		Vid izquierda(Unsint);
		
		Vid derecha();
		
		Vid centrar();
		
		vector<TipeInt> buscar(const string &);

		TipeInt contar(const string &);

		Vid reemplazar(const string &,const string &);

		Vid encriptar(Int);

		Vid desencriptar(Int);
    
		


		inline vector<Uint> getTextSize() const {
            	    vector<Uint> tamanios;
		    for(int i=0;i<VtextoFormateado.size();i++)
		        tamanios.push_back(VtextoFormateado[i].size());

		    return tamanios;
		}

};



#endif
