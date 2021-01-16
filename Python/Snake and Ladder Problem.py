## Snake and Ladder Problem



# Dictionary containing all the possible nodes connected to each node if the board is represented as a graph
dicti = {}
for i in range(0,101):
    l = [i+j for j in range(1,7) if i+j < 101]
    dicti[i] = l

def boardInterruptions():
    '''This function initialises the snakes and ladders in the game'''
    
    # Ladder Input
    n = int(input("Enter the number of ladders in the game: "))
    ladders = {}
    for i in range(n):
        k = [int(j) for j in input(f"Enter the two ends of the ladder {i+1} separated by a space (smaller first):\n").split()]
        ladders[k[0]] = k[1]

    # Snake Input
    n = int(input("Enter the number of snakes in the game: "))
    snakes = {}
    for i in range(n):
        k = [int(j) for j in input(f"Enter the head and tail of the snake {i+1} separated by a space:\n").split()]
        snakes[k[0]] = k[1]

    return [snakes, ladders]

def snakeAndladder(graph, snakes, ladders):
    '''This function replaces the head/bottom of a snake/ladder by its tail/top in the graph of the board'''

    # Replace the bottom of each ladder by its top
    for i in ladders.keys():
        del(dicti[i])
        for j in range(max(0,i-6),i):
            if j in dicti.keys():
                if ladders[i] not in dicti[j]:
                    dicti[j][dicti[j].index(i)] = ladders[i]
                else:
                    dicti[j].remove(i)

    # Replace heads by its tails
    for i in snakes.keys():
        del(dicti[i])
        for j in range(max(0,i-6),i):
            if j in dicti.keys():
                if snakes[i] not in dicti[j]:
                    dicti[j][dicti[j].index(i)] = snakes[i]
                else:
                    dicti[j].remove(i)
    # Sort the list of adjacent nodes of each node in descending order
    # to enable the access of ladders before any other node
    for i in dicti:
        dicti[i].sort(reverse=True)    

def bfs(graph, end):
    '''This function is an implementation of Breadth First Search for the graph representation of the board to search for the position 'end'
    '''

    # List to check if a node is visited or not
    checkVisit = [False] * 101
    # List used as a queue for BFS
    # Initially it contains the source node 
    # and the depth of the source node
    queue  = [[0,0]]
    # Make its visit True as we are starting from it
    checkVisit[0] = True

    # While the loop contains any element
    while len(queue) != 0:
        # Get the first element of the queue and remove it
        s = queue[0]
        del(queue[0])
        # It is the desired position, return its depth
        if s[0]==end:
            return s[1]
        # Else traverse through each of its neighbouring nodes        
        for i in graph[s[0]]:
            # If its visit is False, make its visit True appending it and its depth to the list
            if checkVisit[i] == False:
                queue.append([i,s[1]+1]) 
                checkVisit[i] = True

    # If the loop ends before returning anything, the point cannot be reached
    # i.e. it is either head of snake or bottom of a ladder
    return "Position cannot be reached at the end of any possible turn."

if  __name__=="__main__":
    print("In this game, the player starts from 0 and goes to the desired position p \
as entered by the user in minimum number of throws. The maximum value of p is 100. \
The program tells that minimum number of throws. \n\n")

    board = boardInterruptions()
    snakes = board[0]
    ladders = board[1]

    snakeAndladder(dicti, snakes, ladders)

    p = int(input("Enter the desired positon p: "))
    print("\n\nThe minimum number of throws required to reach p is: ", bfs(dicti, p))