# Quadratic Equation Solver

Программа, способная решать любое квадратное уравнение. 
Поддерживает запуск тестов и флаги командной строки.



## Особенности

*   **Решение уравнений:** Находит действительные и комплексные корни.
*   **Ввод данных:**
    *   Интерактивный режим: запрос коэффициентов `a`, `b` и `c` у пользователя.
    *   Режим флагов: позволяет передать коэффициенты из командной строки.
*   **Флаги командной строки:**
    *   `-h` или `--help` — показать справку.
    *   `-t` или `--test` — запустить встроенные тесты.
    *   `-s` или `--solve` - интерактивный режим ввода данных и решения уравнения
    *   `-f` или `--file` - запускает тесты с помощью данных из указанного файла
    *   `-с` или `--coefs` - решает уравнение с коэффициентами, переданными в командной строке

##  Сборка и установка

1.  Клонируйте репозиторий:
    ````bash
    git clone https://github.com/elizzzrd/Square_solver.git
    ````
2. Соберите проект с помощью `make`
3. Запустите встроенные тесты с помощью
    ```bash
    make tests
    make check
    ```
4. Очистите собранные файлы с помощью `make clean`


##  Использование

Просто запустите программу без аргументов, она выдаст справочную информацию.
```bash
./square_solver.exe
Hello(Meow), this is square solver program!!!

Possible flags to use:

"-h" or "--help" - provide information about usage of this program.

"-s" or "--solve" - launch square equations solver.

"-t" or "--tests" - launch tests for equation solver.

"-f" or "--file" -  launch tests for equation solver from file you provide.
syntax: ["name of programm"] ["--file"] ["path to file"]

"-c" or "--coefs" - launch square equation solver with coefficients you enter.
syntax: ["name of programm"] ["--coefs"] ["a b c"] for equation ax^2 + bx + c = 0

You can also enter several flags like this:
syntax: ["name of programm"] ["flag1 with its arguments"] ["flag2 with its arguments"] and so on...


1 flags has been executed
Program is finished.
```


#### Получение справки
```bash
./square_solver.exe --help
```

#### Интерактивный режим ввода
```bash
./square_solver.exe --solve
```
#### Запуск встроенных тестов
```bash
./square_solver.exe --tests
```

#### Запуск тестов из файла
```bash
./square_solver.exe --file tests/data.txt
```

#### Решение уравнения с коэффициентами из командной строки
```bash
./square_solver.exe --coefs 1 -2 1
```

#### Также поддерживается запуск сразу нескольких флагов
```bash
./square_solver.exe -h -s -t
```
