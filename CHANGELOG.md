11/25/2023 11:59 AM: Setup the CMake build tool

11/25/2023 12:14 PM: Implemented the game, board, cell, and render classes

11/25/2023 12:32 PM: Built out a basic render method

11/25/2023 12:47 PM: Identified some code complexities with the cursor and rows. As a result, implemented both row and cursor classes.

11/25/2023 1:01 PM: Implemented a render loop that takes user input.

11/25/2023 1:16 PM: Parsing user input to add letters to the board.

11/25/2023 1:29 PM: Identified an issue where hitting backspace isn't handled correctly.

11/25/2023 1:44 PM: Fixed the backspace issue. Now, we don't move the cursor if the cell we're backspacing on isn't empty. Instead, we just delete the character.

11/25/2023 1:55 PM: Fixed a misconfiguration of ncurses. Reenabled buffering as well since we don't need to be constantly refreshing the screen.

11/25/2023 2:10 PM: Finished working on a status bar that shows whether the user has won or lost.

11/25/2023 2:24 PM: Added a method to check if the user has won or lost.

11/25/2023 3:39 PM: Cleaned up rendering and dreamt up a nice "Pocket Worldle" title.

11/25/2023 3:48 PM: Added the real Wordle colors as ncurses color pairs.

11/25/2023, 5:04 PM: Finished the keyboard which shows which letters have been guessed and which letters have not.

11/26/2023, 1:02 AM: Fixed a bug where uppercase letters weren't recognized.

11/26/2023, 1:10 AM: Added a proper window title with `iostream`.

11/26/2023, 1:42 AM: Downgraded CMake to the version running on Pyrite.

11/26/2023, 1:46 AM: Finished writing documentation for the `README.md` file.

11/26/2023, 7:33 PM: Moved off of CMake to a simple `Makefile` and updated build/run documentation.
