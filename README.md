![Pocket Wordle](https://i.imgur.com/2Eh3cfN.png)

# Pocket Wordle

Pocket Wordle is tiny (just 300 KB), local, and C++ version of the popular New York Times word game, [Wordle](https://www.nytimes.com/games/wordle/index.html).

## Coursework

This repository was developed as part of COM S 327 (Advanced Programming Techniques) at Iowa State University, instructed by Dr. Jeremy Sheaffer.

## Disclaimer

If you're playing Pocket Wordle on a remote host (such as through ssh), you may experience some issues with the keyboard and display. For the best experience, please build and run Pocket Wordle on your local machine.

If you need to play Pocket Wordle on a remote host, you can use `tmux` to solve most rendering issues. To do so, run the following commands after building the project:

```bash
tmux
./pocketwordle
```

## Building the Project

In order to build Pocket Wordle, you will need to have the following installed:

- [g++](https://gcc.gnu.org/)
- [ncurses](https://invisible-island.net/ncurses/)

Once you have these installed, you can build Pocket Wordle by running the following commands:

```bash
make
```

## Running the Project

Once you have built Pocket Wordle, you can run it by running the following command:

```bash
./pocketwordle
```

## Playing the Game

Pocket Wordle is played exactly like the original Wordle game, with one change. Here are the rules:

1. You have five guesses (instead of six) to guess a 5-letter word.

2. After each guess, you will be shown which letters you guessed correctly, and which letters you guessed incorrectly.

3. If you guess a letter correctly, it will be shown in green. If you guess a letter incorrectly, but it exists in the word, it will be shown in yellow. If you guess a letter incorrectly, and it does not exist in the word, it will be shown in gray.

4. If you guess the word correctly, you win! If you do not guess the word correctly after five guesses, you lose. Though, you have the opportunity to play again by hitting any key after the game ends.

## Tips

- The word is randomly generated each time you play, so you will (hopefully) never play the same word twice.

- The word is always a valid English word, and is always five letters long.

- The keyboard is available on the screen, so you can visualize which letters you have already guessed and which letters you have not.

- There are over 1,000 words available in Pocket Worlde, so you can play as long as you want!
