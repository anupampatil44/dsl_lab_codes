class Stringops:

    def __init__(self,s):
        self.s=s

    def occur(self, ch):
        count=0;
        for i in self.s:
            if(i==ch):
                count+=1
        return count;
    def pal(self):
        rev=""
        for i in range(len(self.s)-1, -1, -1):
            rev+=self.s[i]
        if(rev==self.s):
            return True
        else:
            return False

    def substring(self, start, end):
        subs=""
        for i in range(start,end):
            subs+=self.s[i]
        return subs

    def substringat(self, subs):
        sl=len(subs)
        try:
            for i in range(0, len(self.s)):
                if(self.s[i]==subs[0]):
                    if(self.substring(i, i+sl)==subs):
                        return i
        except:
            return -1

    def wordcount(self):
        so=[]
        k = 0
        start = 0
        while k < len(str):
            if (str[k] == " "):
                if (obj.substring(start, k) not in so):
                    so.append(obj.substring(start, k))
                start = k + 1
            elif (k == len(str) - 1):
                so.append(obj.substring(start, k + 1))
            k += 1

        for m in range(len(so)):
            c=0
            start=0
            for i in range(0, len(self.s)):
                if(self.s[i]==" "):
                    if(self.substring(start,i)==so[m]):
                        c+=1
                    start=i+1
                elif(i==len(self.s)-1):
                    if(self.substring(start,len(self.s))==so[m]):
                        c+=1
                    start=i+1
            print("Occurence of", so[m], "is: ", c)

    def long(self):
        i=0
        start=0
        count=0
        max=0
        space=0
        l=""
        while(i<len(self.s)):
            if self.s[i]==" ":
                space+=1
                if(max<count):
                    max=count
                    start = i - max
                count = 0
            count += 1
            if(i==len(self.s)-1 and space==0):
                start=0
                max=len(self.s)
            i+=1
        l += self.substring(start, start + max)
        print("Longest word:",l)






obj=Stringops("")
while(1):
    print("\n\nEnter choice:",end="")
    print("1)Enter a string")
    print("2)Occurence of a character in string")
    print("3)First index of substring to be searched")
    print("4)Occurence of all words in a string")
    print("5)Check for palindrome string")
    print("6)Longest word in the string")
    print("7)Exit")
    choice=int(input())
    if choice==1:
        print("Enter a string:",end="")
        str=input()
        obj=Stringops(str)
    if choice==2:
        print("Which character do you wish to search?: ",end="")
        char=input()
        print("occurence of char:", obj.occur(char))
    if choice==3:
        print("Enter substring to search: ",end="")
        subs=input()
        print("pos. of required substring:", obj.substringat(subs))
    if choice==4:
        obj.wordcount()
    if choice==5:
        print("Palindrone?: ", obj.pal())
    if choice==6:
        obj.long()
    elif choice==7:
        print("Exiting.....")
        break





