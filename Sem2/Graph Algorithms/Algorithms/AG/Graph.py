'''
Created on 2 iun. 2017

@author: andrei
'''


class DiGraph:
    def __init__(self,nrVertices):
        self._dictIn ={}
        self._dictOut = {}
        self._dictCost= {}
        for vertex in range(nrVertices):
            self._dictIn[vertex] = []
            self._dictOut[vertex] = []
    
    def getNrVertices(self):
        return len(self._dictIn.keys())
    
    def parseEdgeOut(self,v):
        return list(self._dictOut[v])
    
    def parseEdgeIn(self,v):
        return list(self._dictIn[v])
    
    def isEdge(self,v1,v2):
        return v2 in self.parseEdgeOut(v1)
    
    def isNode(self,v):
        return v in self._dictIn[v]
    
    def addVertex(self,v):
        self._dictIn[v] = []
        self._dictOut[v] = []
    
    def addEdge(self,v1,v2):
        self._dictIn[v2].append(v1)
        self._dictOut[v1].append(v2)
    
    def parseVertices(self):
        vList = []
        for v in self._dictOut.keys():
            vList.append(v)
        return vList
    
    def inDegree(self,v):
        return len(self.parseEdgeIn(v))
    
    def outDegree(self,v):
        return len(self.parseEdgeOut(v))
    
    def addCost(self,epkey,cost):
        self._dictCost[epkey] = cost
        
    def retriveCost(self,source,target):
        epkey = (source,target)
        return self._dictCost[epkey]
    
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
        newDict = sorted(self._dictCost.items())
#         newDict.sort()
        for k, v in newDict:
            msg += str(k) + ":" + str(v) + "\n"
        return msg
    
    
    def readFromFile(self,filename):
        try:
            f = open(filename)
            line = f.readline().strip().split()
            nrVerices = int(line[0])
            nrEdges = int(line[1])
            for vertex in range(0,nrEdges):
                line = f.readline().strip().split()
                source = int(line[0])
                target = int(line[1])
                cost = int(line[2])
                
                self.addEdge(source,target)
                epkey = (source,target)
                self.addCost(epkey,cost)
                
        except:
            raise IOError("Cannot open the file")
        finally:
            f.close()
            
class UndirectedGraph:
    def __init__(self,nrVertices):
        self._dict ={}
        self._dictCost= {}
        for vertex in range(nrVertices):
            self._dict[vertex] = []
        
    def getNrVertices(self):
        return len(self._dict)
    
    def parseEdges(self,v):
        return list(self._dict[v])
    
    def isEdge(self,v1,v2):
        return v2 in self._dict[v1]
    
    def isNode(self,v):
        return v in self._dict.keys()
    
    def addVertex(self,v):
        self._dict[v] = []
        
    def addEdge(self,v1,v2):
        self._dict[v1].append(v2)
        self._dict[v2].append(v1)
    
    def parseVertices(self):
        vList = []
        for v in self._dict.keys():
            vList.append(v)
        return vList
    
    def addCost(self,epkey,cost):
        self._dictCost[epkey] = cost
        
    def retriveCost(self,source,target):
        epkey = (source,target)
        return self._dictCost[epkey]
        
        
    def readFromFile(self,filename):
        try:
            f = open(filename)
            line = f.readline().strip().split()
            nrVerices = int(line[0])
            nrEdges = int(line[1])
            for vertex in range(0,nrEdges):
                line = f.readline().strip().split()
                source = int(line[0])
                target = int(line[1])
                cost = int(line[2])
                self.addEdge(source,target)
                epkey1 = (source,target)
                epkey2 = (target,source)
                self.addCost(epkey1, cost)
                self.addCost(epkey2, cost)
        except:
            raise IOError("Cannot open the file")
        finally:
            f.close()
            
        
    def __str__(self):
        msg = "Edges\n"
        newDict = sorted(self._dict.items())
#         newDict.sort()
        for k, v in newDict:
            msg += str(k) + ":" + str(v) + "\n"
        
        return msg


        

    
    
        
        
    
    
    
    