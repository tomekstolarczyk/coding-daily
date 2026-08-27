from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:

        # bedziemy sobie szli z dwoma pointerami i ruszamy ten ktory jest mniejszy
        # stale trakujac max_area
        max_area = 0
        i, j = 0, len(height)-1

        while i<j:

            current_area = min(height[i], height[j]) * (j-i)
            max_area = max(max_area, current_area)

            if height[i] < height[j]:
                i += 1
            else:
                j-=1 

        return max_area

if __name__ == "__main__":
    solution = Solution()
    print("Result :", solution.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7])) # EX : 49