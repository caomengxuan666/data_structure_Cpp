include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

template <class V, class W, W MAX = numeric_limits<W>::max(), bool DIR = false>
class Graph
{
public:
    Graph(const V* a, size_t n)
    {
        _vertexs.reserve(n);
        for (size_t i = 0; i < n; i++)
        {
            _vertexs.push_back(a[i]);
            _idxMap[a[i]] = i;
        }

        _matrix.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            _matrix[i].resize(n, MAX);
        }
    }

    size_t GetIdx(const V& v)
    {
        auto it = _idxMap.find(v);
        if (it == _idxMap.end())
        {
            cerr << "Vertex not found in the graph." << endl;
            return -1;
        }
        return it->second;
    }

    void addEdge(const V& src, const V& dst, const W& w)
    {
        size_t si = GetIdx(src);
        size_t di = GetIdx(dst);
        _matrix[si][di] = w;
        if (DIR == false)
        {
            _matrix[di][si] = w;
        }
    }

    void Print()
    {
        for (size_t i = 0; i < _vertexs.size(); ++i)
        {
            cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
        }
        cout << endl;

        cout << "  ";
        for (size_t i = 0; i < _vertexs.size(); ++i)
        {
            printf("%5d", i);
        }
        cout << endl;

        for (size_t i = 0; i < _matrix.size(); ++i)
        {
            cout << i << " ";
            for (size_t j = 0; j < _matrix[i].size(); ++j)
            {
                if (_matrix[i][j] == MAX)
                    printf("%5c", '*');
                else
                    printf("%5d", _matrix[i][j]);
            }
            cout << endl;
        }
    }

    // Depth-First Search
    void DFS(size_t start, vector<bool>& visited)
    {
        if (start >= _matrix.size())
            return;

        visited[start] = true;
        cout << _vertexs[start] << " ";

        for (size_t i = 0; i < _matrix[start].size(); ++i)
        {
            if (_matrix[start][i] != MAX && !visited[i])
            {
                DFS(i, visited);
            }
        }
    }

    void DepthFirstSearch()
    {
        vector<bool> visited(_matrix.size(), false);

        cout << "DFS sequence: ";
        for (size_t i = 0; i < _matrix.size(); ++i)
        {
            if (!visited[i])
            {
                DFS(i, visited);
            }
        }
        cout << endl;
    }

    // Breadth-First Search
    void BreadthFirstSearch(size_t start)
    {
        if (start >= _matrix.size())
            return;

        vector<bool> visited(_matrix.size(), false);
        queue<size_t> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS sequence: ";
        while (!q.empty())
        {
            size_t current = q.front();
            q.pop();
            cout << _vertexs[current] << " ";

            for (size_t i = 0; i < _matrix[current].size(); ++i)
            {
                if (_matrix[current][i] != MAX && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

private:
    vector<V> _vertexs;
    unordered_map<V, size_t> _idxMap;
    vector<vector<W>> _matrix;
};

void TestGraph()
{
    Graph<char, int, numeric_limits<int>::max(), false> g("ABCDE", 5);
    g.addEdge('A', 'B', 1);
    g.addEdge('B', 'D', 4);
    g.addEdge('A', 'D', 2);
    g.addEdge('B', 'C', 9);
    g.addEdge('A', 'C', 8);
    g.addEdge('E', 'A', 5);
    g.addEdge('A', 'E', 3);
    g.addEdge('C', 'D', 6);

    g.Print();

    g.DepthFirstSearch();
    g.BreadthFirstSearch(0);
}

int main()
{
    TestGraph();

    return 0;
}

