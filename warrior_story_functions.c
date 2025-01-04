#include <stdio.h>

void introduction();
void pathOfVengeance();
void pathOfWisdom();
void pathOfMystic();
void finalBattle(int hasArtifact);

int main() {
    introduction();
    return 0;
}

void introduction() {
    int choice;
    printf("You are a renowned warrior, known throughout the land for your unmatched skill and courage. Your name, %s, strikes fear into the hearts of your enemies. However, dark times have befallen your home. The once peaceful village of Ngoma has been ravaged by a merciless enemy, your family taken captive, and your honor stained.\n\nWith nothing but your warrior's instincts and the fire of vengeance burning in your heart, you must embark on a perilous journey across ancient lands. The fate of your family, your honor, and the future of your people rests in your hands.\nWelcome, %s! Choose your path:\n", "Charis");
    printf("1. The Path of Vengeance\n");
    printf("2. The Path of Wisdom\n");
    printf("3. The Path of the Mystic\n");
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
        finalBattle(0);
    } else if (choice == 2) {
        printf("You are spotted by the guards. You are injured but manage to escape. Continue to the final battle.\n");
        finalBattle(0);
    } else if (choice == 3) {
        printf("You are ambushed during the duel. Game Over.\n");
    } else {
        printf("Invalid choice. Game Over.\n");
    }
}

void pathOfWisdom() {
    int choice;
    printf("You chose the Path of Wisdom. What will you do?\n");
    printf("1. Search for the Hidden Artifact\n");
    printf("2. Rally the Villagers\n");
    printf("3. Meditate for a Vision\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You found the Amulet of Protection!\n");
        finalBattle(1);
    } else if (choice == 2 || choice == 3) {
        printf("You proceed without any special advantages.\n");
        finalBattle(0);
    } else {
        printf("Invalid choice. Game Over.\n");
    }
}

void pathOfMystic() {
    int choice;
    printf("You chose the Path of the Mystic. What will you do?\n");
    printf("1. Accept the Potion of Strength\n");
    printf("2. Bargain for a Magical Weapon\n");
    printf("3. Refuse the Witch's Aid\n");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        printf("You gain powerful abilities!\n");
        finalBattle(1);
    } else if (choice == 3) {
        printf("You proceed without the witch's help.\n");
        finalBattle(0);
    } else {
        printf("Invalid choice. Game Over.\n");
    }
}

void finalBattle(int hasArtifact) {
    if (hasArtifact) {
        printf("With the power of your artifact, you defeat General Rukundo and save your family. You are a hero!\n\n");
    } else {
        printf("The battle is tough, and you fight bravely. However, without any special advantage, you are defeated. Game Over.\n\n");
    }
}

