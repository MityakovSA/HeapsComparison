# HeapsComparison

Программа предназначена для сравнения скорости работы двух структур данных: двоичной кучи и биномиальной кучи.

## Build

```ShellSession
$ git clone https://github.com/MityakovSA/HeapsComparison.git
$ cd HeapsComparison
$ mkdir build && cd build
$ cmake .. && make
```

## Running tests

```ShellSession
$ ./Tests
```

## Usage

```ShellSession
$ ./WordsLadder inputFile outputFile
```

На вход программы подаются 2 текстовых файла. В первом файле `inputFile1` содержится вид структуры данных (одним словом: binary или binomial) и список команд для неё. Если у команды есть аргументы, то каждый из них следует отделить пробелом от названия команды и друг друга. Второй файл `inputFile2` создает программа и записывает туда результаты своей работы (результаты работы приведенных в первом файле команд, если у таковых предусмотрен вывод), а также время, за которое она отработала, в микросекундах.

## Commands templates

```ShellSession
$ insert [key] [data]
$ find [key]
$ delete [key]
$ min
$ max
$ extract_min
$ print
```