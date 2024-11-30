#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contains(char* c, char key){
    int size = strlen(c);
    for(int i=0;i<size;i++){
        if(c[i]==key){
            return true;
        }
    }
    return false;
}

int legthOfLongestSubstring(char* s){
    char* set = "";
    int left = 0;
    int res = 0;
    for(int r = 0; r <= strlen(s);++r){
        while (contains(set,s[r])){  
           memmove(set, set+1, strlen(set)); 
           ++left;
        }
        set = set+s[r];
        if (res < strlen(set)){
           res = strlen(set); 
        }
    }
    return res;
}


int main(){
    int c;
    
    char* input;
    char a = 'a';
    int asciiValue = (int)a;
    while( (c=getchar()) != asciiValue) {
        input += c;
    }
    printf("%d", legthOfLongestSubstring(input));
    return 0;
}
