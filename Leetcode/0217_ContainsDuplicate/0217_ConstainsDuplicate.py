from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # 1. dziek set(nums) stworzymy hash set i automatycznie usuniemy powtorzenia w O(n)
        # 2. len() odczytuje rozmiar w O(1), jesli dlugosci beda rozne to znaczy ze w liscie byly duplikaty
        return len(nums) != len(set(nums))

if __name__ == "__main__":

    solution = Solution()

    # Test 1: Powinno zwrocic True
    test1 = [1, 2, 3, 1]
    print(f"Test 1 {test1}: {solution.containsDuplicate(test1)}")

    # Test 2: Powinno zwrocic False
    test2 = [1, 2, 3, 4]
    print(f"Test 2 {test2}: {solution.containsDuplicate(test2)}")

    # Test 3: Powinno zwrocic True 
    test3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    print(f"Test 3 {test3}: {solution.containsDuplicate(test3)}")