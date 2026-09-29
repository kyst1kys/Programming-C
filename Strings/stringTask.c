#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    char str2[100];
    char result[200]; 
    
    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        str1[strcspn(str1, "\n")] = '\0';
    }
    
    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) != NULL) {
        str2[strcspn(str2, "\n")] = '\0';
    }
    
    int i = 0; 
    int j = 0; 
    int k = 0; 
    
    // Проходимо по строках, поки обидві з них не закінчиться 
    while (str1[i] != '\0' || str2[j] != '\0') {
        if (str1[i] != '\0') {
            result[k] = str1[i];
            k++;
            i++;
        }
        if (str2[j] != '\0') {
            result[k] = str2[j];
            k++;
            j++;
        }
    }
    
    result[k] = '\0';
    
    printf("Merged result: %s\n", result);
    
    return 0;
}