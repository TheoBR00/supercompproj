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
};

struct ponto{
    int id;
    float x;
    float y;
    //float d;
};

int contador_num_folhas_possiveis = 0;
float d_min = 100000000000.0;
//int index = 0;

float calcula_city(graph caminho, graph caminho_2){
    float d = 0.0;
    //std::cout << "Tamanho: " << caminho.size() << endl;

    float dx = caminho_2.x - caminho.x;
    float dy = caminho_2.y - caminho.y;

    //for(int u = caminho.size(); u > 0; u--){
    //    d += sqrt(pow(caminho[u].x - caminho[u-1].x, 2) + pow(caminho[u].y - caminho[u-1].y, 2));
    //    std::cout << "d: " << d << endl;
    //}
    //d+= sqrt(pow(caminho[caminho.size()-1].x - caminho[0].x, 2) + pow(caminho[caminho.size()-1].y - caminho[0].y, 2));
    //std::cout << "Fez d" << endl;
    return sqrt(pow(dx, 2) + pow(dy,2));
}

float calcula(vector<graph> caminho){
    float d = 0.0;
    //std::cout << "Tamanho: " << caminho.size() << endl;
    for(long unsigned int u = 0; u < caminho.size()-1; u++){
        //std::cout << "u: " << u << endl;

        d += calcula_city(caminho[u], caminho[u+1]);
        //std::cout << "d: " << d << endl;
    }
    //d+= sqrt(pow(caminho[caminho.size()-1].x - caminho[0].x, 2) + pow(caminho[caminho.size()-1].y - caminho[0].y, 2));
    d += calcula_city(caminho[0], caminho[(caminho.size()-1)]);
    //std::cout << "d_final: " << d << endl;
    return d;
}


vector<graph> recursao(vector<graph> p, vector<graph> way, long long int &num_folhas){

    //if(i < 0){
    //    return 0;
    //}

    //int N = recursao(i-1, d, p, way);

    //int mat[]


        if(p.size() == 0){
            num_folhas++;
            // std::cerr << "num_leaf " << setw(3) << setfill('0') << num_folhas << endl;
            return way;
        }


        //vector<int> vec;        

        //if(way[vezes] != p[vezes].id){
        //for(int c = 0; c < p.size(); c++)
        vector<vector<graph>> mat(p.size());

        //std::cout << "Criou mat" << endl;
            
        for(long unsigned int ct = 0; ct < p.size(); ct++){

            vector<graph> new_way = way;
            vector<graph> new_p = p;


            new_way.push_back(p[ct]);

            new_p.erase(new_p.begin() + ct);

            mat[ct] = recursao(new_p, new_way, num_folhas);

            //std::cout << "Aqui" << endl;
                //dist = dist + sqrt(pow(way[ct].x - p[c].x, 2) + pow(way[ct].y - p[c].y, 2));
                //std::cout << "Fez dist: " << way[ct].x << way[ct].y << " " << p[c].x << p[c].y << endl;
                //ct = c;
        }

        //std::cout << "Aqui 2" << endl;
        //std::cout << "size: " << mat.size() << endl;
        //std::cout << "Leaf: " << num_folhas << endl;
        vector<graph> melhor_cam = mat[0];
        //std::cout << "Aqui 3" << endl;
        d_min = calcula(melhor_cam);
        //std::cout << "Fez melhor_cam" << endl;
        for(long unsigned int melhor = 1; melhor < mat.size(); melhor++){
            float distancia = calcula(mat[melhor]);
            if(distancia < d_min){
                contador_num_folhas_possiveis++;
                melhor_cam = mat[melhor];
                //std::cerr << "num_leaf XXX" << endl;
                //std::cerr << "num_leaf " << setw(3) << setfill('0') << contador_num_folhas_possiveis << endl;
                d_min = distancia;
            }
        }
            
            //if(visitado){
            //    continue;
            //}
            //recursao(i-1,p, way);

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
        return melhor_cam;


}

    //else{
    //    vector<int> way;
    //    return N;
    //}
    

    //vef = true;



int main(){

    int n;
    //unsigned int limite;
    float x0;
    float y0;

    vector<graph> p;
    vector<float> v;
    vector<graph> way;

    long long int folha = 0;

    std::cin >> n;

    //std::cout << "n: " << n << endl;

    for(int i = 0; i < n; i++){
        std::cin >> x0;
        std::cin >> y0;

        //std::cout << "x: " << x0 << " " << "y: " << y0 << endl;

        graph g;
        g.id = i;
        g.x = x0;
        g.y = y0;        

        p.push_back(g);
    }    

    vector<graph> res = recursao(p, way, folha);
    float di = calcula(res);

    std::cerr << "num_leafs " << folha << endl;

    std::cout << di << " " << 1 << endl;

    for(int cams = 0; cams < n; cams++){
        std::cout << res[cams].id << " ";
    }
    std::cout << endl;

    
}