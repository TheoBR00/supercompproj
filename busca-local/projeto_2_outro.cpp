#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <random>

using namespace std;

struct graph{
    int id;
    float x;
    float y;
    bool vis;
};

struct ponto{
    int id;
    float x;
    float y;
    //float d;
};

//bool compare( ponto a, ponto b){
	/** to use another attribute for sorting, just replace 'age' with it eg. (a.roll_no < b.roll_no)
	 the return value determines which student will go first in the sorted array **/
//	if(a.d < b.d)
//		return 1;
//	else 
//		return 0;
//}


int main(){

    ofstream myfile;

    unsigned int n;

    float x0;
    float y0;
    float x1;
    float y1;
    
    std::cin >> n;

    float dist;

    std::vector<int>vec_ids;

    int chegou = 0;

    if(n - 1 == 1){
        std::cin >> x1;
        std::cin >> y1;

        dist = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
        return dist;
    }

    bool status = true;

    std::vector<graph> vec_pontos;

    int i = 0;
    int pos = 0;

    for(int r = 0; r < n; r++){
        std::cin >> x0;
        std::cin >> y0;

        graph g;
        g.id = r;
        g.x = x0;
        g.y = y0;
        g.vis = false;

        vec_pontos.push_back(g);

    }

    for(int b = 0; b < n; b++){
        //std::cout << "id: " << vec_pontos[b].id << endl;
    }

    int num = 0;
    int count = 0;
    int sw = 0;

    float d_total = 0.0;

    //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //std::default_random_engine e(seed);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,10);

    float d_a = 10000000.0;

    std::vector<graph> vec;
    

    for(int rodada = 0; rodada < 10; rodada++){
        int sorteia = distribution(generator);
        //std::cout << "random: " << sorteia << endl;
        std::shuffle(vec_pontos.begin(), vec_pontos.end(), default_random_engine(sorteia));
        status = true;

        count = 0;

        chegou = 0;
    
        float d_to = 0;

        for(int contagem = 0; contagem < n; contagem++){
            //std::cout << vec_pontos[contagem].x << " " << vec_pontos[contagem].y << endl;
        }

        while(status){

            if(count == n-1){
                status = false;
            }

            d_to = 0;

            //std::cout << "Reiniciou" << endl;

            for(i = 0; i < n; i++){

                ponto p1;
                p1.x = vec_pontos[i+1].x;
                p1.y = vec_pontos[i+1].y;
                p1.id = vec_pontos[i+1].id;
                
                if(vec_pontos[i].vis == false && i < n-1) {
                    float d_novo = sqrt(pow(vec_pontos[i].x - p1.x, 2) + pow(vec_pontos[i].y - p1.y, 2));
                    d_to += d_novo;
                    //std::cout << "d_novo: " << d_novo << endl;
                    //std::cout << vec_pontos[i].x << vec_pontos[i].y << " " << p1.x << p1.y << endl;
                    //std::cout << "i: " << i << endl;

                    //if(d_novo < d_a){
                    //    d_a = d_novo;
                        //num = i;
                    //}

                }

                if(i == n-1){

                    d_to += sqrt(pow(vec_pontos[i].x - vec_pontos[0].x, 2) + pow(vec_pontos[i].y - vec_pontos[0].y, 2));
                    //std::cout << "i: " << i << endl;
                    //std::cout << "d_to: " << d_to << endl;
                }

                //d_to = d_novo;



            }

            if(d_to <= d_a){
                vec.clear();
                d_a = d_to;
                for(int u = 0; u < n; u++){
                    vec.push_back(vec_pontos[u]);
                }
                //d_total += d_a;
                //std::cout << "d_total: " << d_total << endl;
            }
            
            vec_ids.push_back(vec_pontos[pos].id);



            //vec_pontos[pos].vis = true;

            //if(count == n-1){
            //    swap(vec_pontos[count], vec_pontos[0]);
            //}

            if(count < n-1){
                swap(vec_pontos[count], vec_pontos[count+1]);
            }
            
                

            for(int sw = 0; sw < n; sw++){
                //std::cout << "swap: " << vec_pontos[sw].x << " " << vec_pontos[sw].y << endl;
            }

            std::cerr << "local: "  << d_to << " ";
            for(int erros = 0; erros < n; erros++){
                //std::cout << vec_pontos[erros].x << " " << vec_pontos[erros].y << endl;
                std::cerr << vec_pontos[erros].id << " ";
            }
            std::cerr << endl;

            count++;

            //pos = num;

            //if(count == n){
            //    float d_f = sqrt(pow(vec_pontos[pos].x - vec_pontos[0].x, 2) + pow(vec_pontos[pos].y - vec_pontos[0].y, 2));
            //    std::cout << "d_f: " << d_f << endl;
            //    d_to += d_f;

            //    std::cout << "d: "<< d_to << " " << 0 << endl;

            //    std::cout << endl;

            //    if(chegou == n-1){
            //        std::cout << "Trocou final" << endl;
            //        swap(vec_pontos[chegou], vec_pontos[0]);

            //        for(int posi = 0; posi < n; posi++){
            //            std::cout << "swap: " <<vec_pontos[posi].x << " " << vec_pontos[posi].y << endl;
            //        }

            //        std::cout << "Terminou swap" << endl;

            //        chegou = 0;
            //        sw = 0;
            //        status = false;
            //    }

            //    else{
            //        for(int vef = 0; vef < n; vef++){
            //            vec_pontos[vef].vis = false;
            //        }
            //        if(chegou < n-1){
            //            swap(vec_pontos[chegou], vec_pontos[chegou+1]);
            //        }
                    
            //        std::cout << "Chegou: " << chegou << endl;

            //        for(sw = 0; sw < n; sw++){
            //            std::cout << "swap: " <<vec_pontos[sw].x << " " << vec_pontos[sw].y << endl;
            //        }
            //        pos = 0;
            //        num = 0;

            //    }
                
            //    chegou++;

            //    count = 0;

            //    d_total = 0;

            //    std::vector<int>vec_ids;
                
            //}


            //std::vector<ponto>vec;

        }
    }

    std::cout << d_a << " " << 0 << endl;

    for(int min = 0; min < n; min++){
        std::cout << vec[min].id << " ";
    }
    std::cout << endl;
    
}