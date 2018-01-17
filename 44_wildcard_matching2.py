class Solution(object):
    def find(self, s, rev):
        if rev:
            i = len(s) -1
            while i >= 0:
                if s[i] == "*" or s[i] == '?':
                    return i
                i -= 1
            return -1
        else:
            i = 0
            while i < len(s):
                if s[i] == "*" or s[i] == '?':
                    return i
                i += 1
            return -1
    
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if s == p or (len(p) > 0 and all([x=="*" for x in p])):
            return True
        if len(s) == 0 or len(p) == 0:
            return False
        if p.find("*") == -1 and p.find("?") == -1 and s != p:
            return False
        if p[0] == "?":
            return self.isMatch(s[1:], p[1:])
        if p[-1] == "?":
            return self.isMatch(s[:-1], p[:-1])
        #print 'sss--- ', p[:self.find(p, False)]
        if not s.startswith(p[:self.find(p, False)]):
            return False
        #print 'eee--- ',p, "---",self.find(p, True), "====", p[self.find(p, True)+1:]
        if not s.endswith(p[self.find(p, True)+1:]):
            return False

        k = self.find(p, False)
        if s[:k] != p[:k]:
            return False
        if p[k] == "?":
            return self.isMatch(s[k:], p[k:])

        nx = p.find("*", k+1)
        nw = p.find("?", k+1)
        if nx == -1 and nw == -1:
            return s.endswith(p[k+1:])
            
        nk = nx if nx != -1 else nw
        if nw != -1 and nw < nk:
            nk = nw
        if nk == k+1:
            if p[nk] == "*":
                return self.isMatch(s[k:], p[nk:])
            else:
                return self.isMatch(s[k+1:], "*" + p[nk+1:])

        sstr = p[k+1:nk]
        #print sstr
        j = s.find(sstr, k)
        while j != -1:
            if self.isMatch(s[j+len(sstr):], p[nk:]):
                return True
            j = s.find(sstr, j+1)
        return False






s = Solution()

#print s.isMatch("abefcdgiescdfimde", "ab*cd?i*de")
#print s.isMatch("aaaa", "***a")
#print s.isMatch("", "*")
#print s.isMatch("ca", "*?a*")
#print s.isMatch("ho", "**ho")
#print s.isMatch("b", "*?*?")
#print s.isMatch("baaaa", "*aaa")
#print s.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a")
#print s.isMatch("a", "")
#print s.isMatch("abc", "abc?*")
print s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")
