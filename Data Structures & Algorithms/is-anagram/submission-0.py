class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_map = {}
        t_map = {}
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            s_map[s[i]] = 0
            t_map[t[i]] = 0
        for i in range(len(s)):
            s_map[s[i]] = s_map[s[i]]+1
            t_map[t[i]] = t_map[t[i]]+1
        return s_map == t_map