#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000;

void Dijkstra(int option, int n, vector<vector<pair<int, double>>> g, int v_start, int v_end, double ras_gas, double gas_cost, double car_speed){
    vector <double> d(n);
    vector <int> p(n);
    d.assign(d.size(), Inf);
    p.assign(p.size(), 0);
    d[v_start] = 0;
    priority_queue <pair<double, int>> q;
    q.push(make_pair(0, v_start));
    while (!q.empty()) {
        double len = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (len > d[v]) continue;
        for (int i = 0; i < n; i++) {
            double length;
            if(option==1) length = g[v][i].first;
            if(option==2) length = g[v][i].first/g[v][i].second;
            if(option==3) length = g[v][i].first/g[v][i].second*gas_cost*ras_gas;
            if (d[i] > d[v] + length && length > 0) {
                d[i] = d[v] + length;
                q.push(make_pair(-d[i], i));
                p[i] = v;
            }
        }
    }
    if(d[v_end]==Inf){
        cout<<endl<<"False. Way from the vertex "<<v_start+1<<" to the vertex "<<v_end+1<<" does not exist!\n";
    }
    else{
        cout<<endl<<"Way from the vertex "<<v_start+1<<" to the vertex "<<v_end+1<<" equals: ";
        if(option==1) cout<<d[v_end]<<" kilometrs.";
        if(option==2) cout<<d[v_end]/car_speed<<" hours.";
        if(option==3) cout<<d[v_end]<<" hryvnias.";
        cout<<"\nWay from the vertex "<<v_start+1<<" to the vertex "<<v_end+1<<": ";
        vector<int> path;
        for (int v=v_end; v!=v_start; v=p[v]){
        	path.push_back (v);
        }
        path.push_back(v_start);
        reverse(path.begin(), path.end());
        for (int i=0; i<path.size(); i++){
        	cout<<path[i]+1<<" ";
        }
    }
}

int main(){
    cout<<"Dijkstra's algorithm.";
    int n, v_start, v_end;
    cout<<"\nEnter number of vertices: ";
    cin >> n;
    cout<<"\nEnter Adjacency Matrix: \n";
    vector<vector<pair<int, double>>> g;
    for(int i = 0; i < n; i++){
        double g1, k1;
        vector<pair<int, double>> g_halp;
        for (int j = 0; j < n; j++){
            cin >> g1 >> k1;
            g_halp.push_back(make_pair(g1, k1));
        }
        g.push_back(g_halp);
    }
    double ras_gas,  gas_cost, car_speed;
    cout<<"\nEnter the average fuel consumption of your car per kilometer: ";
    cin>>ras_gas;
    cout<<"\nEnter the price of 1 liter of gasoline: ";
    cin>>gas_cost;
    cout<<"\nEnter the average speed of your car: ";
    cin>>car_speed;
    int option=1;
    while(option!=0){
        
        cout<<"\nChoose the option:\n";
        cout<<" 0. Stop the program.\n 1. Minimize road length.\n 2. Minimize travel time.\n 3. Minimize travel costs.\n";
        cin>>option;
        switch(option){
            case 1:
            case 2:
            case 3:
                cout<<"Enter from which and to which vertex you need to find the path: ";
                cin >> v_start >> v_end;
                v_start--;
                v_end--;
                Dijkstra(option, n, g, v_start, v_end, ras_gas, gas_cost, car_speed);
                continue;
            case 0:
                cout<<"Goodbye!"; 
                break;
            default:
                cout<<"Unknown funktion, try again!";
                continue;
        }
    }
    
    return 0;
}
