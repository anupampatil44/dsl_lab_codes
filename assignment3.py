# Matrix Operations
class Matrix:

    def __init__(self,a,b,na,nb,ca,cb):
        self.a=a
        self.b=b
        self.na=na
        self.nb = nb
        self.ca=ca
        self.cb=cb

    def add(self):
        x=self.a
        y=self.b
        s=[]
        for i in range(self.na):
            s.append([])
            for j in range(self.ca):
                s[i].append(0)

        if len(x)!=len(y) or len(x[0])!=len(y[0]):
            return("Addtion cannot be performed as dimensions are different")
        else:
            for i in range(self.na):
                for j in range(self.ca):
                    s[i][j]=x[i][j]+y[i][j]
            return s

    def sub(self):
        d=[]
        for i in range(len(self.a[0])):
            d.append([])
            for j in range(self.na):
                d[i].append(0)
        p=self.a
        q=self.b
        if len(p)!=len(q) or len(p[0])!=len(q[0]):
            return("Subtraction cannot be performed as dimensions are different")

        else:
            for i in range(self.na):
                for j in range(len(self.a[0])):
                    d[i][j]=p[i][j]-q[i][j]
            return d

    def multiply(self):
        x=self.a
        y=self.b

        m=[]
        for i in range(self.cb):
            m.append([])
            for j in range(self.na):
                m[i].append(0)
        try:
            for i in range(self.na):
                for j in range(self.cb):
                    for k in range(self.nb):
                        m[i][j]+=x[i][k]*y[k][j]
            return m
        except:
            return("Multiplication of matrices not possible")

    def transpose(self):
        at=[]
        bt=[]
        # initialize a-transpose matrix
        for i in range(self.ca):
            at.append([])
            for j in range(self.na):
                at[i].append(0)

        #initialize b-transpose matrix
        for i in range(self.cb):
            bt.append([])
            for j in range(self.nb):
                bt[i].append(0)

        # store transpose of a
        for k in range(self.ca):
            for l in range(self.na):
                at[k][l]=self.a[l][k]

        #store transpose of b
        for k in range(self.cb):
            for l in range(self.nb):
                bt[k][l]=self.b[l][k]
        print("A transpose: ",at)
        print("B transpose: ", bt)


def main():
    na=int(input("Enter no of rows of matrix a: "))
    ca=int(input("Enter no of columns of matrix a: "))
    nb=int(input("Enter no of rows of matrix b: "))
    cb=int(input("Enter no of columns of matrix b: "))
    a=[]
    b=[]
    print("Enter elements of matrix a rowise")
    for i in range(na):

        l=input()
        l=l.split()
        l=[int(k) for k in l]
        a.append(l)

    print("Enter elements of matrix b rowise")
    for i in range(nb):
        l=input()
        l=l.split()
        l=[int(k) for k in l]
        b.append(l)
    obj=Matrix(a,b,na,nb,ca,cb)

    while(1):
        print("Choices:")
        print("1: Addition of matrices")
        print("2: Subtraction of matrices")
        print("3: Multiplication of matrices:")
        print("4: Transpose of matrices")
        print("5: Exit")
        c=int(input())
        if c==1:
            print("Addition of matrices: ", obj.add())
        elif c==2:
            print("Subtraction of matrices: ", obj.sub())
        elif c==3:
            print(" Multiplication of matrices: ",obj.multiply())
        elif c==4:
            obj.transpose()
        elif c==5:
            break
        else:
            print("Invalid choice try again")
if __name__=="__main__":
    main()
