#include <cstdlib>
#include <iostream>

using namespace std;

/*Stephanie Correa C.I 19.598.574
  Seccion 2*/
  
class data{
      public:
      data(){}
      int codigo;
      int peso;
      int edad;
};

class archivo{
      public:
      archivo(){
                v=(data*)malloc(sizeof(data)*100);
                aux=(data*)malloc(sizeof(data)*100);
                }
      data *v;
      data *aux;
      void abrir();
      void arreglo(int k);
      void seeking_pos(int k);

};
void archivo::abrir(){
     char cad[50];
     int i=0;
     char *se;
     FILE *fp;
     fp=fopen("data.txt","r");
     if(!fp){cout<<"Error de apertura"<<endl;fclose(fp);}

       else{
          
          while(!feof(fp)){
          fgets(cad,50,fp);
          se=strtok(cad,",");
          v[i].codigo=atoi(se);
          se=strtok(NULL,",");
          v[i].peso=atoi(se);
          se=strtok(NULL,",");
          v[i].edad=atoi(se);
          aux[i]=v[i];
          i++;
          
          }
       }
       fclose(fp);
       arreglo(i);
       seeking_pos(i);
}

void archivo::arreglo(int k){
       data d;
          for(int j=0;j<k;j++){
                  for(int u=0;u<k;u++){
                          if(aux[j].codigo<aux[u].codigo){
                              d=aux[j];
                              aux[j]=aux[u];
                              aux[u]=d; 
                               }
                          }
                  }
	               /* for(int h=0;h<k;h++){
                          cout<<""<<aux[h].codigo<<endl;  
                          }*/
     }

void archivo::seeking_pos(int k){
     int pos=0;
     cout<<"**************METODO SEEKING POSITION************"<<endl;
     for(int g=0;g<k;g++){
             for(int j=0;j<k;j++){
                     if(v[g].codigo==aux[j].codigo){
                         pos=j;
                         cout<<"Elemento codigo: "<<v[g].codigo<<" debe ocupar la posicion: "<<j+1<<endl;                           
                          }
                     }
             }
     }
int main(int argc, char *argv[])
{  
    archivo a;
    a.abrir();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
