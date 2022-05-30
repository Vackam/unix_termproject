#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define MAX_TITLE_SIZE 50 
// We assume TOTAL_NUM_OF_MUSIC is less than 50
// "print_file" will be used in read_file.
void print_file(FILE* stream);


void create_music_titles(FILE* stream) {
	//int num_of_song = fgetc(stream);
	if (feof(stream)) {
		// When, File is Empty
		int start_music_num;
		printf("Number of music: "); 
		scanf("%d", &start_music_num);

		char music_name[MAX_TITLE_SIZE];
		for (int i=0; i<start_music_num; i++){
			scanf("%s", music_name);
			//append_left(MAX_TITLE_SIZE, music_name);
		}
		return;
	}
	else{
		int num_of_song = -1;
		char* title_of_song[MAX_TITLE_SIZE] = {0};
		fscanf(stream, "%d\n", &num_of_song);

		// If file is empty
		/*
		if(num_of_song == -1){
			printf("Empty File!\n");
			return;
		}
		*/
		
		for(int i=0; i<num_of_song; i++){
			*(title_of_song + i) = (char*)malloc(sizeof(char*));
			fgets(title_of_song[i], MAX_TITLE_SIZE, stream); 
			//append_left(MAX_TITLE_SIZE, title_of_song[i]);
		}

		// Check title_of_song and free dynamic alloc
		for (int i=0; i<num_of_song; i++){
			printf("%s", title_of_song[i]);
			free(*(title_of_song+i));
		}
		return;
	}

	return;
}


void write_file(char* file_name) {
	FILE* fp = fopen(file_name, "a");

	if(fp == NULL){
		printf("Can't Find File!\n");
	}	
	else{
		create_music_titles(fp);
		fclose(fp);
	}
	return;
}


void read_file(char* file_name) {
	FILE* fp = fopen(file_name, "r");

	if(fp == NULL){
		printf("Can't Find File!\n");
		return;
	}

	else{
		int num_of_song = -1;
		char* title_of_song[MAX_TITLE_SIZE] = {0};
		fscanf(fp, "%d\n", &num_of_song);

		// If file is empty
		if(num_of_song == -1){
			printf("Empty File!\n");
			return;
		}

		for(int i=0; i<num_of_song; i++){
			*(title_of_song + i) = (char*)malloc(sizeof(char*));
			fgets(title_of_song[i], MAX_TITLE_SIZE, fp); 
		}

		// if I have to control the command(player),
		int command_num = -1;
		char* command[MAX_TITLE_SIZE] = {0};
		fscanf(fp, "%d\n", &command_num);

		if(command_num == -1){
			printf("command is empty!\n");
		}
		
		for(int i=0; i<command_num; i++){
			*(command + i) = (char*)malloc(sizeof(char*));
			fgets(command[i], MAX_TITLE_SIZE, fp);
		}

		for (int i=0; i<num_of_song; i++){
			printf("%s", title_of_song[i]);
			free(*(title_of_song+i));
		}

		for (int i=0; i<command_num; i++){
			printf("%s", command[i]);
			free(*(command + i));
		}

		fclose(fp);
		return;

	}

}

int main(){
	FILE* fp = fopen("Text.txt", "r");
	create_music_titles(fp);
	fclose(fp);
	FILE* fp_2 = fopen("Text2.txt","r");
	create_music_titles(fp_2);
	fclose(fp_2);
	return 0;
}
