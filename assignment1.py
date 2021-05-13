class Set:
    
    def __init__(self):
        self.elements = []
    
    def addelement(self, x):
        dup = 0
        for i in range(len(self.elements)):
            if self.elements[i] == x:
                dup += 1
        if dup == 0:
            self.elements.append(x)
        else:
            print("Duplicate element!")
            self.addelement(input())

    def isemptyset(self):
        return self.elements == []

    def display(self):
        print(self.elements)

    def length(self):
        print(len(self.elements))
    
    def union(self, set2):
        unionSet = Set()
        for i in self.elements:
            unionSet.addelement(i)
        for k in range(len(set2.elements)):
            dup = 0
            for j in range(len(unionSet.elements)):
                if set2.elements[k] == unionSet.elements[j]:
                    dup += 1
                else: 
                    pass
            if dup == 0:
                unionSet.addelement(set2.elements[k])

        return unionSet

    def intersection(self, set2):
        intersectionSet = Set()
        for i in range(len(self.elements)):
            for j in range(len(set2.elements)):
                if self.elements[i] == set2.elements[j]:
                    intersectionSet.addelement(self.elements[i])
                
        return intersectionSet

    def A_minus_B(self, set2):
        A_B=Set()
        for i in range(len(self.elements)):
            dup = 0
            for j in range(len(set2.elements)):
                if self.elements[i] == set2.elements[j]:
                    dup += 1 #basically if the element of A exists in B we do not add it in the set, only exclsives to A are added.
                    break
            if dup == 0:
                A_B.addelement(self.elements[i])
        return A_B

def playIntersection(set1, set2):
    ans1 = set1.intersection(set2)
    return ans1

def playUnion(set1, set2):
    ans2 = set1.union(set2)
    return ans2

def EitherNotBoth(set1, set2):
    a = set1.A_minus_B(set2)
    b = set2.A_minus_B(set1)
    ans3 = playUnion(a ,b)
    return ans3

def cricketfootball(c, f, b):
    cricbad = playIntersection(c, b)
    footbad = playIntersection(f, b)
    cricfoot = playUnion(c, f)
    t = cricfoot.A_minus_B(cricbad)
    ans4 = t.A_minus_B(footbad)
    return ans4

def neithernor(set1, set2, univ):
    temp = univ.A_minus_B(set1.union(set2))
    return temp

print("Input total no. of students: ",end="")
n = int(input())

c = Set()
f = Set()
b = Set()
univ = Set()
for i in range(n):
    print("Name of student {}: ".format(i+1),end="")
    a=input()
    univ.addelement(a)
    print("Which sports does he play? Type f for football,b for badminton & c for cricket: ",end='')
    ch=input()
    ch=ch.split()
    if "f" in ch:
        f.addelement(a)
    if "b" in ch:
        b.addelement(a)
    if "c" in ch:
        c.addelement(a)



print("Students who play both cricket and badminton-")
temp = playIntersection(c, b)
temp.display()

print("List students who play either cricket or badminton but not both-")
temp = EitherNotBoth(c, b)
temp.display()

print("Students who play neither cricket nor badminton-")
temp = neithernor(c, b, univ)
temp.display()

print("Students who play cricket and football but not badminton-")
temp = cricketfootball(c, f, b)
temp.display()

