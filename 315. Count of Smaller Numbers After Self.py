class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def mergeSort(enums):
            mid = len(enums)/2
            if mid:
                left = mergeSort(enums[:mid])
                right = mergeSort(enums[mid:])
                
                m, n = len(left), len(right)
                i=j=0
                
                while (i<m or j<n):#merge sort enums
                    #copy the right number which is smaller than left[i] to enums 
                    if(i==m) or (j<n and right[j][1] < left[i][1]):
                        enums[i+j] = right[j]
                        j += 1
                    else:
                        # j is the first number in the right half which is >= left[i]
                        # then j is the count of right numbers which are < left[i][0]
                        smaller[left[i][0]] += j
                        enums[i+j] = left[i]
                        i += 1

            return enums   
        
        smaller = [0] * len(nums)
        mergeSort(list(enumerate(nums)))
        return smaller
        