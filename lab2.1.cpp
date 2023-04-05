#include "Dijkstra.h"

int main()
{
	setlocale(0, "");
	int start_point = 0, N = 0;
	cout << "Введите кол-во элементов': ";
	cin >> N;
	int** Graph = new int* [N];
	for (int i = 0; i < N; i++)
	{
		Graph[i] = new int[N];
	}
	cout << "введите элемент из которого хотите найти пути до остальных элементов: ";
	cin >> start_point;
	cout << "Введите длины путей между элементами." << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "из элемента " << i + 1;
		for (int j = 0; j < N; j++)
		{
			cout << " в элемент " << j + 1 << ": ";
			cin >> Graph[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Graph[i][j];
		cout << endl;
	}
	clock_t start = clock();
	my_dij(Graph, N, start_point - 1);
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
	system("pause");
}