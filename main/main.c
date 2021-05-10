#include "utils.h"

int main(int argc, char *argv[])
{
	if (strcmp(argv[1], "dfs") != 0 && strcmp(argv[1], "bfs") != 0 && strcmp(argv[1], "greedy") != 0) {
		printf("Enter the traversal from dfs, bfs, greedy\nIn the format\n\t\t./a.out dfs\n# Refer README.md for more info #\n");
		return 0;
	}

	flag = (char *)malloc(7 * sizeof(char));
	T = init_tree();

	// Take the command from the terminal
	strcpy(flag, argv[1]);

	// Taking input
	scanf("%d", &size);
	main_input();

	create_tree(T, size, input);

	traverse();
	print_traversal();

	stats();
	print_stats();

	// Free everything
	destroy_tree(T);
	free(input);
	free(output);
	free(flag);

	return 0;
}