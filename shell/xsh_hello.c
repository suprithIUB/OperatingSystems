// **xsh_hello.c**

/*
Operating Systems - Assignment 1

Authors:
Suprith Chandrashekharachar(suprchan),
Dakshi Kumar(dakumar)

Description:
Program to print hello with an input string

*/


#include<xinu.h>
#include<stdio.h>
#include<string.h>

shellcmd xsh_hello(int nargs, char* args[]){

	if(nargs == 2){
		printf( "Hello %s", args[1]);
		
		printf(" ," );
		printf("Welcome to the world of Xinu!!\n");
	}
	else{
		if(nargs < 2)
			fprintf(stderr, "%s: too few arguments\n", args[0]);
		else
			fprintf(stderr, "%s: too many arguments\n", args[0]);
	}
}

