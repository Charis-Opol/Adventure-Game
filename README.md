# Adventure_Game
A text based adventure game developed as a class project
# The Adventure Game

This is a simple text-based adventure game written in C. The player can choose from three different character classes (Witch, Warrior, and Princess), each with their own unique storyline and challenges.

## How to Play

1.  **Compile the code:** Use a C compiler (like GCC) to compile the `main.c` file. For example:

    ```bash
    gcc main.c -o adventure
    ```

2.  **Run the executable:** Execute the compiled program:

    ```bash
    ./adventure
    ```

3.  **Follow the prompts:** The game will present you with text descriptions and choices. Enter the corresponding numbers to make decisions and progress through the story.

## Game Features

*   **Character Selection:** Choose between a Witch, a Warrior, or a Princess, each with a distinct storyline.
*   **Witch Story:** Search for rare herbs in a forest or explore a mysterious cave, facing challenges and a dragon encounter.
*   **Warrior Story:** Embark on a quest for vengeance, wisdom, or mystical power, leading to a final battle.
*   **Princess Story:** Escape from a tower by finding a hidden artifact and guessing a PIN or waiting for a prince's rescue.
*   **Multiple Endings:** The game has different outcomes depending on the player's choices.
*   **Riddle and Random Events:** Encounter a riddle in the cave and experience random events during the Witch's story.

## Code Structure

*   `main.c`: Contains the main game logic, including character selection, story progression, and game over conditions.
*   Functions are used to organize the code into logical sections, such as `startgame()`, `chooseCharacter()`, `witchStory()`, `warrior_story()`, `princess_story()` and other story-specific functions.

## Future Improvements

*   **More complex storylines:** Expand the existing storylines with more choices and consequences.
*   **Inventory system:** Implement an inventory system to allow players to collect and use items.
*   **Combat system:** Develop a more detailed combat system for the Warrior path.
*   **Sound effects and music:** Add sound effects and background music to enhance the gaming experience.
*   **More robust input validation:** Handle invalid user input more gracefully.
*   **Save/Load functionality:** Allow players to save and load their game progress.
*   **User interface and graphics** To improve user experience

## Author

This game was created by 1's and 0's.


