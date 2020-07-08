#include <iostream>
#include <climits>
using namespace std;

void print(pair<int, int> graph[][20], int n) {
    cout << "Updated adjacency matrix is : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j].first == 0) {
                cout << 0 << " ";
            }
            else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
}

int findMinVertex(int* distance, bool* visited, int n) {
	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}

pair<int, int> Shortest_Path(pair<int, int> graph[][20], int n, int source, int dest) {
	int* distance = new int[n];
	bool* visited = new bool[n];
	int* fare = new int[n];

	for(int i = 0; i < n; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
		fare[i] = INT_MAX;
	}

	distance[source] = 0;
	fare[source] = 0;

	for(int i = 0; i < n - 1; i++) {
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++) {
			if(graph[minVertex][j].second != 0 && !visited[j]) {
				int dist = distance[minVertex] + graph[minVertex][j].second;
				int c = fare[minVertex] + graph[minVertex][j].first;
				if(dist < distance[j]){
					distance[j] = dist;
					fare[j] = c;
				}
			}
		}
	}
	int ans1 = distance[dest];
	int ans2 = fare[dest];
	delete [] visited;
	delete [] distance;
	delete [] fare;
	pair<int, int> p;
	p.first = ans1;
	p.second = ans2;
	return p;
}

void Shortest_Path_Source_To_All(pair<int, int> graph[][20], int n, int source) {
	int* distance = new int[n];
	bool* visited = new bool[n];
	int* fare = new int[n];

	for(int i = 0; i < n; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
		fare[i] = INT_MAX;
	}

	distance[source] = 0;
	fare[source] = 0;

	for(int i = 0; i < n - 1; i++) {
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++) {
			if(graph[minVertex][j].second != 0 && !visited[j]) {
				int dist = distance[minVertex] + graph[minVertex][j].second;
				int c = fare[minVertex] + graph[minVertex][j].first;
				if(dist < distance[j]) {
					distance[j] = dist;
					fare[j] = c;
				}
			}
		}
	}
	cout << "Source  " << "Destination  " << "Shortest Distance   " << "Fare" << endl;
	for(int i = 0; i < n; i++){
		cout << source << "         " << i << "              " << distance[i] << "                " << fare[i] << endl;
	}
	delete [] visited;
	delete [] distance;
	delete [] fare;
}

pair<int, int> MinCostPath(pair<int, int> graph[][20], int n, int source, int dest) {
	int* cost = new int[n];
	bool* visited = new bool[n];
	int* distance = new int[n];

	for(int i = 0; i < n; i++) {
		cost[i] = INT_MAX;
		visited[i] = false;
		distance[i] = INT_MAX;
	}

	cost[source] = 0;
	distance[source] = 0;

	for(int i = 0; i < n - 1; i++) {
		int minVertex = findMinVertex(cost, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++) {
			if(graph[minVertex][j].first != 0 && !visited[j]) {
				int c = cost[minVertex] + graph[minVertex][j].first;
				int dist = distance[minVertex] + graph[minVertex][j].second;
				if(c < cost[j]) {
					cost[j] = c;
					distance[j] = dist;
				}
			}
		}
	}

	/*for(int i = 0; i < n; i++){
		cout << i << " " << cost[i] << endl;
	}*/
	int ans1 = cost[dest];
	int ans2 = distance[dest];
	delete [] visited;
	delete [] cost;
	delete [] distance;
	pair<int, int> p;
	p.first = ans1;
	p.second = ans2;
	return p;
}

void addAirport(pair<int, int> graph[][20], int& n) {
    n++;
    for (int i = 0; i < n; ++i) {
        graph[i][n - 1].first = 0;
        graph[i][n - 1].second = 0;
        graph[n - 1][i].first = 0;
        graph[n - 1][i].second = 0;
    }
    cout << "Airport added successfully!" << endl;
    print(graph, n);
}

void deleteAirport(pair<int, int> graph[][20], int& n, int x) {
    if (x >= n) {
        cout << "Airport not present!" << endl;
        return;
    }
    else {
        int i;
        while (x < n) {
            for (i = 0; i < n; ++i) {
                graph[i][x] = graph[i][x + 1];
            }
            for (i = 0; i < n; ++i) {
                graph[x][i] = graph[x + 1][i];
            }
            x++;
        }
        n--;
        cout << "Airport deleted successfully!" << endl;
        print(graph, n);
    }
}

bool hasPath(pair<int, int> graph[][20], int n, bool* visited, int v1, int v2) {
    if (graph[v1][v2].first != 1) {
        return true;
    }
    visited[v1] = true;
    for (int i = 0; i < n; i++) {
        if (v1 == i) {
            continue;
        }
        if (graph[v1][i].first >= 1 && !visited[i]) {
            bool ans =  hasPath(graph, n, visited, i, v2);
            if (ans) {
                return true;
            }
        }
    }
    return false;
}

bool hasPathHelper(pair<int, int> graph[][20], int n, int v1, int v2) {
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    bool ans =  hasPath(graph, n, visited, v1, v2);
    delete [] visited;
    return ans;
}

void addRoute(pair<int, int> graph[][20],int n, int& e, int x, int y, int fare, int distance) {
    if ((x >= n) || (y >= n)) {
        cout << "Airport does not exists!";
    }
    else if (x == y) {
        cout << "Same Airport!";
    }
    else if (graph[x][y].first != 0) {
        cout << "Route already exists!" << endl;
    }
    else {
        if (!hasPathHelper(graph,n, x, y)) {
            graph[x][y].first = fare;
            graph[x][y].second = distance;
            graph[y][x].first =  fare;
            graph[y][x].second = distance;
            e++;
            cout << "Route added successfully!" << endl;
            print(graph, n);
        }
        else {
            cout << "Warning :" << endl;
            cout << "Adding this route will result in cycle formation!" << endl;
        }
    }
}

void removeRoute(pair<int, int> graph[][20], int n, int& e, int x, int y) {
    if ((x >= n) || (y >= n)) {
        cout << "Airport does not exists!" << endl;
    }
    else if (x == y) {
        cout << "Same Airport!" << endl;
    }
    else if (graph[x][y].first == 0) {
        cout << "Route does not exist!" << endl;
    }
    else {
        graph[x][y].first = 0;
        graph[x][y].second = 0;
        graph[y][x].first = 0;
        graph[y][x].second = 0;
        e--;
        cout << "Route removed successfully!" << endl;
        print(graph, n);
    }
}

void updateRoute(pair<int, int> graph[][20], int n, int x, int y, int fare, int distance) {
    if ((x >= n) || (y >= n)) {
        cout << "Airport does not exists!" << endl;
        return;
    }
    if (x == y) {
        cout << "Same Airport!" << endl;
        return;
    }
    if (graph[x][y].first == 0) {
        cout << "Route does not exist!" << endl;
        return;
    }
    else {
        graph[x][y].first = fare;
        graph[x][y].second = distance;
        graph[y][x].first =  fare;
        graph[y][x].second = distance;
        cout << "Route updated successfully!" << endl;
        print(graph, n);
    }
}

int main() {
    cout << "Enter no. of Airports and Routes : " << endl;
    int n, e;
    cin >> n >> e;
    pair<int, int> graph[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j].first = 0;
            graph[i][j].second = 0;
        }
    }

    cout << "Enter source, destination, fare, distance : " << endl;
    for (int i = 0; i < e; i++) {
        int a, b, fare, distance;
        cin >> a >> b >> fare >> distance;
        graph[a][b].first = fare;
        graph[a][b].second = distance;
        graph[b][a].first = fare;
        graph[b][a].second = distance;
    }

    cout << "1. Add airport" << endl;
    cout << "2. Delete airport" << endl;
    cout << "3. Add a Route" << endl;
    cout << "4. Delete a Route" << endl;
    cout << "5. Update a Route" << endl;
    cout << "6. Get shortest distance path b/w two airports" << endl;
    cout << "7. Get shortest distance path from source to all airports" << endl;
    cout << "8. Get shortest distance path from all airports to all airports" << endl;
    cout << "9. Get minimum cost path b/w two airports" << endl;
    cout << "Enter -1 to exit" << endl;
    int choice;
    cout << "Enter your choice : " << endl;
    cin >> choice;
    while (choice != -1) {
        if (choice == 1) {
            addAirport(graph, n);
        }
        else if (choice == 2) {
            int x;
            cout << "Enter airport to be deleted : " << endl;
            cin >> x;
            deleteAirport(graph, n, x);
        }
        else if (choice == 3) {
            int x, y;
            cout << "Enter source and destination : " << endl;
            cin >> x >> y;
            int fare, distance;
            cout << "Enter fare and distance : " << endl;
            cin >> fare >> distance;
            addRoute(graph, n, e, x, y, fare, distance);
        }
        else if (choice == 4) {
            int x, y;
            cout << "Enter source and destination : " << endl;
            cin >> x >> y;
            removeRoute(graph, n, e, x, y);
        }
        else if (choice == 5) {
            int x, y;
            cout << "Enter source and destination : " << endl;
            cin >> x >> y;
            int fare, distance;
            cout << "Enter fare and distance : " << endl;
            cin >> fare >> distance;
            updateRoute(graph, n, x, y, fare, distance);
        }
        else if (choice == 6) {
            int x, y;
            cout << "Enter source and destination : " << endl;
            cin >> x >> y;
            pair<int, int> p = Shortest_Path(graph, n, x, y);
            cout << "Shortest distance = " << p.first << endl;
            cout << "Cost of this path = " << p.second << endl;
        }
        else if (choice == 7) {
            int x;
            cout << "Enter source : " << endl;
            cin >> x;
            Shortest_Path_Source_To_All(graph, n, x);
        }
        else if (choice == 8) {
            for (int i = 0; i < n; i++) {
                Shortest_Path_Source_To_All(graph, n, i);
            }
        }
        else if (choice == 9) {
            int x, y;
            cout << "Enter source and destination : " << endl;
            cin >> x >> y;
            pair<int, int> p  = MinCostPath(graph, n, x, y);
            cout << "Minimum fare = " << p.first << endl;
            cout << "Distance covered by min cost path = " << p.second << endl;
        }
        else {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;
    }
    return 0;
}
