'''
Created on 2 apr. 2017

@author: andrei
'''
from DDictGraph import DoubleDictGraph
from EdgeProperty import EdgeProperty
from copy import deepcopy
from Utils import Utils

def getVerticesFromFile(fileName = "in.txt"):
    try:
        f = open(fileName, "r")
        line = f.readline().strip().split()
        nrVerices = int(line[0])
        nrEdges = int(line[1])
        return nrVerices
    except IOError:
        raise IOError("Cannot open the file")
    finally:
        f.close()


def showMenu():
    print()
    print("1 - get number of vertices")
    print("2 - check if edge exists")
    print("3 - degrees of vertex")
    print("4 - show outbound edges of a vertex")
    print("5 - show inbound edges of a vertex")
    print("6 - add vertex")
    print("7 - remove vertex")
    print("8 - add edge")
    print("9 - remove edge")
    print("10 - show vertices")
    print("11 - get cost of an edge")
    print("12 - modify cost of an edge")
    print("13 - show original graph")
    print("14 - show the modified graph")
    print("15 - get the number of isolated vertices")
    print("16 - find connected components")
    print("17 - find shortest path between two vertices")
    print("0 - exit")
    print("? - show menu")
    print()
    
showMenu()
nrVertices = getVerticesFromFile()
G = EdgeProperty(nrVertices)
U = Utils()
G.readFromFile("in.txt")
# copyGraph = deepcopy(G)
command = input("> ")
while True:
    #try:
    if command == '1':
        print("There are %i vertices." % G.numberOfVertices())
    elif command == '2':
        source = int(input("source: "))
        target = int(input("target: "))

        if G.isEdge(source, target):
            print("Edge exists.")
        else:
            print("Edge doesn't exist.")
            
    elif command == '3':
        x = int(input("vertex: "))
        print("inDegree: %i" % G.inDegree(x))
        print("outDegree: %i" % G.outDegree(x))
    elif command == '4':
        x = int(input("vertex: "))
        outEdges = G.parseEdgeOut(x)
        print(outEdges)
    elif command == '5':
        x = int(input("vertex: "))
        inEdges = G.parseEdgeIn(x)
        print(inEdges)
    elif command == '6':
        x = int(input("vertex: "))
        G.addVertex(x)
    
    elif command == '7':
        x = int(input("vertex: "))
        G.removeVertex(x)
    
    elif command == '8':
        source = int(input("source: "))
        target = int(input("target: "))
        G.addEdge(source, target)
        epKey = (source, target)
        cost = int(input("cost: "))
        G.addCost(epKey, cost)
        
        
    elif command == '9':
        source = int(input("source: "))
        target = int(input("target: "))
        flag  = G.removeEdge(source, target)
        if flag:
            print("Edge was removed")
        else:
            print("Edge was removed")
            
    elif command == '10':
        vertices = G.parseVertices()
        print(vertices)
    elif command == '11':
        source = int(input("Source"))
        target = int(input("Target"))
        print("Cost = {}".format(G.getCost(source,target)))
    
    elif command == '12':
        source = int(input("Source"))
        target = int(input("Target"))
        newCost = int(input("Enter the new cost"))
        flag = G.modifyCost(source, target, newCost)
        if flag:
            print("Cost was updated")
        else:
            print("Cost was not updated")
    #elif command == '13':
       # print(copyGraph)
    elif command == '14':
        print(G)
    elif command == '15':
        G.getIsolated()
    elif command == '16':
        cmpLst = U.connectedComponents(G)
        nr=1
        for cmp in cmpLst:
            print("Component {}:".format(nr))
            print(cmp)
    elif command == '17':
        source = int(input("Source"))
        target = int(input("target: "))
        lst = U.getMinCostPathBellman(G,source,target)
        if lst != None:
            print(lst)
            
        
    elif command == '0':
        exit(0)
    elif command == '?':
        showMenu()
    else:
        print("bad command.")
#except Exception as e:
    #print(e)
    command = input("> ")
        
