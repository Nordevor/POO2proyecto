//
// Created by rumin on 12/12/2020.
//

#ifndef CLIONPROYECT_MENU_H
#define CLIONPROYECT_MENU_H
#include <iostream>
#include <thread>
#include <cstdlib>
using namespace std;


void f2(const string& texto) {
    cout << texto << endl;
}

void hacer_cin(int &input_) {

}
struct Menu {
    int input_Case{};

    void correr_menu()
    {
        system("cls");
        int input =0;

        do {
            system("cls");

            cout << "\n\nMenu de opciones" << endl;
            cout << "1. Personas libres (sin distanciamiento social)" << endl;
            /* Particulas con igual velocidad, todas se mueven. Solo 1 roja al inicio.
             * */
            cout << "2. Distanciamiento social promedio" << endl;
            /*
             * 1/4 de Particulas se mueven (Solo 1 roja al inicio), las otras no se mueven.
             * */
            cout << "3. Distanciamiento social extensivo" << endl;
            /*
             * 12.5% de particulas se mueve(Solo 1 roja al inicio). Las demas no se mueven
             * */
            cout << "4. SALIR" << endl<<endl;

            cout << "Ingrese una opcion : ";

            //system("pause>nul");
            //thread t([&input]{cin>>input;});
            //t.join();
            cin >> input_Case;
        cout<<input_Case<<endl;
        }while (input_Case>4 || 1>input_Case);
        /*switch (input_Case) {
            case 1:
                system("pause>nul");
                break;
            case 2:
                system("pause>nul");
                break;
            case 3:
                system("pause>nul");
                break;
         }*/
   cout<<"flag1"<<endl;
    }

};


#endif //CLIONPROYECT_MENU_H
