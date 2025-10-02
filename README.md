# get_next_line

## Description
get_next_line est un projet de l'École 42 qui consiste à créer une fonction capable de lire un fichier ligne par ligne. Cette fonction gère plusieurs file descriptors simultanément et optimise la lecture avec un buffer.

## Prototype
```c
char *get_next_line(int fd);
```

## Fonctionnalités
- **Lecture ligne par ligne** depuis n'importe quel fd
- **Gestion multiple fd** simultanément
- **Buffer optimisé** configurable (BUFFER_SIZE)
- **Gestion des fichiers** de toute taille
- **Memory management** sans leaks
- **Retour NULL** à la fin du fichier

## Technologies utilisées
- **Langage** : C
- **I/O** : read() system call
- **Gestion mémoire** : malloc/free
- **Static variables** pour persistance

## Installation
```bash
git clone <repository-url>
cd get_next_line
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c
```

## Utilisation
```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Configuration
La taille du buffer est définie à la compilation :
```bash
gcc -D BUFFER_SIZE=1024 get_next_line.c
```

## Gestion des cas limites
- **Fichiers vides**
- **Lignes très longues** 
- **Fichiers sans '\n' final**
- **Multiple fd** en parallèle
- **Erreurs de lecture**

## Optimisations
- **Buffer statique** pour éviter les re-lectures
- **Gestion efficace** de la mémoire
- **Parsing minimal** des données lues

## Bonus
- **Gestion de multiples fd** avec une seule variable statique
- **Optimisation mémoire** avancée

## Compétences développées
- Gestion avancée des file descriptors
- Optimisation des I/O
- Gestion mémoire rigoureuse
- Programmation système

## Auteur
Alexandre Pommier (apommier) - École 42