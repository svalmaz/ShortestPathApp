# Shortest Path App
## Описание
**Shortest Path App** — это приложение, реализующее алгоритм **Дейкстры** для нахождения кратчайшего пути между двумя вершинами в графе. Приложение использует **Windows Forms** для ввода матрицы смежности и вычисления кратчайших путей в графах.

### Особенности:
- Реализация алгоритма **Дейкстры** для поиска кратчайшего пути между заданными вершинами.
- Графы могут быть разреженными, то есть некоторые вершины могут не быть напрямую соединены.
- Возможность ввода начальной и конечной вершины для нахождения кратчайшего пути.

---
## Структура проекта
Проект состоит из следующих основных компонентов:

1. **MainForm** — форма с графическим интерфейсом, где пользователь может вводить:
   - Матрицу смежности.
   - Начальную и конечную вершины.
2. **Graph** — класс, который реализует логику работы с графом, включая:
   - Добавление рёбер в граф.
   - Реализацию алгоритма Дейкстры для нахождения кратчайшего пути.
3. **Main** — точка входа, которая запускает приложение.

| Command | Description |
| --- | --- |
| git status | List all new or modified files |
| git diff | Show file differences that haven't been staged |
### Пример матрицы смежности
|  | 0 | 1 | 2 | 3 | 4 |
| --- | --- | --- | --- | --- |
|  | 0 | 2 | 0 | 5 | 0
|  | 2 | 0 | 4 | 0 | 3
|  | 0 | 4 | 0 | 2 | 0
|  | 5 | 0 | 2 | 0 | 6
|  | 0 | 3 | 0 | 6 | 0
В этой матрице смежности представлены веса рёбер между вершинами для графа с 5 вершинами.


### Описание:
- **0 → 1**: ребро с весом **2**.
- **1 → 2**: ребро с весом **4**.
- **2 → 3**: ребро с весом **2**.
- **3 → 4**: ребро с весом **6**.
- **1 → 4**: ребро с весом **3**.

Значение **∞** означает отсутствие ребра между вершинами.

---

### Пример для поиска кратчайшего пути:
- **Начальная вершина**: 0
- **Конечная вершина**: 4

Результат: Путь **0 → 1 → 2 → 3 → 4** с общей стоимостью **8**.

## Установка и запуск

1. **Клонируйте репозиторий:**

```bash
git clone https://github.com/yourusername/ShortestPathApp.git
