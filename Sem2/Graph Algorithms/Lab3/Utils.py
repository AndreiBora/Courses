'''
Created on 26 apr. 2017

@author: andrei
'''
from EdgeProperty import EdgeProperty
import sys

# sys.setrecursionlimit(10000)


class Utils(object):
    def getPath(self, s, t, prev):
        """
        Helper function, recove the path from a 
        dictionary in which we store the predecessor
        input: s -source vertex
               t  - target vertex
               prev - dictionary containing predecessor
        """    
        x = t
        sol = []
        while(x != None):
            sol.append(x)
            x = prev[x]
        sol.reverse()
        return sol 
    
    def getMinCostPathBellman(self, g, s, t):
        '''
        Return the minimum cost in a directed graph.Also determine
        if there is a cycle
        input: g - graph adjacency list
               s - source vertex
               t - target vertex
        output: return a list of vertices representing the graph
                print a message in case of a negative cycle or
                if there is no walk between 2 vertices
        '''    
        w = [ {s : 0} ]
        n = g.numberOfVertices()
        prev = {s : None}
        for k in range(n):
            prevDist = w[k]
            nextDist = {}
            for x in prevDist.keys():
                nextDist[x] = prevDist[x]
            for x in prevDist.keys():
                for y in g.parseEdgeOut(x):
                    if (y not in nextDist.keys() or 
                            nextDist[y] > nextDist[x] + g.getCost(x, y)):
                        nextDist[y] = nextDist[x] + g.getCost(x, y)
                        prev[y] = x
            w.append(nextDist)
        
        if t not in prev.keys():
            print("There is not a walk between {} and {}".format(s,t))
            return 
        
        for x in prevDist.keys():
            for y in g.parseEdgeOut(x):
                if(nextDist[y] > nextDist[x] + g.getCost(x,y)):
                    print("There is a negative cycle starting from vertex {}".format(s))
                    return
                
        return self.getPath(s, t, prev)
    
