class quicksort:
    def __init__(self,l,):
        self.l=l


    def divide(self,arr, low, high):
        i = (low - 1)
        pivot = arr[high]

        for j in range(low, high):

            if arr[j] <= pivot:
                i = i + 1
                t=arr[i]
                arr[i]= arr[j]
                arr[j]= t
        t=arr[i+1]
        arr[i + 1]=arr[high]
        arr[high]=t
        return (i + 1)



    def quick(self,low,high):
        if low < high:
            d = self.divide(self.l,low,high)
            self.quick(low,d-1)
            self.quick(d+1,high)



def main():
    print("No. of students whose data you wish to enter:",end=" ")
    n=int(input())
    l=[]
    print("Taking Percentage data of Students:")
    i = 0
    while (i < n):
        print("Student " + str(i + 1) + ": ", end='')
        p = float(input())
        if p >= 0 and p <= 100:
            l.append(p)
            i += 1
            continue
        else:
            print("Percentage should be between 0 and 100, try again.")
            continue
    low=0
    high=n-1
    obj=quicksort(l)
    obj.quick(low, high)
    obj.l=obj.l[::-1]
    print(obj.l)
    print("Displaying Top 5 scores:")
    if len(obj.l) > 5:
        for i in range(5):
            print("No " + str(i + 1) + " :")
            print(str(obj.l[i]) + "%")
    else:
        for i in range(len(obj.l)):
            print("No " + str(i + 1) + " :")
            print(str(obj.l[i]) + "%")
if __name__ == '__main__':
    main()