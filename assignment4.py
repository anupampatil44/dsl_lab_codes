class Course:
    def __init__(self,l):
        self.l=l

    def linear(self,r):

        for i in range(len(self.l)):
            if self.l[i]==r:
                print("Rollno found at index",i, "; so student has attended program!")
                break
        else:
            print("Student did not attend program")



    def sentinel(self,r):
        last=self.l[len(self.l)-1]
        self.l[len(self.l) - 1]=r
        i=0
        while self.l[i]!=r:
            i+=1
        self.l[len(self.l) - 1]=last

        if i<len(self.l)-1 or r==self.l[len(self.l) - 1]:
            print("Rollno found at index ",i, "; so has attended program!")
        else:
            print("Student didn't attend program")


    def binary(self,r):
        s=0
        e=len(self.l)-1

        def bsort(l):
            for i in range(1, len(l)):
                for j in range(0, len(l) - i):
                    if l[j] > l[j + 1]:
                        t = l[j]
                        l[j] = l[j + 1]
                        l[j + 1] = t
            return l

        sl=bsort(self.l)
        while s<=e:
            mid=(s+e)//2
            if sl[mid]==r:
                print("Rollno found at index ", mid, "; so has attended program!")
                break
            elif r>sl[mid]:
                s=mid+1
            else:
                e=mid-1

        if(r not in sl):
            print("Student didn't attend program")
        else:
            print("Rollno found at index ", mid, "; so has attended program!")


    def fibonacci(self,r):
        fibMMm2 = 0
        fibMMm1 = 1
        fibM = fibMMm2 + fibMMm1

        while (fibM < len(self.l)):
            fibMMm2 = fibMMm1
            fibMMm1 = fibM
            fibM = fibMMm2 + fibMMm1

        off = -1

        while (fibM > 1):

            i = min(off + fibMMm2, len(self.l) - 1)

            if (self.l[i] < r):
                fibM = fibMMm1
                fibMMm1 = fibMMm2
                fibMMm2 = fibM - fibMMm1
                off = i

            elif (self.l[i] > r):
                fibM = fibMMm2
                fibMMm1 = fibMMm1 - fibMMm2
                fibMMm2 = fibM - fibMMm1

            else:
                print("Rollno found at index ", i, "; so has attended program!")
                break

        if (fibMMm1 and self.l[off + 1] == r):
            print("Rollno found at index ", off+1, "; so has attended program!")

        else:
            print("Student didn't attend program")


def main():
    print("Enter no of students whose data you wish to enter:",end=" ")
    a=int(input())
    l=[]

    for i in range(a):
        print("Enter roll no: ")
        r=int(input())
        print("Attended training program[y/n]: ",end="")
        d=input()
        if d=='y' or d=="Y":
            l.append(r)
        elif d=='N' or d=="n":
            pass
        else:
            print("Invalid option entered")

    print("Enter a rollno to be searched: ",end='')
    n=int(input())
    obj=Course(l)
    print("Via Sentinal Search:")
    obj.sentinel(n)
    print("Via Linear Search:")
    obj.linear(n)
    print("Via Binary Search:")
    obj.binary(n)
    print("Via Fibonacci Search:")
    obj.fibonacci(n)

if __name__ == '__main__':
    main()
