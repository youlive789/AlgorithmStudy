class Solution:

    def longestPalindrome(self, s: str) -> str:
        long = ""
        if len(s) <= 1:
            return s
        
        for i in range(len(s)):
            for j in range(len(s), i, -1):
                print(i, j)
                if len(long) >= j-i:
                    continue
                elif s[i:j] == s[i:j][::-1]:
                    long = s[i:j]

        return long


if __name__ == "__main__":
    s = Solution()

    print(s.longestPalindrome("babcb"))
    # print(s.longestPalindrome("abcdbbfcba")) # bb
    # print(s.cache)
    # print(s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"))