def longest_increasing_subsequence(numbers):
    temp_list = [1 for x in range(0,n)]
    i,j = 1,0
    while i<len(numbers) and j<len(numbers):
        if numbers[j]<numbers[i]:
            if temp_list[j]+1>temp_list[i]:
                temp_list[i] = temp_list[j]+1
        j=j+1
        if j==i:
            j,i=0,i+1
    return max(temp_list)

if __name__ == '__main__':
    n = int(input())
    numbers=list(map(int,input().split()))
    print (longest_increasing_subsequence(numbers))