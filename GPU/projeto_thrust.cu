#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <thrust/random.h>
#include <thrust/shuffle.h>
#include <thrust/fill.h>
#include <thrust/execution_policy.h>

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

struct dist_calc
{
  graph *vetor;
  dist_calc(graph *vetor_) : vetor(vetor_) {};
  __device__
  float operator()(int ind){
    return sqrt(pow(static_cast<graph>(vetor[ind]).x - vetor[ind+1].x, 2) + pow(static_cast<graph>(vetor[ind]).y - vetor[ind+1].y, 2));
  }
};


struct swap_vec
{
  graph *vetor;
  unsigned int n;
  swap_vec(graph *vetor_n, unsigned int n) : vetor(vetor_n), n(n) {};
  __device__
  float operator()(int posi){

    float dist = 10000000;

    float d;

    //return swap(static_cast<graph>(vetor[posi]), static_cast<graph>(vetor[posi+1]));



    for(int ct_2 = 0; ct_2 < n; ct_2++){

      if(ct_2 == n-1){
        d = sqrt(pow(vetor[ct_2].x - vetor[0].x, 2) + pow(vetor[ct_2].y - vetor[0].y, 2));
      }

      else{
        d = sqrt(pow(vetor[ct_2].x - vetor[ct_2+1].x, 2) + pow(vetor[ct_2].y - vetor[ct_2+1].y, 2));
      }

      if(d < dist){
        dist = d;

        graph p1 = vetor[ct_2];
        graph p2 = vetor[ct_2+1];
        vetor[ct_2] = p2;
        vetor[ct_2+1] = p1;
        //std::cout << "Menor dist = " << dist << std::endl;
      }

    }

    return dist;

  }
};

//float __device__ dist_calc(int ind){

//  return sqrt(pow(raw_cast<graph>(p1).x - p2.x, 2) + pow(raw_cast<graph>(p1).y - p2.y, 2));

//}


int main(){

    std::cout << "Main" << std::endl;

    ofstream myfile;

    std::cout << "ofstream myfile" << std::endl;

    unsigned int n;



    float x0;
    float y0;
    //float x1;
    //float y1;

    std::cin >> n;

    std::cout << "Carregou n: " << n << std::endl;

    //float dist;

    //std::vector<int>vec_ids;

    thrust::device_vector<int> vec_ids(n);

    std::cout << "Criou vec_ids" << std::endl;

    int chegou = 0;

    bool status = true;

    thrust::device_vector<graph> vec_pontos(n);

    int i = 0;
    int pos = 0;

    thrust::device_vector<graph> array[10*n];

    thrust::device_vector<float> array_float(10*n);

    for(int r = 0; r < n; r++){
        std::cin >> x0;
        std::cin >> y0;

        graph g;
        g.id = r;
        g.x = x0;
        g.y = y0;
        g.vis = false;

        vec_pontos[r] = g;

    }

    for(int b = 0; b < n; b++){
        //std::cout << "id: " << vec_pontos[b].id << endl;
    }

    int num = 0;
    int count = 0;
    int sw = 0;

    float d_total = 0.0;

    //std::default_random_engine e(seed);
    thrust::random::default_random_engine generator;
    thrust::uniform_int_distribution<int> distribution(1,10);

    float d_a = 10000000.0;


    thrust::device_vector<graph> vec(n);

    //std::vector<graph> vec;


    for(int rodada = 0; rodada < 10*n; rodada++){
        auto sorteia = distribution(generator);
        std::cout << "random: " << sorteia << endl;

        std::cout << "Antes do shuffle" << std::endl;

        for(int vetores = 0; vetores < 10*n; vetores++){

          array[vetores] = thrust::device_vector<graph>(n);

          for(int sr = 0; sr < n; sr++){
            array[vetores][sr] = vec_pontos[sr];
          }

          thrust::shuffle(thrust::device, array[vetores].begin(), array[vetores].end(), generator);

          thrust::shuffle(thrust::device, vec_pontos.begin(), vec_pontos.end(), generator);

        }

        //for(int lm = 0; lm < 10*n; lm++){
        //  std::cout << " " << std::endl;
        //  for(int k = 0; k < n; k++){
        //    std::cout << "VETORES[lm" << "] " << "= " << static_cast<graph>(array[lm][k]).id << std::endl;

        //    }
        //  }

          std::cout << " " << std::endl;

        //thrust::shuffle(thrust::device, vec_pontos.begin(), vec_pontos.end(), generator);

        std::cout << "Depois do shuffle" << std::endl;

        //std::shuffle(vec_pontos.begin(), vec_pontos.end(), default_random_engine(sorteia));
        status = true;

        count = 0;

        chegou = 0;

        float d_to = 0;

        while(status){

            if(count == n-1){
                status = false;
            }

            d_to = 0;



            thrust::device_vector<float> vec_dists(n);

            for(int u = 0; u < n; u++){
              //vec.push_back(vec_pontos[u]);
              vec[u] = vec_pontos[u];
            }

            count++;
        }

            thrust::counting_iterator<int> iterador(0);

            thrust::device_vector<float>::iterator ar(array_float.begin());

                //auto ar = array_float.begin();

            for(int rod = 0; rod < n; rod++){
              std::cout<< "array[x] = " << static_cast<graph>(array[rodada][rod]).x << " " << "array[y] = " << static_cast<graph>(array[rodada][rod]).y << std::endl;
            }

            auto swa = swap_vec(thrust::raw_pointer_cast(array[rodada].data()), n);

            thrust::transform(iterador, iterador+(n-1), ar, swa);

            //}

            std::cerr << "local: "  << d_to << " ";
            for(int erros = 0; erros < n; erros++){
                //std::cout << vec_pontos[erros].x << " " << vec_pontos[erros].y << endl;
                std::cerr << static_cast<graph>(vec_pontos[erros]).id << " ";
            }
            std::cerr << endl;

            count++;

      }


        for(int rs = 0; rs < 10*n; rs++){
          std::cout << "Menor dist = " << static_cast<float>(array_float[rs]) << std::endl;
        }

        std::cout << d_a << " " << 0 << endl;

        for(int min = 0; min < n; min++){
            std::cout << static_cast<graph>(vec[min]).id << " ";
        }
        std::cout << endl;

}
                                                                                        