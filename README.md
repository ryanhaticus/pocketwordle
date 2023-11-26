![Pocket Wordle](https://i.imgur.com/2Eh3cfN.png)

# Pocket Wordle

Pocket Wordle is tiny (just 300 KB), local, and C++ version of the popular New York Times word game, [Wordle](https://www.nytimes.com/games/wordle/index.html).

## Coursework

This repository was developed as part of COM S 327 (Advanced Programming Techniques) at Iowa State University, instructed by Dr. Jeremy Sheaffer.

## Disclaimer

If you're playing Pocket Wordle through ssh, you may experience some issues with the keyboard and display. You can fix these issues by [allocating the terminal beforehand](https://unix.stackexchange.com/questions/304699/ncurses-over-ssh-will-they-be-displayed), but this is not guarenteed to work depending on your terminal emulator and ssh client.

For the best experience, please build and run Pocket Wordle on your local machine.

## Building the Project

In order to build Pocket Wordle, you will need to have the following installed:

- [CMake](https://cmake.org/)
- [g++](https://gcc.gnu.org/)
- [ncurses](https://invisible-island.net/ncurses/)

Once you have these installed, you can build Pocket Wordle by running the following commands:

```bash
./build.sh
```

or, alternatively,

```bash
cmake .
make
```

## Running the Project

Once you have built Pocket Wordle, you can run it by running the following command:

```bash
./run.sh
```

or, alternatively,

```bash
./pocketwordle
```

## Playing the Game

Pocket Wordle is played exactly like the original Wordle game, with one change. Here are the rules:

1. You have five guesses (instead of six) to guess a 5-letter word.

2. After each guess, you will be shown which letters you guessed correctly, and which letters you guessed incorrectly.

3. If you guess a letter correctly, it will be shown in green. If you guess a letter incorrectly, but it exists in the word, it will be shown in yellow. If you guess a letter incorrectly, and it does not exist in the word, it will be shown in gray.

## Tips

- The word is randomly generated each time you play, so you will (hopefully) never play the same word twice.

- The word is always a valid English word, and is always five letters long.

- The keyboard is available on the screen, so you can visualize which letters you have already guessed and which letters you have not.
