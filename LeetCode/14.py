class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ''
        idx = 0
        
        if len(strs) > 1:
            while idx < len(strs):
                if idx == 0:
                    prefix = self.find_prefix(strs[idx], strs[idx+1])
                    idx += 2
                else:
                    prefix = self.find_prefix(prefix, strs[idx])
                    idx += 1
        elif len(strs) == 1:
            prefix = strs[0]
        
        return prefix
        
    def find_prefix(self, s1, s2):
        prefix = ''        
        loop_str = ''
        if len(s1) > len(s2):
            loop_str = s2
        else:
            loop_str = s1
        
        idx = 0
        while idx < len(loop_str):
            if s1[idx] == s2[idx]:
                prefix += s1[idx]
            else:
                break
            idx += 1
        
        return prefix