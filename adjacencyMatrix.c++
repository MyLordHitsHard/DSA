#include "iostream"
#include "vector"
#include "queue"

// declaring function prototypes
bool checkConnectedness(std::vector<std::vector<int>> &, int);
void DFS(std::vector<std::vector<int>> &, int, int, std::vector<bool> &);
void BFS(std::vector<std::vector<int>> &, int, int);

int main()
{

    std::cout << "**********WELCOME TO THE ADJACENCY MATRIX PROGRAM**********" << std::endl;
    std::cout << "Enter the number of vertices in the graph: " << std::endl;
    int vertices;
    std::cin >> vertices;
    std::vector<std::vector<int>> adjMat(vertices, std::vector<int>(vertices, 0));

    while (true)
    {

        std::cout << "Enter 1 to input an edge,\n2 to see the matrix,\n3 to check connectedness\n4 to do a DFS traversal\n5 to do a BFS traversal\nand 6 to exit the program: " << std::endl;
        int choice;
        std::cin >> choice;
        // switch case to perform the required operation
        std::vector<bool> visited(vertices, false);
        switch (choice)
        {

        case (1):
            std::cout << "Enter the value of source, destination and weight:" << std::endl;

            int source, destination, weight;

            std::cin >> source >> destination >> weight;
            adjMat[source][destination] = weight;
            break;

        case (2):

            for (int i = 0; i < vertices; i++)
            {
                for (int j = 0; j < vertices; j++)
                {
                    std::cout << adjMat[i][j];
                    if (adjMat[i][j] < 10)
                    {
                        std::cout << "   ";
                    }
                    else if (adjMat[i][j] < 100)
                    {
                        std::cout << "  ";
                    }
                    else if (adjMat[i][j] < 1000)
                    {
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
            break;
        case (3):
            std::cout << checkConnectedness(adjMat, vertices) << std::endl;
            break;

        case (4):

            DFS(adjMat, vertices, 0, visited);
            std::cout << std::endl;
            break;
        case (5):
            BFS(adjMat, vertices, 0);
            std::cout << std::endl;
            break;
        case (6):
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }
}

// to check connectedness
bool checkConnectedness(std::vector<std::vector<int>> &adjMat, int vertices)
{

    // using BFS

    std::queue<int> q;

    std::vector<int> visited(vertices, 0);
    visited[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (int i = 0; i < vertices; i++)
        {
            if (adjMat[temp][i] && !visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

// to do a DFS traversal of the graph
void DFS(std::vector<std::vector<int>> &adjMat, int vertices, int v, std::vector<bool> &visited)
{
    visited[v] = true;
    std::cout << v << " ";
    for (int i = 0; i < vertices; i++)
    {
        if (adjMat[v][i] && !visited[i])
        {
            DFS(adjMat, vertices, i, visited);
        }
    }
}

// to do a BFS traversal of the graph
void BFS(std::vector<std::vector<int>> &adjMat, int vertices, int v)
{
    std::vector<bool> visited(vertices, false);
    std::queue<int> q;

    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        std::cout << v << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adjMat[v][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
