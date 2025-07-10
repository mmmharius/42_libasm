# Guide ASM x86-64 - Les bases VRAIMENT expliquées

## 1. C'est quoi un registre ?

Un registre = une petite "boîte" dans le processeur qui stocke un nombre.

### Schéma simple

```
┌─────────────────────────────────────┐
│           PROCESSEUR                │
│                                     │
│  ┌───────┐  ┌───────┐  ┌───────┐    │
│  │  RAX  │  │  RBX  │  │  RCX  │    │
│  │   42  │  │   0   │  │  100  │    │
│  └───────┘  └───────┘  └───────┘    │
│                                     │
└─────────────────────────────────────┘
```

**En gros :** RAX, RBX, RCX... = des variables ultra-rapides.

### Les registres principaux

```
RAX = registre principal (souvent pour les résultats)
RBX = registre général
RCX = registre général (souvent compteur)
RDX = registre général
RSI = pour les adresses "source"
RDI = pour les adresses "destination"
```

## 2. Les tailles de registres - EXPLICATION SIMPLE

Un registre 64 bits, c'est comme une boîte avec des compartiments :

```
        RAX (la boîte complète - 64 bits)
┌─────────────────┬─────────────────┐
│   partie haute  │   EAX (32 bits) │
└─────────────────┴─────────────────┘
                          │
                  ┌───────┴───────┐
                  │ AH(8) │ AL(8) │ ← AX (16 bits)
                  └───────┴───────┘
```

**Concrètement :**
- `RAX` = toute la boîte (8 octets)
- `EAX` = moitié droite de la boîte (4 octets)
- `AX` = petit coin en bas à droite (2 octets)
- `AL` = très petit coin en bas à droite (1 octet)
- `AH` = petit coin juste à côté de AL (1 octet)

### Exemple concret

Si je mets 0x12345678 dans EAX :

```
RAX = 0x0000000012345678
      ^^^^^^^^ ^^^^^^^^
      partie   EAX
      haute    
               ^^^^^^^^
               │      │
               AX  <- ici c'est 0x5678
               ││
               │└─ AL = 0x78
               └─ AH = 0x56
```

## 3. Instructions de base

### MOV = mettre une valeur dans un registre

```asm
mov rax, 42      ; Met 42 dans RAX
mov rbx, rax     ; Copie RAX dans RBX
```

**ATTENTION :** `mov destination, source` (à l'envers du C !)

### ADD = addition

```asm
mov rax, 10      ; RAX = 10
add rax, 5       ; RAX = RAX + 5 = 15
```

### SUB = soustraction

```asm
mov rax, 20      ; RAX = 20
sub rax, 7       ; RAX = RAX - 7 = 13
```

### INC/DEC = +1/-1

```asm
mov rax, 5       ; RAX = 5
inc rax          ; RAX = 6
dec rax          ; RAX = 5
```

### XOR = petit hack pour mettre à zéro

```asm
xor rax, rax     ; RAX = 0 (plus rapide que mov rax, 0)
```

## 4. La mémoire avec les crochets []

### Différence entre adresse et contenu

```
Imagine la mémoire comme des casiers numérotés :

Casier 1000 : contient 'H'
Casier 1001 : contient 'e'  
Casier 1002 : contient 'l'
Casier 1003 : contient 'l'
Casier 1004 : contient 'o'
Casier 1005 : contient '\0'
```

### Sans crochets = adresse

```asm
mov rax, 1000    ; RAX = le NUMÉRO du casier (1000)
```

### Avec crochets = contenu

```asm
mov bl, [rax]    ; BL = ce qui est DANS le casier 1000 ('H')
```

### Exemple complet

```asm
mov rax, demo_string    ; RAX = adresse de la chaîne "Hello"
mov bl, [rax]           ; BL = premier caractère ('H')
mov cl, [rax + 1]       ; CL = deuxième caractère ('e')
mov dl, [rax + 2]       ; DL = troisième caractère ('l')
```

## 5. Les tailles d'accès mémoire

### Pourquoi préciser la taille ?

Le processeur doit savoir combien d'octets lire :

```asm
mov al, [rax]         ; Lit 1 octet
mov ax, [rax]         ; Lit 2 octets
mov eax, [rax]        ; Lit 4 octets
mov rax, [rax]        ; Lit 8 octets
```

### Ou avec les mots-clés

```asm
mov al, byte [rax]    ; 1 octet (comme char)
mov ax, word [rax]    ; 2 octets (comme short)
mov eax, dword [rax]  ; 4 octets (comme int)
mov rax, qword [rax]  ; 8 octets (comme long)
```

## 6. Les comparaisons - CMP

### CMP = comparer deux valeurs

```asm
mov rax, 10
mov rbx, 20
cmp rax, rbx         ; Compare RAX et RBX
```

**Ce que fait CMP :**
- Calcule RAX - RBX (10 - 20 = -10)
- Met à jour des "flags" dans le processeur
- Ne change PAS RAX ni RBX

### Les flags (petits indicateurs)

Le processeur a des petits bits qui retiennent le résultat :

```
ZF = Zero Flag (le résultat était 0 ?)
SF = Sign Flag (le résultat était négatif ?)
CF = Carry Flag (il y a eu un débordement ?)
```

## 7. Les sauts - JMP et conditions

### JMP = aller à un endroit

```asm
jmp ailleurs         ; Va directement à l'étiquette "ailleurs"

; du code...

ailleurs:
    mov rax, 42
```

### Sauts conditionnels

Après un `cmp`, tu peux sauter selon le résultat :

```asm
cmp rax, rbx         ; Compare RAX et RBX
je egaux             ; "jump if equal" - si RAX == RBX
jne differents       ; "jump if not equal" - si RAX != RBX
jg plus_grand        ; "jump if greater" - si RAX > RBX
jl plus_petit        ; "jump if less" - si RAX < RBX

egaux:
    ; code si RAX == RBX
    
differents:
    ; code si RAX != RBX
    
plus_grand:
    ; code si RAX > RBX
    
plus_petit:
    ; code si RAX < RBX
```

## 8. Les boucles

### Boucle simple

```asm
mov rax, 0           ; compteur = 0

debut_boucle:
    cmp rax, 10      ; compare compteur avec 10
    jge fin_boucle   ; si compteur >= 10, sortir
    
    ; code de la boucle ici
    inc rax          ; compteur++
    jmp debut_boucle ; retourner au début

fin_boucle:
    ; suite du programme
```

## 9. Les fonctions - Calling Convention

### Comment les paramètres arrivent

Quand on appelle ta fonction, les paramètres sont automatiquement dans ces registres :

```
1er paramètre → RDI
2ème paramètre → RSI  
3ème paramètre → RDX
4ème paramètre → RCX
```

### Le résultat va dans RAX

Ta fonction doit mettre son résultat dans RAX avant de faire `ret`.

### Exemple : fonction qui additionne deux nombres

```asm
ma_fonction:
    ; RDI = premier nombre
    ; RSI = deuxième nombre
    add rdi, rsi         ; RDI = RDI + RSI
    mov rax, rdi         ; Résultat dans RAX
    ret                  ; Retourner
```

## 10. Structure d'un fichier .s

```asm
section .text            ; "Voici le code"
global ft_strlen         ; "Cette fonction peut être appelée"

ft_strlen:               ; Nom de la fonction
    ; ton code ici
    ret                  ; fin de la fonction
```

**Sur macOS :** ajoute un underscore → `global _ft_strlen` et `_ft_strlen:`

## 11. Exemple complet : ft_strlen

### Logique

1. Compter les caractères jusqu'à '\0'
2. Retourner le compte

### Code

```asm
section .text
global ft_strlen

ft_strlen:
    ; RDI = pointeur vers la chaîne
    mov rax, 0               ; compteur = 0

boucle:
    cmp byte [rdi + rax], 0  ; caractère actuel == '\0' ?
    je fini                  ; si oui, on a fini
    inc rax                  ; compteur++
    jmp boucle               ; continue

fini:
    ret                      ; retourne le compteur (dans RAX)
```

### Explication ligne par ligne

```asm
mov rax, 0               ; RAX sera notre compteur, on commence à 0
cmp byte [rdi + rax], 0  ; On regarde le caractère à la position RDI+RAX
                         ; byte = on lit 1 octet seulement
                         ; [rdi + rax] = contenu à l'adresse RDI+RAX
je fini                  ; "jump if equal" - si le caractère était '\0'
inc rax                  ; RAX++ (compteur++)
jmp boucle               ; retour au début de la boucle
ret                      ; retourner (résultat dans RAX)
```

## 12. Exemple : ft_strcmp

### Logique

1. Comparer caractère par caractère
2. Si différents : retourner la différence
3. Si identiques et fin de chaîne : retourner 0

### Code

```asm
section .text
global ft_strcmp

ft_strcmp:
    ; RDI = première chaîne (s1)
    ; RSI = deuxième chaîne (s2)

boucle:
    mov al, [rdi]        ; AL = caractère de s1
    mov bl, [rsi]        ; BL = caractère de s2
    
    cmp al, bl           ; compare les deux caractères
    jne differents       ; si différents, aller à "differents"
    
    cmp al, 0            ; le caractère est '\0' ?
    je egaux             ; si oui, les chaînes sont égales
    
    inc rdi              ; passer au caractère suivant de s1
    inc rsi              ; passer au caractère suivant de s2
    jmp boucle           ; continuer la boucle

differents:
    ; Calculer s1[i] - s2[i]
    movzx rax, al        ; mettre AL dans RAX (avec des zéros)
    movzx rbx, bl        ; mettre BL dans RBX (avec des zéros)
    sub rax, rbx         ; RAX = RAX - RBX
    ret

egaux:
    mov rax, 0           ; retourner 0 (chaînes égales)
    ret
```

## 13. Syscalls - Parler au système

### Principe

Un syscall = demander au système de faire quelque chose (écrire, lire...)

### Convention Linux

```
RAX = numéro du syscall
RDI = 1er paramètre
RSI = 2ème paramètre  
RDX = 3ème paramètre
```

### write (syscall numéro 1)

```asm
mov rax, 1           ; syscall write
mov rdi, 1           ; fd = 1 (stdout)
mov rsi, message     ; pointeur vers le texte
mov rdx, 13          ; nombre de caractères
syscall              ; appeler le système
```

### read (syscall numéro 0)

```asm
mov rax, 0           ; syscall read
mov rdi, 0           ; fd = 0 (stdin)
mov rsi, buffer      ; où stocker ce qui est lu
mov rdx, 100         ; maximum à lire
syscall              ; appeler le système
```

## 14. Gestion d'erreur avec errno

### Principe

Si un syscall échoue, il retourne -1 et met le code d'erreur dans `errno`.

### Code type

```asm
ft_write:
    mov rax, 1           ; syscall write
    ; RDI, RSI, RDX déjà corrects
    syscall              ; appel système
    
    cmp rax, 0           ; erreur ?
    jl erreur            ; si RAX < 0, il y a erreur
    ret                  ; sinon, retourner le résultat

erreur:
    neg rax              ; rendre le nombre positif
    ; ici on devrait mettre la valeur dans errno
    ; et retourner -1
    mov rdi, rax
    call __errno_location ; fonction du système
    mov [rax], rdi       ; mettre l'erreur dans errno
    mov rax, -1          ; retourner -1
    ret
```

## 15. Compilation et test

### Compilation

```bash
# Linux
nasm -f elf64 ft_strlen.s -o ft_strlen.o
gcc main.c ft_strlen.o -o test

# macOS
nasm -f macho64 ft_strlen.s -o ft_strlen.o
gcc main.c ft_strlen.o -o test
```

### Test simple

```c
// main.c
#include <stdio.h>

int ft_strlen(char *str);

int main() {
    printf("Longueur : %d\n", ft_strlen("Hello"));
    return 0;
}
```

---

## Résumé des concepts clés

1. **Registres** = variables ultra-rapides (RAX, RBX, RCX...)
2. **MOV** = mettre une valeur (`mov rax, 42`)
3. **[]** = aller chercher en mémoire (`mov al, [rax]`)
4. **CMP** = comparer (`cmp rax, rbx`)
5. **JE/JNE/JG/JL** = sauter selon condition
6. **Fonctions** : paramètres dans RDI, RSI, RDX... / résultat dans RAX
7. **Syscalls** : RAX=numéro, RDI/RSI/RDX=paramètres, puis `syscall`

**Maintenant tu peux commencer à coder tes fonctions !**
