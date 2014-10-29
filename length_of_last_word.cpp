
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//For example, 
//Given s = "Hello World",
//return 5.


class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int olen = 0;
            int len = 0;
            for (;*s != '\0';s++) {
                if (*s == ' ') {
                    if (len != 0) {olen = len;}
                    len = 0;
                } else {
                    len ++;
                }
            }
            if (len == 0) {
                return olen;
            }
            return len;
        }
};

// other people answer
//int lengthOfLastWord(const char* s) {
//    int len = 0;
//    while (*s) {
//        if (*s++ != ' ')
//            ++len;
//        else if (*s && *s != ' ')
//            len = 0;
//
//    }
//    return len;
//}
