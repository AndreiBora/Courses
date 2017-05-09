
from DDictGraph import DoubleDictGraph

class EdgeProperty(DoubleDictGraph):
    """
    A directed graph that have a cost dictionary
    """
    def __init__(self,nrVertices):
        DoubleDictGraph.__init__(self, nrVertices)
        self._DictCost = {}
        
    def getEdges(self):
        return list(self._DictCost.keys())
        
    def retriveCost(self,source,target):
        """
        Return the cost of an edge between two given vertices
        input: source-first vertex
                destination - second vertex
        Precondition: Both vertices to exists 
                      There must be an edge between the two nodes
        """
        if not (self.isNode(source) and self.isNode(target)):
            raise ValueError("This are not valid nodes")
        if not(self.isEdge(source,target)):
            raise ValueError("There is no edge between %i and %i",source,target)
        epKey = (source,target)
        return self._DictCost[epKey]
    
    def addCost(self,epKey,cost):
        """
        Assign to an edge a cost
        """
        self._DictCost[epKey] = cost
    
    def getCost(self,source,target):
        """
        Return the cost of a given edge
        input: source-first vertex
                destination - second vertex
        Precondition: The edge must exist
        Raises Value Error if there is no edge between vertices
        """
        if not self.isEdge(source, target):
            raise ValueError("It is not a valid edge")
        epKey =(source,target)
        return self._DictCost[epKey]
    
    def modifyCost(self,source,target,cost):
        """
        Change the cost of a given vertex
        input: source-first vertex
                destination - second vertex
        Precondition: The edge must exist
        Raises Value Error if there is no edge between vertices
        """
        if not self.isEdge(source, target):
            raise ValueError("It is not a valid edge")
        epKey =(source,target)
        self._DictCost[epKey] = cost
        return True
    
    def _removeCost(self,lst):
        """
        Delete the cost from the map
        input: lst- list containing vertices(pairs of two nodes)
        """
        for edge in lst:
            del self._DictCost[edge]
    
    def removeVertex(self,delNode):
        """
        Delete the Vertex and all the connections to other vertices
        input delNode: node to be deleted
        output True if the operation was successful
        """
        removeCostsLst = []
#         delete out edges
        for vertex in self._dictOut[delNode]:
            removeCostsLst.append((delNode,vertex))
            self._dictIn[vertex].remove(delNode)
#         delete in edges
        for vertex in self._dictIn[delNode]:
            removeCostsLst.append((vertex,delNode))
            self._dictOut[vertex].remove(delNode)
            
#         delete the delNode from both dictionaries
        del self._dictIn[delNode]
        del self._dictOut[delNode]
        
        self._removeCost(removeCostsLst)
        return True
    
    def removeEdge(self,source, target):
        """
        Remove the edge and the cost associated 
        input source - first vertex
                target-  second vertex
        output: return True if successful
        """
        if self.isEdge(source, target):
            self._dictOut[source].remove(target)
            self._dictIn[target].remove(source)
            removeCostLst = []
            removeCostLst.append((source,target))
            self._removeCost(removeCostLst)
        return True
        
    def readFromFile(self,fileName):
        try:
            f = open(fileName, "r")
            line = f.readline().strip().split()
            nrVerices = int(line[0])
            nrEdges = int(line[1])
            
            for vertex in range(nrEdges):
                line = f.readline().strip().split()
                source = int(line[0])
                target = int(line[1])
                cost = int(line[2])
                self.addEdge(source, target)
                
#                key represented by a tubple of the two vertices
                epKey  = (source,target)
                self.addCost(epKey, cost)
                
        except IOError:
            raise IOError("Cannot open the file")
        finally:
            f.close()
        
    def __str__(self):
        msg = "Outbound\n"
        newDict = sorted(self._dictOut.items())
#         newDict.sort()
        for k, v in newDict:
            msg += str(k) + ":" + str(v) + "\n"
        msg += "Inbound\n"
        newDict = sorted(self._dictIn.items())
#         newDict.sort()
        for k, v in newDict:
            msg += str(k) + ":" + str(v) + "\n"
        newDict = sorted(self._DictCost.items())
#         newDict.sort()
        for k, v in newDict:
            msg += str(k) + ":" + str(v) + "\n"
        return msg
        