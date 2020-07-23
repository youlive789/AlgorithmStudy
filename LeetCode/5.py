class Solution:

    def longestPalindrome(self, s: str) -> str:
        self.cache = [[0] * (len(s)+1)] * (len(s)+1)
        return self.answer(s, 0, len(s))

    def answer(self, target, start, end) ->str:
        if self.cache[start][end]:
            return self.cache[start][end]
        else :
            if len(target) <= 1:
                self.cache[start][end] = target
                return target
            else:
                if self.is_palindrome(target):
                    self.cache[start][end] = target
                    return target
                left = self.cache[start][end - 1] = self.answer(target[start:end-1], start, end - 1)
                right = self.cache[start + 1][end] = self.answer(target[start+1:end], start + 1, end)
                if len(left) > len(right):
                    return left
                else:
                    return right

    def is_palindrome(self, target):
        mid = int(len(target) / 2)
        if len(target) % 2 == 0:
            if target[:mid] == target[mid:][::-1]:
                return True
        else:
            if target[:mid] == target[mid+1:][::-1]:
                return True
        return False

if __name__ == "__main__":
    s = Solution()

    # print(s.longestPalindrome("babac"))
    # print(s.longestPalindrome("ccb"))
    print(s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"))