print ("Enter number of elements")
n = int(input())
print ("Enter array")
l=list(map(int,input().split()))

for i in range(n-1):  
        for j in range(n-i-1): 
            if l[j] > l[j+1] : 
                l[j], l[j+1] = l[j+1], l[j] 

print ("Sorted Array:") 
print (l)