#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "Menu.h"
#include "CollisionSystem.h"
#include <stdio.h>
#include <string>
#include <ctime>
using namespace sf;
using namespace std;
std::vector<particle*> particles;
template<typename Numeric, typename Generator = std::mt19937>
Numeric random(Numeric from, Numeric to)
{
    thread_local static Generator gen(std::random_device{}());

    using dist_type = typename std::conditional
            <
                    std::is_integral<Numeric>::value
                    , std::uniform_int_distribution<Numeric>
                    , std::uniform_real_distribution<Numeric>
            >::type;

    thread_local static dist_type dist;

    return dist(gen, typename dist_type::param_type{from, to});
}
void case1(){
    //freopen("D:/CLIONPROYECT/input/case1.txt", "r", stdin);
    int cant_particulas; //std::cin >> n;
      double rx, ry, vx, vy, r, mass; int re, ge, be;
       // std::cin >> rx >> ry >> vx >> vy >> r >>  mass >> re >> ge >> be;
        //r = 0.02;
        //std::cout << rx <<" "<< ry <<" "<< vx <<" "<< vy <<" "<<r <<" "<<mass <<" "<< re <<" "<< ge <<" "<< be<<endl;
        //particles.push_back(new particle(rx,ry,vx,vy,r,mass,re,ge,be));

    cant_particulas = 100;
    //particles.push_back(new particle(rx,ry,vx,vy,r,mass,re,ge,be));
    cout<<"cant_particulas:"<<cant_particulas<<endl;
    //particula infectada
    auto a = new particle(0.4932, 0.556 ,0.005 ,0.001, 0.01, 0.0025 ,250 ,0 ,0);
    a->set_infected(true);
    //CollisionSystem::infeccion(a);
    cout<<"creacion"<<endl;

    particles.push_back(a);
    for(int i = 0 ; i < cant_particulas - 1; i++){
        particles.push_back(new particle(random<double>(0, 2)/3,
                random<double>(0, 3)/3 ,random<double>(0.001, 0.056)/2 ,
                        random<double>(0.001, 0.0056)/2, 0.01, 0.0025 ,0 ,
                                0 ,250));
        cout<<"creacion"<<endl;
    }
}
void case2(){

    //int radio_general = ;
    //int masa_de_estaticos = ;
   // int ;

    int cant_particulas; //std::cin >> n;
    //double rx, ry, vx, vy, r, mass; int re, ge, be;

    cant_particulas = 100;

    int particulas_libres = cant_particulas/4;

    cout<<"cant_particulas:"<<cant_particulas<<endl;
    cout<<"cant_libres:"<<particulas_libres<<endl;

    //particula infectada
    auto a = new particle(0.4932, 0.556 ,0.005 ,0.001, 0.01, 0.0025 ,250 ,0 ,0) ;
    a->set_infected(true );
    //cout<<"creacion"<<endl;
    particles.push_back(a);

    //25 == 100/4
    cout<<"particulas_libres: "<<particulas_libres<<endl;
    for(int i = 0 ; i < particulas_libres-1; i++){
        particles.push_back(new particle(random<double>(0.1, 1),
                                         random<double>(0, 1) ,random<double>(0.001, 0.056)/7,
                                         random<double>(0.001, 0.0056)/7, 0.01, 0.0025 ,0 ,
                                         0 ,250));
        // cout<<"creacion"<<endl;
    }


    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){
        particles.push_back(new particle(random<double>(0, 0.3),
                                         random<double>(0, 1) ,0 ,
                                         0, 0.01, 30 ,0 ,
                                         0 ,250));
        //cout<<"creacion"<<endl;
    }

    cout<<"particulas_libres: "<<particulas_libres<<endl;

    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){
        particles.push_back(new particle(random<double>(0.3, 0.6),
                                         random<double>(0, 1) ,0 ,
                                         0, 0.01, 30 ,0 ,
                                         0 ,250));
    }


    for(int i = 0 ; i < ((cant_particulas-particulas_libres)/3 ); i++){

        //2.3/3 = 0.766  <->  3/3 = 1
        particles.push_back(new particle(random<double>(0.7, 1),
                                         random<double>(0, 1) ,0 ,
                                         0, 0.01, 30 ,0 ,
                                         0 ,250));

    }


    }


void case3(){
    srand(time(nullptr));

    int cant_particulas; //std::cin >> n;
    double rx, ry, vx, vy, r, mass; int re, ge, be;
    cant_particulas = 100;
    int particulas_libres = cant_particulas/8;
    cout<<"cant_particulas:"<<cant_particulas<<endl;
    cout<<"cant_libres:"<<particulas_libres<<endl;

    //particula infectada
    auto a = new particle(0.4932, 0.556 ,0.005 ,0.001, 0.01, 0.0025 ,250 ,0 ,0) ;
    a->set_infected(true);
    cout<<"creacion"<<endl;
    particles.push_back(a);

    for(int i = 0 ; i < particulas_libres - 1; i++){
        particles.push_back(new particle(random<double>(0.1, 0.9)/3,
                                         random<double>(0.1, 0.56)/3 ,random<double>(0.001, 0.056)/2 ,
                                         random<double>(0.001, 0.0056)/2, 0.01, 0.0025 ,0 ,
                                         0 ,250));
        cout<<"creacion"<<endl;
    }

    for(int i = 0 ; i < (cant_particulas-particulas_libres) - 1; i++){
        particles.push_back(new particle(random<double>(0.1, 0.9)/3,
                                         random<double>(0.1, 0.56)/3 ,0 ,
                                         0, 0.01, 1 ,0 ,
                                         0 ,250));
        cout<<"creacion"<<endl;
    }


}




int main() {
    Menu menu;
    menu.correr_menu();

    if(menu.input_Case == 1){
        cout<<"case1();"<<endl;
        thread t(case1);
        t.join();
    }else if(menu.input_Case == 2 ){
        cout<<"case2();"<<endl;
        thread t(case2);
        t.join();
    }else if (menu.input_Case == 3){
        cout<<"case3();"<<endl;
        thread t(case3);
        t.join();
    }else{
        return 0;
    }

    cout<<"particles.size(): "<<particles.size()<<endl;
    RenderWindow* window = new RenderWindow (VideoMode(1000,1000), "POO2");
    window->setFramerateLimit(144);

    cout<<"window->getSize(): "<<window->getSize().x<<endl;
    cout<<"window->getSize(): "<<window->getSize().y<<endl;


    CollisionSystem test(2000, particles);

    while (window->isOpen()){
        test.simulate(2000, window);

        sf::Event event;
        while (window->pollEvent(event))
        {
        if (event.type == sf::Event::Closed)
            window->close();
        }
    }


    return 0;
}
