#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000;

int main(){
    cout<<"Dijkstra's algorithm.";
    int n, v_start, v_end;
    cout<<"\nEnter number of vertices: ";
    cin >> n;
    cout<<"\nEnter from which and to which vertex you need to find the path: ";
    cin >> v_start >> v_end;
    v_start--;
    v_end--;
    cout<<"\nEnter Adjacency Matrix: ";
    vector<vector<int>> g (n, vector<int>(n)); //Створюємо матрицю суміжності
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> g[i][j]; //Заповлюємо матрицю суміжності
        }
    }
    vector <int> d(n); //вектор де будуть зберігатися шляхи з вершини s у всі інші
    vector <int> p(n); //вектор де будуть зберігатися предки вершини
    d.assign(d.size(), Inf); //заповнюємо масив шляхів бескінчностями
    p.assign(p.size(), 0); //заповнюємо масив предків нулями
    d[v_start] = 0; //шлях у початкову точку дорівнює нулю
    priority_queue <pair<int, int>> q; //черга
    q.push(make_pair(0, v_start)); //додаємо в чергу вихідну вершину
    while (!q.empty()) { //цикл працює поки що черга не порожня
        int len = -q.top().first; //змінна що зберігає шлях від вихідної вершини до поточної
        int v = q.top().second; //змінна що зберігає вершину
        q.pop(); //видалення елемнту з черги
        if (len > d[v]) continue; //якщо довжина від початкової вершини до поточної більше тієї, що зберігається в d то переходимо до наступної ітерації
        for (int i = 0; i < n; i++) {
            int length = g[v][i]; //позначаємо нову змінну довжини від вершини v до вершини i
            if (d[i] > d[v] + length && length > 0) { //якщо довжина маршруту d[v] + length менша d[i]якщо d[v] + length менша d[i]
                d[i] = d[v] + length; //то записуємо в d[i] значення d[v] + length
                q.push(make_pair(-d[i], i)); //додаємо в чергу нові вершини
                p[i] = v; //запам'ятовуємо предка вершини i
            }
        }
    }
    if(d[v_end]==Inf){ //перевіряємо чи існує шлях від v_start до v_end
        cout<<endl<<"False. Way from the vertex "<<v_start+1<<" to the vertex "<<v_end+1<<" does not exist!";
    }
    else{ //якщо існує виводимо його
        cout<<endl<<"\nWay from the vertex "<<v_start+1<<" to the vertex "<<v_end+1<<" equals: "<<d[v_end]<<endl;
        
        cout<<"\nWay from the vertex "<<v_start+1<<" to the vertex "<<v_end+1<<": ";
        vector<int> path; //створюємо вектор для відтворення шляху
        for (int v=v_end; v!=v_start; v=p[v]){
        	path.push_back (v); //додаємо вершини в порядку від вершини v_start до v_end
        }
        path.push_back(v_start); //додаємо початкову вершину 
        reverse(path.begin(), path.end()); //перевертаємо вектор path
        for (int i=0; i<path.size(); i++){
        	cout<<path[i]+1<<" "; //виводимо вектор, що і є шляхом від вершини v_start до v_end
        }
    }
    return 0;
}
