#include <bits/stdc++.h>
#include "kot.h"
using namespace std;

vector<vector<pair<int, int>>> sc;

int N, M, A, B, S;
vector<int> U, V;

struct ERROR
{
    string error;
    ERROR(string s)
    {
        error = s;
    }
};

namespace
{
    vector<vector<vector<int>>> adjacent_towns;
    vector<int> distances;
    std::mt19937 rng;

    // inicjowanie działania
    void init(const vector<int> &x)
    {

        adjacent_towns.assign(N, vector<vector<int>>(A));
        for (int i = 0; i < M; ++i)
        {
            adjacent_towns[U[i]][x[i]].push_back(V[i]);
            adjacent_towns[V[i]][x[i]].push_back(U[i]);
        }
        std::queue<int> que;
        distances.assign(N, -1);
        distances[0] = 0;
        que.push(0);
        for (; !que.empty();)
        {
            const int u = que.front();
            que.pop();
            for (int j = 0; j < A; ++j)
            {
                for (const int v : adjacent_towns[u][j])
                {
                    if (distances[v] == -1)
                    {
                        distances[v] = distances[u] + 1;
                        que.push(v);
                    }
                }
            }
        }
    }

    // generuje tablicę y dla funkcji idz
    vector<vector<int>> GetNextTowns(int last_town, int current_town)
    {
        vector<vector<int>> next_towns(A);
        for (int j = 0; j < A; ++j)
            for (const int v : adjacent_towns[current_town][j])
                if (v != last_town)
                    next_towns[j].push_back(v);
        return next_towns;
    }

    // wybiera losowe miasto spośród możliwych
    int SelectNextTown(int last_town, int current_town, int z, const vector<int> &vs)
    {
        return vs[std::uniform_int_distribution<int>(0, (int)vs.size() - 1)(rng)];
    }
    void run()
    {
        
        rng.seed(420);
        rozpocznij(A, B);
        int num_moves = 0;
        int last_town = -1, current_town = S;
        for (; current_town != 0;)
        {
            if (num_moves >= distances[S] + B)
                throw ERROR("Wykonano za dużo ruchów");
            const vector<vector<int>> next_towns = GetNextTowns(last_town, current_town);
            vector<int> y(A);
            for (int j = 0; j < A; ++j)
                y[j] = next_towns[j].size();

            int z = idz(y);

            ++num_moves;
            if (!(-1 <= z && z <= A - 1))
            {
                // z spoza zakresu (-1,a-1)
                throw ERROR("Błędny ruch[1]");
            }
            if (last_town == -1 && z == -1)
            {
                // zwrócono polecenie cofnięcia się, jednak jest to początkowy wierzchołek
                throw ERROR("Błędny ruch[2]");
            }
            if (0 <= z && z <= A - 1 && y[z] == 0)
            {
                // nie ma krawędzi o danym oznaczeniu
                throw ERROR("Błędny ruch[3]");
            }
            if (z == -1)
            {
                std::swap(last_town, current_town);
            }
            else
            {
                const int next_town =
                    SelectNextTown(last_town, current_town, z, next_towns[z]);
                last_town = current_town;
                current_town = next_town;
            }
        }
        string res = "OK. Długość twojej trasy: " + to_string(num_moves) + ". Najkrótsza ścieżka: " + to_string(distances[S]);
        throw ERROR(res);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    // n, m, a, b zgodnie z treścią zadania
    // s - wieszchołek początkowy
    cin >> N >> M >> A >> B >> S;
    U.resize(M);
    V.resize(M);
    for (int i = 0; i < M; i++)
        cin >> U[i] >> V[i];
    vector<int> kolorowanie = pokoloruj(N, M, A, B, U, V);

    // sprawdzanie poprawności pokolorowania
    assert((int)kolorowanie.size() == M);
    for (int i = 0; i < M; i++)
        assert(kolorowanie[i] >= 0 && kolorowanie[i] < A);
    try
    {
        //poruszanie się po mieście (grafie)
        init(kolorowanie);
        run();
    }
    catch (ERROR e)
    {
        cout << e.error << '\n';
    }
}