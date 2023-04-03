#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//1.Same input always return same output
//2.Needes to be fast
//3.Different inputs should return different outputs
#define MAX_NAME 256
#define TABLE_SIZE 10


struct hash{
   char name[MAX_NAME];
   int age;
   //...add other stuff later.
}person;

struct hash* hash_table[TABLE_SIZE]; 

int hash(char *name){
   int length = strnlen(name, MAX_NAME);
   int hash_value = 0;
   for (int i = 0; i < length; i++) {
      hash_value += name[i];//Not random enough
      hash_value = (hash_value * name[i]) % TABLE_SIZE; //This funciton causes the collision problem
   }
   return hash_value;
}

void init_hash_table(){
   for (int i = 0; i < TABLE_SIZE; i++){
      hash_table[i] = NULL;
   }
   //table is empty
}

void print_table(){
   for (int i = 0; i < TABLE_SIZE; i++)
      if (hash_table[i] == NULL){
         printf("\t%d\t----\n", i);
      } else {
         printf("\t%s\t---\n", hash_table[i] -> name);
      }
   
}

bool hash_table_insert(struct hash *person){
   if (person == NULL) return false;
   int index = hash(person -> name);
   if (hash_table[index] != NULL) return false;
   hash_table[index] = person;
   return true;
}

int main(){
   init_hash_table();
   print_table();
   //printf("Jacob => %d\n", hash("Jacob"));
   //printf("Natalie => %d\n", hash("Natalie"));
   //printf("John => %d\n", hash("John"));
}