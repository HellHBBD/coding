#include <stdio.h>
#include <stdlib.h>

struct File{
	int name;
	int size;
};

struct System{
	struct File *disk[21];
	int count;
};

void add(struct System *system){
	int i = 0;
	for (;i < 21;i++){
		if (system->disk[i] == 0){
			system->disk[i] = malloc(sizeof(struct File));
			printf("Please input file name and file sizes: ");
			scanf("%d%d",&system->disk[i]->name,&system->disk[i]->size);
			system->count++;
			break;
		}
	}
	if (system->count == 21){
		int fileCount,fileSize;
		printf("Hard drive exceeds its capacity, please enter the number of files to be deleted:");
		scanf("%d%d",&fileCount,&fileSize);
		//delete
	}
}

void query(struct System *system){
	int fileName;
	printf("Please input the file name: ");
	scanf("%d",&fileName);
	for (int i = 0;i < 21;i++){
		if (system->disk[i] == 0)
			continue;
		if (system->disk[i]->name == fileName){
			puts("YES");
			return;
		}
	}
	puts("NO");
}

void delete(struct System *system){
	for (int i = 0;i < 21;i++){
		free(system->disk[i]);
		system->disk[i] = 0;
	}
}

int main(){
	struct System system = {.disk = {}, .count = 0};
	while (1){
		int option;
		printf("Option: ");
		scanf("%d",&option);
		switch (option){
			case 1:
				add(&system);
				break;
			case 2:
				query(&system);
				break;
			case 3:
				delete(&system);
				return 0;
		}
	}
}
