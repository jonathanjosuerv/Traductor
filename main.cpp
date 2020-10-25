
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Crud
{
    string word, translation;
	char function[500];
};

int main() {
    system("mode con: cols=80 lines=25");
	system("COLOR 1F");
    loop:
    Crud c;
    int a;
    string b;

    cout<<" ------------------------------------------------------------ "<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|               PROYECTO TRADUCTOR DE C++                    |"<<endl;
    cout<<"|                   INGLES ESPAÑOL                           |"<<endl;
    cout<<" ------------------------------------------------------------- "<<endl;
    cout<<"1 GUARDAR NUEVA PALABRA"<<endl;
    cout<<"2 MOSTRAR PALABRAS GUARDADAS"<<endl;
    cout<<"3 ELIMINAR PALABRA GUARDADA "<<endl;
    cout<<"4 RENOMBRAR PALABRA GUARDADA "<<endl;
    cout<<"5 SALIR"<<endl;
    cout<<"%%%%%%%%%%%%%%%%%"<<endl;
    cout<<endl;
    cout<<"Elija una opcion:"<<endl;
    cin>>a;

    switch (a)
    {
        case 1:
            //guarda nuevas palabras:
        {
            cout<<"Ingrese palabra : "<<endl;
            cin>>c.word;
            cout<<"Ingrese traduccion :"<<endl;
            cin>>c.translation;
            cout<<"Ingrese funcion :"<<endl;
            cin>>c.function;

            ofstream sdata;
            sdata.open("file.txt", ios :: app);
            sdata << endl;
            sdata << c.word; //guarda  la PALABRA en el archivo
            sdata << endl;
            sdata << c.translation; //guarda la TRADUCCION en el archivo
            sdata << endl;
            sdata << c.function; // guarda la Funcion en el archivo
            sdata << endl;
            sdata.close();
            goto loop;
            break;
        }

        case 2:
        {
            ifstream tdata;
            tdata.open("file.txt");

            tdata >> c.word;
            tdata >> c.translation;
            tdata >> c.function;


            while (!tdata.eof())
            {
                cout<<"La funcion es : " << c.word<<endl;
                cout<<"La palabra es : " << c.translation<<endl;
                cout<<"La traduccion es : " << c.function<<endl;
                cout<<"----------------------------------------.-----"<<endl;
                tdata >> c.word;
                tdata >> c.translation;
                tdata >> c.function;
            }
            tdata.close();
            goto loop;
            break;

        }

        case 3:
        {
            cout<<"Ingrese palabra que desea ELIMINAR : "<<endl;
            cin >> b;
            ifstream d;
            d.open("file.txt");
            ofstream e;
            e.open("new.txt");


            d >> c.word;
            d >> c.translation;
            d >> c.function;

            while(!d.eof())
            {
                if (c.word != b)
                {
                    e << endl;
                    e << c.word;
                    e << endl;
                    e << c.translation;
                    e << endl;
                    e << c.function;
                    e << endl;
                }
                else
                {
                   cout<<"Palabra eliminada"<<endl;
                }

                d >> c.word;
                d >> c.translation;
                d >> c.function;

            }
            e.close();
            d.close();

            if (remove("file.txt") != 0)
            {
                cout<<"Palabra no removida "<<endl;
            }
            else
            {
                cout<<"ok"<<endl;
            }

            if (rename("new.txt", "file.txt") != 0)
            {
                cout <<"File no renombrado"<<endl;

            }
            else
            {
                cout<<"ok"<<endl;
            }
            goto loop;
            break;


        }
        	
			
        case 4:
        {
            string g, h, i;
            cout <<"Ingrese palabra que desea MODIFICAR : "<<endl;
            cin >> b;
            ifstream d;
            d.open("file.txt");
            ofstream e;
            e.open("new.txt");


            d >> c.word;
            d >> c.translation;
            d >> c.function;

            while(!d.eof())
            {
                if (c.word != b)
                {
                    e << endl;
                    e << c.word;
                    e << endl;
                    e << c.translation;
                    e << endl;
                    e << c.function;
                    e << endl;
                }
                else
                {
                    cout<<"Ingrese nueva palabra: "<<endl;
                    cin>>g;
                    cout<<"Ingrese traduccion: "<<endl;
                    cin>>h;
                    cout<<"Ingrese funcionalidad: "<<endl;
                    cin>>i;

                    e << endl;
                    e << g;
                    e << endl;
                    e << h;
                    e << endl;
                    e << i;
                    e << endl;
                }

                d >> c.word;
                d >> c.translation;
                d >> c.function;

            }
            e.close();
            d.close();

            if (remove("file.txt") != 0)
            {
                cout<<"Palabra no removida "<<endl;
            }
            else
            {
                cout<<"ok"<<endl;
            }

            if (rename("new.txt", "file.txt") != 0)
            {
                cout <<"File no renombrado"<<endl;

            }
            else
            {
                cout<<"ok"<<endl;
            }
            goto loop;
            break;


        }

    }

    return 0;
}
