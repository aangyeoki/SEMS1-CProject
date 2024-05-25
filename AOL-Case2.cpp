#include<stdio.h>
//library for standard input output
#include<string.h>
//library for string manipulation functions
#include<unistd.h>
//library for sleep()
#include<stdlib.h>
//library for automatic clearscreen
 
//struct to store data based on location, city, price, and others.
struct Data{
	char location[30];
	char city[30];
	int price;
	int rooms;
	int bathrooms;
	int carParks;
	char type[30];
	char furnish[30];
};

//declare index to count how many data in file
long long int index = 0;

//declare a struct to store struct data perline
struct Data Hotel[100000];

//declare variabels as checker for sorting and searching data
int checker = 0;
char YorN;
int print;

//function to return int to sort
int sortCase(char sorting[]){
	if(strcmp(sorting, "asc") == 0){
		return 1;
	} else if (strcmp(sorting, "desc") == 0){
		return 2;
	}
	return -1;
}

//function swap to swap data
void swap(Data *a, Data *b){
	struct Data temp = *a;
	*a = *b;
	*b = temp;
}

//function to read file
void readFile(){
	FILE *fp = fopen("file.csv","r");
	if(fp == NULL){
		perror("Error!");
	}else{
		while(!feof(fp)){
		fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", Hotel[index].location, Hotel[index].city, &Hotel[index].price, &Hotel[index].rooms, &Hotel[index].bathrooms, &Hotel[index].carParks, Hotel[index].type, Hotel[index].furnish);
		index++;
		}
	}
	fclose(fp);
}

//function to make me easier to print table header
void tablePrinter(){
	printf("+---------------------------------------------------------------------------------------------------------------------+\n");
	printf("| %8s%-8s | %7s%-7s | %5s%-5s | %5s%-5s | %5s%-5s | %5s%-5s | %6s%-6s | %6s%-6s |\n", "LOCA","TION", "CI","TY", "PRI","CE", "ROO","MS", "BATH","ROOMS", "CARP", "ARK", "TY", "PE", "FURN", "ISH");
	printf("+---------------------------------------------------------------------------------------------------------------------+\n");
}

//function for . . .
void sleepTime(){
	for(int i = 0; i < 4; i++){
		sleep(1);
		printf(" .");
	}
	sleep(1);
	printf("\n");
}

//function for display data
void displayData(int rows){
	printf("Just like the way you requested\n");
	sleep(1);
	printf("Here it is");
	sleepTime();
	puts("");
	tablePrinter();
	for(int i = 0; i < rows; i++){
		printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
			Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
	}
}

//function for searching string
void stringSearch(int columnCase){
	char find[30];
	long long int i = 0;
	checker = 0;
	int forn = 0;	
	printf("What are you searching for? ");
	scanf("%s", find);
	getchar();
	switch(columnCase){
		case 1:		
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(strcmpi(Hotel[i].location, find)==0){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();	
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}			
			}while(checker != 1); 
			break;
		case 2:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(strcmpi(Hotel[i].city, find)==0){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}		
			}while(checker != 1); 
			break;
		case 7:		
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(strcmpi(Hotel[i].type, find)==0){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();		
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}		
			}while(checker != 1); 
			break;
		case 8:	
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(strcmpi(Hotel[i].furnish, find)==0){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();	
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}		
			}while(checker != 1);
			break;
	}
}

//function for searching integer
void intSearch(int columnCase){
	long long int find;
	long long int i = 0;
	checker = 0;
	int forn = 0;	
	printf("What are you searching for? ");
	scanf("%lld", &find);
	getchar();
	switch(columnCase){
		case 3:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(Hotel[i].price == find){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();	
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}			
			}while(checker == 0); 
			break;
		case 4:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(Hotel[i].rooms == find){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}				
			}while(checker != 1); 
			break;
		case 5:
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(Hotel[i].bathrooms == find){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();	
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}			
			}while(checker != 1); 
			break;
		case 6:	
			do{
				print = 0;
				for(i; i < index; i++){
					if(i == index-1 && forn == 0){
						puts("");
						printf("No data to show:(\n");
						checker = 1;
						return;
					}
					if(Hotel[i].carParks == find){
						if(forn == 0){
							printf("Found it! Let me show you the details");
							sleepTime();
							tablePrinter();	
							forn = 1;		
						}
						printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
							Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
						printf("-----------------------------------------------------------------------------------------------------------------------\n");	
						print++;
						if(print == 10){
							break;
						}
					}
					if(i == index - 1 && forn == 1){
						printf("Thats all!\n");
						return;
					}
				}
				printf("Do you want to see more data [y or n]? ");
				scanf("%c", &YorN);
				getchar();
				if(YorN == 'y'){
					system("cls");
					tablePrinter();
				}
				else if(YorN == 'n'){
					checker = 1;
				}				
			}while(checker != 1); 
			break;
	}
}

//function for merge sort
void sort(int left, int mid, int right, int columnCase, int whichSort){
	int nLeft = mid - left + 1;
	int nRight = right - mid;
	struct Data Left[nLeft];
	struct Data Right[nRight];
	for(int i = 0; i < nLeft; i++){
		Left[i] = Hotel[left + i];
	}
	for(int i = 0; i < nRight; i++){
		Right[i] = Hotel[mid + 1 + i];
	}
	int i = 0, j = 0, k = left;
	while(i < nLeft && j < nRight){
		switch(columnCase){
			case 1:
				if(whichSort == 1){
					if(strcmp(Left[i].location, Right[j].location) < 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].location, Right[j].location) > 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		case 2:
				if(whichSort == 1){
					if(strcmp(Left[i].city, Right[j].city) < 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].city, Right[j].city) > 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		case 3:
				if(whichSort == 1){
					if(Left[i].price < Right[j].price){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].price > Right[j].price){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		case 4:
				if(whichSort == 1){
					if(Left[i].rooms < Right[j].rooms){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].rooms > Right[j].rooms){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		case 5:
				if(whichSort == 1){
					if(Left[i].bathrooms < Right[j].bathrooms){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].bathrooms > Right[j].bathrooms){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		case 6:
				if(whichSort == 1){
					if(Left[i].carParks < Right[j].carParks){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(Left[i].carParks > Right[j].carParks){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		case 7:
				if(whichSort == 1){
					if(strcmp(Left[i].type, Right[j].type) < 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].type, Right[j].type) > 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		case 8:
				if(whichSort == 1){
					if(strcmp(Left[i].furnish, Right[j].furnish) < 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}if (whichSort == 2){
					if(strcmp(Left[i].furnish, Right[j].furnish) > 0){
						Hotel[k] = Left[i];
						i++;
					}
					else {
						Hotel[k] = Right[j];
						j++;
					}
				}
			break;
		}
	k++;
	}
	while(i < nLeft){
		Hotel[k++] = Left[i++];
	}
	while(j < nRight){
		Hotel[k++] = Right[j++];
	}
}
void merge(int left, int right, int columnCase, int whichSort){
	int mid = left + (right - left)/2;
	if(left < right){
		merge(left, mid, columnCase, whichSort);
		merge(mid+1, right, columnCase, whichSort);
		sort(left, mid, right, columnCase, whichSort);
	}
}

//function that returns an int for switch case
int columnSearch(char column[]){
	if(strcmpi(column, "location") == 0){
		return 1;
	} else if(strcmpi(column, "city") == 0){
		return 2; 
	} else if(strcmpi(column, "price") == 0){
		return 3;
	} else if(strcmpi(column, "rooms") == 0){
		return 4;
	} else if(strcmpi(column, "bathrooms") == 0){
		return 5;
	} else if(strcmpi(column, "carparks") == 0){
		return 6;
	} else if(strcmpi(column, "type") == 0){
		return 7; 
	} else if(strcmpi(column, "furnish") == 0){
		return 8; 
	} else {
		printf("Sorry, I cant find what you're looking for :(\n");
		return 9;
	}
}

//function for export data
void ExportData(char fileName[]){
	printf("File Name : ");
	scanf("%[^\n]", fileName);
	getchar();
	strcat(fileName, ".csv");
	printf("Wait! Exporting data");
	sleepTime();
	FILE *fn = fopen(fileName, "w");
	for(int i = 0; i < index; i++){
		fprintf(fn, "%s,%s,%d,%d,%d,%d,%s,%s\n", Hotel[i].location,Hotel[i].city,Hotel[i].price,Hotel[i].rooms,Hotel[i].bathrooms,Hotel[i].carParks,Hotel[i].type,Hotel[i].furnish);
	}
	fclose(fn);	
}

int main(){
	int usersInput, rows, columnCase;
	char column[15];
	readFile();
	do{
		do{
			system("cls");			
			puts("======== MENU ========");
			puts("What do you want to do?");
			puts("1. Display data");
			puts("2. Search data");
			puts("3. Sort data");
			puts("4. Export data");
			puts("5. Exit");
			printf("Your choice: ");
			scanf("%d", &usersInput);
			getchar();
			}while(usersInput < 1 || usersInput > 5);
			switch(usersInput){
				case 1: 
					do{
						printf("Number of rows : ");
						scanf("%d", &rows);
						getchar();
					}while(rows < 0);
					if(rows > index){
						rows = index;
					}
					displayData(rows);	
					break;
				case 2:
					do{
						printf("Choose column : ");
						scanf("%[^\n]", column);
						getchar();
						columnCase = columnSearch(column);
						if(columnCase == 1 || columnCase == 2 || columnCase == 7 || columnCase == 8){
							stringSearch(columnCase);
						} else if(columnCase == 3 || columnCase == 4 || columnCase == 5 || columnCase == 6){
							intSearch(columnCase);
						}						
					}while(columnCase == 9);
					break;
				case 3:
					char sorting[10];
					checker = 0;
					int i; 
					rows = 10;
					int whichSort;
					do{
						printf("Choose column : ");
						scanf("%s", column);
						getchar();
						columnCase = columnSearch(column);
					}while(columnCase == 9);
					do{
						whichSort = 0;
						printf("Sort ascending or descending [asc or desc]? ");
						scanf("%[^\n]", sorting);
						getchar();
						whichSort = sortCase(sorting);
					}while(whichSort == -1);
					i = 0;
					printf("Okay! Please wait! i am sorting the data");
					sleepTime();
					merge(0, index - 1, columnCase, whichSort);
					printf("Sorting done!\n");
					puts("");
					sleep(1);
					tablePrinter();
					do{
						for(i; i < rows; i++){
							printf("| %-16s | %-14s | %-10d | %-10d | %-10d | %-10d | %-12s | %-12s |\n", 
								Hotel[i].location, Hotel[i].city, Hotel[i].price, Hotel[i].rooms, Hotel[i].bathrooms, Hotel[i].carParks, Hotel[i].type, Hotel[i].furnish);
							printf("-----------------------------------------------------------------------------------------------------------------------\n");
							if(i == index - 1){
								puts("");
								printf("That's all!\n");
								break;
							}
						}
						puts("");
						printf("Do you want to see more data [y or n]? ");
						scanf("%c", &YorN);
						getchar();
						if(YorN == 'n'){
							checker = 1;
						}
						else {
							system("cls");
							tablePrinter(); 
							rows+=10;
							if(rows > index){
								rows = index;
							}
						}
					}while(checker != 1 && rows <= index);
					break;
				case 4:
					char fileName[30];
					ExportData(fileName);
					puts("");
					printf("Okay! exporting to %s finished!\n", fileName);
					sleep(1);
					break;
				case 5:
					system("cls");
					puts(" ________   __   __      ___      __   __   __   __");
					puts("|___  ___| |  |_|  |    /   \\    |  \\ |  | |  |/  /");
					puts("   |  |    |   _   |   / /_\\ \\   |   \\|  | |     /");
					puts("   |  |    |  | |  |  /  ___  \\  |  |\\   | |     \\");
					puts("   |__|    |__| |__| /_ /   \\ _\\ |__| \\__| |__|\\__\\");
					puts("                                           ___");  
					puts("         __    __     ____     __   __    |   |");
					puts("        \\  \\  /  /  /  __  \\  |  | |  |   |   | ");
					puts("         \\  \\/  /  |  |  |  | |  | |  |   |___| ");
					puts("          \\    /   |  |__|  | |  |_|  |    _ _ ");
					puts("           |__|     \\______/   \\_____/    \\ v /");
					puts("                                           \\ /  ");
					puts("");
					printf("You are leaving the system");
					sleepTime();
					break;
			}
		puts("");
		printf("Press ENTER to leave\n");	
		getchar();
		fflush(stdout);
	}while(usersInput != 5);
	return 0;
}
