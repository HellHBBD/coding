#include "prototype.h"

int main()
{
	struct LinkedList *head = create("Colten", 2024, 'p', 'd', '1', 2023);

	while (1) {
		char opt[30] = {};
		scanf("%s", opt);
		if (strcmp(opt, "insert") == 0) {
			char target1[20] = {}, target2[20] = {};
			int val1, x, y, z, val2;
			scanf("%s %s %d %d %d %d %d", target1, target2, &val1,
			      &x, &y, &z, &val2);

			struct LinkedList *new_people =
				create(target2, val1, x, y, z, val2);
			int val = insert(head, target1, new_people);
			if (val == -1)
				printf("Insert Error: Not Found\n");
			else
				printf("Insert: OK!\n");
		} else if (strcmp(opt, "find") == 0) {
			char target[20] = {};
			scanf("%s", target);
			struct LinkedList *p = find(head, target);
			if (p == NULL)
				printf("Find: %s not found!\n", target);
			else
				printf("Find: %s found\n", target);
		}
		/*     else if( strcmp(opt,"update_public") == 0 ) */
		/*     { */
		/*         int idx1,idx2,idx3,idx4,v = 0; */
		/*         char target[20] = {}; */
		/*         scanf("%s %d %d %d %d %d",target,&idx1,&idx2,&idx3,&idx4,&v); */
		/*         int val = update_public(head,target,idx1,idx2,idx3,idx4,&v); */
		/*         if( val == -1 ) printf("Update_Public Error: Not Found!\n"); */
		/*         if( val == -2 ) printf("Update_Public Error: Index out of bound!\n"); */
		/*         if( val == 0 ) printf("Update_Public: OK!, Value of v: %d\n",v); */
		/*     } */
		/*     else if( strcmp(opt,"update_public_target") == 0 ) */
		/*     { */
		/*         int idx1,idx2,idx3,idx4,val; */
		/*         char target[20] = {}; */
		/*         scanf("%s %d %d %d %d %d",target,&idx1,&idx2,&idx3,&idx4,&val); */
		/*         struct LinkedList* pos = find(head,target); */
		/*         if( pos == NULL ) printf("Update_Public_Target Error: Not Found!\n"); */
		/*         else */
		/*         { */
		/*             update_public_target(&(pos->passwd_public),idx1,idx2,idx3,idx4,val); */
		/*             printf("Update_Public_Target: OK!"); */
		/*         } */
		/*     } */
		/*     else if( strcmp(opt,"update_private") == 0 ) */
		/*     { */
		/*         int idx1,idx2,idx3,v; */
		/*         char target[20] = {}; */
		/*         scanf("%s %d %d %d %d",target,&idx1,&idx2,&idx3,&v); */
		/*         int val = update_private(head,target,idx1,idx2,idx3,v); */
		/*         if( val == -1 ) printf("Update_Private Error: Not Found!\n"); */
		/*         if( val == 0 ) printf("Update_Private: OK!\n"); */
		/*     } */
		/*     else if( strcmp(opt,"update_name") == 0 ) */
		/*     { */
		/*         char a[20] = {},b[20] = {}; */
		/*         scanf("%s %s",a,b); */
		/*         int val = update_name(head,a,b); */
		/*         if( val == -1 ) printf("Update_Name Error: Not Found!\n"); */
		/*         if( val == 0 ) printf("Update_Name: OK!\n"); */
		/*     } */
		/*     else if( strcmp(opt,"lower_to_upper") == 0 ) */
		/*     { */
		/*         char target[20] = {}; */
		/*         scanf("%s",target); */
		/*         int val = LowerToUpper(head,target); */
		/*         if( val == -1 ) printf("Lower_to_Upper Error: Not Found!\n"); */
		/*         if( val == 0 ) printf("Lower_to_Upper: OK!\n"); */
		/*     } */
		/*     else if( strcmp(opt,"sort") == 0 ) */
		/*     { */
		/*         char target[40] = {}; */
		/*         scanf("%s",target); */
		/*         sort_name(target); */
		/*         printf("After Sorting: %s\n",target); */
		/*     } */
		/*     else break; */
	}
	return 0;
}
