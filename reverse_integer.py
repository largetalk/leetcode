
# Reverse digits of an integer.

# Example1: x = 123, return 321
# Example2: x = -123, return -321

class Solution:
    # @return an integer
    def reverse(self, x):
        a = str(x)
        if not a.startswith('-'):
            return int(''.join(reversed(a)))
        else:
            b = int(''.join(reversed(a[1:])))
            return -b
            
