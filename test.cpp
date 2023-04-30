#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

const int V=50;
vector<pair<int,int>> adj[V];
vector<vector<int>> dist(V,vector<int>(V));
void floydwarshall(){
    for(int i=0;i<V;i++){
        for(auto adjNode:adj[i]){
            dist[i][adjNode.first] = adjNode.second;
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j){
                dist[i][j]=0;
            }
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != 1e7
                        && dist[i][k] != 1e7))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return;
} 
int main() {
    
    adj[0] = {{22,73},{43,80},{44,72}};
    adj[1] = {{2,2},{3,1},{42,8},{7,5},{44,6},{43,7},{9,4}};
    adj[2] = {{2,2},{5,9},{10,3},{8,14},{9,13}};
    adj[3] = {{4,11},{5,10},{1,1}};
    adj[4] = {{5,12},{3,11},{34,55},{38,54}};
    adj[5] = {{3,10},{4,12},{38,53},{2,9},{10,50},{6,51}};
    adj[6] = {{37,63},{5,51},{11,49},{38,52}};
    adj[7] = {{1,5},{9,18},{44,107}};
    adj[8] = {{2,14},{9,15},{21,16},{17,74},{10,79}};
    adj[9] = {{2,13},{1,4},{7,18},{23,19},{21,17},{8,15}};
    adj[10] = {{2,3},{8,79},{5,50},{11,47},{15,30},{8,79}};
    adj[11] = {{10,47},{6,49},{12,48},{28,94}};
    adj[12] = {{11,48},{28,43},{24,44},{25,97}};
    adj[13] = {{15,32},{28,31},{14,33},{32,93}};
    adj[14] = {{13,33},{29,101},{32,34}};
    adj[15] = {{13,32},{17,29},{10,30}};
    adj[16] = {{17,28},{18,27},{32,92},{33,100}};
    adj[17] = {{16,28},{18,78},{15,29},{8,74},{19,75}};
    adj[18] = {{16,27},{19,26},{17,78},{20,25}};
    adj[19] = {{18,26},{17,75},{20,24},{21,23},{22,76}};
    adj[20] = {{18, 25}, {22, 22}, {19, 24}};
    adj[21] = {{9, 17}, {23, 20}, {22, 77}, {8, 16}, {19, 23}};
    adj[22] = {{19, 76}, {20, 22}, {23, 21}, {21, 77}, {0, 73}};
    adj[23] = {{21, 20}, {22, 21}, {44, 81}, {9, 19}};
    adj[24] = {{25, 45}, {26, 41}, {12, 44}, {29, 42}};
    adj[25] = {{12, 97}, {39, 46}, {40, 102}, {24, 45}};
    adj[26] = {{27, 40}, {24, 41}, {30, 98}};
    adj[27] = {{30, 39}, {26, 40}};
    adj[28] = {{29, 95}, {12, 43}, {11, 94}, {13, 31}};
    adj[29] = {{30, 96}, {32, 38}, {14, 101}, {28, 95}, {24,42}};
    adj[30] = {{29, 96}, {27, 39}, {31, 99}, {26, 98}};
    adj[31] = {{30, 99}, {33, 36}, {32, 37}};
    adj[32] = {{31, 37}, {33, 35}, {29, 38}, {14, 34}, {16, 92}, {13, 93}};
    adj[33] = {{31, 36}, {32, 35}, {16, 100}};
    adj[34] = {{38, 56}, {4, 55}, {45, 87}};
    adj[35] = {{36,58},{37,61},{39,59},{41,89}};
    adj[36] = {{35,58},{39,57},{40,91}};
    adj[37] = {{35,61},{39,60},{38,62},{6,63}};
    adj[38] = {{4,54},{5,53},{6,52},{34,56},{37,62},{41,88},{45,64}};
    adj[39] = {{25,46},{36,57},{35,59},{37,60}};
    adj[40] = {{36,91},{41,90},{25,102}};
    adj[41] = {{35,89},{38,88},{40,90}};
    adj[42] = {{1,8},{45,86},{48,85}};
    adj[43] = {{1,7},{44,71},{0,80},{48,82},{46,69}};
    adj[44] = {{1,6},{7,107},{23,81},{0,72},{43,71}};
    adj[45] = {{38,64},{34,87},{42,86},{48,66},{49,65}};
    adj[46] = {{43,69},{48,70},{47,68}};
    adj[47] = {{46,68},{48,83},{49,67}};
    adj[48] = {{43,82},{46,70},{47,83},{49,84},{45,66},{42,85}};
    adj[49] = {{47,67},{48,84},{45,65}};
    floydwarshall();
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}