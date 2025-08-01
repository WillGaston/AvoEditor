#include <iostream>
#include "gapBuffer.h"

gapBuffer::gapBuffer() {
  contents = vector<char>(50);
  leftPtr = 0;
  rightPtr = contents.size();
}

void gapBuffer::left() {
  if (leftPtr != 0) {
    leftPtr--;
    rightPtr--;
    contents[rightPtr] = contents[leftPtr];
  }
}

void gapBuffer::right() {
  if (rightPtr != contents.size()) {
    contents[leftPtr] = contents[rightPtr];
    leftPtr++;
    rightPtr++;
  }
}

void gapBuffer::insert(char newChar) {
  // buffer has size 0
  if (leftPtr == rightPtr) {
    grow();
  }
  contents[leftPtr] = newChar;
  leftPtr++;
}

void gapBuffer::grow() {
  int oldSize = contents.size();
  contents.resize(50 + oldSize);

  for (int i = oldSize - 1; i >= 0; i--) {
    contents[rightPtr + oldSize + 1] = contents[rightPtr + 1];
  }
}

void gapBuffer::remove() {
  if (rightPtr != 0) {
    rightPtr++;
  }
}

void gapBuffer::printContents() {
  for (int i = 0; i < contents.size(); i++) {
    if (i == leftPtr) cout << '|';
    else if (i > leftPtr && i < rightPtr) continue;
    else cout << contents[i];
  }
  cout << endl;
}
