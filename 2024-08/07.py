# Problem: 273. Integer to English Words
# Link: https://leetcode.com/problems/integer-to-english-words/
# Beats: 54.07% (Runtime: 37 ms), 75.27% (Memory: 16.56 MB)
# Time Complexity: O(log(N)) - The while loop iterates log base 1000 of num times, which is effectively O(log(N)).
# Space Complexity: O(1) - The space used is constant and does not depend on the input size.

ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
thousands = ["", "Thousand", "Million", "Billion"]

class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        
        # Helper function to convert a number less than 1000 to words
        def words(n: int) -> str:
            if n == 0:
                return ""
            elif n < 20:
                return ones[n]
            elif n < 100:
                return tens[n // 10] + (" " + ones[n % 10] if n % 10 != 0 else "")
            else:
                return ones[n // 100] + " Hundred" + (" " + words(n % 100) if n % 100 != 0 else "")

        result = ""
        index = 0
        
        while num > 0:
            if num % 1000 != 0:
                result = words(num % 1000) + " " + thousands[index] + " " + result
            num //= 1000
            index += 1
        
        return result.strip()

# Example test cases
solution = Solution()

# Test case 1
num1 = 123
print(solution.numberToWords(num1))  # Output: "One Hundred Twenty Three"

# Test case 2
num2 = 12345
print(solution.numberToWords(num2))  # Output: "Twelve Thousand Three Hundred Forty Five"

# Test case 3
num3 = 1234567
print(solution.numberToWords(num3))  # Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
