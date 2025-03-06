# pipex

## Description

`pipex` est un projet qui reproduit le fonctionnement du pipe (`|`) en ligne de commande sous Unix. Il permet d'exécuter deux commandes en les connectant via un tube (`pipe`), redirigeant ainsi la sortie standard de la première commande vers l'entrée standard de la seconde.

Ce projet permet de mieux comprendre la manipulation des processus, des redirections et des descripteurs de fichiers en C.

## Fonctionnement

Le programme s'utilise de la manière suivante :

```sh
./pipex file1 cmd1 cmd2 file2
```
Equivalent en bash à :
```sh
< file1 cmd1 | cmd2 > file2
```
Explication :

 - `file1` : Fichier d'entrée, dont le contenu est redirigé vers `cmd1`
 - `cmd1` : Première commande exécutée, sa sortie est envoyée dans un pipe
 - `cmd2` : Seconde commande qui récupère l'entrée depuis le pipe
 - `fil2` : Fichier de sortie qui reçoit la sortie de `cmd2`

## Fonctionnement

- `pipe()` pour créer un tube entre deux processus
   - `fork()` : pour dupliquer les processus courant
   - `dup2()` : pour rediriger les entrées et sorties standards
   - `execve` pour exécuter les commandes
- Gestion des erreurs (permissions, commandes invalides, environnement introuvable)
- Prise en charge des chemins relatifs avec le `PATH`

## Exécution

Exemple d'utilisation :
```sh
./pipex infile "cat" "wc -l" outfile
```
Equivalent a :
```sh
cat < infile | wc -l > outfile
```
