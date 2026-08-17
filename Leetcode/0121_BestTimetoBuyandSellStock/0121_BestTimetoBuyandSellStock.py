from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        if not prices:
            return 0
        
        minPriceSoFar = prices[0]
        maxProfit = 0

        for priceToday in prices:

            maxProfit = max(priceToday - minPriceSoFar, maxProfit)
            minPriceSoFar = min(minPriceSoFar, priceToday)

        return maxProfit

if __name__ == "__main__":
    solution = Solution()

    prices1 = [7, 1, 5, 3, 6, 4]
    print(f"Case 1: {solution.maxProfit(prices1)}")  # Oczekiwane 5

    prices2 = [7, 6, 4, 3, 1]
    print(f"Case 2: {solution.maxProfit(prices2)}")  # Oczekiwane 0