# EventHandler

## Description

Create a simple console application that reads alphanumeric words (delimited by spaces) from the standard input 
and raises an event if the current word is a number (e.g. "1024") or a simple string (e.g. "apple").

You should add and implement a `Main.cpp` under the [`keyEvent`](test/keyEvent/) folder 
where you read the words from the standard input.

Furthermore, you should implement the [`KeyEventListener`](test/keyEvent/KeyEventListener.h) class 
for handling the events:

- You can only use the [`Event`](src/Event.h) and [`EventArgs`](src/EventArgs.h) class in this example,
- The `void onNumber(...)` function must be called if a number was read from the standard input,
- The `void onString(...)` function must be called if a string was read from the standard input.

The `onNumber(...)` and `onString(...)` must print out the number or string into the standard output.

HINT: you can inherit from `EventArgs` class for this reason.

HINT: you can modify the [`KeyEventListener`](test/keyEvent/KeyEventListener.h) class the way you want, 
but the classes under the [`src`](src) should not be touched.