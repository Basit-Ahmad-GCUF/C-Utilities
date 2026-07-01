# C-Utilities
A custom C++ Library For students to Help them in thier Projects.

# utilities.h

## About
"Utilities" As the name Suggests, is a Library Containing all the Necessary Functions that are used in almost every C++ project(Student). I myself had faced many problems with C++ in the very start, This Library would have helped me a lot.
It has Fucntions for:
1. Getting Input.
2. Styling Output.
3. Drawing in Console. etc
The Details are Given below.

## Namespaces
### color::
Provides ANSI escape code string constants for console text coloring. Includes 8 standard colors 
```
black, red, green, yellow, blue, magenta, cyan, white
```
And 8 bright variants prefixed with b_ (b_red, b_green etc). 
```
b_black, b_red, b_green, b_yellow, b_blue, b_magenta, b_cyan, b_white
```
Also A Fucntion to Reset the Entire Consloe
```
color::reset
```
Use with std::cout.
### style::
Provides ANSI text style constants
```
bold, dim, italic, underline, blink
```
Combine with color constants freely. 
Use with std::cout.

## Classes
### sys::
```
clearscreen();
```
Clears the console.
```
pause();
```
Waits for any keypress.
```
playspinner(cycles, msg);
```
Animated loading spinner.
```
printdots(count);
```
Prints dots with delay, useful for exit animations.
```
type_write(message);
```
Typewriter effect for strings.
```
timer(time, message);
```
Countdown timer displayed inline.
```
maskedinput();
```
Password input showing * instead of characters, Returns the Real String.
```
getint(message);
```
Validated integer input, loops until valid.
```
getfloat(message);
```
Validated float input, loops until valid.
### design::
```
line(n, symbol);
```
Prints a symbol n times in a row
```
draw_header(message, symbol);
```
Draws a centered box with message inside

## How to Use
### Step 1 — Copy the file
Take utilities.h and put it in the same folder as your .cpp project file.

### Step 2 — Include it
At the very top of your .cpp file, write:
```
#include "utilities.h"
```
That's it! Now everything inside is available to use.

### Step 3 — Using colors
Want red text? Just write:
```
std::cout << color::red << "This is red!" << color::reset;
```
Always put color::reset at the end or everything after it stays colored too!

### Step 4 — Using styles
Want bold text?
```
std::cout << style::bold << "This is bold!" << color::reset;
```
You can combine color and style together:
```
std::cout << color::green << style::bold << "Bold Green!" << color::reset;
```
### Step 5 — Using sys::
Want to clear the screen?
```
sys::clearscreen();
```
Want safe integer input?
```
int age = sys::getint("Enter your age: ");
```
It won't crash if user types letters — it keeps asking until a valid number is entered!

### Step 6 — Using design::
Use to Draw Lines are Boxes with Headers.
```
design::line(20, "=");             // prints ====================
design::draw_header("Hello", "="); // prints a box around Hello
```

## Author
Basit Ahmad 
Github: Basit-Ahmad-GCUF

## End-Note
If you have any Problem using the Library You can Contact me!
