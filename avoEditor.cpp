#include <iostream>
#include <string>
#include "gapBuffer.h"

int main() {
  gapBuffer buffer;

  string command;

  cout << "avoEditor Gap Buffer Text Editor" << endl;
  cout << "i {char} | left | right | delete | print" << endl;

  while (1) {
    getline(cin, command);

    cout << '\n';

    if (command[0] == 'i') {
      if (command[1] != ' ' || command.size() > 3) {
        cout << "Incorrect Insert Command" << endl;
        exit(1);
      }
      buffer.insert(command[2]);
    } else if (command == "left") {
      buffer.left();
    } else if (command == "right") {
      buffer.right();
    } else if (command == "delete") {
      buffer.remove();
    } else if (command != "print") {
      cout << "Incorrect Command" << endl;
      exit(1);
    }

    buffer.printContents();

  }
}