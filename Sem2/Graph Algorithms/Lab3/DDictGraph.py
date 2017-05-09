'''
Created on 2 apr. 2017

@author: andrei

'''

class DoubleDictGraph:
    """A directed graph, represented as two maps,
    one from each vertex to the set of outbound neighbors,
    the other from each vertex to the set of inbound neighbors"""

    def __init__(self,vertices):
        """Creates a graph with n vertices (numbered from 0 to n-1)
        and no edges"""
        self._dictOut={}
        self._dictIn = {}
        for vertex in range(vertices):
            self._dictOut[vertex]=[]
            self._dictIn[vertex] = []
    

    def addVertex(self,node):
        """
        Insert a vertex
        input: node
        Precondition: node to exists
        """
        if self.isNode(node):
            print("Vertex {} already exists".format(node))
        else:
            self._dictIn[node] = []
            self._dictOut[node] = []
            print("Vertex {} was successfully added".format(node))
    
    def addEdge(self,source,target):
        """"
        Add an arc between 2 given vertices
        input:source - first vertex
                target - second vertex
        Precondition: Both vertices to exists 
                      The is no vertices from source to target
        """
        '''
        if not self.isNode(source):
            raise ValueError("Vertex {} doesn't exists".format(source))
        if not self.isNode(target):
            raise ValueError("Vertex {} doesn't exists".format(target))
        '''
        #raise ValueError("Edge exists")
        
        if not self.isEdge(source, target):
            self._dictOut[source].append(target)
            self._dictIn[target].append(source)

    def parseEdgeIn(self, v):
        """
        Return a list of the inbound neighbors
        input v- vertex
        Precondition: vertex to exist
        """
        if not self.isNode(v):
            raise ValueError("{} is not a vertex ".format(v))   
        vList = [] 
        for vertex in self._dictIn[v]:
            vList.append(vertex)
        
        return vList
        
    def parseEdgeOut(self, v):
        """
        Return a list of the inbound neighbors
        input v- vertex
        Precondition: vertex to exist
        """
        if not self.isNode(v):
            raise ValueError("{} is not a vertex ".format(v)) 
        
        vList = [] 
        for vertex in self._dictOut[v]:
            vList.append(vertex)
        
        return vList
    
    def parseVertices(self):
        """
        Return a list of all the vertices in the graph
        """
        vList = []
        for vertex in self._dictOut.keys():
            vList.append(vertex)
        
        return vList

    def isEdge(self,source,target):
        """
        Returns True if there is an edge from source to target, False otherwise
        input:source - first vertex
                target - second vertex
        Precondition: Both vertices to exists 
        """
        if not self.isNode(source):
            raise ValueError("Vertex {} doesn't exists".format(source))
        if not self.isNode(target):
            raise ValueError("Vertex {} doesn't exists".format(target))
        return target in self._dictOut[source]


    def numberOfVertices(self):
        """
        Return the number of vertices
        """
        return len(self._dictIn.keys())
    
    def isNode(self,node):
        """
        Returns True if node is in the graph, False otherwise
        input:node - vertex
        """
        return node in list(self._dictIn.keys())
        
    def inDegree(self,x):
        """
        Return the number of outbound neighbors of vertex x
        """ 
        if self.isNode(x):
            return len(self._dictIn[x])
        raise Exception("Node {} is not a node.".format(x))
    
    def outDegree(self,x):
        """
        Return the number of inbound neighbors of vertex x
        """ 
        if self.isNode(x):
            return len(self._dictOut[x])
        raise Exception("Node {} is not a node.".format(x))
    
    def getIsolated(self):
        for vertex in range(0,self.numberOfVertices()):
            if len(self._dictIn[vertex]) == 0 and len(self._dictOut[vertex]) == 0:
                print(vertex)
                
    
    
            