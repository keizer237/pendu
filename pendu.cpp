#include <stdio.h>
#include <string.h>

void afficher_pendu(int erreurs) {
    // Affiche le dessin du pendu en fonction du nombre d'erreurs
    switch (erreurs) {
        case 1: printf(" O\n"); break;
        case 2: printf(" O\n |\n"); break;
        case 3: printf(" O\n/|\n"); break;
        case 4: printf(" O\n/|\\\n"); break;
        case 5: printf(" O\n/|\\\n/\n"); break;
        case 6: printf(" O\n/|\\\n/ \\\n"); break;
        default: break;
    }
}

void afficher_mot(const char *mot, const int *lettres_trouvees) {
    // Affiche le mot avec les lettres trouvées, et les autres en "_"
    for (int i = 0; mot[i] != '\0'; i++) {
        if (lettres_trouvees[i]) {
            printf("%c ", mot[i]); // Affiche la lettre trouvée
        } else {
            printf("_ "); // Affiche un tiret pour une lettre non trouvée
        }
    }
    printf("\n");
}

int verifier_lettre(const char *mot, char lettre, int *lettres_trouvees) {
    int trouve = 0;
    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] == lettre && !lettres_trouvees[i]) {
            lettres_trouvees[i] = 1; // Marque la lettre comme trouvée
            trouve = 1; // Indique que la lettre est dans le mot
        }
    }
    return trouve;
}

int mot_complet(const int *lettres_trouvees, int taille) {
    // Vérifie si toutes les lettres du mot ont été trouvées
    for (int i = 0; i < taille; i++) {
        if (!lettres_trouvees[i]) {
            return 0; // Retourne 0 si une lettre n'a pas été trouvée
        }
    }
    return 1; // Retourne 1 si toutes les lettres ont été trouvées
}

int main() {
    const char *mot = "programmation"; // Le mot à deviner
    int lettres_trouvees[strlen(mot)]; // Tableau pour suivre les lettres trouvées
    for (int i = 0; i < strlen(mot); i++) lettres_trouvees[i] = 0;

    int erreurs = 0; // Nombre d'erreurs de l'utilisateur
    char lettre;

    printf("Bienvenue au jeu du Pendu !\n");

    while (erreurs < 6 && !mot_complet(lettres_trouvees, strlen(mot))) {
        afficher_mot(mot, lettres_trouvees);
        printf("Entrez une lettre : ");
        scanf(" %c", &lettre);

        if (!verifier_lettre(mot, lettre, lettres_trouvees)) {
            erreurs++; // Incrémente le nombre d'erreurs si la lettre est incorrecte
            afficher_pendu(erreurs); // Affiche le pendu en fonction du nombre d'erreurs
        }

        if (mot_complet(lettres_trouvees, strlen(mot))) {
            printf("Félicitations ! Vous avez deviné le mot : %s\n", mot);
        } else if (erreurs == 6) {
            printf("Désolé, vous avez perdu. Le mot était : %s\n", mot);
        }
    }

    return 0;
}