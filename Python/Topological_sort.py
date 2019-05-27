from collections import defaultdict 
class Graph: 
	def __init__(self,vertices): 
		self.graph = defaultdict(list)
		self.V = vertices  
	def addEdge(self,u,v): 
		self.graph[u].append(v) 
	def topo_sort(self,v,marked,stack): 
		marked[v] = True 
		for i in self.graph[v]: 
			if marked[i] == False: 
				self.topo_sort(i,marked,stack)  
		stack.insert(0,v) 

	
	def final_sort(self): 
		marked = [False]*self.V 
		stack =[]
		for i in range(self.V): 
			if marked[i] == False: 
				self.topo_sort(i,marked,stack)
		print(stack) 

g= Graph(5) 
g.addEdge(0, 1); 
g.addEdge(0, 3); 
g.addEdge(4, 3); 
g.addEdge(3, 1); 
g.addEdge(2, 4); 
g.addEdge(1, 2); 
g.final_sort() 

