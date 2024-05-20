// flutter pub add math_expressions - installation of math_expressions
import 'dart:math';
import 'package:flutter/material.dart';
import 'package:math_expressions/math_expressions.dart';

void main() {
  runApp(const MaterialApp(home: SimpleCalculator()));
}

class SimpleCalculator extends StatefulWidget {
  const SimpleCalculator({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _SimpleCalculatorState createState() => _SimpleCalculatorState();
}

class _SimpleCalculatorState extends State<SimpleCalculator> {
  String equation = "0";
  String result = "0";
  List<String> history = [];
  bool isPower = false;

  void buttonPressed(String buttonText) {
    setState(() {
      if (buttonText == "C") {
        equation = "0";
        result = "0";
      } else if (buttonText == "⌫") {
        equation = equation.substring(0, equation.length - 1);
        if (equation == "") {
          equation = "0";
        }
      } else if (buttonText == "=") {
        if (isPower) {
          List<String> parts = equation.split('^');
          double base = double.parse(parts[0]);
          double exponent = double.parse(parts[1]);
          result = (pow(base, exponent)).toString();
          history.add("$equation = $result");
          equation = result;
          isPower = false;
        } else {
          try {
            Parser p = Parser();
            Expression exp = p.parse(equation);
            ContextModel cm = ContextModel();
            result = '${exp.evaluate(EvaluationType.REAL, cm)}';
            history.add("$equation = $result");
            equation = result;
          } catch (e) {
            result = "Error";
          }
        }
      } else if (buttonText == "^") {
        isPower = true;
        equation = equation + buttonText;
      } else if (buttonText == "BIN") {
        String binResult = int.parse(result.split('.')[0]).toRadixString(2);
        equation = 'BIN $binResult';
      } else if (buttonText == "OCT") {
        String octResult = int.parse(result.split('.')[0]).toRadixString(8);
        equation = 'OCT $octResult';
      } else if (buttonText == "HEX") {
        String hexResult = int.parse(result.split('.')[0]).toRadixString(16);
        equation = 'HEX $hexResult';
      } else if (buttonText == "HIST") {
        showDialog(
          context: context,
          builder: (context) {
            return AlertDialog(
              content: SizedBox(
                height: MediaQuery.of(context).size.height *
                    0.4,
                child: SingleChildScrollView(
                  child: Column(
                    children: history.map((item) => Text(item)).toList(),
                  ),
                ),
              ),
            );
          },
        );
      } else {
        if (equation == "0") {
          equation = buttonText;
        } else {
          equation = equation + buttonText;
        }
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Calculator - task 2')),
      body: Column(
        children: <Widget>[
          Container(
            alignment: Alignment.centerRight,
            padding: const EdgeInsets.fromLTRB(10, 20, 10, 0),
            child: Text(equation, style: const TextStyle(fontSize: 38.0)),
          ),
          Container(
            alignment: Alignment.centerRight,
            padding: const EdgeInsets.fromLTRB(10, 30, 10, 0),
            child: Text(result, style: const TextStyle(fontSize: 48.0)),
          ),
          const Expanded(child: Divider()),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              SizedBox(
                width: MediaQuery.of(context).size.width,
                child: Table(
                  children: [
                    TableRow(children: [
                      buildButton("BIN", 1, Colors.green),
                      buildButton("OCT", 1, Colors.green),
                      buildButton("HEX", 1, Colors.green),
                      buildButton("HIST", 1, Colors.green),
                    ]),
                    TableRow(children: [
                      buildButton("C", 1, Colors.redAccent),
                      buildButton("⌫", 1, Colors.blue),
                      buildButton("%", 1, Colors.blue),
                      buildButton("^", 1, Colors.blue),
                    ]),
                    TableRow(children: [
                      buildButton("7", 1, Colors.black54),
                      buildButton("8", 1, Colors.black54),
                      buildButton("9", 1, Colors.black54),
                      buildButton("*", 1, Colors.blue),
                    ]),
                    TableRow(children: [
                      buildButton("4", 1, Colors.black54),
                      buildButton("5", 1, Colors.black54),
                      buildButton("6", 1, Colors.black54),
                      buildButton("-", 1, Colors.blue),
                    ]),
                    TableRow(children: [
                      buildButton("1", 1, Colors.black54),
                      buildButton("2", 1, Colors.black54),
                      buildButton("3", 1, Colors.black54),
                      buildButton("+", 1, Colors.blue),
                    ]),
                    TableRow(children: [
                      buildButton(".", 1, Colors.black54),
                      buildButton("0", 1, Colors.black54),
                      buildButton("00", 1, Colors.black54),
                      buildButton("=", 1, Colors.redAccent),
                    ]),
                  ],
                ),
              ),
            ],
          ),
        ],
      ),
    );
  }
Widget buildButton(String buttonText, double buttonHeight, Color buttonColor) {
  return Container(
    height: MediaQuery.of(context).size.height * 0.1 * buttonHeight,
    decoration: BoxDecoration(
      border: Border.all(color: Colors.black, width: 2), // This adds the border
      color: buttonColor,
    ),
    child: TextButton(
      style: TextButton.styleFrom(
        padding: const EdgeInsets.all(16.0),
      ),
      onPressed: () => buttonPressed(buttonText),
      child: Text(
        buttonText,
        style: const TextStyle(
            fontSize: 30.0,
            fontWeight: FontWeight.normal,
            color: Colors.white),
      ),
    ),
  );
}

}
