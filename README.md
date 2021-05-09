# DSA-Mini-Project

## Topic
Tree Search Library

## How to clone

Open terminal and run the following command \
`$ git clone https://github.com/phish432/DSA-Mini-Project.git`


## How to compile

Compile using the following shell command on terminal\
`$ gcc ./main/main.c ./main/utils.c ./priority_queue/priority_queue.c ./tree/tree.c ./node/node.c`

## How to run the executable
1. If the user wants to run the "greedy" algorithm\
   `$ ./a.out greedy`
2. If the user wants to run the "DFS" algorithm\
   `$ ./a.out dfs`
3. If the user wants to run the "BFS" algorithm\
   `$ ./a.out bfs`



 **NOTE**: Sample test cases are found in the `Sample Code` directory. If the user wants to input using an input file, the user can input in the following format\
        `$ ./a.out bfs < ./Sample\ Code/ts_data_1.txt`

## How to check out the stats
1. ### If we are using the plot.py to plot the graph
   1. Compile the program by following the above steps and run the executable created.
   2. Change directory into the stats folder using the command `cd stats` 
   3. Run the command `python3 plot.py` on the terminal.
   4. This will create a *graph.png* file.
   5. On opening the file we will see an image of the graph.
   6. The 1st graph is the graph for max_depth  
   7. The 2st graph is the graph for avg_depth  
   8. The 3st graph is the graph for max_children  
2. ### If we are using a spreadsheet software for plotting the graph
   1. Compile the program by following the above steps and run the executable created.
   2. Change directory into the stats folder using the command `cd stats` 
   3. Open the **out.csv** file.
   4. It will open in the default spreadsheet software of the computer.
   5. Now insert a chart in the spreadsheet with the following data starting from the second row as the 1st row has the titles for the respective coloumns.