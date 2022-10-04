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
    int x;
    int y;
    bool vis = false;
};

struct ponto{
    int id;
    float x;
    float y;
    //float d;
};

int d_min = 10000000;
//int index = 0;


int recursao(int i, int c, int ct, vector<graph> p, vector<graph> way, int vezes, bool visitado, int dist, bool vef){

    if(i < 0){
        return 0;
    }

    //int N = recursao(i-1, d, p, way);

    //int mat[]

    else{
        if(i >= 0 && vef == false){

            int size = p.size();
            int size_way = way.size();
            std::cout << "size_way: " << size_way << endl;
            std::cout << "size: " << size << endl;

            //int dist = 0;

            if(c == size){
                std::cout << "Aqui" << endl;
                std::cout << "Aqui dist: " << dist << endl;
                std::cout << "c: " << c << endl;
                c--;
                i = 0;
                vef = true;
                return 0;
            }
            std::cout << "Aqui 2" << endl;



            //vector<int> vec;        

            //if(way[vezes] != p[vezes].id){
            //for(int c = 0; c < p.size(); c++)
            visitado = false;
            for(ct; ct < way.size(); ct++){
                for(int z = 0; z < way.size(); z++){
                    std::cout << "way[p] = " << way[z].id << " ";
                }
                std::cout << endl;
                if(way[ct].id == p[c].id){
                    //std::cout << "Pontos: " << way[ct].x << way[ct].y << " " << p[c].x << p[c].y << endl;
                    //way[ct].vis = true;
                    visitado = true;
                    //way[ct].vis = true;
                    //p[c].vis = true;
                    //std::cout << "visitado = true" << endl;
                    continue;
                }
                else{
                    if(way[ct].vis == true && p[c].vis == true){
                        visitado = true;
                        continue;
                    }
                }

                dist = dist + sqrt(pow(way[ct].x - p[c].x, 2) + pow(way[ct].y - p[c].y, 2));
                std::cout << "Fez dist: " << way[ct].x << way[ct].y << " " << p[c].x << p[c].y << endl;
                ct = c;

                way[ct].vis = true;
                p[c].vis = true;
                break;
            }
            
            //if(visitado){
            //    continue;
            //}
            
            std::cout << "Ponto: " << p[c].x << " " << p[c].y << endl;
            way.push_back(p[c]);
            std::cout << "Recursao" << endl;
            std::cout << "dist: " << dist << endl;
            std::cout << "d_min: " << d_min << endl;
            if(dist < d_min){
                d_min = dist;
                std::cout << "Fez d_min" << endl;
            }
            recursao(i-1, c+1, ct, p, way, vezes+1, visitado, dist, vef);

                //if(way[c].id != p[vezes+1].id && vezes < size-1){
                //    dist = sqrt(pow(way[c].x - p[vezes+1].x, 2) + pow(p[vezes].y - p[vezes+1].y, 2));
                //    std::cout << "Fez dist: " << p[vezes].x << p[vezes].y << " " << p[vezes+1].x << p[vezes+1].y << endl;
                //    break;
                //}
            
        
            
            //}

            

            //std::cout << "vezes: " << vezes << endl;
            
            
            //std::cout << "b" << endl;
            //std::cout << "d: " << d << endl;

            //std::cout << "index: " << index << endl;

            //if(c == size-1){
                //vector<int> way;
            //    std::cout << "Reiniciou vetor" << endl;
            //    d = 0;
                //vezes = 0;
            //    return d_min;
            //}
            
            
        
        

        //return min(S);


        }
    }

    //else{
    //    vector<int> way;
    //    return N;
    //}
    return i;

    //vef = true;

return dist;}


int main(){

    unsigned int n;
    //unsigned int limite;
    unsigned int x0;
    unsigned int y0;

    vector<graph> p;
    vector<float> v;
    vector<graph> way;

    int index = 0;

    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> x0;
        std::cin >> y0;

        graph g;
        g.id = i;
        g.x = x0;
        g.y = y0;        

        p.push_back(g);
    }

    int fact = n;

    for(int j = n-1; j > 0; j--){
        fact *= j;
    }

    way.push_back(p[0]);

    bool visit = false;

    int res = recursao(10, 1, 0, p, way, index, visit, 0, false);
    std::cout << fact << endl;
}