#include <bits/stdc++.h>
using namespace std;

struct nodes
{
    int code;
    string name;
    bool delhivery;
    bool ekart;
    nodes(int code, string name, bool delhivery, bool ekart)
    {
        this->code = code;
        this->name = name;
        this->delhivery = delhivery;
        this->ekart = ekart;
    }
} * array_of_cities[15];

nodes **Make_Nodes()
{
    array_of_cities[0] = new nodes(0, "New Delhi", true, true);
    array_of_cities[1] = new nodes(1, "Jammu", true, true);
    array_of_cities[2] = new nodes(2, "Shimla", true, false);
    array_of_cities[3] = new nodes(3, "Chandigarh", false, true);
    array_of_cities[4] = new nodes(4, "Lucknow", true, true);
    array_of_cities[5] = new nodes(5, "Patna", true, false);
    array_of_cities[6] = new nodes(6, "Kolkata", false, true);
    array_of_cities[7] = new nodes(7, "Jaipur", true, false);
    array_of_cities[8] = new nodes(8, "Guwahati", true, true);
    array_of_cities[9] = new nodes(9, "Bhubaneshwar", true, false);
    array_of_cities[10] = new nodes(10, "Mumbai", true, true);
    array_of_cities[11] = new nodes(11, "Bengaluru", true, true);
    array_of_cities[12] = new nodes(12, "Chennai", true, true);
    array_of_cities[13] = new nodes(13, "Hyderabad", false, true);
    array_of_cities[14] = new nodes(14, "Bhopal", false, true);
    return array_of_cities;
}

int** EdgeWeight(){
    int **WeightMatrix = new int*[15];
    for(int i=0; i<15; i++){
        WeightMatrix[i] = new int[15];
    }
    int Delhi[] = {0, 6, 4, 3, 5, 10, 15, 3, 19, 17, 14, 21, 22, 16, 8};
    int Jammu[] = {6, 0, 4, 4, 11, 16, 21, 9, 25, 23, 19, 28, 28, 22, 14};
    int Shimla[] = {4, 4, 0, 1, 9, 14, 19, 6, 23, 21, 17, 25, 26, 19, 11};
    int C_garh[] = {3, 4, 1, 0, 8, 14, 18, 5, 22, 20, 17, 24, 24, 18, 10};
    int Lucknow[] = {5, 11, 9, 8, 0, 5, 10, 6, 14, 12, 14, 19, 20, 13, 6};
    int Patna[] = {10, 16, 14, 14, 5, 0, 5, 11, 9, 8, 17, 21, 21, 15, 10};
    int Kolkata[] = {15, 21, 19, 18, 10, 5, 0, 16, 10, 4, 19, 19, 17, 15, 14};
    int Jaipur[] = {3, 9, 6, 5, 6, 11, 16, 0, 19, 18, 11, 19, 21, 14, 6};
    int Guwahati[] = {19, 25, 23, 22, 14, 9, 10, 19, 0, 14, 28, 30, 26, 24, 19};
    int Bbaneswar[] = {17, 23, 21, 20, 12, 8, 4, 18, 14, 0, 18, 14, 12, 10, 12};
    int Mumbai[] = {14, 19, 17, 17, 14, 17, 19, 11, 28, 18, 0, 10, 13, 7, 8};
    int Bangalore[] = {21, 28, 25, 24, 19, 21, 19, 19, 30, 14, 10, 0, 3, 6, 14};
    int Chennai[] = {22, 28, 26, 24, 20, 21, 17, 21, 26, 12, 13, 3, 0, 6, 15};
    int Hyderabad[] = {16, 22, 19, 18, 13, 15, 15, 14, 24, 10, 7, 6, 6, 0, 9};
    int Bhopal[] = {8, 14, 11, 10, 6, 10, 14, 6, 19, 12, 8, 14, 15, 9, 0};

    for(int i=0; i<15; i++){
        WeightMatrix[0][i] = Delhi[i];
        WeightMatrix[1][i] = Jammu[i];
        WeightMatrix[2][i] = Shimla[i];
        WeightMatrix[3][i] = C_garh[i];
        WeightMatrix[4][i] = Lucknow[i];
        WeightMatrix[5][i] = Patna[i];
        WeightMatrix[6][i] = Kolkata[i];
        WeightMatrix[7][i] = Jaipur[i];
        WeightMatrix[8][i] = Guwahati[i];
        WeightMatrix[9][i] = Bbaneswar[i];
        WeightMatrix[10][i] = Mumbai[i];
        WeightMatrix[11][i] = Bangalore[i];
        WeightMatrix[12][i] = Chennai[i];
        WeightMatrix[13][i] = Hyderabad[i];
        WeightMatrix[14][i] = Bhopal[i];
    }

    return WeightMatrix;
}

bool** DelhiveryGraph(){
    bool** D_AdjMatrix = new bool*[15];
    for(int i=0; i<15; i++){
        D_AdjMatrix[i] = new bool[15];
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            D_AdjMatrix[i][j] = false;
        }
    }
    vector<pair<int,int>> edges = {make_pair(1,2), make_pair(0,2), make_pair(0,7), make_pair(4,0), make_pair(4,5), make_pair(5,8), make_pair(5,9), make_pair(5,12), make_pair(9,12), make_pair(11,10), make_pair(11, 12), make_pair(7, 10)};

    for(int i=0; i<edges.size(); i++){
        pair<int,int> temp = edges[i];
        D_AdjMatrix[temp.first][temp.second] = true;
        D_AdjMatrix[temp.second][temp.first] = true;
    }
    return D_AdjMatrix;
}

bool** eKartGraph(){
    bool** E_AdjMatrix = new bool*[15];
    for(int i=0; i<15; i++){
        E_AdjMatrix[i] = new bool[15];
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            E_AdjMatrix[i][j] = false;
        }
    }
    vector<pair<int,int>> edges = {make_pair(0,4), make_pair(0,14), make_pair(0,1), make_pair(4,14), make_pair(4,6), make_pair(4,8), make_pair(3,1), make_pair(0,3), make_pair(14,13), make_pair(14,10), make_pair(11, 13), make_pair(11, 10), make_pair(11,12)};

    for(int i=0; i<edges.size(); i++){
        pair<int,int> temp = edges[i];
        E_AdjMatrix[temp.first][temp.second] = true;
        E_AdjMatrix[temp.second][temp.first] = true;
    }
    return E_AdjMatrix;
}

int main(){
    int** EdgeWeights = EdgeWeight();
    nodes** Cities = Make_Nodes();
    for(int i=0; i<15; i++){
        cout<<Cities[i]->name<<" "<<Cities[i]->code<<" | ";
        for(int j=0; j<15; j++){
            cout<<EdgeWeights[i][j]<<" | ";
        }
        cout<<endl<<"______________________________________________________________________________________________"<<endl;
    }
    return 0; 
}