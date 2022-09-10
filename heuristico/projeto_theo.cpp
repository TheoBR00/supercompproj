#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

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

    //std::cout << "n: " << n << std::endl;

    //std::cin >> x0;
    //std::cin >> y0;

    //std::cout << "x0: " << x0 << std::endl;
    //std::cout << "y0: " << y0 << std::endl;

    float dist;

    std::vector<ponto>vec;

    std::vector<int>vec_ids;

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

        //std::cout << "Ponto: " << g.x << " " << g.y << std::endl;
    }

    int num = 0;
    int count = 0;

    float d_total = 0.0;

    //myfile.open("out_teste.txt");

    while(status){

        float d_a = 10000000.0;

        for(i = 0; i < n; i++){

            ponto p1;
            p1.x = vec_pontos[i].x;
            p1.y = vec_pontos[i].y;
            p1.id = vec_pontos[i].id;
            
            if(i != pos && vec_pontos[i].vis == false) {
                float d_novo = sqrt(pow(vec_pontos[pos].x - p1.x, 2) + pow(vec_pontos[pos].y - p1.y, 2));
            
            

                //vec.push_back(p1);
                if(d_novo < d_a){
                    d_a = d_novo;
                    num = i;
                }

                //std::cout << "Dist: " << d_novo << std::endl;

                //std::cout << "i: " << p1.id << std::endl;
            }

        }

        if(d_a < 10000000.0){
            d_total += d_a;
        }
        
        //cout << " d_a  "  << d_a << endl;

        //std::cout<< "Ponto: " << vec_pontos[pos].x << " " << vec_pontos[pos].y  << " id: " << vec_pontos[pos].id<< std::endl;
        vec_ids.push_back(vec_pontos[pos].id);



        //std::cout << "num: " << num << std::endl;
        vec_pontos[pos].vis = true;
        count++;

        //std::cout << "Acabou" << std::endl;

        //int menor = 0;
        //float test = 100000.0;
        //for(int b = 0; b < n-1; b++){
        //    if(vec[b].d < test){
        //        menor = vec_pontos[b].id;
        //    }
        //    std::cout << "Acabou 2" << std::endl;
            
        //}
        //std::cout << "menor: " << menor << std::endl;
        //float compare = 0;

        //sort(vec.begin(), vec.end(), compare);

        //for(int dis = 0; dis < n; dis++){
        //    std::cout << "ids: " << vec[dis].id << std::endl;
        //}

        //std::cout << "Acabou 3" << std::endl;

        //std::cout << "Begin: " << vec_pontos.begin() << std::endl;

        //if(pos != n-1){
        //    vec_pontos.erase(vec_pontos.begin());
        //}

        //std::cout << "Acabou 4" << std::endl;

        //pos++;
        pos = num;

        if(count == n){
            float d_f = sqrt(pow(vec_pontos[pos].x - vec_pontos[0].x, 2) + pow(vec_pontos[pos].y - vec_pontos[0].y, 2));
            d_total += d_f;

            //std::cout << "Distancia total: " << d_total << std::endl;



            std::cout << d_total << " " << 0 << endl;

            for(int h = 0; h < n; h++){
                std::cout << vec_ids[h] << " ";
            }
            std::cout << endl;

            //myfile.close();
            //for(int u = 0; u < n; u++){
            //    std::cout << "Ponto: " << vec[u].id << std::endl;
            //}
            status = false;
        }


        std::vector<ponto>vec;

        //std::cout << "pos: " << pos << std::endl;

        
        //status = false;

    }

    
}