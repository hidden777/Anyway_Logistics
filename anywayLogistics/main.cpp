#include <bits/stdc++.h>
#include "headerfile.h"
using namespace std;
nodes **Array;

class later
{
public:
    template <class callable, class... arguments>
    later(int after, bool async, callable&& f, arguments&&... args)
    {
        std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

        if (async)
        {
            std::thread([after, task]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(after));
                task();
            }).detach();
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(after));
            task();
        }
    }

};

void transit(void)
{
    return;
}

void traverse(queue<int> path, int from, int to,int cost, int** weight_mat){
    if(cost == INT_MAX){
        cout<<"Sorry you chose the wrong path!";
        return;
    }
    else{
        path.pop();
        int i = from;
        int j = 0;
        while(!path.empty()){
            j = path.front();
            cout<<"In transition...."<<endl;
            cout<<"Dispatched from "<<Array[i]->name<<endl;
            later later_wait(weight_mat[i][j]*3000, false, &transit);
            cout<<"Recieved at "<<Array[j]->name<<endl;
            i = path.front();
            path.pop();
        }
        return;
    }
}

void Display_Path(queue<int> Traverse, int To)
{
    while (!Traverse.empty())
    {
        if (Traverse.front() == To)
        {
            cout << Array[Traverse.front()]->name;
            Traverse.pop();
        }
        else
        {
            cout << Array[Traverse.front()]->name << "->";
            Traverse.pop();
        }
    }
    cout << endl;
}
int main()
{
    system("cls");
    Array = Make_Nodes();
    cout<<"-----------------------Welcome to AnyWay Logistics-------------------"<<endl<<endl;
    cout<<"We have two operators right now: Delhivery and eKart"<<endl;
    cout<<"From the given cities and their codes, choose two and we'll help you with the transition!"<<endl<<endl;
    for (int i = 0; i < 15; i++)
    {
        cout << Array[i]->code << "-" << Array[i]->name<<" ";
        i++;
        cout << Array[i]->code << "-" << Array[i]->name<<" ";
        i++;
        cout << Array[i]->code << "-" << Array[i]->name<<" ";
        i++;
        cout << Array[i]->code << "-" << Array[i]->name<<" ";
        i++;
        cout << Array[i]->code << "-" << Array[i]->name<<" ";
        cout << endl;
    }
    cout<<endl;
    int From, To;
    cout << "Enter the starting city: ";
    cin >> From;
    cout << "Enter the final city: ";
    cin >> To;
    pair<queue<int>, int> Path1;
    Path1.second = INT_MAX;
    pair<queue<int>, int> Path2;
    Path2.second = INT_MAX;
    queue<int> Traverse;
    int **Weight_Mat = EdgeWeight();
    bool **Delhivery_Mat = DelhiveryGraph();
    bool **eKart_Mat = eKartGraph();
    // for(int i=0; i<15; i++){
    //     cout<<Array[i]->code<<" "<<Array[i]->name<<" | ";
    //     for(int j=0; j<15; j++){
    //         cout<<Delhivery_Mat[i][j]<<" | ";
    //     }
    //     cout<<endl<<"________________________________"<<endl;
    // }
    if (Array[From]->delhivery && Array[From]->ekart)
    {
        if (Array[To]->delhivery && Array[To]->ekart)
        {
            Path1 = Shortest_Path(Weight_Mat, Delhivery_Mat, From, To);
            if (Path1.second == INT_MAX)
            {
                cout << "Sorry! Unfortunately there is no path.";
                goto ab;
            }
            cout << "We have two paths.\n";
            cout << "First path is through Delhivery: ";
            Traverse = Path1.first;
            Display_Path(Traverse, To);
            cout << "Distance is: " << Path1.second*100 <<" Path Code = 1 "<<"Price per 100 km = 10"<< "\n";
        ab:
            Path2 = Shortest_Path(Weight_Mat, eKart_Mat, From, To);
            if (Path2.second == INT_MAX)
            {
                cout << "Sorry! Unfortunately there is no path.";
                return 0;
            }
            cout << "Second path is through eKart: ";
            Traverse = Path2.first;
            Display_Path(Traverse, To);
            cout << "Distance is: " << Path2.second*100 <<" Path Code = 2 "<<"Price per 100 km = 12"<< "\n";
        }
        else if (Array[To]->delhivery || Array[To]->ekart)
        {
            if (Array[To]->delhivery)
            {
                Path1 = Shortest_Path(Weight_Mat, Delhivery_Mat, From, To);
                if (Path1.second == INT_MAX)
                {
                    cout << "Sorry! Unfortunately there is no path.";
                    return 0;
                }
                cout << "We have one path through Delhivery: ";
                Traverse = Path1.first;
                Display_Path(Traverse, To);
                cout << "Distance is: " << Path1.second*100 <<" Path Code = 1 "<<"Price per 100 km = 10"<< "\n";
            }
            else
            {
                Path2 = Shortest_Path(Weight_Mat, eKart_Mat, From, To);
                if (Path2.second == INT_MAX)
                {
                    cout << "Sorry! Unfortunately there is no path.";
                    return 0;
                }
                cout << "We have one path through eKart: ";
                Traverse = Path2.first;
                Display_Path(Traverse, To);
                cout << "Distance is: " << Path2.second*100 <<" Path Code = 2 "<<"Price per 100 km = 12"<< "\n";
            }
        }
    }
    else if (Array[From]->delhivery || Array[From]->ekart)
    {
        if (Array[To]->delhivery && Array[To]->ekart)
        {
            if (Array[From]->delhivery)
            {
                Path1 = Shortest_Path(Weight_Mat, Delhivery_Mat, From, To);
                if (Path1.second == INT_MAX)
                {
                    cout << "Sorry! Unfortunately there is no path.";
                    return 0;
                }
                cout << "We have one path through Delhivery: ";
                Traverse = Path1.first;
                Display_Path(Traverse, To);
                cout << "Distance is: " << Path1.second*100 <<" Path Code = 1 "<<"Price per 100 km = 10"<< "\n";
            }
            else
            {
                Path2 = Shortest_Path(Weight_Mat, eKart_Mat, From, To);
                if (Path2.second == INT_MAX)
                {
                    cout << "Sorry! Unfortunately there is no path.";
                    return 0;
                }
                cout << "We have one path through eKart: ";
                Traverse = Path2.first;
                Display_Path(Traverse, To);
                cout << "Distance is: " << Path2.second*100 <<" Path Code = 2 "<<"Price per 100 km = 12"<< "\n";
            }
        }
        else if (Array[To]->delhivery || Array[To]->ekart)
        {
            if (Array[From]->delhivery && Array[To]->delhivery)
            {
                Path1 = Shortest_Path(Weight_Mat, Delhivery_Mat, From, To);
                if (Path1.second == INT_MAX)
                {
                    cout << "Sorry! Unfortunately there is no path.";
                    return 0;
                }
                cout << "We have one path through Delhivery: ";
                Traverse = Path1.first;
                Display_Path(Traverse, To);
                cout << "Distance is: " << Path1.second*100 <<" Path Code = 1 "<<"Price per 100 km = 10"<< "\n";
            }
            else if (Array[From]->ekart && Array[To]->ekart)
            {
                Path2 = Shortest_Path(Weight_Mat, eKart_Mat, From, To);
                if (Path2.second == INT_MAX)
                {
                    cout << "Sorry! Unfortunately there is no path.";
                    return 0;
                }
                cout << "We have one path through eKart: ";
                Traverse = Path2.first;
                Display_Path(Traverse, To);
                cout << "Distance is: " << Path2.second*100 <<" Path Code = 2 "<<"Price per 100 km = 12"<< "\n";
            }
            else
            {
                cout << "Sorry! Unfortunately there is no path."<<endl;
            }
        }
    }
    cout<<endl<<"Would you like to continue?(1/0) ";
    bool choice;
    cin>>choice;
    
    if(choice){
        cout<<"Enter your consignment details:"<<endl;
        int pathCode;
        if(Path2.second != INT_MAX && Path1.second != INT_MAX){
            cout<<"Select the path chosen: ";
            cin>>pathCode;
        }
        else if(Path2.second != INT_MAX){
            pathCode = 2;
        }
        else if(Path1.second != INT_MAX){
            pathCode = 1;
        }
        else return 0;
        bool fragility;
        cout<<"Is your item fragile?(1/0) ";
        cin>>fragility;
        int itemPrc;
        cout<<"Enter your item value: ";
        cin>>itemPrc;
        int itemWgt;
        cout<<"Enter your item weight: ";
        cin>>itemWgt;
        consignment CurrentC(pathCode, fragility, itemPrc, itemWgt);
        if(pathCode == 1){
            cout<<endl<<"You have to pay Rs."<<cost(10, Path1.second,fragility, itemPrc, itemWgt)<<endl;
            cout<<"Pay through UPI at: anyway@ybl"<<endl;
            later later_wait(5000, false, &transit);
            traverse(Path1.first, From, To,Path1.second, Weight_Mat);
            cout<<"Thank You for using our service!"<<endl;
        }
        else{
            cout<<endl<<"You have to pay Rs."<<cost(12, Path2.second, fragility, itemPrc, itemWgt)<<endl;
            cout<<"Pay through UPI at: anyway@ybl"<<endl;
            later later_wait(5000, false, &transit);
            traverse(Path2.first, From, To,Path2.second, Weight_Mat);
            cout<<"Thank You for using our service!"<<endl;
        }

    }
    else cout<<"Thank you, looking forward to help you next time!"<<endl;
    return 0;
}