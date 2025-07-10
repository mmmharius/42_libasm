/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 06:14:16 by mpapin            #+#    #+#             */
/*   Updated: 2025/07/10 06:15:56 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2); //fonction asm

void test_strcmp(char *s1, char *s2) {
    int result_ft = ft_strcmp(s1, s2);
    int result_std = strcmp(s1, s2);
    
    printf("Test: '%s' vs '%s'\n", s1, s2);
    printf("ft_strcmp: %d\n", result_ft);
    printf("strcmp:    %d\n", result_std);
    
    // Vérifie que les signes sont les mêmes
    if ((result_ft > 0 && result_std > 0) || 
        (result_ft < 0 && result_std < 0) || 
        (result_ft == 0 && result_std == 0)) {
        printf("✅ OK\n");
    } else {
        printf("❌ ERREUR\n");
    }
    printf("---\n");
}

int main() {
    // Test 1 : chaînes identiques
    test_strcmp("hello", "hello");
    
    // Test 2 : première plus petite
    test_strcmp("abc", "abd");
    
    // Test 3 : première plus grande
    test_strcmp("abd", "abc");
    
    // Test 4 : première plus courte
    test_strcmp("abc", "abcd");
    
    // Test 5 : première plus longue
    test_strcmp("abcd", "abc");
    
    // Test 6 : chaînes vides
    test_strcmp("", "");
    
    // Test 7 : une chaîne vide
    test_strcmp("", "abc");
    test_strcmp("abc", "");
    
    // Test 8 : différence au début
    test_strcmp("z", "a");
    
    return 0;
}