
#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct binaryheap
{
private:
    vector<int> heap;

    // вернуть левого потомка `A[i]`
    int LEFT(int i)
    {
        return (2 * i + 1);
    }

    // вернуть правого потомка `A[i]`
    int RIGHT(int i)
    {
        return (2 * i + 2);
    }

    int PARENT(int i)
    {
        return (i - 1) / 2;
    }

    // –екурсивный алгоритм heapify-down.
// ”зел с индексом `i` и два его пр€мых потомка
// нарушает свойство кучи
    void heapify_down(int i)
    {
        // получить левый и правый потомки узла с индексом `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int smallest = i;

        // сравниваем `A[i]` с его левым и правым дочерними элементами
// и находим наименьшее значение
        if (left < heap.size() && heap[left] < heap[i]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // помен€тьс€ местами с дочерним элементом с меньшим значением и
        // вызовите heapify-down дл€ дочернего элемента
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }

    // –екурсивный алгоритм heapify-up
    void heapify_up(int i)
    {
        // провер€ем, не нарушают ли узел с индексом `i` и его родитель свойство кучи
        if (i && heap[PARENT(i)] > heap[i])
        {
            // помен€ть их местами, если свойство кучи нарушено
            swap(heap[i], heap[PARENT(i)]);

            // вызываем heapify-up дл€ родител€
            heapify_up(PARENT(i));
        }
    }

public:
    void push(int key)
    {
        // вставл€ем новый элемент в конец вектора
        heap.push_back(key);

        // получаем индекс элемента и вызываем процедуру heapify-up
        int index = heap.size() - 1;
        heapify_up(index);
    }

    //удала€ет корень
    void pop()
    {
        if (heap.size())
        {
            heap[0] = heap.back();
            heap.pop_back();
            heapify_down(0);
        }
        else
        {
            cout << " уча пуста" << endl;
        }
    }

    int top()
    {
        if (heap.size())
        {
            return heap[0];
        }
        else
        {
            cout << " уча пуста" << endl;
        }
    }
};

void Dijkstra(int** GR, int N, int st)
{
	int* distance = new int[N];//массив дистанций до грани
	int count, index, i, u, m = st + 1;// count - , index - , i - , u - , m = 
	bool* visited = new bool[N];//массив отвечающий за посещЄнность граней
	for (i = 0; i < N; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < N - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < N; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i < N; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "—тоимость пути из начальной вершины до остальных:\t\n";
	for (i = 0; i < N; i++) if (distance[i] != INT_MAX)
		cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
}


void my_dij(int** graph, int N, int start)
{
	//graph - матрица рассто€ний между гран€ми, N - кол-во граней, start - грань, от которой ведут отчЄт
	int* distance = new int[N];//массив длин путей до конкретной грани
	bool* visited = new bool[N];//массив посещаемости
	for (int i = 0; i < N; i++)
	{
		distance[i] = INT_MAX;// по умолчанию рассто€ние до любой грани очень большое, бесконечность в идеале
		visited[i] = 0;//ни одна грань не посещена
	}
	distance[start] = 0;// рассто€ние из стартовой грани равно 0, мы итак в ней
	int minindex, min, temp;
	do
	{
		for (int i = 0; i < N; i++)
		{
			cout << "d: " << i << " = " << distance[i] << endl;
		}
		for (int i = 0; i < N; i++)
		{
			cout << "v: " << i << " = " << visited[i] << endl;
		}
		cout << endl;
		minindex = INT_MAX;
		min = INT_MAX;
		for (int i = 0; i < N; i++)
		{ // ≈сли вершину ещЄ не обошли и вес меньше min
			if ((!visited[i]) && (distance[i] < min))
			{ // ѕереприсваиваем значени€
				min = distance[i];
				minindex = i;
			}
		}
		// ƒобавл€ем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minindex != INT_MAX)
		{
			for (int i = 0; i < N; i++)
			{
				if (graph[minindex][i] > 0)//есть путь из minindex в i
				{
					temp = min + graph[minindex][i];
					if (temp < distance[i])
					{
						distance[i] = temp;
					}
				}
			}
			visited[minindex] = 1;
		}
	} while (minindex < INT_MAX);

	cout << "—тоимость пути из начальной вершины до остальных:\t\n";
	for (int i = 0; i < N; i++) if (distance[i] != INT_MAX)
		cout << start + 1 << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << start + 1 << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
}