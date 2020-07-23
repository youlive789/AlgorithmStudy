class Solution:

    def longestPalindrome(self, s: str) -> str:
        import sys
        sys.setrecursionlimit(2000)
        self.cache = [[0] * (len(s)+1)] * (len(s)+1)
        return self.answer(s, 0, len(s))

    def answer(self, target, start, end) -> str:
        if target == '':
            return target

        if self.cache[start][end] != 0:
            return self.cache[start][end]
        else:
            if len(target) == 1:
                return target
            else:
                if self.is_palindrome(target):
                    self.cache[start][end] = target
                    return target

                left = self.answer(target[start:end-1], start, end - 1)
                mid = self.answer(target[start-1:end-1], start - 1, end - 1)
                right = self.answer(target[start+1:end], start + 1, end)

                subs = [len(left), len(mid), len(right)]
                idx = subs.index(max(subs))
                if idx == 0:
                    if left != '':
                        self.cache[start][end] = left
                    return left
                elif idx == 1:
                    if mid != '':
                        self.cache[start][end] = mid
                    return mid
                else:
                    if right != '':
                        self.cache[start][end] = right
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

    print(s.longestPalindrome("babcb"))
    print(s.longestPalindrome("abcdbbfcba")) # bb
    # print(s.cache)
    print(s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"))