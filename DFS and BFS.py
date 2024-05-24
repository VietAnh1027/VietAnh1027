from collections import defaultdict


class node:
    def __init__(self, name, par = None):
        self.name = name
        self.par = par
    def display(self):
        print(self.name, end=', ')


def equal(O,G):
    return O.name == G.name


def checkInArray(temp, Open):
    for x in Open:
        if equal(temp,x):
            return True
    return False


def path(O):
    while O != None:
        print(O.name)
        O = O.par
    return


def printLst(filename, lst):
    print(filename, end=' ')
    for x in lst:
        x.display()
    print()
    return

data = defaultdict(list)
data['A'] = ['B','C']
data['B'] = ['D','E']
data['E'] = ['I','J']
data['I'] = ['N','P']
data['P'] = ['R']
data['C'] = ['F','G','H']
data['G'] = ['K','M']
data['H'] = ['M']
data['K'] = ['L']
data['L'] = ['1']
data['M'] = ['Q']


def DFS(S = node('A'), F = node('Q')):
    Open = []
    Closed = []
    Open.append(S)
    while True:
        printLst('Open = ', Open)
        printLst('Closed = ', Closed)
        if len(Open) == 0:
            print("Can't Find !")
            return
        O = Open.pop(0)
        Closed.append(O)
        if equal(O,F):
            print('Finished !')
            path(O)
            return
        index = 0
        for x in data[O.name]:
            tmp = node(x,O)
            check1 = checkInArray(tmp, Open)
            check2 = checkInArray(tmp, Closed)
            if not check1 and not check2:
                Open.insert(index,tmp)
                index += 1


def BFS(S = node('A'), F = node('1')):
    Open = []
    Closed = []
    Open.append(S)
    while True:
        printLst('Open = ', Open)
        printLst('Closed = ', Closed)
        if len(Open) == 0:
            print("Can't find !")
            return
        O = Open.pop(0)
        Closed.append(O)
        if equal(O,F):
            print("Finished !")
            path(O)
            return
        for x in data[O.name]:
            tmp = node(x,O)
            check1 = checkInArray(tmp, Open)
            check2 = checkInArray(tmp, Closed)
            if not check1 and not check2:
                Open.append(tmp)


BFS()