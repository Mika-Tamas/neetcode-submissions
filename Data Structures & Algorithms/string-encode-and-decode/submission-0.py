class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for word in strs:
            encoded = encoded + str(len(word)) + "#"
            for char in word:
                encoded = encoded + char
        return encoded

    def decode(self, s: str) -> List[str]:
        j = 0
        i = 0
        decoded = []
        while j < len(s):
            i = j
            j += 1
            c_len_str = ""
            while s[i] != "#" and i < len(s):
                c_len_str = c_len_str + s[i]
                i += 1
            c_len = int(c_len_str)
            i += 1
            decoded.append(s[i:i+c_len])
            j = i + c_len
        return decoded


