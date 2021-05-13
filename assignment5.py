class Perc:
    def __init__(self, arr):
        self.arr=arr
    def insertionSort(self):

        for i in range(1, len(self.arr)):
            k = self.arr[i]
            j = i - 1
            while j >= 0 and k < self.arr[j]:
                self.arr[j + 1] = self.arr[j]
                j -= 1
            self.arr[j + 1] = k
        return(self.arr)

    def shellSort(self):

        g = len(self.arr) // 2
        while g > 0:

            for i in range(g, len(self.arr)):
                t = self.arr[i]
                j = i
                while j >= g and self.arr[j - g] > t:
                    self.arr[j] = self.arr[j - g]
                    j -= g

                self.arr[j] = t
            g //= 2

        return(self.arr)


def main():
    print("How many students' percentages do you wish to enter?:",end=" ")
    n=int(input())
    arr=[]
    print("Enter the percentages of students:")
    i=0
    while (i<n):
        p=float(input())
        if p>=0 and p<=100:
            arr.append(p)
            i+=1
            continue
        else:
            print("Percentage should be between 0 and 100, try again.")
            continue

    obj=Perc(arr)
    i=obj.insertionSort()
    s=obj.shellSort()
    print("Showing Top 5 Scores in Descending Order:")
    print("Via Insertion sort:")
    if len(i)>5 or len(s)>5:
        for j in range(5):
            print(i[len(i)-1-j])

        print("Via Shell sort:")
        for k in range(5):
            print(s[len(s) - 1 - k])
    else:
        for j in range(len(i)):
            print(i[len(i)-1-j],"%")

        print("\nVia Shell sort:")
        for k in range(len(s)):
            print(s[len(s) - 1 - k],"%")

if __name__=="__main__":
    main()
