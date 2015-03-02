
class Solution:
    # @return a string
    def convertToTitle(self, num):
        if num < 1:
            return ''
        a = []
        while num:
            num -= 1
            t = num%26
            num /= 26
            a.append(chr(t+65))
        a.reverse()
        return ''.join(a)

s = Solution()

print s.convertToTitle(1)
print s.convertToTitle(26)
print s.convertToTitle(27)
print s.convertToTitle(28)
print s.convertToTitle(1343)
#print s.convertToTitle(1000000001)
