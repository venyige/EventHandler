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

## Notes on implementation

The series of events in term of the actual project (series of pseudo events) is triggered by hitting the “Enter” key after a zero or more string inputs. For more sophisticated (time-based) key event handling please take a look at 
[`Flatland-simulator-right-Now`](https://github.com/venyige/Flatland-simulator-right-Now)
where I have used the `Curses` library.

In this sense the “real” event is a space-separated string input. I have implemented the logic in the [`main()`](test/keyEvent/Main.cpp) function to handle this event in order to dispatch it to the pseudo events of processing the sub strings, those pseudo events are handled by an instance of [`KeyEventListener`](test/keyEvent/KeyEventListener.h) class.

To filter on the numeric strings I utilized the `std::stold()` which is good enough to process
- general integer,
- general floating point,
- scientific,
- hexadecimal,
- and infinity as e.g. `inf`  

formats of numbers. As `std::out_of_range` exception is being handled with SFINAE spirit, there is no need to fit to `long double` in order to be judged number. Note that integer strings are to be converted to `long double`.

The processing is limited to put the strings to the standard output, so there would have been good enough solution to simply `std::cout<<` them, but taking the job assignment into consideration, I had to assume that there was some additional purpose behind the distinction between the alphabetic and numerical strings. That is why I decided to put more work in the number formats than that, playing around with it a bit more. It becomes obvious if the program is being started with “-v” switch.

To invoke the callbacks, the `Event::Raise(const EventArgs& iArgs)` is to be called, so functionally there is no need to store the `Event` instances in the [`KeyEventListener`](test/keyEvent/KeyEventListener.h).
While functionally there is no need for this, in a real-life application there is, because we should handle the events via the highest level access possible. So, instead of passing references, I have moved them into the  [`KeyEventListener`](test/keyEvent/KeyEventListener.h) instance in order to handle out and bind their life cycle to that of the  [`KeyEventListener`](test/keyEvent/KeyEventListener.h) as best practice in a real-life scenario, where there are lots of event and event listener instances existing simultaneously or in overlapping life cycles.