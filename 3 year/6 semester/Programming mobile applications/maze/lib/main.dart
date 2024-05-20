import 'package:flutter/material.dart';
import 'dart:math';

//Klasa labiryntu
class Maze {
  List<List<int>> structure;
  Map<String, int> doorKeys;
  int? playerRow;
  int? playerCol;

  Maze(this.structure, this.doorKeys) {
    for (int i = 0; i < structure.length; i++) {
      for (int j = 0; j < structure[i].length; j++) {
        if ((structure[i][j] & 16) != 0) {
          playerRow = i;
          playerCol = j;
          return;
        }
      }
    }
    if (playerRow == null || playerCol == null) {
      throw Exception('No starting chamber found');
    }
  }

  bool canMoveLeft() => (structure[playerRow!][playerCol!] & 1) != 0;
  bool canMoveRight() => (structure[playerRow!][playerCol!] & 2) != 0;
  bool canMoveUp() => (structure[playerRow!][playerCol!] & 4) != 0;
  bool canMoveDown() => (structure[playerRow!][playerCol!] & 8) != 0;

  void moveLeft() {
    if (canMoveLeft()) {
      int tempCol = playerCol!;
      tempCol--;
      playerCol = tempCol;
    }
  }

  void moveRight() {
    if (canMoveRight()) {
      int tempCol = playerCol!;
      tempCol++;
      playerCol = tempCol;
    }
  }

  void moveUp() {
    if (canMoveUp()) {
      int tempRow = playerRow!;
      tempRow--;
      playerRow = tempRow;
    }
  }

  void moveDown() {
    if (canMoveDown()) {
      int tempRow = playerRow!;
      tempRow++;
      playerRow = tempRow;
    }
  }

  bool isGameOver() => structure[playerRow!][playerCol!] == 0;

  //Funkcja do generowania labiryntów o wartości do przejścia
  static Maze generateSolvable(int size) {
    List<List<int>> structure =
        List.generate(size, (_) => List.generate(size, (_) => 15));
    Map<String, int> doorKeys = {};
    Random random = Random();

    int startRow = random.nextInt(size);
    int startCol = random.nextInt(size);
    int endRow, endCol;
    do {
      endRow = random.nextInt(size);
      endCol = random.nextInt(size);
    } while (endRow == startRow && endCol == startCol);

    structure[startRow][startCol] = 30;
    structure[endRow][endCol] = 0;

    List<List<bool>> visited =
        List.generate(size, (_) => List.generate(size, (_) => false));
    List<List<int>> directions = [
      [-1, 0],
      [1, 0],
      [0, -1],
      [0, 1],
    ];
    void dfs(int row, int col) {
      visited[row][col] = true;
      directions.shuffle(random);
      for (List<int> direction in directions) {
        int newRow = row + direction[0];
        int newCol = col + direction[1];
        if (newRow >= 0 &&
            newRow < size &&
            newCol >= 0 &&
            newCol < size &&
            !visited[newRow][newCol]) {
          if (direction[0] == -1) {
            structure[row][col] &= ~4;
          } else if (direction[0] == 1) {
            structure[row][col] &= ~8;
          } else if (direction[1] == -1) {
            structure[row][col] &= ~1;
          } else if (direction[1] == 1) {
            structure[row][col] &= ~2;
          }
          dfs(newRow, newCol);
        }
      }
    }

    dfs(startRow, startCol);

    for (int i = 0; i < size; i++) {
      structure[0][i] &= ~4;
      structure[size - 1][i] &= ~8;
      structure[i][0] &= ~1;
      structure[i][size - 1] &= ~2;
    }

    if (structure[startRow][startCol] == 16) {
      List<int> possibleDoors = [1, 2, 4, 8];
      possibleDoors
          .removeWhere((door) => (structure[startRow][startCol] & door) != 0);
      structure[startRow][startCol] |=
          possibleDoors[random.nextInt(possibleDoors.length)];
    }

    if (structure[startRow][startCol] == 16) {
      List<int> possibleDoors = [1, 2, 4, 8];
      possibleDoors
          .removeWhere((door) => (structure[startRow][startCol] & door) != 0);
      structure[startRow][startCol] |=
          possibleDoors[random.nextInt(possibleDoors.length)];
      for (int key = 1; key <= 4; key++) {
        int row, col;
        do {
          row = random.nextInt(size);
          col = random.nextInt(size);
        } while (doorKeys.containsKey('$row,$col'));
        doorKeys['$row,$col'] = key;
      }
    }
    Maze maze = Maze(structure, doorKeys);
    return maze;
  }
}

//Główna funkcja
void main() {
  runApp(const MyApp());
}

//Funkcja do rysowania komórek labiryntu
class MazeCell extends StatelessWidget {
  final int value;
  final bool isPlayer;
  final int? cellKey;

  const MazeCell(
      {super.key, required this.value, required this.isPlayer, this.cellKey});

  @override
  Widget build(BuildContext context) {
    Color cellColor;
    if (isPlayer) {
      cellColor = Colors.blue;
    } else if (value == 0) {
      cellColor = Colors.green;
    } else {
      cellColor = Colors.white;
    }
    return Container(
      decoration: BoxDecoration(
        color: cellColor,
        border: const Border(
          left: BorderSide(width: 1.0, color: Colors.black),
          right: BorderSide(width: 1.0, color: Colors.black),
          top: BorderSide(width: 1.0, color: Colors.black),
          bottom: BorderSide(width: 1.0, color: Colors.black),
        ),
      ),
      child: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'Door: $value',
              style: const TextStyle(fontSize: 10, fontWeight: FontWeight.bold),
            ),
            if (cellKey != null)
              Text(
                'Key: $cellKey',
                style:
                    const TextStyle(fontSize: 10, fontWeight: FontWeight.bold),
              ),
            if (isPlayer)
              const Text(
                'Player',
                style: TextStyle(fontSize: 10, fontWeight: FontWeight.bold),
              ),
          ],
        ),
      ),
    );
  }
}

//Klasa do wyrysowania drzwi pomiędzy strzałkami
class Door extends StatelessWidget {
  final Maze maze;

  const Door({super.key, required this.maze});

  @override
  Widget build(BuildContext context) {
    return Container(
      width: 100,
      height: 100,
      padding: const EdgeInsets.all(8.0),
      decoration: BoxDecoration(
        color: Colors.white,
        border: Border(
          left: BorderSide(
            color: maze.canMoveLeft() ? Colors.green : Colors.red,
            width: 3.0,
          ),
          right: BorderSide(
            color: maze.canMoveRight() ? Colors.green : Colors.red,
            width: 3.0,
          ),
          top: BorderSide(
            color: maze.canMoveUp() ? Colors.green : Colors.red,
            width: 3.0,
          ),
          bottom: BorderSide(
            color: maze.canMoveDown() ? Colors.green : Colors.red,
            width: 3.0,
          ),
        ),
      ),
      child: const Center(child: Text('DOOR')),
    );
  }
}

//Tworzenie ekranu gry
class GameScreen extends StatefulWidget {
  const GameScreen({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _GameScreenState createState() => _GameScreenState();
}

//Klasa ekranu gry - całe serce programu
class _GameScreenState extends State<GameScreen> {
  late Maze maze;
  int moveCounter = 0;

  @override
  void initState() {
    super.initState();
    startGame();
  }

  void startGame() {
    Random random = Random();
    int size = 3 + random.nextInt(6);
    maze = Maze.generateSolvable(size);
    moveCounter = 0;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: const Text("Game",
            style: TextStyle(
              fontWeight: FontWeight.bold,
              fontSize: 30.0,
            )),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              "Maze map",
              style: TextStyle(
                  color: Colors.black,
                  fontSize: 20.0,
                  fontWeight: FontWeight.bold),
            ),
            Expanded(
              child: SizedBox(
                child: GridView.builder(
                  itemCount: maze.structure.length * maze.structure[0].length,
                  gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
                    crossAxisCount: maze.structure[0].length,
                  ),
                  itemBuilder: (context, index) {
                    int row = index ~/ maze.structure[0].length;
                    int col = index % maze.structure[0].length;
                    int? cellKey = maze.doorKeys['$row,$col'];
                    return MazeCell(
                      value: maze.structure[row][col],
                      isPlayer: row == maze.playerRow && col == maze.playerCol,
                      cellKey: cellKey,
                    );
                  },
                ),
              ),
            ),
            Text(
              maze.isGameOver()
                  ? 'You escaped\nGame end! Congratulations!\nYour moves: $moveCounter'
                  : 'Legend\nBlue - player, Green - exit',
              textAlign: TextAlign.center,
              style: const TextStyle(
                fontSize: 20.0,
                color: Colors.black,
                fontWeight: FontWeight.bold,
              ),
            ),
            maze.isGameOver()
                ? ElevatedButton(
                    onPressed: () {
                      setState(() {
                        startGame();
                      });
                    },
                    style: ButtonStyle(
                      backgroundColor:
                          MaterialStateProperty.all<Color>(Colors.green),
                      foregroundColor:
                          MaterialStateProperty.all<Color>(Colors.black),
                      padding: MaterialStateProperty.all<EdgeInsets>(
                          const EdgeInsets.all(20)),
                      textStyle: MaterialStateProperty.all<TextStyle>(
                          const TextStyle(fontSize: 20)),
                      shape: MaterialStateProperty.all<RoundedRectangleBorder>(
                        RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(10.0),
                        ),
                      ),
                    ),
                    child: const Text('Get a new Map!'),
                  )
                : Column(
                    children: <Widget>[
                      ElevatedButton(
                        onPressed: maze.canMoveUp()
                            ? () {
                                setState(() {
                                  maze.moveUp();
                                  moveCounter++;
                                });
                              }
                            : null,
                        child: const Text('Up'),
                      ),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: <Widget>[
                          ElevatedButton(
                            onPressed: maze.canMoveLeft()
                                ? () {
                                    setState(() {
                                      maze.moveLeft();
                                      moveCounter++;
                                    });
                                  }
                                : null,
                            child: const Text('Left'),
                          ),
                          Door(maze: maze),
                          ElevatedButton(
                            onPressed: maze.canMoveRight()
                                ? () {
                                    setState(() {
                                      maze.moveRight();
                                      moveCounter++;
                                    });
                                  }
                                : null,
                            child: const Text('Right'),
                          ),
                        ],
                      ),
                      ElevatedButton(
                        onPressed: maze.canMoveDown()
                            ? () {
                                setState(() {
                                  maze.moveDown();
                                  moveCounter++;
                                });
                              }
                            : null,
                        child: const Text('Down'),
                      ),
                      ElevatedButton(
                        onPressed: () {
                          setState(() {
                            startGame();
                          });
                        },
                        style: ButtonStyle(
                          backgroundColor:
                              MaterialStateProperty.all<Color>(Colors.green),
                          foregroundColor:
                              MaterialStateProperty.all<Color>(Colors.black),
                          padding: MaterialStateProperty.all<EdgeInsets>(
                              const EdgeInsets.all(20)),
                          textStyle: MaterialStateProperty.all<TextStyle>(
                              const TextStyle(fontSize: 20)),
                          shape:
                              MaterialStateProperty.all<RoundedRectangleBorder>(
                            RoundedRectangleBorder(
                              borderRadius: BorderRadius.circular(10.0),
                            ),
                          ),
                        ),
                        child: const Text('Try another map'),
                      )
                    ],
                  ),
          ],
        ),
      ),
    );
  }
}

//Klasa do bara u góry
class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.lightGreenAccent),
        useMaterial3: true,
      ),
      home: const MyHomePage(title: 'Labyrinth - first task'),
    );
  }
}

//Tworzenie main screena
class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

//Strona główna aplikacji
class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title,
            style: const TextStyle(
              fontWeight: FontWeight.bold,
              fontSize: 30.0,
            )),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              "First version game labyrinth ",
              style: TextStyle(
                  color: Colors.black,
                  fontSize: 20.0,
                  fontWeight: FontWeight.bold),
            ),
            TextButton(
              style: TextButton.styleFrom(
                foregroundColor: Colors.black,
                backgroundColor: Colors.lightGreenAccent,
                fixedSize: const Size(300, 60),
              ),
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const GameScreen()),
                );
              },
              child: const Text(
                'Start Game',
                style: TextStyle(
                  fontWeight: FontWeight.bold,
                  fontSize: 20.0,
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
