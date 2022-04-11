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
};

struct consignment
{
    int pathCode;
    
    bool fragility;
    int itemPrice;
    int itemLoad;

    consignment(int pathcode, bool fragility, int itemPrice, int itemLoad){
        this->pathCode = pathCode;
        this->itemPrice = itemPrice;
        this->fragility = fragility;
        this->itemLoad = itemLoad;
    }
};

nodes **Make_Nodes();
int **EdgeWeight();
bool **DelhiveryGraph();
bool **eKartGraph();
pair<queue<int>, int> Shortest_Path(int **mat, bool **adj, int From, int To);
int cost(int priceprWeight, int totalWeight,bool fragility, int itemPrice, int itemLoad);