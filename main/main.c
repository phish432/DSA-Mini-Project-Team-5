#include "utils.h"

int main(int argc, char *argv[])
{
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