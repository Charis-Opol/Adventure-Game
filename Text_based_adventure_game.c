#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char characterName[50];   // This stores the character name 

// Function Prototypes
void startgame(); // Function prototype for the function that starts the entire game
void chooseCharacter(); // Function prototype for the function for choosing the characters
void witchStory(); // Function prototype for the function that intiates the witch's story
void choosePath(); // Function prototype for the function for the witch choosing a path
void herbSearch(); // Function prototype for the function for the to search for the herb
void treeClimb(); // Function prptotpye for the function for witch climb a tree
void exploreCave(); // Function prototype for the function for the witch to explore the cave
void randomEvent(); // Function prototype for the function that brings about a random event
void dragonEncounter(); // Function prototype for the function that brings the dragon encounter
void warrior_story(); // Function prototype for the function that intiates the warrior's story
void warrior_introduction(); // Function prototype for the function that that introduces the warriors story
void pathOfVengeance(); // Function prototype for the function that carries out the path of vengance
void pathOfWisdom(); // Function prototype for the function that carries out the path of wisdom
void pathOfMystic(); // Function prototype for the function that carries out the path of divination
void finalBattle(int hasArtifact); // Function prototype for the function that leads to the final battle
void princess_story(); // Function prototype for the function for te princess story

int main(){
    startgame();
    return 0;
}

// Function for starting the game and taking input for character's name
void startgame(){
    printf("Welcome to Mystic Realms!\n");

    // Ask the player to enter their character's name
    printf("Please enter your character's name: ");
    fgets(characterName, sizeof(characterName), stdin);
    characterName[strcspn(characterName, "\n")] ='\0';  // Removes the newline character from input

    printf("Welcome, %s!\n", characterName);
    chooseCharacter(); // Call out the Funcion to pick characters
}

// Function to let the player choose their character
void chooseCharacter(){
    int choice;
    printf("Choose your Character:\n");
    printf("1. Witch\n2. Warrior\n3. Princess\n");
    scanf("%d", &choice);

    if (choice == 1){
        witchStory();
    }
    else if (choice == 2)
    {
        warrior_story();
    }
    else if (choice == 3)
    {
        princess_story();
    } 
    else{
        printf("Invalid Character. Restart the game.\n");
        startgame();
    }
}

// Function to the Witch Story - the main story of the Witch of Dokoloma
void witchStory(){
    printf("%s, you are the Witch of Dokoloma. You are searching for a rare ingredient for a magical potion to cast a powerful spell.\n", characterName);
    choosePath();
}

// Function to let the player choose between different paths (Forest or Cave)
void choosePath(){
    int choice;
    printf("What would you do?\n");
    printf("1. Search the mysterious forest for herbs\n");
    printf("2. Approach the mysterious cave\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            herbSearch(); // Proceed to the forest
            break;
        case 2:
            exploreCave(); // Proceed to the cave
            break;
        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
            choosePath();
    }
}

// Function for searching the forest for herbs
void herbSearch(){
    int choice;
    printf("You are in the forest, looking for rare herbs.\n");
    printf("You see three possible locations:\n");
    printf("1. Search the roots\n2. Climb a tree\n3. Check the bushes\n");
    printf("Enter your choice");

    scanf("%d", &choice);

    if (choice == 1){
        printf("You find an old root, but it's not the one you're looking for.\n");
        printf("Would you like to search again? (1 for yes, 2 for no): ");
        int retrychoice; 
        printf(" Enter your choice:");
        scanf("%d", &retrychoice);
        if (retrychoice == 1){
            herbSearch(); // Calls the function again to give the user a chance to retry the herb search
        } else {
            printf("You leave the forest empty-handed.\n");
        }
    }
    else if (choice == 2){
        treeClimb(); // Proceed to climb the tree
    }
    else if (choice == 3){
        printf("You search the bushes and find a thorn that pricks you!\n");
        printf("GAME OVER! %s, you died from the thorn.\n", characterName);
    }
}

// Function for climbing the tree and triggering random events
void treeClimb(){
    printf("You begin climbing a tree...\n");
    printf("As you climb, you hear a rustling noise in the branches.\n");

    // Give the player multiple options with potential for Game Over
    printf("What will you do?\n");
    printf("1. Continue climbing\n");
    printf("2. Look down to see what's making the noise\n");
    printf("3. Climb back down\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1){
        printf("You keep climbing higher. Suddenly, a branch snaps under your weight!\n");
        printf("You fall to the ground. GAME OVER!\n");
    }
    else if (choice == 2){
        printf("You look down, and you see a wild animal creeping up the tree towards you!\n");
        printf("The animal attacks before you can react. GAME OVER!\n");
    }
    else if (choice == 3){
        printf("You climb back down safely, but the herbs remain out of reach.\n");
        printf("GAME OVER - You left the forest empty-handed.\n");
    }
    else {
        printf("Invalid choice! The branch snaps and you fall. GAME OVER!\n");
    }
}

// Function for exploring the cave and solving the riddle
void exploreCave(){
    char answer[20];
    int attempts = 3;

    printf("You approach a cave with a large stone door. A voice booms: 'SOLVE THE RIDDLE TO ENTER.'\n");
    printf("RIDDLE: I speak without a mouth and hear without ears. What am I?\n");

    while(attempts > 0) {
        printf("Your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';  // Remove newline character

        if (strcmp(answer, "echo") == 0){
            printf("Correct! The entrance of the cave opens.\n");
            dragonEncounter(); // Proceed to encounter the dragon
            return;
        } else {
            attempts--;
            if (attempts > 0){
                printf("Incorrect answer. You have %d attempts left.\n", attempts);
            } else {
                printf("Incorrect! You failed the riddle and cannot enter the cave.\n");
                printf("GAME OVER!\n");
            }
        }
    }
}

// Functions for random events that may occur during the game
void randomEvent(){
    int event = rand() % 3; // Random number to decide the event

    if(event == 0){
        printf("Suddenly, a storm brews! The wind howls, making it hard to see.\n");
        printf("The storm rages on and sweeps you away. GAME OVER!\n");
    } else if(event == 1){
        printf("A wild animal appears in front of you! It looks like it wants to have you for a meal.\n");
        printf("You couldn't escape the animal in time. %s, GAME OVER!\n", characterName);
    } else {
        printf("You hear a distant voice calling out your name...\n");
    }
}

// Functions for encountering the dragon in the cave
void dragonEncounter(){
    printf("As you step deeper into the cave, you encounter a massive dragon guarding a treasure!\n");
    printf("The dragon growls at you and breathes fire. What will you do?\n");
    printf("1. Cast a protective shield\n2. Try to outrun the dragon\n3. Attempt to reason with the dragon\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1){
        printf("You cast a powerful protective shield just in time! The dragon roars in frustration.\n");
        printf("You narrowly escape and find the potion formula! You have succeeded!\n");
        printf("GAME OVER - You have survived the cave and completed your mission!\n");
    } else if (choice == 2){
        printf("You try to outrun the dragon, but it catches you with its fiery breath.\n");
        printf("GAME OVER! %s, the dragon has defeated you.\n", characterName);
    } else if (choice == 3){
        printf("You try to reason with the dragon, but it doesn't trust you.\n");
        printf("The dragon attacks! GAME OVER!\n");
    } else {
        printf("Invalid choice! The dragon grows angrier and attacks.\n");
        printf("GAME OVER!\n");
    }
}

// Functions for intiating the warrior story
void warrior_story() {
    warrior_introduction();
}

// Functions for introducing te warrior story
void warrior_introduction() {
    int choice;
    printf("You are a renowned warrior, known throughout the land for your unmatched skill and courage. Your name, %s, strikes fear into the hearts of your enemies. However, dark times have befallen your home. The once peaceful village of Ngoma has been ravaged by a merciless enemy, your family taken captive, and your honor stained.\n\nWith nothing but your warrior's instincts and the fire of vengeance burning in your heart, you must embark on a perilous journey across ancient lands. The fate of your family, your honor, and the future of your people rests in your hands.\nWelcome, %s! Choose your path:\n", characterName);
    printf("1. The Path of Vengeance. You choose to march directly toward Rukundo's fortress, your heart filled with rage and your spear ready for battle\n");
    printf("2. The Path of Wisdom. You decide to consult the wise Elder Kato, a shaman who has lived through the rise and fall of many warriors\n");
    printf("3. The Path of the Mystic.  Desperation drives you to seek the aid of the mysterious Witch Doctor Nambi, are but you are willing to risk anything if it means saving your family.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            pathOfVengeance();
            break;
        case 2:
            pathOfWisdom();
            break;
        case 3:
            pathOfMystic();
            break;
        default:
            printf("Invalid choice. Game Over.\n");
    }
}

//Function for the path of vengeance
void pathOfVengeance() {
    int choice;
    printf("You chose the Path of Vengeance. What will you do?\n");
    printf("1. Ambush the Enemy Scouts\n");
    printf("2. Sneak into the Fortress\n");
    printf("3. Challenge General Rukundo to a Duel\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Your ambush succeeded! You proceed to the fortress.\n");
        finalBattle(0); // The final battle function is called and the parameter is zero
    } else if (choice == 2) {
        printf("You are spotted by the guards. You are injured but manage to escape. Continue to the final battle.\n");
        finalBattle(0); // The final battle function is called and the parameter is zero
    } else if (choice == 3) {
        printf("You are ambushed during the duel. Game Over.\n");
    } else {
        printf("Invalid choice. Game Over.\n");
    }
}

// Functions for the path of wisdom
void pathOfWisdom() {
    int choice;
    printf("You chose the Path of Wisdom. What will you do?\n");
    printf("1. Search for the Hidden Artifact\n");
    printf("2. Rally the Villagers\n");
    printf("3. Meditate for a Vision\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You found the Amulet of Protection!\n");
        finalBattle(1); // The final battle function is called and the parameter is one
    } else if (choice == 2 || choice == 3) {
        printf("You proceed without any special advantages.\n");
        finalBattle(0); // The final battle function is called and the parameter is zero
    } else {
        printf("Invalid choice. Game Over.\n");
    }
}

// Functions for the path of Divination and Mystic arts
void pathOfMystic() {
    int choice;
    printf("You chose the Path of the Mystic. What will you do?\n");
    printf("1. Accept the Potion of Strength\n");
    printf("2. Bargain for a Magical Weapon\n");
    printf("3. Refuse the Witch's Aid\n");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        printf("You gain powerful abilities!\n");
        finalBattle(1); // The final battle function is called and the parameter is one
    } else if (choice == 3) {
        printf("You proceed without the witch's help.\n");
        finalBattle(0); // The final battle function is called and the parameter is zero 
    } else {
        printf("Invalid choice. Game Over.\n");
    }
}

// Functions for the final battle. The artifact is the parameter and it is either one or zero. If the artifact is 1 they have it and if it is zero they don't
void finalBattle(int hasArtifact) {
    if (hasArtifact == 1) {
        printf("With the power of your artifact, you defeat General Rukundo and save your family. You are a hero!\n\n");
    } else {
        printf("The battle is tough, and you fight bravely. However, without any special advantage, you are defeated. Game Over.\n\n");
    }
}

// Function for the princess story.
void princess_story(){ 

int response;
printf("You are %s, a princess from the kingdom of Maalio-Mombasa \n and you are locked in a tower \n you have to find a way to escape \n", characterName); 
printf("You have 2 options\n1. Search for an ancient artifact which is the key to your escape \n 2. Wait for your one true love, Prince Opol to come and rescue you \n\n"); 
printf("Enter 1 or 2"); 
scanf("%d", &response);
    // If statement to check user response  
    if (response == 1) 
    { 
        printf("You found a chest with the artifact but it requires you to input the correct PIN \n\n The PIN is a number between 0 and 10 \n\n I wish you luck because you are gonna need it! \n\n"); 
        printf("You have 7 chances only\n"); 

        int chances = 7;   
        // Generate the random number 
        int correct_number = rand() % 10; 
        // Variable to store user number  
        int user_guess = 0; 

        // While loop to ask user for correct PIN 
        while (chances >= 0) 
        { 
            // Prompt user to enter their guesss 
            printf("Enter your guess >>"); 
            // Store user_guess in memory 
            scanf("%d", &user_guess); 
            // If statement to check if user entered the right number  
            if (user_guess == correct_number) { 
               // Tell user they got the number right 
               printf("You got the PIN right! You now have the key!\n\n"); 
               printf ("You have won the game :) !"); 
               break;
            } else if (chances == 0) 
            {
                // If all your guesses are done and you haven't yet gotten the number right then you repeat 
                // Tell user they are gonna repeat since they haven't gotten the PIN right and have exhausted all their chances
                printf("%s, you have exhausted all your options! You've lost! . You are gonna start from the beginning!",characterName); 
                break; 
            } else { 
                printf("You got the number wrong!"); 
                chances --; // Reduce the number of chances by one 
            }
        }
    } 
    else // Waiting for Prince Opol 
    { 
        printf("Prince Opol has come, peeped through the window but he thinks you ain't hard so he has left you there! Game Over!"); 
    }
} 
