'''
Created on 2 iun. 2017

@author: andrei
'''

from Graph import DiGraph, UndirectedGraph
from Utils import *

def getVerticesFromFile(filename = "ham.txt"):
    try:
        f= open(filename,"r")
        line = f.readline().strip().split()
        nrVertices = int(line[0])
        return nrVertices
    except IOError:
        raise IOError("Cannot open the file")
    finally:
        f.close()

def showMenu():
    print()
    print("1 - print graph")
    print("2 - BFS - find all accessible vertices")
    print("3 - BFS - find the minimum length path between two vertices")
    print("4 - DFS - find all the connected components")
    print("5 - Find strongly connected components in a directed graph")
    print("6 - Find shortest path in a weighted directed graph(Bellman-Ford)")
    print("7 - Shortest path between 2 vertices using Dijkstra algorithm")
    print("8 - Shortest path between all pair using Floyd-Warshall algorithm")
    print("9 - Topological sort by predecessor counting")
    print("10 - Topological sorting using DFS")
    print("11 - Find the longest path in DAG (unweighted) in O(V+E)")
    print("12 - Find minimum spanning tree using Prim's algorithm")
    print("13 - Find hamiltonean cycle")
    print("14 - Print all hamiltonean cycles")
    
showMenu()
vertices= getVerticesFromFile("ham.txt")


g = DiGraph(vertices)
g.readFromFile("ham.txt")

command = input("> ")
while  True:
    if command == '0':
        break    
    elif command == '1':
        print(g)
    elif command == '2':
        v = int(input("Input starting vertex"))
        acc,prev = bfs(g,v)
        print("Accessible vertices are")
        print(acc)
        print("The tree is :")
        printTree(g,v,prev)
        
    elif command == '3':
        source = int(input("source: "))
        target = int(input("target: "))
        print(getMinLengthPath(g,source,target))
        
    elif command == "4":
        dict = connectedComponents(g)
        print(dict)
    elif command == '5':
        dict = scc(g)
        print(dict)
    elif command == '6':
        source = int(input("source: "))
        target = int(input("target: "))
        lst = bellman(g,source,target)
        print(lst)
    elif command == '7':
        source = int(input("source: "))
        target = int(input("target: "))
        lst = dijkstra(g,source,target)
        print(lst)
    elif command == '8':
        source = int(input("source: "))
        target = int(input("target: "))
        print(getPathFloyd(g, source, target))
        
    elif command == '9':
        print(topoSortByCounting(g))
    elif command == '10':
        print(topoSortByDFS(g))
    elif command == '11':
        print(longestPathDag(g))
    elif command == '12':
        source = int(input("source: "))
        print(prim(g,source))
    elif command == '13':
        print(hamiltoneanCycle(g))
    elif command == '14':
        print(allHamiltoneanCycle(g))
    command = input("> ")
        