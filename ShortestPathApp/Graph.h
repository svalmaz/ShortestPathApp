#pragma once
#include <climits>

using namespace System;

public ref class Graph {
private:
    int vertices;  
    array<array<int>^>^ adjMatrix;  

public:
    
    Graph(int v) {
        vertices = v;
        adjMatrix = gcnew array<array<int>^>(v);
        for (int i = 0; i < v; i++) {
            adjMatrix[i] = gcnew array<int>(v);
            for (int j = 0; j < v; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;  
            }
        }
    }

    // Метод для добавления ребра
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;  
    }

    // Метод для нахождения кратчайшего пути с помощью алгоритма Дейкстры
    array<int>^ dijkstra(int start, int end) {
        array<int>^ dist = gcnew array<int>(vertices);
        array<int>^ prev = gcnew array<int>(vertices);
        array<bool>^ visited = gcnew array<bool>(vertices);

        // Инициализация
        for (int i = 0; i < vertices; i++) {
            dist[i] = INT_MAX;
            prev[i] = -1;
            visited[i] = false;
        }
        dist[start] = 0;

        // Алгоритм Дейкстры
        for (int i = 0; i < vertices - 1; i++) {
            int u = -1;
            for (int j = 0; j < vertices; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    prev[v] = u;
                }
            }
        }

        // Восстановление пути
        array<int>^ path = gcnew array<int>(vertices);
        int index = 0;
        for (int at = end; at != -1; at = prev[at]) {
            path[index++] = at;
        }
        Array::Reverse(path, 0, index);
        return path;
    }
};
