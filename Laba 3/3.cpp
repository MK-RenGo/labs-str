#include <iostream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Функция для поиска в глубину (DFS) с учетом "склейки" цилиндра
void dfs(int r, int c, int N, int M, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    visited[r][c] = true;

    // Векторы направлений: вверх, вниз, влево, вправо
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        // Проверка выхода за верхний и нижний края (высота цилиндра N)
        // Эти края не склеены, поэтому за них выходить нельзя
        if (next_r < 0 || next_r >= N) continue;

        // Модификация (цилиндр): склейка левого и правого краев (длина окружности M)
        if (next_c < 0) {
            next_c = M - 1; // Шаг влево за край переносит на правый край
        } else if (next_c >= M) {
            next_c = 0;     // Шаг вправо за край переносит на левый край
        }

        // Если соседняя клетка не удалена (1) и мы в ней еще не были
        if (grid[next_r][next_c] == 1 && !visited[next_r][next_c]) {
            dfs(next_r, next_c, N, M, grid, visited);
        }
    }
}

int main() {
    // Настройка вывода кириллицы в консоли

    setlocale(LC_ALL, ".UTF-8");


    int N, M;
    cout << "Введите высоту N (количество строк) и ширину M (количество столбцов): ";
    if (!(cin >> N >> M)) return 0;

    // Создание матрицы N x M. 1 - клетка есть, 0 - клетка удалена.
    vector<vector<int>> grid(N, vector<int>(M));
    cout << "Введите матрицу " << N << "x" << M << " (используйте пробелы между элементами):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    // Матрица посещенных клеток
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int components = 0; // Счетчик кусков (компонент связности)

    // Обход всех клеток
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Если находим непосещенную неудаленную клетку
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, N, M, grid, visited); // Закрашиваем весь кусок
                components++; // Увеличиваем счетчик кусков
            }
        }
    }

    cout << "\nРезультат: оставшаяся часть листа распадется на " << components << " кусков." << endl;
    
    // Вывод ФИО 
    cout << "\n Дружинин Максим Андреевич РПИа-о25" << endl;
    
    while(getchar() != '\n');

    return 0;
}
