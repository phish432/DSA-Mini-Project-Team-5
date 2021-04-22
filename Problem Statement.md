# Tree Search Library

**TA Incharge**: Arpan Dasgupta

Tree searches and their visualizations are key to the widest variety of modern algorithms. Make a general tree search library to contribute to this task.

## A. Legend
You need to write a generic tree search library with the ability to simply change the exploration strategy (and hence the algorithm) by changing a single function in the code. The library should also provide several statistics about the search algorithm which allows easy plotting and analysis of the strategy. These kinds of libraries (much advanced versions ofc) are used in places like DeepMind to analyse their search strategies like Monte Carlo Tree Search.

## B. Project Requirements (Subparts)
1. The tree node should be generic enough to allow arbitrarily complex information to be stored (say game states and other variables). By default, you might want to store information like time seen, depth etc. to perform different searches.
2. The next node to explore in a tree search can be picked via a generic priority queue instead of a specific data structure like stack or queue in DFS or BFS. The comparator function for the priority queue should be something which can be plugged in by the user to allow them to change the algorithm.
3. Default algorithms - DFS, BFS, A-star and greedy search need to be provided as sample (basically, write the comparator function with required node structure for these algorithms). [Big bonus if you can do MCTS :P]
4. Some information needs to be placed in a global array at each iteration for analytics. Some of this information will be - max depth, average depth,
branching factor. You can add more of this if you want. This information can be plotted/analyzed for different algorithms to show the difference. (DFS
max depth increases fast, branching factor less, etc.) [Plotting not necessary but would be nice]

## C. Additional Information
1. The file the user needs to change must be a single file which has the node struct, the comparator for the priority queue and any other necessary function which the user needs to modify.
2. The tree structure will be input beforehand from the user (including required details for each node).
3. The data to test your algorithm on can be picked from somewhere or can be generated or we might provide it to you, more info on this later.