class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        while p.find("**") != -1:
            p = p.replace("**", "*")
        i = 0
        k = 0
        while(i < len(s) and k < len(p)):
            c = p[k]
            if c == "?" or c == s[i]:
                i += 1
                k += 1
                continue
            if c == "*":
                nc = None if k+1 >= len(p) else p[k+1]
                if nc is None:
                    return True
                elif nc == "*":
                    k += 1
                    continue
                elif nc == "?":
                    return self.isMatch(s[i+1:], "*" + p[k+2:])
                else:
                    nx = p.find("*", k+2)
                    nw = p.find("?", k+2)
                    if nx != -1 or nw != -1:
                        nk = nx if nx != -1 else nw
                        if nw != -1 and nw < nk:
                            nk = nw
                    else:
                        nk = len(p)
                    j = i
                    sstr = p[k+1:nk]
                    #print sstr
                    while s.find(sstr, j) != -1:
                        j = s.find(sstr, j)
                        #print s[j+len(sstr):], "===", p[k+1+len(sstr):]
                        if self.isMatch(s[j+len(sstr):], p[k+1+len(sstr):]):
                            return True
                        j += 1
                    return False
            else:
                return False

        if i < len(s):
            return False
        if k < len(p):
            return all([x=="*" for x in p[k:]])
        
        return True


s = Solution()

print s.isMatch("abefcdgiescdfimde", "ab*cd?i*de")
print s.isMatch("aaaa", "***a")
print s.isMatch("", "*")
print s.isMatch("ca", "*?a*")
print s.isMatch("ho", "**ho")
print s.isMatch("b", "*?*?")
print s.isMatch("baaaa", "*aaa")
print s.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a")
