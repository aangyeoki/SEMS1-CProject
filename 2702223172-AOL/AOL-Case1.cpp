#include<stdio.h>
#include<string.h>
//saya menggunakan library string.h karena saya melibatkan string manipulation strlen
//strlen() -> untuk mencari length of string

void swap(char *a, char *b){
// function swap untuk menukar char index i = 0, i++ dengan char index length - i - 1
	char temp = *a;
	*a = *b;
	*b = temp;
}

void converter(char string[], int length){
	//function converter untuk ngeconvert char yang awalnya uppercase
	//saya ubah menjadi lowercase dan sebaliknya
	//saya melibatkan adanya penggunaan ASCII
//	SELECTION
	for(int i = 0; i < length; i++){
		if(string[i] >= 65 && string[i] <= 90){
		//jika char dalam string lebih besar dari 65(A) dan lebih kecil dari 90(Z)
			string[i]=string[i]+32;
			//char tersebut akan ditambah 32 karena untuk mengubah upper to lower 
			//char harus ditambah 32
		} else if (string[i] >=97 && string[i]<=122){
		//jika char dalam string lebih besar dari 97(a) dan lebih kecil dari 122(z)
			string[i]=string[i]-32;
			//char tersebut akan dikurang 32 untuk diubah dari lower jadi upper
		}
	}
}

int main(){
	char string[101]={};
	
	scanf("%[^\n]", &string);
	getchar();
//	STRING MANIPULATION
	int length = strlen(string);
//	ITERATION
	for(int i = 0; i < length/2; i++){
		//saya looping untuk bisa mengubah char index paling kiri dan char index paling kanan
		//lalu looping akan berhenti kedua string[] bertemu ditengah - tengah
			swap(&string[i], &string[length - i - 1]);
			//pemanggilan function swap
	}
	converter(string, length);
	//pemanggilan function converter
	printf("%s\n", string);
	//print hasil inverse dan convert
	return 0;
}
