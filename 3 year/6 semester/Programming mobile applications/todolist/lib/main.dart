// instalacje
// flutter pub add intl
// flutter pub add path
// flutter pub add sqflite
import 'package:intl/intl.dart';
import 'package:flutter/material.dart';
import 'package:path/path.dart';
import 'package:sqflite/sqflite.dart';

void main() {
  runApp(const MaterialApp(
    home: TaskManager(),
  ));
}

class Task {
  int id;
  String name;
  String description;
  DateTime startDate;
  int priority;

  Task(
      {required this.id,
      required this.name,
      required this.description,
      required this.startDate,
      required this.priority});

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'name': name,
      'description': description,
      'start_date': startDate.toIso8601String(),
      'priority': priority,
    };
  }
}

class TaskManager extends StatefulWidget {
  const TaskManager({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _TaskManagerState createState() => _TaskManagerState();
}

class _TaskManagerState extends State<TaskManager> {
  List<Task> tasks = [];

  void deleteTask(int index) {
    setState(() {
      tasks.removeAt(index);
    });
  }

  Color getPriorityColor(int priority) {
    switch (priority) {
      case 1:
        return Colors.lightGreen;
      case 2:
        return Colors.lightBlue;
      case 3:
        return Colors.yellow;
      default:
        return Colors.grey;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('TODO LIST - task 3'),
      ),
      body: ListView.builder(
        itemCount: tasks.length,
        itemBuilder: (context, index) {
          return ListTile(
            tileColor: getPriorityColor(tasks[index].priority),
            title: Text(tasks[index].name),
            subtitle: Text(
                'Data: ${tasks[index].startDate.toLocal().toString().split(' ')[0]}\nPriorytet: ${tasks[index].priority}'),
            trailing: IconButton(
              icon: const Icon(Icons.delete),
              onPressed: () {
                deleteTask(index);
              },
            ),
            onTap: () {
              Navigator.push(
                context,
                MaterialPageRoute(
                  builder: (context) =>
                      EditTaskScreen(task: tasks[index], index: index, tasks: tasks),
                ),
              ).then((editedTask) {
                if (editedTask != null) {
                  setState(() {
                    tasks[index] = editedTask;
                  });
                }
              });
            },
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => NewTaskScreen(tasks: tasks),
            ),
          ).then((newTask) {
            if (newTask != null) {
              setState(() {
                tasks.add(newTask);
              });
            }
          });
        },
        child: const Icon(Icons.add),
      ),
    );
  }
}

class NewTaskScreen extends StatefulWidget {
  final List<Task> tasks;

  const NewTaskScreen({super.key, required this.tasks});

  @override
  // ignore: library_private_types_in_public_api
  _NewTaskScreenState createState() => _NewTaskScreenState();
}

class _NewTaskScreenState extends State<NewTaskScreen> {
  final _formKey = GlobalKey<FormState>();
  String _name = '';
  String _description = '';
  DateTime _startDate = DateTime.now();
  int _priority = 1;

  Future<void> _selectDate(BuildContext context) async {
    final DateTime? picked = await showDatePicker(
      context: context,
      initialDate: _startDate,
      firstDate: DateTime(2015, 8),
      lastDate: DateTime(2101),
    );
    if (picked != null && picked != _startDate) {
      setState(() {
        _startDate = picked;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Nowe zadanie'),
      ),
      body: Form(
        key: _formKey,
        child: Column(
          children: <Widget>[
            TextFormField(
              decoration: const InputDecoration(labelText: 'Nazwa zadania'),
              validator: (value) {
                if (value!.isEmpty) {
                  return 'Proszę wprowadzić nazwę zadania';
                }
                return null;
              },
              onSaved: (value) {
                _name = value!;
              },
            ),
            TextFormField(
              decoration: const InputDecoration(labelText: 'Opis zadania'),
              validator: (value) {
                if (value!.isEmpty) {
                  return 'Proszę wprowadzić opis zadania';
                }
                return null;
              },
              onSaved: (value) {
                _description = value!;
              },
            ),
            ElevatedButton(
              onPressed: () => _selectDate(context),
              child:
                  Text('Wybierz datę: ${_startDate.toLocal()}'.split(' ')[0]),
            ),
            Text(
              'Wybrana data: ${DateFormat('yyyy-MM-dd').format(_startDate)}',
              style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
            ),
            DropdownButtonFormField(
              value: _priority,
              decoration: const InputDecoration(labelText: 'Priorytet'),
              items: [1, 2, 3].map((priority) {
                return DropdownMenuItem(
                  value: priority,
                  child: Text(priority.toString()),
                );
              }).toList(),
              onChanged: (value) {
                setState(() {
                  _priority = value!;
                });
              },
            ),
            ElevatedButton(
              child: const Text('Zapisz zadanie'),
              onPressed: () {
                if (_formKey.currentState!.validate()) {
                  _formKey.currentState?.save();
                  Navigator.pop(
                      context,
                      Task(
                          id: widget.tasks.length + 1,
                          name: _name,
                          description: _description,
                          startDate: _startDate,
                          priority: _priority));
                }
              },
            ),
          ],
        ),
      ),
    );
  }
}

class TaskDetail extends StatelessWidget {
  final Task task;
  final Function onDelete;

  const TaskDetail({super.key, required this.task, required this.onDelete});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(task.name),
        actions: <Widget>[
          IconButton(
            icon: const Icon(Icons.delete),
            onPressed: () {
              onDelete();
              Navigator.pop(context);
            },
          ),
        ],
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Text(
            'Opis: ${task.description}\nData rozpoczęcia: ${DateFormat('yyyy-MM-dd').format(task.startDate)}\nPriorytet: ${task.priority}'),
      ),
    );
  }
}

class EditTaskScreen extends StatefulWidget {
  final Task task;
  final int index;
  final List<Task> tasks;

  const EditTaskScreen(
      {super.key,
      required this.task,
      required this.index,
      required this.tasks});

  @override
  // ignore: library_private_types_in_public_api
  _EditTaskScreenState createState() => _EditTaskScreenState();
}

class _EditTaskScreenState extends State<EditTaskScreen> {
  final _formKey = GlobalKey<FormState>();
  late String _name;
  late String _description;
  late DateTime _startDate;
  late int _priority;

  @override
  void initState() {
    super.initState();
    _name = widget.task.name;
    _description = widget.task.description;
    _startDate = widget.task.startDate;
    _priority = widget.task.priority;
  }

  Future<void> _selectDate(BuildContext context) async {
    final DateTime? picked = await showDatePicker(
      context: context,
      initialDate: _startDate,
      firstDate: DateTime(2015, 8),
      lastDate: DateTime(2101),
    );
    if (picked != null && picked != _startDate) {
      setState(() {
        _startDate = picked;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Edytuj zadanie'),
      ),
      body: Form(
        key: _formKey,
        child: Column(
          children: <Widget>[
            TextFormField(
              initialValue: _name,
              decoration: const InputDecoration(labelText: 'Nazwa zadania'),
              validator: (value) {
                if (value!.isEmpty) {
                  return 'Proszę wprowadzić nazwę zadania';
                }
                return null;
              },
              onSaved: (value) {
                _name = value!;
              },
            ),
            TextFormField(
              initialValue: _description,
              decoration: const InputDecoration(labelText: 'Opis zadania'),
              validator: (value) {
                if (value!.isEmpty) {
                  return 'Proszę wprowadzić opis zadania';
                }
                return null;
              },
              onSaved: (value) {
                _description = value!;
              },
            ),
            ElevatedButton(
              onPressed: () => _selectDate(context),
              child:
                  Text('Wybierz datę: ${_startDate.toLocal()}'.split(' ')[0]),
            ),
            Text(
              'Wybrana data: ${DateFormat('yyyy-MM-dd').format(_startDate)}',
              style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
            ),
            DropdownButtonFormField(
              value: _priority,
              decoration: const InputDecoration(labelText: 'Priorytet'),
              items: [1, 2, 3].map((priority) {
                return DropdownMenuItem(
                  value: priority,
                  child: Text(priority.toString()),
                );
              }).toList(),
              onChanged: (value) {
                setState(() {
                  _priority = value!;
                });
              },
            ),
            ElevatedButton(
              child: const Text('Zapisz zadanie'),
              onPressed: () {
                if (_formKey.currentState!.validate()) {
                  _formKey.currentState?.save();
                  Navigator.pop(
                      context,
                      Task(
                          id: widget.tasks.length + 1,
                          name: _name,
                          description: _description,
                          startDate: _startDate,
                          priority: _priority));
                }
              },
            ),
          ],
        ),
      ),
    );
  }
}

class DatabaseHelper {
  static const _databaseName = "TaskDatabase.db";
  static const _databaseVersion = 1;

  static const table = 'tasks';

  static const columnId = '_id';
  static const columnName = 'name';
  static const columnDescription = 'description';
  static const columnStartDate = 'start_date';
  static const columnPriority = 'priority';

  DatabaseHelper._privateConstructor();
  static final DatabaseHelper instance = DatabaseHelper._privateConstructor();

  static Database? _database;
  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDatabase();
    return _database!;
  }

  _initDatabase() async {
    String path = join(await getDatabasesPath(), _databaseName);
    return await openDatabase(path,
        version: _databaseVersion, onCreate: _onCreate);
  }

  Future _onCreate(Database db, int version) async {
    await db.execute('''
          CREATE TABLE $table (
            $columnId INTEGER PRIMARY KEY,
            $columnName TEXT NOT NULL,
            $columnDescription TEXT NOT NULL,
            $columnStartDate TEXT NOT NULL,
            $columnPriority INTEGER NOT NULL
          )
          ''');
  }

  Future<int> insert(Task task) async {
    Database db = await instance.database;
    return await db.insert(table, task.toMap());
  }


  Future<List<Map<String, dynamic>>> queryAllRows() async {
    Database db = await instance.database;
    return await db.query(table);
  }

  Future<int?> queryRowCount() async {
    Database db = await instance.database;
    return Sqflite.firstIntValue(
        await db.rawQuery('SELECT COUNT(*) FROM $table'));
  }

  Future<int> update(Task task) async {
    Database db = await instance.database;
    int id = task.toMap()[columnId];
    return await db
        .update(table, task.toMap(), where: '$columnId = ?', whereArgs: [id]);
  }

  Future<int> delete(int id) async {
    Database db = await instance.database;
    return await db.delete(table, where: '$columnId = ?', whereArgs: [id]);
  }
}
