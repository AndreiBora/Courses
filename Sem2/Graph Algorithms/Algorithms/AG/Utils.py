'''
Created on 2 iun. 2017

@author: andrei
'''

import math
import heapq
from copy import deepcopy

def bfs(g,start):
    '''
    Perform a BFS on the graph g and return all the accessible
    vertices from start
    '''
    visited =set()
    queue = []
    prev ={}
    dist = {}
    
    visited.add(start)
    queue.append(start)
    prev[start] = None
    dist[start]= 0
    accesible = []
    
    while queue:
        x = queue.pop(0)
        for y in g.parseEdges(x):
            if(y not in visited):
                visited.add(y)
                prev[y] = x
                dist[y] = dist[x] + 1
                queue.append(y)
    
    for i in visited:
        accesible.append(i)
    
    return accesible,prev

def getPath(source,target,prev):
    x = target
    sol = []
    while x != None:
        sol.append(x)
        x = prev[x]
    sol.reverse()
    
    return sol

def getMinLengthPath(g,s,t):
    acc,prev = bfs(g,s)
    return getPath(s,t,prev)

def printTree(g, s, parent):
    children = {}
    for x in parent.keys():
        children[x] = []
        
    for x in parent.keys():
        if(parent[x] != None):
            children[parent[x]].append(x)
    #print children
    indent = ""
    printTreeRecursive(s ,children,indent)
    print()
    

def printTreeRecursive(x, children, indent):
    '''
    It prints x, then the subtree of x 
    Input: 
        indent - string the tree indented 
    
    '''
    print (indent + str(x))
    indent += "    "
    for y in children[x]:
        printTreeRecursive(y, children, indent)
        
def dfs(g,vertex,visited,component):
    for x in g.parseEdges(vertex):
        if x not in visited:
            visited.add(x)
            dfs(g,x,visited,component)
    
    component.append(vertex)
    
def connectedComponents(g):
    '''
    Return the connected components in an undirected
    graph
    '''
    visited = set()
    components = {}
    nr = 0
    for vertex in g.parseVertices():
        if vertex not in visited:
            nr +=1
            component = []
            visited.add(vertex)
            dfs(g,vertex,visited,component)
            components[nr] = component
    
    return components
    

def dfs1(g,x,visited,procesed):
    for y in g.parseEdgeOut(x):
        if y not in visited:
            visited.add(y)
            dfs1(g,y,visited,procesed)
    procesed.append(x)
            
def scc(g):
    '''
    Return the vertices with the number of component it belongs to
    input g - directed graph 
    '''
    visited = set()
    processed= []
    
    for s in g.parseVertices():
        if s not in visited:
            visited.add(s)
            dfs1(g,s,visited,processed)
    
    visited.clear()
    q =[]
    comp ={}
    c = 0
    rez = []
    while processed:
        s = processed.pop()
        if s not in visited:
            c += 1
            comp[s] = c
            q.append(s)
            visited.add(s)
            while q:
                x = q.pop(0)
                for y in g.parseEdgeIn(x):
                    if y not in visited:
                        visited.add(y)
                        q.append(y)
                        comp[y] = c 
    
    rez1 ={}
    for k in comp.values():
        if k not in rez1.keys():
            rez1[k] = []
            
    for x in comp.keys():
        rez1[comp[x]].append(x)
        
    return rez1

def bellman(g,source,target):
    '''
    Find the shortest path between 2 vertices. 
    if there isn't a path between source and target it print a message
    if there is a negative cost cycle it prints a message
    input : source - the source vertex
            target - the destination vertex
    output a list with the vertices from the path
    '''
    prev = {}
    prev[source]= None
    #all node except the source have distance
    #infinity from the source vertex
    n = g.getNrVertices()
    dist = [math.inf]*n
    dist[source] = 0
    
    for step in range(0,g.getNrVertices()-1):
        for x in g.parseVertices():
            for y in g.parseEdgeOut(x):
                if(dist[y] > dist[x] + g.retriveCost(x,y)):
                    dist[y] = dist[x] + g.retriveCost(x,y)
                    prev[y] = x
                   
    if target not in prev.keys():
        print("Not a path from source to target")
        return 
    
    for x in g.parseVertices():
        for y in g.parseEdgeOut(x):
            if dist[y] > dist[x] + g.retriveCost(x,y):
                print("Negative cost cycle")
                return 
    
    return getPath(source, target, prev)

class PriorityQueueElement:
    def __init__(self,vertex,cost):
        self.vertex = vertex
        self.cost = cost
    
    def __eq__(self,that):
        return isinstance(that, PriorityQueueElement) and self.cost == that.cost
    
    def __lt__(self,that):
        return self.cost < that.cost

class PriorityQueue:
    def __init__(self):
        self.__l= []
    
    def dequeue(self):
        element = heapq.heappop(self.__l)
        return element.vertex,element.cost
    
    def enqueue(self,vertex,cost):
        element = PriorityQueueElement(vertex,cost)
        heapq.heappush(self.__l, element)
    
    def isEmpty(self):
        return len(self.__l) == 0
    
def dijkstra(g,source,target):
    prev ={}
    dist ={}
    q = PriorityQueue()
    dist[source] = 0
    prev[source] = None
    q.enqueue(source, 0)
    
    while not q.isEmpty():
        x,d = q.dequeue()
        for y in g.parseEdgeOut(x):
            if y not in dist.keys() or dist[y] > dist[x] + g.retriveCost(x,y):
                dist[y] = dist[x] + g.retriveCost(x,y)
                prev[y] = x
                q.enqueue(y, dist[y]) 
    
    if target not in dist:
        return None
    print("The distance from {} to {} is {}".format(source,target,dist[target]))
    
    sol =[]
    x = target
    while x !=None:
        sol.append(x)
        x = prev[x]
    
    sol.reverse()
    return dist,prev
    
def getPathFloyd(g,source,target):
    next = floyd(g)
    if next[source][target] == None:
        return []
    path = [source]
    while source != target:
        source = next[source][target]
        path.append(source)
    return path

def floyd(g):
    #create the distance matrix and initialize it with infinity
    dist = []
    next =[]
    n = g.getNrVertices()
    for i in range(n):
        dist.append([])
        next.append([])
        for j in range(n):
            dist[i].append(math.inf)
            next[i].append(None)
    for i in range(n):
        for j in range(n):
            if i == j:
                dist[i][j] = 0
            if g.isEdge(i,j):
                dist[i][j] = g.retriveCost(i,j)
                next[i][j] = j
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                altdist = dist[i][k] + dist[k][j]
                if dist[i][j] > altdist:
                    dist[i][j] = altdist
                    next[i][j] = next[i][k]
    
    '''
    print("Distance matrix")
    for i in range(n):
        for j in range(n):
            if dist[i][j] == math.inf:
                print(" {} ".format("INF"),end="")
            else:
                print(" {} ".format(dist[i][j]),end="")
        print()
    '''
    return next

def topoSortByCounting(g):
    '''
    Return nodes from a DAG into a topological order
    If there is a cycle it return None
    '''
    count = {}
    topoSort =[]
    q = []
    
    #put in the dictionary the indegree of all the vertices
    for vertex in g.parseVertices():
        count[vertex] = g.inDegree(vertex)
        if(g.inDegree(vertex) == 0):
            q.append(vertex)
    
    while q:
        x = q.pop(0)
        topoSort.append(x)
        for y in g.parseEdgeOut(x):
            count[y] -= 1
            if count[y] == 0:
                q.append(y)
    if len(topoSort) != len(g.parseVertices()):
        return None
    
    return topoSort
      

def dfsTopoSort(g,x,inProcess,fullyProcess):
    inProcess.add(x)
    for y in g.parseEdgeIn(x):
        if y in inProcess:
            return False
        if y not in fullyProcess:
            ok = dfsTopoSort(g,y,inProcess,fullyProcess)
            if not ok:
                return False
    inProcess.remove(x)
    fullyProcess.append(x)
    return True

def topoSortByDFS(g):
    '''
    Perform a topological sorting using an DFS based algorithm
    return None if there is a cycle
    '''
    fullyProcess =[]
    inProcess = set()
    
    for x in g.parseVertices():
        if x not in fullyProcess:
            ok = dfsTopoSort(g,x,inProcess,fullyProcess)
            if ok == False:
                return None
    return fullyProcess

def longestPathDag(g):
    topoSort = topoSortByCounting(g)
    dist = {}
    prev ={}
    for vertex in topoSort:
        dist[vertex] = 0
        prev[vertex] = None
    
    for x in topoSort:
        for y in g.parseEdgeOut(x):
            if dist[y] < dist[x] + 1:
                dist[y] = dist[x] + 1
                prev[y] = x
    longestDist = -1
    for x in topoSort:
        if dist[x] > longestDist:
            longestDist = dist[x]
            final = x
    
    x = final
    sol = []
    while x != None:
        sol.append(x)
        x = prev[x]
    
    sol.reverse()
    return sol
        
        
def prim(g,s):
    q = PriorityQueue()
    prev ={}
    dist={}
    edges =[]
    vertices = set()
    vertices.add(s)
    for x in g.parseEdges(s):
        dist[x] = g.retriveCost(s,x)
        prev[x] = s
        q.enqueue(x, dist[x])
    while not q.isEmpty():
        x,cost = q.dequeue()
        if x not in vertices:
            edges.append((prev[x],x))
            for y in g.parseEdges(x): 
                if (y not in dist.keys() or g.retriveCost(x,y) < dist[y]) and(y not in vertices):
                    dist[y] = g.retriveCost(x,y)
                    q.enqueue(y, dist[y])
                    prev[y] = x
            vertices.add(x)
    
    return edges

def hamiltoneanCycle(g):
    '''Returns a Hamiltonean cycle in g, if one exists, as a list of vertices,
    with the first and the last vertex on the list being equal (the length of
    the returned list will be n+1).
    Returns None if no Hamiltonean cycle exists in g.'''
    
    start_vertex = None

    
    for x in g.parseVertices():
        start_vertex = x
        break
    
    sol = []

    dfsHam(g, [ start_vertex ], sol)
    
    if( sol == [] ):
        return None
    
    return sol

def dfsHam(g, current_path, solution):
    '''
    the dfs function will put the hamiltonean cycle in solution if one exists
    '''
    current_node = current_path[-1]
    
    if( len( current_path ) == g.getNrVertices() ):
        if( current_path[ 0 ] in g.parseEdgeOut( current_node ) and solution == [] ):
              for it in current_path:
                  solution.append( it )
              solution.append( current_path[ 0 ] )
        return
    
    for v in g.parseEdgeOut( current_node ):
        if ( v not in current_path ):
            current_path.append( v )
            dfsHam(g, current_path, solution)
            current_path.pop()

def allHamiltoneanCycle(g):
    '''Returns a Hamiltonean cycle in g, if one exists, as a list of vertices,
    with the first and the last vertex on the list being equal (the length of
    the returned list will be n+1).
    Returns None if no Hamiltonean cycle exists in g.'''
    
    start_vertex = None

    
    for x in g.parseVertices():
        start_vertex = x
        break
    
    cycles = []

    dfsHam2(g, [ start_vertex ], cycles)
    
    if( cycles == [] ):
        return None
    
    return cycles

def dfsHam2(g, current_path, cycles):
    '''
    the dfs function will put the hamiltonean cycle in solution if one exists
    '''
    current_node = current_path[-1]
    
    if( len( current_path ) == g.getNrVertices() ):
        if( current_path[ 0 ] in g.parseEdgeOut( current_node ) ):
            solution = deepcopy(current_path)
            solution.append( current_path[ 0 ] )
            cycles.append(solution)
        return
    
    for v in g.parseEdgeOut( current_node ):
        if ( v not in current_path ):
            current_path.append( v )
            dfsHam2(g, current_path, cycles)
            current_path.pop()