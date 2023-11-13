
#### Пономаренко Маргарита Альбертівна ІМ-11

## Build & Run project

Для збірки проекту, треба встановити поточку директорію на: `\src\KPI_Lab1` та прописати команду

```bash
  msbuild KPI_Lab1.sln
```
Запуск проекту відбувається з директорії: `\src\KPI_Lab1\x64\Debug`
за допомогою команди:
```bash
  start KPI_Lab1.exe
```
Передаємо шлях, до файлу .txt, що містить в собі умову задачі та отримуємо вихідний файл `output.txt`, який зберігся в директорії, з якої було запущено проект.

Демонстрація шляху до заготовленого файлу-прикладу з репозиторія: `../../../KPI_Lab1/KPI_Lab1/data.txt` 

## Run Tests
Запуск тестів відбувається з директорії: `\src\KPI_Lab1\x64\Debug`
за допомогою команди:
```bash
  KPI_Lab1_Test.exe
```

## Task demonstration
- Налаштування GitHub Actions відбувалося у гілках [integrations](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/tree/integrations) та [integrations-2](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/tree/integrations-2)
- [Pull Request](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/pull/2) з unit test, що успішно проходить в GitHub Actions
- [Pull Request #2](https://github.com/future-stardust/im-1x-lab-1-MargoPonomarenko/pull/3) з unit test, що НЕ проходить в GitHub Actions
